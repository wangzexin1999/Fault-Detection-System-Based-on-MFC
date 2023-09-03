// CollectionPlanParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionPlanParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CollectionPlanParaPresetView �Ի���

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


// CollectionPlanParaPresetView ��Ϣ�������


BOOL CollectionPlanParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE;  
}
void CollectionPlanParaPresetView::GridCtrlInit()
{
	// 1.����doc
	Document doc;
	doc.Parse(m_collectionPlan.GetDictValue());
	if (!doc.HasMember("planParaTitle") || !doc.HasMember("planParaContent")) return;
	const Value& planParaTitle = doc["planParaTitle"];
	const Value& planParaContent = doc["planParaContent"];
	///���json����û�в�����Ϣ������ʾ
	if (planParaTitle.IsNull() || planParaContent.IsNull()){ return; }
	// 2. �����Ϣ
	m_collectionStatusGridCtrl.SetEditable(true);
	m_collectionStatusGridCtrl.SetEditable(true);
	m_collectionStatusGridCtrl.SetEditable(false);
	m_collectionStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_collectionStatusGridCtrl.SetRowCount(planParaContent.Size()+1); //��ʼΪn��
	m_collectionStatusGridCtrl.SetColumnCount(planParaTitle.Size()+1); //��ʼ��Ϊ3��
	m_collectionStatusGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_collectionStatusGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_collectionStatusGridCtrl.SetColumnResize(TRUE);
	m_collectionStatusGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_collectionStatusGridCtrl.ExpandColumnsToFit(true);

	m_collectionStatusGridCtrl.SetSingleRowSelection(true);
	//m_collectionStatusGridCtrl.OnGridClick();
	for (int row = 0; row < m_collectionStatusGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_collectionStatusGridCtrl.GetColumnCount(); col++)
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
	///���ѡ�еĵ�ѡ���״̬
	if (!m_collectionStatusGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_collectionStatusGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_collectionStatusGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);
	if (pItem->iRow == 0){
		///ȫѡ��ť
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
	///1.����һ��
	m_collectionStatusGridCtrl.InsertRow("");
	///2.�����²����еĵ�һ��Ϊ��ѡ��
	m_collectionStatusGridCtrl.SetCellType(m_collectionStatusGridCtrl.GetRowCount()-1, 0, RUNTIME_CLASS(CGridCellCheck));
	m_collectionStatusGridCtrl.Refresh();
}
