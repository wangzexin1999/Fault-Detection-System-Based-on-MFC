// CollectionPlanParaPresetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionPlanParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CollectionPlanParaPresetView 对话框

IMPLEMENT_DYNAMIC(CollectionPlanParaPresetView, CDialogEx)

CollectionPlanParaPresetView::CollectionPlanParaPresetView(TbDictionary collectionPlan, CWnd* pParent)
: CDialogEx(CollectionPlanParaPresetView::IDD, pParent)
{
	m_collectionPlan = collectionPlan;
}
CollectionPlanParaPresetView::CollectionPlanParaPresetView(CWnd* pParent)
: CDialogEx(CollectionPlanParaPresetView::IDD, pParent)
{

}

CollectionPlanParaPresetView::~CollectionPlanParaPresetView()
{
}

void CollectionPlanParaPresetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GRIDCTRL_STABLESTATUSPARA, m_stableStatusGridCtrl);
}


BEGIN_MESSAGE_MAP(CollectionPlanParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_STABLESTATUSPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_STABLESTATUSPARA, OnGridDblClick)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CollectionPlanParaPresetView::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CollectionPlanParaPresetView 消息处理程序


BOOL CollectionPlanParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE;  
}
void CollectionPlanParaPresetView::GridCtrlInit()
{
	////获取采集计划的参数信息
	CString csPara  = m_collectionPlan.GetDictValue();
	// 1.解析doc
	Document doc;
	doc.Parse(m_collectionPlan.GetDictValue());

	const Value& planParaTitle = doc["planParaTitle"];
	const Value& planParaContent = doc["planParaContent"];

	// 2. 获得信息
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(false);
	m_stableStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_stableStatusGridCtrl.SetRowCount(planParaContent.Size()+1); //初始为n行
	m_stableStatusGridCtrl.SetColumnCount(planParaTitle.Size()+1); //初始化为3列
	m_stableStatusGridCtrl.SetFixedRowCount(1); //表头为一行
	m_stableStatusGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_stableStatusGridCtrl.SetColumnResize(TRUE);
	m_stableStatusGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_stableStatusGridCtrl.ExpandColumnsToFit(true);

	m_stableStatusGridCtrl.SetSingleRowSelection(true);
	//m_stableStatusGridCtrl.OnGridClick();
	for (int row = 0; row < m_stableStatusGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_stableStatusGridCtrl.GetColumnCount(); col++)
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
				m_stableStatusGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText.Format(_T(planParaTitle[0].GetString()), 2);
			}
			if (col == 2){
				Item.strText.Format(_T(planParaTitle[1].GetString()), 3);
			}
			m_stableStatusGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		if (col == 0){ m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		CString strText;
		if (col != 0) 
				strText = planParaContent[row - 1][col -1 ].GetString();
		Item.strText=strText;
		m_stableStatusGridCtrl.SetItem(&Item);

	}
}

void CollectionPlanParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///获得选中的单选框的状态
	if (!m_stableStatusGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_stableStatusGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);
	if (pItem->iRow == 0){
		///全选按钮
		for (int row = 1; row < m_stableStatusGridCtrl.GetRowCount(); row++){
			SetGridCellCheck(row, 0, !isChecked);
		}
	}
	else{

	}
}

void CollectionPlanParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_stableStatusGridCtrl.SetEditable(TRUE);
}

void CollectionPlanParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_stableStatusGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_stableStatusGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}

void CollectionPlanParaPresetView::OnBnClickedButtonAdd()
{
	m_stableStatusGridCtrl.InsertRow("");
	m_stableStatusGridCtrl.Refresh();
}
/*
{
"planName": "平稳状态",
"planIntro": "平稳状态下的采集",
"planParaTitle": ["转速", "备注"],
"planParaContent": [
["126hz", "正在使用"],
["126hz", "正在使用"]
]
}
*/

void  CollectionPlanParaPresetView::GetCollectionPlan(TbCollectionPlan &collectionPlan){

	collectionPlan.SetPlanId( m_collectionPlan.GetDictId());
	///解析原计划模板
	Document planDoc;
	planDoc.Parse(m_collectionPlan.GetDictValue());
	Value& planParaContent = planDoc["planParaContent"];
	/// 清空
	planParaContent.GetArray().Clear();

	for (int row = 1; row < m_stableStatusGridCtrl.GetRowCount(); row++){
		if (!m_stableStatusGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, 0);
		if (pCell->GetCheck()){
			Value lineData(kArrayType);
			for (int col = 1; col < m_stableStatusGridCtrl.GetColumnCount();col++){
				///获得每一行每一列的参数
				Value  para(kStringType);
				//////乱码
				string  temp;
				temp = m_stableStatusGridCtrl.GetItemText(row, col).GetString();
				para.SetString(temp.c_str(), temp.size(), planDoc.GetAllocator());
				lineData.PushBack(para,planDoc.GetAllocator());
			}
			planParaContent.GetArray().PushBack(lineData, planDoc.GetAllocator());
		}
	}

	//Document document;
	////获得分配器
	//Document::AllocatorType& allocator = document.GetAllocator();
	/////创建根节点
	//Value root(kObjectType);
	/////创建rotatingSpeed节点
	//Value rotatingSpeed(kArrayType);
	////rotatingSpeed.SetString("rotatingSpeed");
	//for (int row = 1; row < m_stableStatusGridCtrl.GetRowCount();row++){
	//	if (!m_stableStatusGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
	//		m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
	//	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, 0);
	//	if (pCell->GetCheck()){

	//		Value  rotatingSpeedEntity(kObjectType);

	//		////获得选中的，将其记录下来，拼成json数据
	//		Value  speed(kStringType);
	//		Value  remarks(kStringType);
	//		string  temp;
	//		///获得转速
	//		temp= m_stableStatusGridCtrl.GetItemText(row, 1).GetString();
	//		speed.SetString(temp.c_str(), temp.size(), allocator);
	//		///获得备注
	//		temp = m_stableStatusGridCtrl.GetItemText(row, 2).GetString();
	//		remarks.SetString(temp.c_str(), temp.size(), allocator);
	//		///将转速和备注添加到转速实体中
	//		rotatingSpeedEntity.AddMember("speed", speed, allocator);
	//		rotatingSpeedEntity.AddMember("remarks", remarks, allocator);
	//		///将转速实体添加到数组中
	//		rotatingSpeed.PushBack(rotatingSpeedEntity,allocator);
	//	}
	//}
	//root.AddMember("rotatingSpeed", rotatingSpeed, allocator);
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	planDoc.Accept(writer);
	std::string result = buffer.GetString();
	collectionPlan.SetPlanPara(result.c_str());
}