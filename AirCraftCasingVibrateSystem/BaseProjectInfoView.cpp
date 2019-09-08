// BaseProjectInfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "BaseProjectInfoView.h"
#include "afxdialogex.h"


// BaseProjectInfoView �Ի���

IMPLEMENT_DYNAMIC(BaseProjectInfoView, CDialogEx)

BaseProjectInfoView::BaseProjectInfoView(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseProjectInfoView::IDD, pParent)
{

}

BaseProjectInfoView::~BaseProjectInfoView()
{
}

void BaseProjectInfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_PROJECTPLAN_GRID, m_projectPlanGridCtrl);
}


BEGIN_MESSAGE_MAP(BaseProjectInfoView, CDialogEx)

	ON_NOTIFY(NM_CLICK, IDC_PROJECTPLAN_GRID, OnGridClick)

END_MESSAGE_MAP()


// BaseProjectInfoView ��Ϣ�������
void BaseProjectInfoView::GridCtrlInit()
{
	m_projectPlanGridCtrl.SetEditable(true);
	m_projectPlanGridCtrl.SetEditable(false);
	m_projectPlanGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_projectPlanGridCtrl.SetRowCount(3); //��ʼΪn��
	m_projectPlanGridCtrl.SetColumnCount(4); //��ʼ��Ϊ5��
	m_projectPlanGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_projectPlanGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	//m_projectPlanGridCtrl.SetColumnResize(TRUE);
	m_projectPlanGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	//m_projectPlanGridCtrl.ExpandColumnsToFit(true);
	m_projectPlanGridCtrl.SetColumnWidth(0, 50);
	m_projectPlanGridCtrl.SetColumnWidth(1, 90);
	m_projectPlanGridCtrl.SetColumnWidth(2, 380);
	m_projectPlanGridCtrl.SetColumnWidth(3, 447);

	m_projectPlanGridCtrl.SetSingleRowSelection(true);
	//m_projectPlanGridCtrl.OnGridClick();
	for (int row = 0; row < m_projectPlanGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_projectPlanGridCtrl.GetColumnCount(); col++)
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
				m_projectPlanGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText.Format(_T("���"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("�ƻ�����"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("����"), 3);
			}
			m_projectPlanGridCtrl.SetItem(&Item);
			continue;
		}
		
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_projectPlanGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) strText = "1��";
		if (col == 2) strText = "����";
		if (col == 3) strText = "�����������ɼ��ƻ�";
		Item.strText.Format(_T(strText), row);
		m_projectPlanGridCtrl.SetItem(&Item);

	}

	/*CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(0, 0);
	pCell->SetCheck(TRUE);*/
}

BOOL BaseProjectInfoView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	


	GridCtrlInit();
	return TRUE;  
}

void BaseProjectInfoView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///���ѡ�еĵ�ѡ���״̬
	if (!m_projectPlanGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///ȫѡ��ť
		for (int row = 1; row < m_projectPlanGridCtrl.GetRowCount();row++){
			SetGridCellCheck(row,0,!isChecked);
		}
	}
}
void BaseProjectInfoView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_projectPlanGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked); 
}