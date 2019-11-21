// CollectionPlanManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionPlanManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CollectionPlanManageView 对话框

IMPLEMENT_DYNAMIC(CollectionPlanManageView, CDialogEx)

CollectionPlanManageView::CollectionPlanManageView(CWnd* pParent /*=NULL*/)
: CDialogEx(CollectionPlanManageView::IDD, pParent)
{

}

CollectionPlanManageView::~CollectionPlanManageView()
{
}


void CollectionPlanManageView::DoDataExchange(CDataExchange* pDX)
{
	DDX_GridControl(pDX, IDC_GRIDCTRL_COLLECTIONPLANBASEINFO, m_collectionPlanBaseInfoGridCtrl);
	DDX_GridControl(pDX, IDC_GRIDCTRL_COLLECTIONPARAINFO, m_collectionPlanParaInfoGridCtrl);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CollectionPlanManageView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_COLLECTIONPLANBASEINFO, OnCollectionPlanBaseInfoGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_COLLECTIONPLANBASEINFO, OnCollectionPlanBaseInfoGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_COLLECTIONPARAINFO, OnCollectionPlanParaInfoGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_COLLECTIONPARAINFO, OnCollectionPlanParaInfoGridDblClick)
	ON_BN_CLICKED(IDC_BUTTON_ADDPLANBASEINFO, &CollectionPlanManageView::OnBnClickedButtonAddPlanBaseInfo)
	ON_BN_CLICKED(IDC_BUTTON_DELPLANBASEINFO, &CollectionPlanManageView::OnBnClickedButtonDelPlanBaseInfo)
	ON_BN_CLICKED(IDC_BUTTON_SAVEPLANBASEINFO, &CollectionPlanManageView::OnBnClickedButtonSavePlanBaseInfo)
	ON_BN_CLICKED(IDC_BUTTON_ADDPLANPARAROW, &CollectionPlanManageView::OnBnClickedButtonAddPlanParaRow)
	ON_BN_CLICKED(IDC_BUTTON_DELPLANPARAROW, &CollectionPlanManageView::OnBnClickedButtonDelPlanParaRow)
	ON_BN_CLICKED(IDC_BUTTON_ADDPLANPARACOL, &CollectionPlanManageView::OnBnClickedButtonAddPlanParaCol)
	ON_BN_CLICKED(IDC_BUTTON_SAVEPLANPARA, &CollectionPlanManageView::OnBnClickedButtonSavePlanPara)
END_MESSAGE_MAP()

// CollectionPlanManageView 消息处理程序
void CollectionPlanManageView::CollectionPlanBaseInfoGridCtrlInit(){
	///1.首先删除所有的项
	m_collectionPlanBaseInfoGridCtrl.DeleteAllItems();
	m_collectionPlanBaseInfoGridCtrl.Refresh();

	m_collectionPlanBaseInfoGridCtrl.SetEditable(false);
	m_collectionPlanBaseInfoGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_collectionPlanBaseInfoGridCtrl.SetRowCount(m_vcollectionPlan.size() + 1); //初始为n行
	m_collectionPlanBaseInfoGridCtrl.SetColumnCount(3); //初始化为3列
	m_collectionPlanBaseInfoGridCtrl.SetFixedRowCount(1); //表头为一行
	m_collectionPlanBaseInfoGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_collectionPlanBaseInfoGridCtrl.SetColumnResize(TRUE);
	m_collectionPlanBaseInfoGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_collectionPlanBaseInfoGridCtrl.ExpandColumnsToFit(true);

	m_collectionPlanBaseInfoGridCtrl.SetSingleRowSelection(true);
	//m_collectionPlanBaseInfoGridCtrl.OnGridClick();
	for (int row = 0; row < m_collectionPlanBaseInfoGridCtrl.GetRowCount(); row++){
		CString planName;
		CString planIntro;
		if (row > 0){
			// 1.解析doc
			Document doc;
			doc.Parse(m_vcollectionPlan[row - 1].GetDictValue());
			// 2. 获得信息
			planName = ((string)doc["planName"].GetString()).c_str();
			planIntro = ((string)doc["planIntro"].GetString()).c_str();
		}
		for (int col = 0; col < m_collectionPlanBaseInfoGridCtrl.GetColumnCount(); col++)
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
					Item.strText = "序号";
				}
				if (col == 1){
					Item.strText = "计划名称";
				}
				if (col == 2){
					Item.strText = "介绍";
				}
				m_collectionPlanBaseInfoGridCtrl.SetItem(&Item);
				continue;
			}

			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

			CString strText;
			if (col == 0) strText = CommonUtil::Int2CString(row);
			if (col == 1) strText = planName;
			if (col == 2) strText = planIntro;
			Item.strText = strText;
			m_collectionPlanBaseInfoGridCtrl.SetItem(&Item);
		}
	}

}

