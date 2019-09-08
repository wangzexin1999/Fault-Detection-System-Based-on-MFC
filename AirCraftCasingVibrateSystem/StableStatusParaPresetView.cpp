// StableStatusParaPresetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StableStatusParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// StableStatusParaPresetView 对话框

IMPLEMENT_DYNAMIC(StableStatusParaPresetView, CDialogEx)

StableStatusParaPresetView::StableStatusParaPresetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(StableStatusParaPresetView::IDD, pParent)
{

}

StableStatusParaPresetView::~StableStatusParaPresetView()
{
}

void StableStatusParaPresetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GRIDCTRL_STABLESTATUSPARA, m_stableStatusGridCtrl);
}


BEGIN_MESSAGE_MAP(StableStatusParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_STABLESTATUSPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_STABLESTATUSPARA, OnGridDblClick)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &StableStatusParaPresetView::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// StableStatusParaPresetView 消息处理程序


BOOL StableStatusParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE;  
}
void StableStatusParaPresetView::GridCtrlInit()
{
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(false);
	m_stableStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_stableStatusGridCtrl.SetRowCount(3); //初始为n行
	m_stableStatusGridCtrl.SetColumnCount(4); //初始化为8列
	m_stableStatusGridCtrl.SetFixedRowCount(1); //表头为一行
	m_stableStatusGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_stableStatusGridCtrl.SetColumnResize(TRUE);
	m_stableStatusGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_stableStatusGridCtrl.ExpandColumnsToFit(true);


	/*m_stableStatusGridCtrl.SetColumnWidth(0, 50);
	m_stableStatusGridCtrl.SetColumnWidth(1, 90);
	m_stableStatusGridCtrl.SetColumnWidth(2, 380);
	m_stableStatusGridCtrl.SetColumnWidth(3, 447);*/

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
				Item.strText.Format(_T("序号"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("转速"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("备注"), 3);
			}
			m_stableStatusGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) strText = "1";
		if (col == 2) strText = "70hz";
		if (col == 3) strText = "正在使用";
		Item.strText.Format(_T(strText), row);
		m_stableStatusGridCtrl.SetItem(&Item);

	}
}

void StableStatusParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
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
}

void StableStatusParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_stableStatusGridCtrl.SetEditable(TRUE);
}

void StableStatusParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_stableStatusGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_stableStatusGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}

void StableStatusParaPresetView::OnBnClickedButtonAdd()
{
	m_stableStatusGridCtrl.InsertRow("");
	m_stableStatusGridCtrl.Refresh();
}
