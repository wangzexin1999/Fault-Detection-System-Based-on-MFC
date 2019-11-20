// CollectionPlanManageView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionPlanManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CollectionPlanManageView �Ի���

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

// CollectionPlanManageView ��Ϣ�������
void CollectionPlanManageView::CollectionPlanBaseInfoGridCtrlInit(){
	///1.����ɾ�����е���
	m_collectionPlanBaseInfoGridCtrl.DeleteAllItems();
	m_collectionPlanBaseInfoGridCtrl.Refresh();

	m_collectionPlanBaseInfoGridCtrl.SetEditable(false);
	m_collectionPlanBaseInfoGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_collectionPlanBaseInfoGridCtrl.SetRowCount(m_vcollectionPlan.size() + 1); //��ʼΪn��
	m_collectionPlanBaseInfoGridCtrl.SetColumnCount(3); //��ʼ��Ϊ3��
	m_collectionPlanBaseInfoGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_collectionPlanBaseInfoGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_collectionPlanBaseInfoGridCtrl.SetColumnResize(TRUE);
	m_collectionPlanBaseInfoGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_collectionPlanBaseInfoGridCtrl.ExpandColumnsToFit(true);

	m_collectionPlanBaseInfoGridCtrl.SetSingleRowSelection(true);
	//m_collectionPlanBaseInfoGridCtrl.OnGridClick();
	for (int row = 0; row < m_collectionPlanBaseInfoGridCtrl.GetRowCount(); row++){
		CString planName;
		CString planIntro;
		if (row > 0){
			// 1.����doc
			Document doc;
			doc.Parse(m_vcollectionPlan[row - 1].GetDictValue());
			// 2. �����Ϣ
			planName = ((string)doc["planName"].GetString()).c_str();
			planIntro = ((string)doc["planIntro"].GetString()).c_str();
		}
		for (int col = 0; col < m_collectionPlanBaseInfoGridCtrl.GetColumnCount(); col++)
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
					Item.strText = "���";
				}
				if (col == 1){
					Item.strText = "�ƻ�����";
				}
				if (col == 2){
					Item.strText = "����";
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
	///Ĭ�����õ�һ������Ϊѡ�еĲɼ�״̬
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(1, 0, 1, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(1, 0);
	m_selectedPlanIndex = 0;
	CollectionPlanParaInfoGridCtrlInit();
	return TRUE;
}
void CollectionPlanManageView::CollectionPlanParaInfoGridCtrlInit(){
	///1.����ɾ�����е���
	m_collectionPlanParaInfoGridCtrl.DeleteAllItems();
	m_collectionPlanParaInfoGridCtrl.Refresh();
	if (m_selectedPlanIndex < 0 || m_selectedPlanIndex >= m_vcollectionPlan.size()){ return; }
	///2.�����ɼ��ƻ�����
	Document doc;
	doc.Parse(m_vcollectionPlan[m_selectedPlanIndex].GetDictValue());
	///3.1����ɼ��ƻ���������û�вɼ��ƻ������ı�����߲ɼ����������ݣ�����ʾ֮�������
	if (doc.HasParseError()) return;
	Value planParaTitle(kArrayType);
	Value planParaContent(kArrayType);

	if (doc.HasMember("planParaTitle")){ planParaTitle = doc["planParaTitle"].GetArray(); }
	if (doc.HasMember("planParaContent")){ planParaContent = doc["planParaContent"].GetArray(); }
	
	///3.���ñ�������
	m_collectionPlanParaInfoGridCtrl.SetEditable(false);
	m_collectionPlanParaInfoGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_collectionPlanParaInfoGridCtrl.SetRowCount(planParaContent.Size() + 1); //��ʼΪn��
	m_collectionPlanParaInfoGridCtrl.SetColumnCount(planParaTitle.Size()); //��ʼ��Ϊn��
	m_collectionPlanParaInfoGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_collectionPlanParaInfoGridCtrl.SetColumnResize(TRUE);
	m_collectionPlanParaInfoGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_collectionPlanParaInfoGridCtrl.ExpandColumnsToFit(true);
	m_collectionPlanParaInfoGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_collectionPlanParaInfoGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_collectionPlanParaInfoGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
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
	///��ȡ��ǰѡ�еĲɼ�״̬
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
	///1.����ȷ���Ƿ�Ҫɾ��
	if (MessageBox("�Ƿ�ɾ���òɼ��ƻ�", "ɾ���ɼ��ƻ�", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	///2.ɾ���ɼ�����
	Result res = m_collectionPlanController.DeleteById(m_vcollectionPlan[m_selectedPlanIndex]);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); return; }
	///3.ɾ�����ѯ���еĲɼ��ƻ�
	m_vcollectionPlan.clear();
	res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///Ĭ���������һ�μ�¼�Ĳɼ��ƻ�������
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(m_selectedPlanIndex, 0, m_selectedPlanIndex, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(m_selectedPlanIndex, 0);
	///��ʼ���ɼ��豸�����ı��
	CollectionPlanParaInfoGridCtrlInit();
}
void CollectionPlanManageView::OnBnClickedButtonSavePlanBaseInfo()
{
	///1.ѭ�������ɼ�������Ϣ���б����浱ǰ���޸�
	//1.1���document������
	Document document;
	Document::AllocatorType& allocator = document.GetAllocator();
	for (int row = 1; row < m_collectionPlanBaseInfoGridCtrl.GetRowCount(); row++){
		TbDictionary collectPlan;
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		string jsonResult;
		///1.1 ���������¼����Ҫ�޸ĵġ�
		if (row < m_vcollectionPlan.size() + 1){
			collectPlan = m_vcollectionPlan[row - 1];
			///1.2 ����ԭ�ȵ�json���ݣ�Ŀ���ǲ����ԭ�ȵĲ�����Ϣ��
			document.Parse(collectPlan.GetDictValue());
			///1.3 �������json����������ִ��
			if (document.HasParseError()){ continue; }
			///1.4 �޸Ĳɼ��ƻ��Ļ�����Ϣ
			document["planName"].SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 1).GetBuffer(0), allocator);
			document["planIntro"].SetString(m_collectionPlanBaseInfoGridCtrl.GetItemText(row, 2).GetBuffer(0), allocator);
			///1.5 ���޸�֮���doc��ת��json��
			document.Accept(writer);
			jsonResult = buffer.GetString();
			collectPlan.SetDictValue(jsonResult.c_str());
			m_collectionPlanController.Update(collectPlan);
		}
		else{
			///1.2 ���������¼����Ҫ����ġ�
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
	///2.���²�ѯ���еĲɼ����󣬲�ˢ���б�
	m_vcollectionPlan.clear();
	Result res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///3.�����ϴ�ѡ�е���Ϊѡ��״̬
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

/////ɾ��������bug��ɾ��û��Ӧ
void CollectionPlanManageView::OnBnClickedButtonDelPlanParaRow()
{
	m_collectionPlanParaInfoGridCtrl.DeleteRow(m_selectedPlanParaIndex);
	m_collectionPlanParaInfoGridCtrl.Refresh();
}

void CollectionPlanManageView::OnBnClickedButtonAddPlanParaCol()
{
	m_collectionPlanParaInfoGridCtrl.InsertColumn("δ֪����", DT_CENTER | DT_WORDBREAK);
	m_collectionPlanParaInfoGridCtrl.ExpandColumnsToFit(true);
	/// ����ÿһ�еĿ��Ϊ
	long width = m_collectionPlanParaInfoGridCtrl.GetVirtualWidth();
	int colWidth = width / m_collectionPlanParaInfoGridCtrl.GetColumnCount();
	for (int col = 0; col < m_collectionPlanParaInfoGridCtrl.GetColumnCount(); col++){
		m_collectionPlanParaInfoGridCtrl.SetColumnWidth(col, colWidth);
	}
	m_collectionPlanParaInfoGridCtrl.Refresh();
}

void CollectionPlanManageView::OnBnClickedButtonSavePlanPara()
{
	///1.��ȡ��ǰѡ�еĲɼ��ƻ�������Ϣ
	TbDictionary selectedCollectionPlan =  m_vcollectionPlan[m_selectedPlanIndex];
	///2.�޸Ĳɼ��ƻ�����
	Document document;
	Document::AllocatorType& allocator = document.GetAllocator();
	///3.�����ɼ��ƻ�����
	document.Parse(selectedCollectionPlan.GetDictValue());
	///4.ɾ���ɼ��ƻ��ļƻ�����ͼƻ�����
	if (document.HasMember("planParaTitle")){ document.RemoveMember("planParaTitle"); }
	if (document.HasMember("planParaContent")){ document.RemoveMember("planParaContent"); }
	///5.�����ɼ���������ݵ�json����
	Value planParaTitle(kArrayType);
	Value planParaContent(kArrayType);
	///6.��װjson
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
	///7.��json������ӵ��ɼ��ƻ�
	document.AddMember("planParaTitle", planParaTitle,allocator);
	document.AddMember("planParaContent", planParaContent,allocator);
	///8.��json�������ַ���
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	string result;
	document.Accept(writer);
	result = buffer.GetString();
	selectedCollectionPlan.SetDictValue(result.c_str());
	m_collectionPlanController.Update(selectedCollectionPlan);
	///9.ˢ�²ɼ�������Ϣ�Ľ���
	///9.1.���²�ѯ���еĲɼ����󣬲�ˢ���б�
	m_vcollectionPlan.clear();
	Result res = m_collectionPlanController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		return;
	}
	CollectionPlanBaseInfoGridCtrlInit();
	///9.2 �����ϴ�ѡ�е���Ϊѡ��״̬
	m_collectionPlanBaseInfoGridCtrl.SetSelectedRange(m_selectedPlanIndex+1, 0, m_selectedPlanIndex+1, m_collectionPlanBaseInfoGridCtrl.GetColumnCount() - 1);
	m_collectionPlanBaseInfoGridCtrl.EnsureVisible(m_selectedPlanIndex+1, 0);
	CollectionPlanParaInfoGridCtrlInit();
}
