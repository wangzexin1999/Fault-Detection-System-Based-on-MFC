// SignalDataView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView 对话框

IMPLEMENT_DYNAMIC(CSignalDataView, CDialogEx)

CSignalDataView::CSignalDataView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalDataView::IDD, pParent){

}

CSignalDataView::~CSignalDataView()
{
}

void CSignalDataView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_SIGNALDATA_GRIDCTRL, m_signalDataGridCtrl);

	DDX_Control(pDX, IDC_DATE_COMBO, m_dateSelectComboBox);
	DDX_Control(pDX, IDC_COMBO_PRODUCT_NAME, m_productNameCombo);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_SIGNALDATA_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(IDOK, &CSignalDataView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CSignalDataView::OnBnClickedSearchButton)
	ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT_NAME, &CSignalDataView::OnCbnSelchangeComboProductName)
	ON_CBN_SELCHANGE(IDC_DATE_COMBO, &CSignalDataView::OnCbnSelchangeDateCombo)

END_MESSAGE_MAP()


// CSignalDataView 消息处理程序

BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	///初始化信号显示表格控件的标题栏
	m_recordSignalGridTitle.push_back("序号");
	m_recordSignalGridTitle.push_back("产品");
	//m_recordSignalGridTitle.push_back("通道个数");
	m_recordSignalGridTitle.push_back("开始时间");
	m_recordSignalGridTitle.push_back("结束时间");

	m_dateSelectComboBox.InsertString(0,"全部日期");
	m_dateSelectComboBox.InsertString(1,"最近一天");
	m_dateSelectComboBox.InsertString(2,"最近一周");
	m_dateSelectComboBox.InsertString(3,"最近一月");
	m_dateSelectComboBox.InsertString(4,"最近半年");
	m_dateSelectComboBox.InsertString(5,"最近一年");
	m_dateSelectComboBox.SetCurSel(0);

	/////查询所有的产品
	Result res = m_productController.FindAllProduct(m_productVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("产品初始化失败"); CDialogEx::OnCancel(); }
	///将查询到的产品初始化到下拉框
	m_productNameCombo.InsertString(0, "所有产品");
	for (int i = 0; i < m_productVector.size(); i++){
		m_productNameCombo.InsertString(i + 1, m_productVector[i].GetProductName());
	}
	m_productNameCombo.SetCurSel(0);
	///根据当前登录人和产品去查询所有项目
	OnCbnSelchangeComboProductName();
	///根据以上的选择去查询所有的数据文件
	OnBnClickedSearchButton();
	return TRUE;
}
void CSignalDataView::GridCtrlInit(){
	m_signalDataGridCtrl.SetEditable(false);
	m_signalDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_signalDataGridCtrl.SetRowCount(m_signalVector.size()+1); //初始为n行
	m_signalDataGridCtrl.SetColumnCount(m_recordSignalGridTitle.size() + m_planParaTitle.size()); //初始化为5列
	m_signalDataGridCtrl.SetFixedRowCount(1); //表头为一行
	m_signalDataGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_signalDataGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_signalDataGridCtrl.ExpandColumnsToFit(true);
	m_signalDataGridCtrl.SetSingleRowSelection(true);

	///首先设置标题内容
	for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++){
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = 0;
		Item.col = col;
		Item.nFormat = DT_CENTER | DT_WORDBREAK;
		if (col < m_recordSignalGridTitle.size()){
			Item.strText = m_recordSignalGridTitle[col];
		}
		else{
			Item.strText = m_planParaTitle[col - m_recordSignalGridTitle.size()];
		}
		m_signalDataGridCtrl.SetItem(&Item);
	}
	///设置表格内容
	for (int row = 1; row <m_signalDataGridCtrl.GetRowCount(); row++){
		for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
		{
			//设置表格显示属性
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			CString strText;
			if (col == 0) strText = CommonUtil::Int2CString(row);
			if (col == 1) strText = m_signalVector[row - 1].GetProduct().GetProductName();
			//if (col == 2) strText = CommonUtil::Int2CString(m_signalVector[row - 1].GetAllSignal().size());
			if (col == 2) strText = m_signalVector[row - 1].GetStartTime() ;
			if (col == 3) strText = m_signalVector[row - 1].GetEndTime();
			Item.strText = strText;
			m_signalDataGridCtrl.SetItem(&Item);
		}
	}
	
}

///项目的双击事件--》打开数据
void CSignalDataView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSumsignal g_signal = m_signalVector.at(pItem->iRow - 1);
	if (MessageBox("是否打开数据 " + g_signal.GetSumsignalId(), "打开数据", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////将选择的项目赋给全局project对象。
	///关闭窗口
	CDialogEx::OnOK();
}
void CSignalDataView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSumsignal g_signal = m_signalVector.at(pItem->iRow - 1);
	m_selectedSignal = g_signal;
}

////点击确定按钮
void CSignalDataView::OnBnClickedOk()
 {

	if (m_selectedSignal.GetSumsignalId() == ""){AfxMessageBox("请选择数据");return;}

	if (MessageBox("是否打开数据", "确认打开数据？", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;

	CDialogEx::OnOK();
}


void CSignalDataView::OnBnClickedSearchButton()
{
	////清空数据集合
	m_signalVector.clear();
	
	Result	res = m_signalController.FindAllSumSignalBySearchCondition(m_searchSignalEntity, m_signalVector);
	if (!res.GetIsSuccess()){
		AfxMessageBox("数据文件检索失败");
		return;
	}
	GridCtrlInit();
}


void CSignalDataView::OnCbnSelchangeComboProductName()
{
	int selectedProductIndex = m_productNameCombo.GetCurSel();
	int productId = 0;
	if (selectedProductIndex != 0){
		productId = m_productVector[selectedProductIndex - 1].GetProductId();
	}
	m_searchSignalEntity.SetProductId(productId);
	OnBnClickedSearchButton();
}

void CSignalDataView::OnCbnSelchangeDateCombo()
{
	int testingIndex = m_dateSelectComboBox.GetCurSel();
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	if (testingIndex == 0){ m_searchSignalEntity.SetStartTime(""); }
	if (testingIndex == 1){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(1)); }
	if (testingIndex == 2){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(7)); }
	if (testingIndex == 3){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(30)); }
	if (testingIndex == 4){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(182)); }
	if (testingIndex == 5){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(365)); }
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	OnBnClickedSearchButton();
}

TbSumsignal CSignalDataView::GetSelectedSumSignal(){
	return m_selectedSignal;
}