BOOL CollectionPlanManageView::OnInitDialog()
{
	Result res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return FALSE;
	}
	CDialogEx::OnInitDialog();
	CollectionPlanBaseInfoGridCtrlInit();
	///默认设置第一条数据为选中的采集状态
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(1, 0, 1, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(1, 0);
	m_selectedPlanIndex = 0;
	CollectionPlanParaInfoGridCtrlInit();
	return TRUE;
}
void CollectionPlanManageView::CollectionPlanParaInfoGridCtrlInit(){
	///1.首先删除所有的项
	m_collectionPlanParaInfoGridCtrl.DeleteAllItems();
	m_collectionPlanParaInfoGridCtrl.Refresh();
	if (m_selectedPlanIndex < 0 || m_selectedPlanIndex >= m_vcollectionPlan.size()){ return; }
	///2.解析采集计划数据
	Document doc;
	doc.Parse(m_vcollectionPlan[m_selectedPlanIndex].GetDictValue());
	///3.1如果采集计划数据里面没有采集计划参数的标题或者采集参数的内容，则不显示之后的内容
	if (doc.HasParseError()) return;
	Value planParaTitle(kArrayType);
	Value planParaContent(kArrayType);

	if (doc.HasMember("planParaTitle")){ planParaTitle = doc["planParaTitle"].GetArray(); }
	if (doc.HasMember("planParaContent")){ planParaContent = doc["planParaContent"].GetArray(); }
	
	///3.设置表格的属性
	m_collectionPlanParaInfoGridCtrl.SetEditable(false);
	m_collectionPlanParaInfoGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_collectionPlanParaInfoGridCtrl.SetRowCount(planParaContent.Size() + 1); //初始为n行
	m_collectionPlanParaInfoGridCtrl.SetColumnCount(planParaTitle.Size()); //初始化为n列
	m_collectionPlanParaInfoGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_collectionPlanParaInfoGridCtrl.SetColumnResize(TRUE);
	m_collectionPlanParaInfoGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_collectionPlanParaInfoGridCtrl.ExpandColumnsToFit(true);
	m_collectionPlanParaInfoGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_collectionPlanParaInfoGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_collectionPlanParaInfoGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			Item.strText = planParaTitle[col].GetString();
			m_collectionPlanParaInfoGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		Item.strText = planParaContent[row - 1][col].GetString();
		m_collectionPlanParaInfoGridCtrl.SetItem(&Item);
	}

}

void CollectionPlanManageView::OnCollectionPlanBaseInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	///获取当前选中的采集状态
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	m_selectedPlanIndex = pItem->iRow - 1;
	CollectionPlanParaInfoGridCtrlInit();
}

void CollectionPlanManageView::OnCollectionPlanBaseInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_collectionPlanBaseInfoGridCtrl.SetEditable(TRUE);
}

void CollectionPlanManageView::OnBnClickedButtonAddPlanBaseInfo()
{
	m_collectionPlanBaseInfoGridCtrl.InsertRow(CommonUtil::Int2CString(m_vcollectionPlan.size() + 1));
	m_collectionPlanBaseInfoGridCtrl.CheckAutoCenter();
	m_collectionPlanBaseInfoGridCtrl.Refresh();
}


void CollectionPlanManageView::OnBnClickedButtonDelPlanBaseInfo()
{
	///1.首先确定是否要删除
	if (MessageBox("是否删除该采集计划", "删除采集计划", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	///2.删除采集参数
	Result res = m_collectionPlanController.DeleteById(m_vcollectionPlan[m_selectedPlanIndex]);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); return; }
	///3.删除后查询所有的采集计划
	m_vcollectionPlan.clear();
	res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///默认设置最后一次记录的采集计划的索引
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(m_selectedPlanIndex, 0, m_selectedPlanIndex, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(m_selectedPlanIndex, 0);
	///初始化采集设备参数的表格
	CollectionPlanParaInfoGridCtrlInit();
}
void CollectionPlanManageView::OnBnClickedButtonSavePlanBaseInfo()
{
	///1.循环遍历采集基本信息的列表，保存当前的修改
	//1.1获得document分配器
	Document document;
	Document::AllocatorType& allocator = document.GetAllocator();
	for (int row = 1; row < m_collectionPlanBaseInfoGridCtrl.GetRowCount(); row++){
		TbDictionary collectPlan;
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		string jsonResult;
		///1.1 如果该条记录是需要修改的。
		if (row < m_vcollectionPlan.size() + 1){
			collectPlan = m_vcollectionPlan[row - 1];
			///1.2 解析原先的json数据，目的是不清除原先的参数信息。
			document.Parse(collectPlan.GetDictValue());
			///1.3 如果解析json出错，则不往下执行
			if (document.HasParseError()){ continue; }
			///1.4 修改采集计划的基本信息
			document["planName"].SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 1).GetBuffer(0), allocator);
			document["planIntro"].SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 2).GetBuffer(0), allocator);
			///1.5 将修改之后的doc树转成json串
			document.Accept(writer);
			jsonResult = buffer.GetString();
			collectPlan.SetDictValue(jsonResult.c_str());
			m_collectionPlanController.Update(collectPlan);
		}
		else{
			///1.2 如果该条记录是需要保存的。
			Value planName(kStringType);
			Value planIntro(kStringType);
			Value root(kObjectType);
			planName.SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 1).GetBuffer(0), allocator);
			planIntro.SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 2).GetBuffer(0), allocator);
			root.AddMember("planName", planName, allocator);
			root.AddMember("planIntro", planIntro, allocator);
			root.Accept(writer);
			jsonResult = buffer.GetString();
			collectPlan.SetDictName("collectionplan");
			collectPlan.SetDictValue(jsonResult.c_str());
			m_collectionPlanController.Add(collectPlan);
		}
	}
	///2.重新查询所有的采集对象，并刷新列表
	m_vcollectionPlan.clear();
	Result res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///3.设置上次选中的行为选中状态
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(m_selectedPlanIndex, 0, m_selectedPlanIndex, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(m_selectedPlanIndex, 0);
}


