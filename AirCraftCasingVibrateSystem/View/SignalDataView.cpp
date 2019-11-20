// SignalDataView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView �Ի���

IMPLEMENT_DYNAMIC(CSignalDataView, CDialogEx)

CSignalDataView::CSignalDataView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalDataView::IDD, pParent)
{

}

CSignalDataView::~CSignalDataView()
{
}

void CSignalDataView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_SIGNALDATA_GRIDCTRL, m_signalDataGridCtrl);
	DDX_GridControl(pDX, IDC_PLAN_PARA, m_planParaGridCtrl);

	DDX_Control(pDX, IDC_DATE_COMBO, m_dateSelectComboBox);
	DDX_Control(pDX, IDC_COMBO_PRODUCT_NAME, m_productNameCombo);
	DDX_Control(pDX, IDC_COMBO_PROJECT_NAME, m_projectNameCombo);
	DDX_Control(pDX, IDC_COMBO_PLAN_NAME, m_planNameCombo);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_SIGNALDATA_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(IDOK, &CSignalDataView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CSignalDataView::OnBnClickedSearchButton)
	ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT_NAME, &CSignalDataView::OnCbnSelchangeComboProductName)
	ON_CBN_SELCHANGE(IDC_COMBO_PROJECT_NAME, &CSignalDataView::OnCbnSelchangeComboProjectName)
	ON_CBN_SELCHANGE(IDC_COMBO_PLAN_NAME, &CSignalDataView::OnCbnSelchangeComboPlanName)
	ON_CBN_SELCHANGE(IDC_DATE_COMBO, &CSignalDataView::OnCbnSelchangeDateCombo)
END_MESSAGE_MAP()


// CSignalDataView ��Ϣ�������

BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	///��ʼ���ź���ʾ���ؼ��ı�����
	m_recordSignalGridTitle.push_back("��Ʒ");
	m_recordSignalGridTitle.push_back("��Ŀ");
	m_recordSignalGridTitle.push_back("����ʱ��");
	m_recordSignalGridTitle.push_back("����������");
	m_recordSignalGridTitle.push_back("�ɼ��ƻ�");

	m_dateSelectComboBox.InsertString(0,"ȫ������");
	m_dateSelectComboBox.InsertString(1,"���һ��");
	m_dateSelectComboBox.InsertString(2,"���һ��");
	m_dateSelectComboBox.InsertString(3,"���һ��");
	m_dateSelectComboBox.InsertString(4,"�������");
	m_dateSelectComboBox.InsertString(5,"���һ��");
	m_dateSelectComboBox.SetCurSel(0);
	////��ѯ���еĲɼ��ƻ�
	Result res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	if (!res.GetIsSuccess()){ AfxMessageBox("�ɼ��ƻ���ʼ��ʧ��"); CDialogEx::OnCancel(); }
	for (int i = 0; i < m_vcollectionPlan.size(); i++){
		Document doc;
		doc.Parse(m_vcollectionPlan[i].GetDictValue());
		// 2. �����Ϣ
		CString planName = ((string)doc["planName"].GetString()).c_str();
		m_planNameCombo.InsertString(i,planName);
	}
	m_planNameCombo.SetCurSel(0);
	////����ѡ���״̬�ƻ��������������в���
	OnCbnSelchangeComboPlanName();
	/////��ѯ���еĲ�Ʒ
	res = m_productController.FindAllProduct(m_productVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("��Ʒ��ʼ��ʧ��"); CDialogEx::OnCancel(); }
	///����ѯ���Ĳ�Ʒ��ʼ����������
	for (int i = 0; i < m_productVector.size(); i++){
		m_productNameCombo.InsertString(i, m_productVector[i].GetProductName());
	}
	m_productNameCombo.SetCurSel(0);
	///���ݵ�ǰ��¼�˺Ͳ�Ʒȥ��ѯ������Ŀ
	OnCbnSelchangeComboProductName();
	///�������ϵ�ѡ��ȥ��ѯ���е������ļ�
	GridCtrlInit();
	return TRUE;
}
void CSignalDataView::GridCtrlInit(){
	m_signalDataGridCtrl.SetEditable(false);
	m_signalDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_signalDataGridCtrl.SetRowCount(m_signalVector.size()+1); //��ʼΪn��
	m_signalDataGridCtrl.SetColumnCount(m_recordSignalGridTitle.size() + m_planParaTitle.size()); //��ʼ��Ϊ5��
	m_signalDataGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_signalDataGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_signalDataGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_signalDataGridCtrl.ExpandColumnsToFit(true);
	m_signalDataGridCtrl.SetSingleRowSelection(true);

	///�������ñ�������
	for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++){
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = 0;
		Item.col = col;
		Item.nFormat = DT_CENTER | DT_WORDBREAK;
		if (col < m_recordSignalGridTitle.size()){
			Item.strText = m_recordSignalGridTitle[col];
		}
		else{
			Item.strText = m_planParaTitle[col - m_recordSignalGridTitle.size()];
		}
		m_signalDataGridCtrl.SetItem(&Item);
	}
	///���ñ������
	for (int row = 1; row < m_signalDataGridCtrl.GetRowCount(); row++){
		////1.�����ɼ�״̬
		Document doc;
		doc.Parse(m_signalVector[row - 1].GetCollectionStatus());

		if (doc.HasParseError()){ continue; }

		CString collectionPlan = ((string)doc["collectionPlan"].GetString()).c_str();
		const Value& collectionPlanPara = doc["collectionPlanPara"];
		////2.����ͨ����Ϣ
		int	channelCount = 0;
		doc.Parse(m_signalVector[row - 1].GetSensorInfo());
		if (doc.HasParseError()){ continue; }
		channelCount = doc["channelCount"].GetInt();
		for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
		{
			//���ñ����ʾ����
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			CString strText;
			if (col == 0) strText = m_signalVector[row - 1].GetProduct().GetProductName();
			if (col == 1) strText = m_signalVector[row - 1].GetProject().GetProjectName();
			if (col == 2) strText = m_signalVector[row - 1].GetStartTime() + "-" + m_signalVector[row - 1].GetEndTime();
			if (col == 3) strText = CommonUtil::Int2CString(channelCount);
			if (col == 4) strText = collectionPlan;
			if (col >= m_recordSignalGridTitle.size())
				strText = collectionPlanPara[col - m_recordSignalGridTitle.size()].GetString();

			Item.strText = strText;
			m_signalDataGridCtrl.SetItem(&Item);
		}
	}
	
}

/**/
void CSignalDataView::GridCtrlPlanParaInit(const Value& planParaTitle)
{
	m_planParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_planParaGridCtrl.SetRowCount(planParaTitle.Size()+1); //��ʼΪn��
	m_planParaGridCtrl.SetColumnCount(2); //��ʼ��Ϊ2��
	m_planParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_planParaGridCtrl.SetFixedColumnCount(1);///���ù̶��еĸ���Ϊ1
	m_planParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_planParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_planParaGridCtrl.ExpandColumnsToFit(true);
	m_planParaGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_planParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_planParaGridCtrl.GetColumnCount(); col++)
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
				Item.strText.Format(_T("������"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("ֵ"), 0);
			}
			m_planParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = planParaTitle[row-1].GetString();
		Item.strText = strText;
		m_planParaGridCtrl.SetItem(&Item);
	}

}
///��Ŀ��˫���¼�--��������
void CSignalDataView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbRecordSignal g_signal = m_signalVector.at(pItem->iRow - 1);
	if (MessageBox("�Ƿ������ " + g_signal.GetSignalId(), "������", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////��ѡ�����Ŀ����ȫ��project����
	///�رմ���
	CDialogEx::OnOK();
}
void CSignalDataView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbRecordSignal g_signal = m_signalVector.at(pItem->iRow - 1);
	m_selectedSignal = g_signal;
}

