// StableStatusParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StableStatusParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// StableStatusParaPresetView �Ի���

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


// StableStatusParaPresetView ��Ϣ�������


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
	m_stableStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_stableStatusGridCtrl.SetRowCount(3); //��ʼΪn��
	m_stableStatusGridCtrl.SetColumnCount(4); //��ʼ��Ϊ8��
	m_stableStatusGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_stableStatusGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_stableStatusGridCtrl.SetColumnResize(TRUE);
	m_stableStatusGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
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
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			if (col == 0){
				m_stableStatusGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText.Format(_T("���"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("ת��"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("��ע"), 3);
			}
			m_stableStatusGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) strText = "1";
		if (col == 2) strText = "70hz";
		if (col == 3) strText = "����ʹ��";
		Item.strText.Format(_T(strText), row);
		m_stableStatusGridCtrl.SetItem(&Item);

	}
}

void StableStatusParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///���ѡ�еĵ�ѡ���״̬
	if (!m_stableStatusGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_stableStatusGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///ȫѡ��ť
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
