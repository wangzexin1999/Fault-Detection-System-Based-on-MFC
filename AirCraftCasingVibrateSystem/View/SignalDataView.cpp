// SignalDataView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView �Ի���

IMPLEMENT_DYNAMIC(CSignalDataView, CDialogEx)

CSignalDataView::CSignalDataView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalDataView::IDD, pParent){

}

CSignalDataView::~CSignalDataView()
{
}

void CSignalDataView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_SIGNALDATA_GRIDCTRL, m_signalDataGridCtrl);

	DDX_Control(pDX, IDC_DATE_COMBO, m_dateSelectComboBox);
	DDX_Control(pDX, IDC_COMBO_PRODUCT_NAME, m_productNameCombo);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_SIGNALDATA_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(IDOK, &CSignalDataView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CSignalDataView::OnBnClickedSearchButton)
	ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT_NAME, &CSignalDataView::OnCbnSelchangeComboProductName)
	ON_CBN_SELCHANGE(IDC_DATE_COMBO, &CSignalDataView::OnCbnSelchangeDateCombo)

END_MESSAGE_MAP()


// CSignalDataView ��Ϣ�������

BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	///��ʼ���ź���ʾ���ؼ��ı�����
	m_recordSignalGridTitle.push_back("���");
	m_recordSignalGridTitle.push_back("��Ʒ");
	//m_recordSignalGridTitle.push_back("ͨ������");
	m_recordSignalGridTitle.push_back("��ʼʱ��");
	m_recordSignalGridTitle.push_back("����ʱ��");

	m_dateSelectComboBox.InsertString(0,"ȫ������");
	m_dateSelectComboBox.InsertString(1,"���һ��");
	m_dateSelectComboBox.InsertString(2,"���һ��");
	m_dateSelectComboBox.InsertString(3,"���һ��");
	m_dateSelectComboBox.InsertString(4,"�������");
	m_dateSelectComboBox.InsertString(5,"���һ��");
	m_dateSelectComboBox.SetCurSel(0);

	/////��ѯ���еĲ�Ʒ
	Result res = m_productController.FindAllProduct(m_productVector);
	if (!res.GetIsSuccess()){ AfxMessageBox("��Ʒ��ʼ��ʧ��"); CDialogEx::OnCancel(); }
	///����ѯ���Ĳ�Ʒ��ʼ����������
	m_productNameCombo.InsertString(0, "���в�Ʒ");
	for (int i = 0; i < m_productVector.size(); i++){
		m_productNameCombo.InsertString(i + 1, m_productVector[i].GetProductName());
	}
	m_productNameCombo.SetCurSel(0);
	///���ݵ�ǰ��¼�˺Ͳ�Ʒȥ��ѯ������Ŀ
	OnCbnSelchangeComboProductName();
	///�������ϵ�ѡ��ȥ��ѯ���е������ļ�
	OnBnClickedSearchButton();
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
	for (int row = 1; row <m_signalDataGridCtrl.GetRowCount(); row++){
		for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
		{
			//���ñ����ʾ����
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			CString strText;
			if (col == 0) strText = CommonUtil::Int2CString(row);
			if (col == 1) strText = m_signalVector[row - 1].GetProduct().GetProductName();
			//if (col == 2) strText = CommonUtil::Int2CString(m_signalVector[row - 1].GetAllSignal().size());
			if (col == 2) strText = m_signalVector[row - 1].GetStartTime() ;
			if (col == 3) strText = m_signalVector[row - 1].GetEndTime();
			Item.strText = strText;
			m_signalDataGridCtrl.SetItem(&Item);
		}
	}
	
}

///��Ŀ��˫���¼�--��������
void CSignalDataView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSumsignal g_signal = m_signalVector.at(pItem->iRow - 1);
	if (MessageBox("�Ƿ������ " + g_signal.GetSumsignalId(), "������", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////��ѡ�����Ŀ����ȫ��project����
	///�رմ���
	CDialogEx::OnOK();
}
void CSignalDataView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSumsignal g_signal = m_signalVector.at(pItem->iRow - 1);
	m_selectedSignal = g_signal;
}

////���ȷ����ť
void CSignalDataView::OnBnClickedOk()
 {

	if (m_selectedSignal.GetSumsignalId() == ""){AfxMessageBox("��ѡ������");return;}

	if (MessageBox("�Ƿ������", "ȷ�ϴ����ݣ�", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;

	CDialogEx::OnOK();
}


void CSignalDataView::OnBnClickedSearchButton()
{
	////������ݼ���
	m_signalVector.clear();
	
	Result	res = m_signalController.FindAllSumSignalBySearchCondition(m_searchSignalEntity, m_signalVector);
	if (!res.GetIsSuccess()){
		AfxMessageBox("�����ļ�����ʧ��");
		return;
	}
	GridCtrlInit();
}


void CSignalDataView::OnCbnSelchangeComboProductName()
{
	int selectedProductIndex = m_productNameCombo.GetCurSel();
	int productId = 0;
	if (selectedProductIndex != 0){
		productId = m_productVector[selectedProductIndex - 1].GetProductId();
	}
	m_searchSignalEntity.SetProductId(productId);
	OnBnClickedSearchButton();
}

void CSignalDataView::OnCbnSelchangeDateCombo()
{
	int testingIndex = m_dateSelectComboBox.GetCurSel();
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	if (testingIndex == 0){ m_searchSignalEntity.SetStartTime(""); }
	if (testingIndex == 1){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(1)); }
	if (testingIndex == 2){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(7)); }
	if (testingIndex == 3){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(30)); }
	if (testingIndex == 4){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(182)); }
	if (testingIndex == 5){ m_searchSignalEntity.SetStartTime(DateUtil::GetSeveralDaysAgoCStringDate(365)); }
	m_searchSignalEntity.SetEndTime(DateUtil::GetCurrentCStringTime());
	OnBnClickedSearchButton();
}

TbSumsignal CSignalDataView::GetSelectedSumSignal(){
	return m_selectedSignal;
}