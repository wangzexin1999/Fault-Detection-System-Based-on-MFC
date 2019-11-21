// SignalDataView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView 对话框

IMPLEMENT_DYNAMIC(CSignalDataView, CDialogEx)

CSignalDataView::CSignalDataView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalDataView::IDD, pParent)
{

}

CSignalDataView::~CSignalDataView()
{
}

void CSignalDataView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_SIGNALDATA_GRIDCTRL, m_signalDataGridCtrl);
	DDX_GridControl(pDX, IDC_PLAN_PARA, m_planParaGridCtrl);

	DDX_Control(pDX, IDC_DATE_COMBO, m_dateSelectComboBox);
	DDX_Control(pDX, IDC_COMBO_PRODUCT_NAME, m_productNameCombo);
	DDX_Control(pDX, IDC_COMBO_PROJECT_NAME, m_projectNameCombo);
	DDX_Control(pDX, IDC_COMBO_PLAN_NAME, m_planNameCombo);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_SIGNALDATA_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(IDOK, &CSignalDataView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CSignalDataView::OnBnClickedSearchButton)
	ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT_NAME, &CSignalDataView::OnCbnSelchangeComboProductName)
	ON_CBN_SELCHANGE(IDC_COMBO_PROJECT_NAME, &CSignalDataView::OnCbnSelchangeComboProjectName)
	ON_CBN_SELCHANGE(IDC_COMBO_PLAN_NAME, &CSignalDataView::OnCbnSelchangeComboPlanName)
	ON_CBN_SELCHANGE(IDC_DATE_COMBO, &CSignalDataView::OnCbnSelchangeDateCombo)
END_MESSAGE_MAP()


// CSignalDataView 消息处理程序

BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	///初始化信号显示表格控件的标题栏
	m_recordSignalGridTitle.push_back("产品");
	m_recordSignalGridTitle.push_back("项目");
	m_recordSignalGridTitle.push_back("采样时间");
	m_recordSignalGridTitle.push_back("传感器数量");
	m_recordSignalGridTitle.push_back("采集计划");

	m_dateSelectComboBox.InsertString(0,"全部日期");
	m_dateSelectComboBox.InsertString(1,"最近一天");
	m_dateSelectComboBox.InsertString(2,"最近一周");
	m_dateSelectComboBox.InsertString(3,"最近一月");
	m_dateSelectComboBox.InsertString(4,"最近半年");
	m_dateSelectComboBox.InsertString(5,"最近一年");
	m_dateSelectComboBox.SetCurSel(0);
	////查询所有的采集计划
	Result res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){ AfxMessageBox("采集计划初始化失败"); CDialogEx::OnCancel(); }
	for (int i = 0; i < m_vcollectionPlan.size(); i++){
		Document doc;
		doc.Parse(m_vcollectionPlan[i].GetDictValue());
		// 2. 获得信息
		CString planName = ((string)doc["planName"].GetString()).c_str();
		m_planNameCombo.InsertString(i,planName);
	}
	m_planNameCombo.SetCurSel(0);
	////根据选择的状态计划，加载他的所有参数
	OnCbnSelchangeComboPlanName();
	/////查询所有的产品
	res = m_productController.FindAllProduct(m_productVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("产品初始化失败"); CDialogEx::OnCancel(); }
	///将查询到的产品初始化到下拉框
	for (int i = 0; i < m_productVector.size(); i++){
		m_productNameCombo.InsertString(i, m_productVector[i].GetProductName());
	}
	m_productNameCombo.SetCurSel(0);
	///根据当前登录人和产品去查询所有项目
	OnCbnSelchangeComboProductName();
	///根据以上的选择去查询所有的数据文件
	GridCtrlInit();
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
	for (int row = 1; row < m_signalDataGridCtrl.GetRowCount(); row++){
		////1.解析采集状态
		Document doc;
		doc.Parse(m_signalVector[row - 1].GetCollectionStatus());

		if (doc.HasParseError()){ continue; }

		CString collectionPlan = ((string)doc["collectionPlan"].GetString()).c_str();
		const Value& collectionPlanPara = doc["collectionPlanPara"];
		////2.解析通道信息
		int	channelCount = 0;
		doc.Parse(m_signalVector[row - 1].GetSensorInfo());
		if (doc.HasParseError()){ continue; }
		channelCount = doc["channelCount"].GetInt();
		for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
		{
			//设置表格显示属性
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			CString strText;
			if (col == 0) strText = m_signalVector[row - 1].GetProduct().GetProductName();
			if (col == 1) strText = m_signalVector[row - 1].GetProject().GetProjectName();
			if (col == 2) strText = m_signalVector[row - 1].GetStartTime() + "-" + m_signalVector[row - 1].GetEndTime();
			if (col == 3) strText = CommonUtil::Int2CString(channelCount);
			if (col == 4) strText = collectionPlan;
			if (col >= m_recordSignalGridTitle.size())
				strText = collectionPlanPara[col - m_recordSignalGridTitle.size()].GetString();

			Item.strText = strText;
			m_signalDataGridCtrl.SetItem(&Item);
		}
	}
	
}

