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
	DDX_GridControl(pDX, IDC_GRIDCTRL_STABLESTATUSPARA, m_collectionStatusGridCtrl);
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
	// 1.解析doc
	Document doc;
	doc.Parse(m_collectionPlan.GetDictValue());
	if (!doc.HasMember("planParaTitle") || !doc.HasMember("planParaContent")) return;
	const Value& planParaTitle = doc["planParaTitle"];
	const Value& planParaContent = doc["planParaContent"];
	///如果json数据没有参数信息，则不显示
	if (planParaTitle.IsNull() || planParaContent.IsNull()){ return; }
	// 2. 获得信息
	m_collectionStatusGridCtrl.SetEditable(true);
	m_collectionStatusGridCtrl.SetEditable(true);
	m_collectionStatusGridCtrl.SetEditable(false);
	m_collectionStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_collectionStatusGridCtrl.SetRowCount(planParaContent.Size()+1); //初始为n行
	m_collectionStatusGridCtrl.SetColumnCount(planParaTitle.Size()+1); //初始化为3列
	m_collectionStatusGridCtrl.SetFixedRowCount(1); //表头为一行
	m_collectionStatusGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_collectionStatusGridCtrl.SetColumnResize(TRUE);
	m_collectionStatusGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_collectionStatusGridCtrl.ExpandColumnsToFit(true);

	m_collectionStatusGridCtrl.SetSingleRowSelection(true);
	//m_collectionStatusGridCtrl.OnGridClick();
	for (int row = 0; row < m_collectionStatusGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_collectionStatusGridCtrl.GetColumnCount(); col++)
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
				m_collectionStatusGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			else{
				Item.strText = planParaTitle[col - 1].GetString();
			}
			m_collectionStatusGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		if (col == 0){
			m_collectionStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); 
			m_collectionStatusGridCtrl.SetItemState(row, col, GVIS_READONLY);
		}
		CString strText;
		if (col != 0) 
				strText = planParaContent[row - 1][col -1 ].GetString();
		Item.strText=strText;
		m_collectionStatusGridCtrl.SetItem(&Item);

	}
}

void CollectionPlanParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///获得选中的单选框的状态
	if (!m_collectionStatusGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_collectionStatusGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_collectionStatusGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);
	if (pItem->iRow == 0){
		///全选按钮
		for (int row = 1; row < m_collectionStatusGridCtrl.GetRowCount(); row++){
			SetGridCellCheck(row, 0, !isChecked);
		}
	}
	else
	{
		if (isChecked)
		{
			SetGridCellCheck(0, 0, !isChecked);
		}
		else
		{
			int count = 0;
			for (int row = 1; row < m_collectionStatusGridCtrl.GetRowCount(); row++){
				if (GetGridCellCheck(row, 0))
				{
					count = count + 1;
				}
			}
			if (count == m_collectionStatusGridCtrl.GetRowCount() - 1)
			{
				SetGridCellCheck(0, 0, !isChecked);
			}
		}
	}

}

void CollectionPlanParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_collectionStatusGridCtrl.SetEditable(TRUE);
}

void CollectionPlanParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_collectionStatusGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_collectionStatusGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_collectionStatusGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}
bool CollectionPlanParaPresetView::GetGridCellCheck(int row, int col){
	if (!m_collectionStatusGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_collectionStatusGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_collectionStatusGridCtrl.GetCell(row, col);
	bool isChecked = pCell->GetCheck();
	return isChecked;
}

void CollectionPlanParaPresetView::OnBnClickedButtonAdd()
{
	///1.插入一行
	m_collectionStatusGridCtrl.InsertRow("");
	///2.设置新插入行的第一列为多选框
	m_collectionStatusGridCtrl.SetCellType(m_collectionStatusGridCtrl.GetRowCount()-1, 0, RUNTIME_CLASS(CGridCellCheck));
	m_collectionStatusGridCtrl.Refresh();
}