////���ȷ����ť
void CSignalDataView::OnBnClickedOk()
{
	

	if (MessageBox("�Ƿ������ " + m_selectedSignal.GetSignalId(), "������", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	CDialogEx::OnOK();
}


void CSignalDataView::OnBnClickedSearchButton()
{
	////������ݼ���
	m_signalVector.clear();
	m_searchSignalEntity.SetTesingDevice(theApp.m_currentProject.GetTestingDevice());
	m_searchSignalEntity.SetCollectionStatus(GetCollectionParaKeyWords());
	Result	res = m_signalController.FindAllRecordSignalBySearchCondition(m_searchSignalEntity, m_signalVector);
	if (!res.GetIsSuccess()){
		AfxMessageBox("�����ļ�����ʧ��");
		return;
	}
	GridCtrlInit();
}


void CSignalDataView::OnCbnSelchangeComboProductName()
{
	int selectedProductIndex = m_productNameCombo.GetCurSel();
	m_projectNameCombo.ResetContent();
	TbProject searchProject;
	searchProject.SetProduct(m_productVector[selectedProductIndex]);
	searchProject.SetTester(theApp.m_currentProject.GetTester());
	////�����Ŀ����
	m_projectVector.clear();
	Result res = m_projectController.FindAllProjectBySearchCondition(searchProject, "", "", m_projectVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("��Ŀ��ʼ��ʧ��"); CDialogEx::OnCancel(); }
	if (m_projectVector.size() == 0){ return; }///��ѯ������Ŀ����Ϊ��
	for (int i = 0; i < m_projectVector.size(); i++){
		m_projectNameCombo.InsertString(i, m_projectVector[i].GetProjectName());
	}
	m_projectNameCombo.SetCurSel(0);
	m_searchSignalEntity.SetProject(m_projectVector[0]);
	m_searchSignalEntity.SetProduct(m_productVector[selectedProductIndex]);
	OnBnClickedSearchButton();
}


void CSignalDataView::OnCbnSelchangeComboProjectName()
{
	int selectedProjectIndex = m_projectNameCombo.GetCurSel();
	if (selectedProjectIndex < 0) return;
	m_searchSignalEntity.SetProject(m_projectVector[selectedProjectIndex]);
	OnBnClickedSearchButton();
}

////�ı�ɼ��ƻ����������ֵ����Ӧ�ı�ɼ��ƻ������б����ʾ
void CSignalDataView::OnCbnSelchangeComboPlanName()
{
	int collectionPlanIndex = m_planNameCombo.GetCurSel();
	Document doc;
	doc.Parse(m_vcollectionPlan[collectionPlanIndex].GetDictValue());
	const Value& planParaTitle = doc["planParaTitle"];
	for (int i = 0; i < planParaTitle.Size();i++){
		m_planParaTitle.push_back(planParaTitle[i].GetString());
	}

	GridCtrlPlanParaInit(planParaTitle);
	OnBnClickedSearchButton();
}


void CSignalDataView::OnCbnSelchangeDateCombo()
{
	int testingIndex = m_dateSelectComboBox.GetCurSel();
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	if (testingIndex == 1){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(1)); }
	if (testingIndex == 2){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(7)); }
	if (testingIndex == 3){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(30)); }
	if (testingIndex == 4){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(182)); }
	if (testingIndex == 5){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(365)); }
	OnBnClickedSearchButton();
}
CString CSignalDataView::GetCollectionParaKeyWords(){
	int collectionPlanIndex = m_planNameCombo.GetCurSel();
	CString keyWords;
	m_planNameCombo.GetLBText(collectionPlanIndex, keyWords);
	for (int row = 1; row < m_planParaGridCtrl.GetRowCount();row++){
		for (int col = 0; col < m_planParaGridCtrl.GetColumnCount();col++){
			if (m_planParaGridCtrl.GetItemText(row, col) != ""){
				keyWords += "," + m_planParaGridCtrl.GetItemText(row, col);
			}
		}
	}
	return keyWords;
}

TbRecordSignal CSignalDataView::GetSelectedRecordSignal(){
	return m_selectedSignal;
}