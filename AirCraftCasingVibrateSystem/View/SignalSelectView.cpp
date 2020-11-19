// SignalSelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalSelectView.h"
#include "afxdialogex.h"
#include "Result.h"
#include "CommonUtil.h"
// CSignalSelectView 对话框

IMPLEMENT_DYNAMIC(CSignalSelectView, CDialogEx)

CSignalSelectView::CSignalSelectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalSelectView::IDD, pParent)
{

}

CSignalSelectView::~CSignalSelectView()
{
}

void CSignalSelectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_TREE_SELECT_CHANNEL2, m_treeSignalSelect);
	DDX_Control(pDX, IDC_TREE_SELECTED_CHANNEL, m_treeSignalSelected);
}


BEGIN_MESSAGE_MAP(CSignalSelectView, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_SELECT_CHANNEL, &CSignalSelectView::OnNMDblclkTreeSelectChannel)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_SELECTED_CHANNEL, &CSignalSelectView::OnNMDblclkTreeSelectedChannel)
	ON_BN_CLICKED(IDOK, &CSignalSelectView::OnBnClickedOk)
END_MESSAGE_MAP()


// CSignalSelectView 消息处理程序
TbChannel & CSignalSelectView::GetSelectedChannel(){
	return m_selectedChannel;
}

BOOL CSignalSelectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/////初始化传感器选择树控件
	InitChannelSelectTree();
	////初始化传感器被选择控件
	InitChannelSelectedTree();
	return TRUE;  
}

void CSignalSelectView::InitChannelSelectTree(){
	m_treeSignalSelect.DeleteAllItems();
	///从硬件读取所有的传感器


	//int testingDeviceId = theApp.m_currentProject.GetTestingDevice().GetId();
	//Result res = m_sensorController.FindAllSensorByTestingDeviceId(testingDeviceId, m_sensorVector);
	//if (!res.GetIsSuccess()){
	//	AfxMessageBox(res.GetMessages());
	//}
	//// 树的根节点的句柄   
	//HBITMAP hDirBmp;
	//hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	//m_treeSignalSelect.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);
	//CFont font;
	//font.CreatePointFont(100, _T("Book Antiqua"));

	//m_treeSignalSelect.SetFont(&font);
	//m_treeSignalSelect.SetFocus();
	//m_treeSignalSelect.SetBkColor(RGB(255, 255, 255));

	//HTREEITEM hCurrent;
	//hCurrent = m_treeSignalSelect.InsertItem(_T("FFT"), TVI_ROOT, TVI_LAST);
	//m_treeSignalSelect.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);

	//HTREEITEM hCurrent1;
	//HBITMAP itemBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(IDB_BMPSIGNALGREEN));
	//int num = 1;
	//for (auto sensor : m_sensorVector){
	//	hCurrent1 = m_treeSignalSelect.InsertItem(_T(CommonUtil::Int2CString(num++) + "-" + sensor.GetSensorDesc()), hCurrent, TVI_LAST);
	//	m_treeSignalSelect.AddItemBitmap(hCurrent1, itemBmp, ppLastLeft);
	//}
}
void CSignalSelectView::InitChannelSelectedTree(){
	// 树的根节点的句柄   

	m_treeSignalSelected.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);
	CFont font;
	font.CreatePointFont(100, _T("Book Antiqua"));

	m_treeSignalSelected.SetFont(&font);
	m_treeSignalSelected.SetFocus();
	m_treeSignalSelected.SetBkColor(RGB(255, 255, 255));

	if (m_selectedChannel.GetId() != 0){
		////如果已经选择了传感器，则显示已经显示的传感器
		HBITMAP hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
		HTREEITEM hCurrent = m_treeSignalSelected.InsertItem(_T(m_selectedChannel.GetChannelDesc()), TVI_ROOT, TVI_LAST);
		m_treeSignalSelected.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);
	}

}

///双击左边树结构节点时，将该节点赋值给临时传感器对象，并显示。
void CSignalSelectView::OnNMDblclkTreeSelectChannel(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_channelVector.empty()){ return; }
	CString tmp;
	HTREEITEM selectedItem;
	CWnd *m_CWnd;
	m_CWnd = GetDlgItem(IDC_TREE_SELECT_CHANNEL);
	selectedItem = m_treeSignalSelect.GetSelectedItem();
	if (m_treeSignalSelect.ItemHasChildren(selectedItem)) {
		return; ///如果还有子节点，则不做任何操作
	}
	CString text = m_treeSignalSelect.GetItemText(selectedItem);

	////拿到当前选中的传感器
	int num = atoi(CommonUtil::GetCStringVectorFromSplitCString(text, "-")[0]);
	m_tempSelectedChannel = m_channelVector[num - 1];
	/////删除选中的所有节点
	m_treeSignalSelected.DeleteAllItems();
	HBITMAP hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	HTREEITEM hCurrent = m_treeSignalSelected.InsertItem(_T(m_tempSelectedChannel.GetChannelDesc()), TVI_ROOT, TVI_LAST);
	m_treeSignalSelected.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);
}

////双击节点删除
void CSignalSelectView::OnNMDblclkTreeSelectedChannel(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_treeSignalSelected.DeleteAllItems();
	m_tempSelectedChannel = TbChannel();
}
void CSignalSelectView::OnBnClickedOk()
{
	m_selectedChannel = m_tempSelectedChannel;
	CDialogEx::OnOK();
}

void CSignalSelectView::SetChannel(TbChannel channel){
	m_selectedChannel = channel;
}
void  CSignalSelectView::GetChannel(TbChannel & channel){
	channel = m_selectedChannel;
}