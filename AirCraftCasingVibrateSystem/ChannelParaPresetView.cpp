// ChannelParaPresetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaPresetView.h"
#include "afxdialogex.h"


// ChannelParaPresetView 对话框

IMPLEMENT_DYNAMIC(ChannelParaPresetView, CDialogEx)

ChannelParaPresetView::ChannelParaPresetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChannelParaPresetView::IDD, pParent)
{

}

ChannelParaPresetView::~ChannelParaPresetView()
{
}

void ChannelParaPresetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GRIDCTRL_CHANNELPARA, m_channelParaGridCtrl);
}


BEGIN_MESSAGE_MAP(ChannelParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_CHANNELPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_CHANNELPARA, OnGridDblClick)
END_MESSAGE_MAP()


// ChannelParaPresetView 消息处理程序


BOOL ChannelParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE; 
}
void ChannelParaPresetView::GridCtrlInit()
{
	m_channelParaGridCtrl.SetEditable(true);
	m_channelParaGridCtrl.SetEditable(true);
	m_channelParaGridCtrl.SetEditable(false);
	m_channelParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_channelParaGridCtrl.SetRowCount(3); //初始为n行
	m_channelParaGridCtrl.SetColumnCount(8); //初始化为8列
	m_channelParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_channelParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_channelParaGridCtrl.SetColumnResize(TRUE);
	m_channelParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_channelParaGridCtrl.ExpandColumnsToFit(true);
	
	
	/*m_channelParaGridCtrl.SetColumnWidth(0, 50);
	m_channelParaGridCtrl.SetColumnWidth(1, 90);
	m_channelParaGridCtrl.SetColumnWidth(2, 380);
	m_channelParaGridCtrl.SetColumnWidth(3, 447);*/

	m_channelParaGridCtrl.SetSingleRowSelection(true);
	//m_channelParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_channelParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_channelParaGridCtrl.GetColumnCount(); col++)
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
				m_channelParaGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText.Format(_T("序号"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("通道描述"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("通道状态"), 3);
			}
			if (col == 4){
				Item.strText.Format(_T("窗类型"), 3);
			}
			if (col == 5){
				Item.strText.Format(_T("灵敏度"), 3);
			}
			if (col == 6){
				Item.strText.Format(_T("输入方式"), 3);
			}
			if (col == 7){
				Item.strText.Format(_T("量程"), 3);
			}
			m_channelParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) strText = "1";
		if (col == 2) strText = "一号通道";
		if (col == 3) strText = "正在使用";
		if (col == 4) strText = "窗类型未知";
		if (col == 5) strText = "灵敏度未知";
		if (col == 6) strText = "输入方式未知";
		if (col == 7) strText = "量程未知";
		Item.strText.Format(_T(strText), row);
		m_channelParaGridCtrl.SetItem(&Item);

	}
}

void ChannelParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///获得选中的单选框的状态
	if (!m_channelParaGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///全选按钮
		for (int row = 1; row < m_channelParaGridCtrl.GetRowCount(); row++){
			SetGridCellCheck(row, 0, !isChecked);
		}
	}
}


void ChannelParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_channelParaGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}

void ChannelParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_channelParaGridCtrl.SetEditable(TRUE);
}