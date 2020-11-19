// SignalSelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalSelectView.h"
#include "afxdialogex.h"
#include "Result.h"
#include "CommonUtil.h"
// CSignalSelectView �Ի���

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


// CSignalSelectView ��Ϣ�������
TbChannel & CSignalSelectView::GetSelectedChannel(){
	return m_selectedChannel;
}

BOOL CSignalSelectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/////��ʼ��������ѡ�����ؼ�
	InitChannelSelectTree();
	////��ʼ����������ѡ��ؼ�
	InitChannelSelectedTree();
	return TRUE;  
}

void CSignalSelectView::InitChannelSelectTree(){
	m_treeSignalSelect.DeleteAllItems();
	///��Ӳ����ȡ���еĴ�����


	//int testingDeviceId = theApp.m_currentProject.GetTestingDevice().GetId();
	//Result res = m_sensorController.FindAllSensorByTestingDeviceId(testingDeviceId, m_sensorVector);
	//if (!res.GetIsSuccess()){
	//	AfxMessageBox(res.GetMessages());
	//}
	//// ���ĸ��ڵ�ľ��   
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
	// ���ĸ��ڵ�ľ��   

	m_treeSignalSelected.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);
	CFont font;
	font.CreatePointFont(100, _T("Book Antiqua"));

	m_treeSignalSelected.SetFont(&font);
	m_treeSignalSelected.SetFocus();
	m_treeSignalSelected.SetBkColor(RGB(255, 255, 255));

	if (m_selectedChannel.GetId() != 0){
		////����Ѿ�ѡ���˴�����������ʾ�Ѿ���ʾ�Ĵ�����
		HBITMAP hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
		HTREEITEM hCurrent = m_treeSignalSelected.InsertItem(_T(m_selectedChannel.GetChannelDesc()), TVI_ROOT, TVI_LAST);
		m_treeSignalSelected.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);
	}

}

///˫��������ṹ�ڵ�ʱ�����ýڵ㸳ֵ����ʱ���������󣬲���ʾ��
void CSignalSelectView::OnNMDblclkTreeSelectChannel(NMHDR *pNMHDR, LRESULT *pResult)
{
	if (m_channelVector.empty()){ return; }
	CString tmp;
	HTREEITEM selectedItem;
	CWnd *m_CWnd;
	m_CWnd = GetDlgItem(IDC_TREE_SELECT_CHANNEL);
	selectedItem = m_treeSignalSelect.GetSelectedItem();
	if (m_treeSignalSelect.ItemHasChildren(selectedItem)) {
		return; ///��������ӽڵ㣬�����κβ���
	}
	CString text = m_treeSignalSelect.GetItemText(selectedItem);

	////�õ���ǰѡ�еĴ�����
	int num = atoi(CommonUtil::GetCStringVectorFromSplitCString(text, "-")[0]);
	m_tempSelectedChannel = m_channelVector[num - 1];
	/////ɾ��ѡ�е����нڵ�
	m_treeSignalSelected.DeleteAllItems();
	HBITMAP hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	HTREEITEM hCurrent = m_treeSignalSelected.InsertItem(_T(m_tempSelectedChannel.GetChannelDesc()), TVI_ROOT, TVI_LAST);
	m_treeSignalSelected.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);
}

////˫���ڵ�ɾ��
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