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
	DDX_GridControl(pDX, IDC_TESTINGDEVICE_GRIDCTRL, m_testingDeviceGridCtrl);
	DDX_Control(pDX, IDC_TESTINGDEVICENAME_EDIT, m_testingDeviceNameEdit);
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
	Result res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("",m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	////初始化GridCtrl控件
	GridCtrlInit();
	return TRUE;  
}

void CDetectDeviceManageView::GridCtrlInit(){
	m_testingDeviceGridCtrl.SetEditable(true);
	m_testingDeviceGridCtrl.SetEditable(false);
	m_testingDeviceGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_testingDeviceGridCtrl.SetRowCount(m_vtestingDevice.size()+1); //初始为n行
	m_testingDeviceGridCtrl.SetColumnCount(5); //初始化为5列
	m_testingDeviceGridCtrl.SetFixedRowCount(1); //表头为一行
	m_testingDeviceGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_testingDeviceGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_testingDeviceGridCtrl.ExpandColumnsToFit(true);
	m_testingDeviceGridCtrl.SetSingleRowSelection(true);
	m_testingDeviceGridCtrl.SetRowCount(m_vtestingDevice.size() + 1); //初始为n行
	m_testingDeviceGridCtrl.SetModified(FALSE);////初始状态
	//m_testingDeviceGridCtrl.OnGridClick();
	for (int row = 0; row < m_testingDeviceGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_testingDeviceGridCtrl.GetColumnCount(); col++)
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
			m_testingDeviceGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = m_vtestingDevice[row - 1].GetTestingdeviceIp();
		if (col == 2) strText = m_vtestingDevice[row - 1].GetTestingdeviceName();
		if (col == 3) strText = m_vtestingDevice[row - 1].GetTestingdeviceBorndate();
		if (col == 4) strText = m_vtestingDevice[row - 1].GetTestingdeviceImportdate();

		Item.strText=strText;
		m_testingDeviceGridCtrl.SetItem(&Item);
	}
}

void CDetectDeviceManageView::OnBnClickedSearchButton()
{
	CString testingDeviceName="";
	m_testingDeviceNameEdit.GetWindowTextA(testingDeviceName);
	Result res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition(testingDeviceName, m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();
}
void CDetectDeviceManageView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_vtestingDevice.size()) return;
	m_selectedTestingDevice = m_vtestingDevice.at(pItem->iRow - 1);
}

void CDetectDeviceManageView::OnBnClickedDeleteButton(){
	if (m_selectedTestingDevice.GetTestingdeviceId() == 0){
		AfxMessageBox("请选择需要删除的设备");
		return;
	}
	if (MessageBox("是否删除 " + m_selectedTestingDevice.GetTestingdeviceName(), "删除设备", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_testingDeviceController.DeleteByTestingDeviceId(m_selectedTestingDevice);
	if (res.GetIsSuccess()){
		m_selectedTestingDevice.SetTestingdeviceId(0);
		///删除成功之后刷新页面
		res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///重新加载表格
		GridCtrlInit();
	}

}

void CDetectDeviceManageView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_testingDeviceGridCtrl.SetEditable(TRUE);
}

///添加检测设备按钮
void CDetectDeviceManageView::OnBnClickedAddButton()
{
	m_testingDeviceGridCtrl.InsertRow(CommonUtil::Int2CString(m_vtestingDevice.size() + 1));
	m_testingDeviceGridCtrl.Refresh();
}


void CDetectDeviceManageView::OnBnClickedSaveButton(){
	if (MessageBox("是否保存当前修改", "保存设备", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_testingDeviceGridCtrl.GetRowCount();
	int cols = m_testingDeviceGridCtrl.GetColumnCount();
	///遍历表格的所有数据进行保存
	Result res;
	for (int row = 1; row < rows; row++){
		TbTestingDevice testingDevice;
		if (row < m_vtestingDevice.size() + 1){
			////对于需要更新的单元格，对检测设备id进行赋值
			testingDevice.SetTestingdeviceId(m_vtestingDevice[row-1].GetTestingdeviceId()); 
			testingDevice.SetTestingDeviceStatus(m_vtestingDevice[row - 1].GetTestingDeviceStatus());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_testingDeviceGridCtrl.GetItemText(row, col);
			if (col == 1){testingDevice.SetTestingdeviceIp(itemText);}
			if (col == 2){testingDevice.SetTestingdeviceName(itemText);}
			if (col == 3){ testingDevice.SetTestingdeviceBorndate(itemText); }
			if (col == 4){ testingDevice.SetTestingdeviceImportdate(itemText); }
		}
		////如果修改了没保存
		if (testingDevice.GetTestingdeviceId() != 0 && testingDevice != m_vtestingDevice[row - 1]){
			res = m_testingDeviceController.UpdateTestingDevice(testingDevice);
		}
		////如果添加了之后没有保存。
		if (testingDevice.GetTestingdeviceId()== 0){
			res = m_testingDeviceController.AddTestingDevice(testingDevice);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}
	///刷新表格
	res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///重新加载表格
	GridCtrlInit();
}
