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
	DDX_GridControl(pDX, IDC_GRIDCTRL_STABLESTATUSPARA, m_stableStatusGridCtrl);
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
	////��ȡ�ɼ��ƻ��Ĳ�����Ϣ
	CString csPara  = m_collectionPlan.GetDictValue();
	// 1.����doc
	Document doc;
	doc.Parse(m_collectionPlan.GetDictValue());

	const Value& planParaTitle = doc["planParaTitle"];
	const Value& planParaContent = doc["planParaContent"];

	// 2. �����Ϣ
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(true);
	m_stableStatusGridCtrl.SetEditable(false);
	m_stableStatusGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_stableStatusGridCtrl.SetRowCount(planParaContent.Size()+1); //��ʼΪn��
	m_stableStatusGridCtrl.SetColumnCount(planParaTitle.Size()+1); //��ʼ��Ϊ3��
	m_stableStatusGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_stableStatusGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_stableStatusGridCtrl.SetColumnResize(TRUE);
	m_stableStatusGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_stableStatusGridCtrl.ExpandColumnsToFit(true);

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
"planName": "ƽ��״̬",
"planIntro": "ƽ��״̬�µĲɼ�",
"planParaTitle": ["ת��", "��ע"],
"planParaContent": [
["126hz", "����ʹ��"],
["126hz", "����ʹ��"]
]
}
*/

void  CollectionPlanParaPresetView::GetCollectionPlan(TbCollectionPlan &collectionPlan){

	collectionPlan.SetPlanId( m_collectionPlan.GetDictId());
	///����ԭ�ƻ�ģ��
	Document planDoc;
	planDoc.Parse(m_collectionPlan.GetDictValue());
	Value& planParaContent = planDoc["planParaContent"];
	/// ���
	planParaContent.GetArray().Clear();

	for (int row = 1; row < m_stableStatusGridCtrl.GetRowCount(); row++){
		if (!m_stableStatusGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, 0);
		if (pCell->GetCheck()){
			Value lineData(kArrayType);
			for (int col = 1; col < m_stableStatusGridCtrl.GetColumnCount();col++){
				///���ÿһ��ÿһ�еĲ���
				Value  para(kStringType);
				//////����
				string  temp;
				temp = m_stableStatusGridCtrl.GetItemText(row, col).GetString();
				para.SetString(temp.c_str(), temp.size(), planDoc.GetAllocator());
				lineData.PushBack(para,planDoc.GetAllocator());
			}
			planParaContent.GetArray().PushBack(lineData, planDoc.GetAllocator());
		}
	}

	//Document document;
	////��÷�����
	//Document::AllocatorType& allocator = document.GetAllocator();
	/////�������ڵ�
	//Value root(kObjectType);
	/////����rotatingSpeed�ڵ�
	//Value rotatingSpeed(kArrayType);
	////rotatingSpeed.SetString("rotatingSpeed");
	//for (int row = 1; row < m_stableStatusGridCtrl.GetRowCount();row++){
	//	if (!m_stableStatusGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
	//		m_stableStatusGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
	//	CGridCellCheck* pCell = (CGridCellCheck*)m_stableStatusGridCtrl.GetCell(row, 0);
	//	if (pCell->GetCheck()){

	//		Value  rotatingSpeedEntity(kObjectType);

	//		////���ѡ�еģ������¼������ƴ��json����
	//		Value  speed(kStringType);
	//		Value  remarks(kStringType);
	//		string  temp;
	//		///���ת��
	//		temp= m_stableStatusGridCtrl.GetItemText(row, 1).GetString();
	//		speed.SetString(temp.c_str(), temp.size(), allocator);
	//		///��ñ�ע
	//		temp = m_stableStatusGridCtrl.GetItemText(row, 2).GetString();
	//		remarks.SetString(temp.c_str(), temp.size(), allocator);
	//		///��ת�ٺͱ�ע��ӵ�ת��ʵ����
	//		rotatingSpeedEntity.AddMember("speed", speed, allocator);
	//		rotatingSpeedEntity.AddMember("remarks", remarks, allocator);
	//		///��ת��ʵ����ӵ�������
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