void CollectionPlanManageView::OnBnClickedButtonAddPlanParaRow()
{
	m_collectionPlanParaInfoGridCtrl.InsertRow("");
	m_collectionPlanParaInfoGridCtrl.CheckAutoCenter();
	m_collectionPlanParaInfoGridCtrl.Refresh();
}

void CollectionPlanManageView::OnCollectionPlanParaInfoGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	m_selectedPlanParaIndex = pItem->iRow - 1;
}

void CollectionPlanManageView::OnCollectionPlanParaInfoGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_collectionPlanParaInfoGridCtrl.SetEditable(TRUE);
}

/////删除这里有bug，删除没反应
void CollectionPlanManageView::OnBnClickedButtonDelPlanParaRow()
{
	m_collectionPlanParaInfoGridCtrl.DeleteRow(m_selectedPlanParaIndex);
	m_collectionPlanParaInfoGridCtrl.Refresh();
}

void CollectionPlanManageView::OnBnClickedButtonAddPlanParaCol()
{
	m_collectionPlanParaInfoGridCtrl.InsertColumn("未知参数", DT_CENTER | DT_WORDBREAK);
	m_collectionPlanParaInfoGridCtrl.ExpandColumnsToFit(true);
	/// 设置每一列的宽度为
	long width = m_collectionPlanParaInfoGridCtrl.GetVirtualWidth();
	int colWidth = width / m_collectionPlanParaInfoGridCtrl.GetColumnCount();
	for (int col = 0; col < m_collectionPlanParaInfoGridCtrl.GetColumnCount(); col++){
		m_collectionPlanParaInfoGridCtrl.SetColumnWidth(col, colWidth);
	}
	m_collectionPlanParaInfoGridCtrl.Refresh();
}

void CollectionPlanManageView::OnBnClickedButtonSavePlanPara()
{
	///1.获取当前选中的采集计划基本信息
	TbDictionary selectedCollectionPlan =  m_vcollectionPlan[m_selectedPlanIndex];
	///2.修改采集计划参数
	Document document;
	Document::AllocatorType& allocator = document.GetAllocator();
	///3.解析采集计划参数
	document.Parse(selectedCollectionPlan.GetDictValue());
	///4.删除采集计划的计划标题和计划内容
	if (document.HasMember("planParaTitle")){ document.RemoveMember("planParaTitle"); }
	if (document.HasMember("planParaContent")){ document.RemoveMember("planParaContent"); }
	///5.创建采集标题和内容的json对象
	Value planParaTitle(kArrayType);
	Value planParaContent(kArrayType);
	///6.封装json
	for (int row = 0; row < m_collectionPlanParaInfoGridCtrl.GetRowCount(); row++){
		Value paralineData(kArrayType);
		for (int col = 0; col < m_collectionPlanParaInfoGridCtrl.GetColumnCount(); col++){
			Value item(kStringType);
			item.SetString(m_collectionPlanParaInfoGridCtrl.GetItemText(row, col), allocator);
			if (row == 0 ){ planParaTitle.PushBack(item, allocator);}
			else paralineData.PushBack(item, allocator);
		}
		if (row != 0) planParaContent.PushBack(paralineData, allocator);
	}
	///7.将json数据添加到采集计划
	document.AddMember("planParaTitle", planParaTitle,allocator);
	document.AddMember("planParaContent", planParaContent,allocator);
	///8.将json解析成字符串
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	string result;
	document.Accept(writer);
	result = buffer.GetString();
	selectedCollectionPlan.SetDictValue(result.c_str());
	m_collectionPlanController.Update(selectedCollectionPlan);
	///9.刷新采集基本信息的界面
	///9.1.重新查询所有的采集对象，并刷新列表
	m_vcollectionPlan.clear();
	Result res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///9.2 设置上次选中的行为选中状态
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(m_selectedPlanIndex+1, 0, m_selectedPlanIndex+1, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(m_selectedPlanIndex+1, 0);
	CollectionPlanParaInfoGridCtrlInit();
}
