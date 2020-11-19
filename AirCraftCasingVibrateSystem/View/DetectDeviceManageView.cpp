// DetectDeviceManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DetectDeviceManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CDetectDeviceManageView 对话框

IMPLEMENT_DYNAMIC(CDetectDeviceManageView, CDialogEx)

CDetectDeviceManageView::CDetectDeviceManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDetectDeviceManageView::IDD, pParent)
{

}

CDetectDeviceManageView::~CDetectDeviceManageView()
{
}

void CDetectDeviceManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_TESTINGDEVICE_GRIDCTRL, m_collectionparasGridCtrl);
	DDX_Control(pDX, IDC_TESTINGDEVICENAME_EDIT, m_collectionparasNameEdit);
}


BEGIN_MESSAGE_MAP(CDetectDeviceManageView, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CDetectDeviceManageView::OnBnClickedSearchButton)
	ON_NOTIFY(NM_DBLCLK, IDC_TESTINGDEVICE_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_TESTINGDEVICE_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(ID_DELETE_BUTTON, &CDetectDeviceManageView::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CDetectDeviceManageView::OnBnClickedAddButton)
	ON_BN_CLICKED(ID_SAVE_BUTTON, &CDetectDeviceManageView::OnBnClickedSaveButton)
END_MESSAGE_MAP()


// CDetectDeviceManageView 消息处理程序


BOOL CDetectDeviceManageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////获取检测设备的数据
	Result res = m_collectionparasController.FindAllCollectionparasBySearchCondition("", m_vcollectionparas);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	////初始化GridCtrl控件
	GridCtrlInit();
	return TRUE;  
}

void CDetectDeviceManageView::GridCtrlInit(){
	m_collectionparasGridCtrl.SetEditable(true);
	m_collectionparasGridCtrl.SetEditable(false);
	m_collectionparasGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_collectionparasGridCtrl.SetRowCount(m_vcollectionparas.size() + 1); //初始为n行
	m_collectionparasGridCtrl.SetColumnCount(5); //初始化为5列
	m_collectionparasGridCtrl.SetFixedRowCount(1); //表头为一行
	m_collectionparasGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_collectionparasGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_collectionparasGridCtrl.ExpandColumnsToFit(true);
	m_collectionparasGridCtrl.SetSingleRowSelection(true);
	m_collectionparasGridCtrl.SetRowCount(m_vcollectionparas.size() + 1); //初始为n行
	m_collectionparasGridCtrl.SetModified(FALSE);////初始状态
	//m_testingDeviceGridCtrl.OnGridClick();
	for (int row = 0; row < m_collectionparasGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_collectionparasGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("序号"), 0); }
			if (col == 1){ Item.strText.Format(_T("检测设备IP"), 1); }
			if (col == 2){ Item.strText.Format(_T("检测设备名称"), 2); }
			if (col == 3){ Item.strText.Format(_T("检测设备生产时间"), 3); }
			if (col == 4){ Item.strText.Format(_T("检测设备引入时间"), 4); }
			m_collectionparasGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		/*if (col == 1) strText = m_vtestingDevice[row - 1].GetTestingdeviceIp();
		if (col == 2) strText = m_vtestingDevice[row - 1].GetTestingdeviceName();
		if (col == 3) strText = m_vtestingDevice[row - 1].GetTestingdeviceBorndate();
		if (col == 4) strText = m_vtestingDevice[row - 1].GetTestingdeviceImportdate();*/

		Item.strText=strText;
		m_collectionparasGridCtrl.SetItem(&Item);
	}
}

void CDetectDeviceManageView::OnBnClickedSearchButton()
{
	CString collectionparasName = "";
	m_collectionparasNameEdit.GetWindowTextA(collectionparasName);
	Result res = m_collectionparasController.FindAllCollectionparasBySearchCondition(collectionparasName, m_vcollectionparas);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();
}
void CDetectDeviceManageView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_vcollectionparas.size()) return;
	m_selectedCollectionparas = m_vcollectionparas.at(pItem->iRow - 1);
}

void CDetectDeviceManageView::OnBnClickedDeleteButton(){
	/*if (m_selectedTestingDevice.GetId() == 0){
		AfxMessageBox("请选择需要删除的设备");
		return;
	}
	if (MessageBox("是否删除 " + m_selectedTestingDevice.GetTestingdeviceName(), "删除设备", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_testingDeviceController.DeleteByTestingDeviceId(m_selectedTestingDevice);
	if (res.GetIsSuccess()){
		m_selectedTestingDevice.SetId(0);
		///删除成功之后刷新页面
		res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///重新加载表格
		GridCtrlInit();
	}*/

}

void CDetectDeviceManageView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_collectionparasGridCtrl.SetEditable(TRUE);
}

///添加检测设备按钮
void CDetectDeviceManageView::OnBnClickedAddButton()
{
	m_collectionparasGridCtrl.InsertRow(CommonUtil::Int2CString(m_vcollectionparas.size() + 1));
	m_collectionparasGridCtrl.Refresh();
}


void CDetectDeviceManageView::OnBnClickedSaveButton(){
	//if (MessageBox("是否保存当前修改", "保存设备", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	//int rows = m_testingDeviceGridCtrl.GetRowCount();
	//int cols = m_testingDeviceGridCtrl.GetColumnCount();
	/////遍历表格的所有数据进行保存
	//Result res;
	//for (int row = 1; row < rows; row++){
	//	TbTestingDevice testingDevice;
	//	if (row < m_vtestingDevice.size() + 1){
	//		////对于需要更新的单元格，对检测设备id进行赋值
	//		testingDevice.SetTestingdeviceId(m_vtestingDevice[row-1].GetId()); 
	//		testingDevice.SetTestingDeviceStatus(m_vtestingDevice[row - 1].GetTestingDeviceStatus());
	//	}
	//	for (int col = 1; col < cols; col++){
	//		CString itemText = m_testingDeviceGridCtrl.GetItemText(row, col);
	//		if (col == 1){testingDevice.SetTestingdeviceIp(itemText);}
	//		if (col == 2){testingDevice.SetTestingdeviceName(itemText);}
	//		if (col == 3){ testingDevice.SetTestingdeviceBorndate(itemText); }
	//		if (col == 4){ testingDevice.SetTestingdeviceImportdate(itemText); }
	//	}
	//	////如果修改了没保存
	//	if (testingDevice.GetId() != 0 && testingDevice != m_vtestingDevice[row - 1]){
	//		res = m_testingDeviceController.UpdateTestingDevice(testingDevice);
	//	}
	//	////如果添加了之后没有保存。
	//	if (testingDevice.GetId()== 0){
	//		res = m_testingDeviceController.AddTestingDevice(testingDevice);
	//	}
	//	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	//}
	/////刷新表格
	//res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
	//if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	/////重新加载表格
	//GridCtrlInit();
}