/**/
void CSignalDataView::GridCtrlPlanParaInit(const Value& planParaTitle)
{
	m_planParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_planParaGridCtrl.SetRowCount(planParaTitle.Size()+1); //初始为n行
	m_planParaGridCtrl.SetColumnCount(2); //初始化为2列
	m_planParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_planParaGridCtrl.SetFixedColumnCount(1);///设置固定列的个数为1
	m_planParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_planParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_planParaGridCtrl.ExpandColumnsToFit(true);
	m_planParaGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_planParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_planParaGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;

		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			if (col == 0){
				Item.strText.Format(_T("参数名"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("值"), 0);
			}
			m_planParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = planParaTitle[row-1].GetString();
		Item.strText = strText;
		m_planParaGridCtrl.SetItem(&Item);
	}

}
///项目的双击事件--》打开数据
void CSignalDataView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbRecordSignal g_signal = m_signalVector.at(pItem->iRow - 1);
	if (MessageBox("是否打开数据 " + g_signal.GetSignalId(), "打开数据", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////将选择的项目赋给全局project对象。
	///关闭窗口
	CDialogEx::OnOK();
}
void CSignalDataView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbRecordSignal g_signal = m_signalVector.at(pItem->iRow - 1);
	m_selectedSignal = g_signal;
}

////点击确定按钮
void CSignalDataView::OnBnClickedOk()
{
	

	if (MessageBox("是否打开数据 " + m_selectedSignal.GetSignalId(), "打开数据", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	CDialogEx::OnOK();
}


void CSignalDataView::OnBnClickedSearchButton()
{
	////清空数据集合
	m_signalVector.clear();
	m_searchSignalEntity.SetTesingDevice(theApp.m_currentProject.GetTestingDevice());
	m_searchSignalEntity.SetCollectionStatus(GetCollectionParaKeyWords());
	Result	res = m_signalController.FindAllRecordSignalBySearchCondition(m_searchSignalEntity, m_signalVector);
	if (!res.GetIsSuccess()){
		AfxMessageBox("数据文件检索失败");
		return;
	}
	GridCtrlInit();
}


void CSignalDataView::OnCbnSelchangeComboProductName()
{
	int selectedProductIndex = m_productNameCombo.GetCurSel();
	m_projectNameCombo.ResetContent();
	TbProject searchProject;
	searchProject.SetProduct(m_productVector[selectedProductIndex]);
	searchProject.SetTester(theApp.m_currentProject.GetTester());
	////清空项目集合
	m_projectVector.clear();
	Result res = m_projectController.FindAllProjectBySearchCondition(searchProject, "", "", m_projectVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("项目初始化失败"); CDialogEx::OnCancel(); }
	if (m_projectVector.size() == 0){ return; }///查询到的项目集合为空
	for (int i = 0; i < m_projectVector.size(); i++){
		m_projectNameCombo.InsertString(i, m_projectVector[i].GetProjectName());
	}
	m_projectNameCombo.SetCurSel(0);
	m_searchSignalEntity.SetProject(m_projectVector[0]);
	m_searchSignalEntity.SetProduct(m_productVector[selectedProductIndex]);
	OnBnClickedSearchButton();
}


void CSignalDataView::OnCbnSelchangeComboProjectName()
{
	int selectedProjectIndex = m_projectNameCombo.GetCurSel();
	if (selectedProjectIndex < 0) return;
	m_searchSignalEntity.SetProject(m_projectVector[selectedProjectIndex]);
	OnBnClickedSearchButton();
}

////改变采集计划的下拉框的值会相应改变采集计划参数列表的显示
void CSignalDataView::OnCbnSelchangeComboPlanName()
{
	int collectionPlanIndex = m_planNameCombo.GetCurSel();
	Document doc;
	doc.Parse(m_vcollectionPlan[collectionPlanIndex].GetDictValue());
	const Value& planParaTitle = doc["planParaTitle"];
	for (int i = 0; i < planParaTitle.Size();i++){
		m_planParaTitle.push_back(planParaTitle[i].GetString());
	}

	GridCtrlPlanParaInit(planParaTitle);
	OnBnClickedSearchButton();
}


void CSignalDataView::OnCbnSelchangeDateCombo()
{
	int testingIndex = m_dateSelectComboBox.GetCurSel();
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	if (testingIndex == 1){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(1)); }
	if (testingIndex == 2){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(7)); }
	if (testingIndex == 3){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(30)); }
	if (testingIndex == 4){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(182)); }
	if (testingIndex == 5){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(365)); }
	OnBnClickedSearchButton();
}
CString CSignalDataView::GetCollectionParaKeyWords(){
	int collectionPlanIndex = m_planNameCombo.GetCurSel();
	CString keyWords;
	m_planNameCombo.GetLBText(collectionPlanIndex, keyWords);
	for (int row = 1; row < m_planParaGridCtrl.GetRowCount();row++){
		for (int col = 0; col < m_planParaGridCtrl.GetColumnCount();col++){
			if (m_planParaGridCtrl.GetItemText(row, col) != ""){
				keyWords += "," + m_planParaGridCtrl.GetItemText(row, col);
			}
		}
	}
	return keyWords;
}

TbRecordSignal CSignalDataView::GetSelectedRecordSignal(){
	return m_selectedSignal;
}