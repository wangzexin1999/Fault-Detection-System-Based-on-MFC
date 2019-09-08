// ChannelParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaPresetView.h"
#include "afxdialogex.h"


// ChannelParaPresetView �Ի���

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


// ChannelParaPresetView ��Ϣ�������


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
	m_channelParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_channelParaGridCtrl.SetRowCount(3); //��ʼΪn��
	m_channelParaGridCtrl.SetColumnCount(8); //��ʼ��Ϊ8��
	m_channelParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_channelParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_channelParaGridCtrl.SetColumnResize(TRUE);
	m_channelParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
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
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			if (col == 0){
				m_channelParaGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText.Format(_T("���"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("ͨ������"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("ͨ��״̬"), 3);
			}
			if (col == 4){
				Item.strText.Format(_T("������"), 3);
			}
			if (col == 5){
				Item.strText.Format(_T("������"), 3);
			}
			if (col == 6){
				Item.strText.Format(_T("���뷽ʽ"), 3);
			}
			if (col == 7){
				Item.strText.Format(_T("����"), 3);
			}
			m_channelParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) strText = "1";
		if (col == 2) strText = "һ��ͨ��";
		if (col == 3) strText = "����ʹ��";
		if (col == 4) strText = "������δ֪";
		if (col == 5) strText = "������δ֪";
		if (col == 6) strText = "���뷽ʽδ֪";
		if (col == 7) strText = "����δ֪";
		Item.strText.Format(_T(strText), row);
		m_channelParaGridCtrl.SetItem(&Item);

	}
}

void ChannelParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///���ѡ�еĵ�ѡ���״̬
	if (!m_channelParaGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///ȫѡ��ť
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