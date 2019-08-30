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

	DDX_Control(pDX, IDC_DATE_COMBO, m_dateSelectComboBox);
	DDX_Control(pDX, IDC_PROJECTNAME_EDIT, m_projectNameEdit);
	DDX_Control(pDX, IDC_PRODUCTNAME_EDIT, m_productNameEdit);
	DDX_Control(pDX, IDC_ROTATINGSPEED_EDIT, m_rotatingSpeedEdit);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_SIGNALDATA_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(IDOK, &CSignalDataView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CSignalDataView::OnBnClickedSearchButton)
END_MESSAGE_MAP()


// CSignalDataView ��Ϣ�������

BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_dateSelectComboBox.InsertString(0,"ȫ������");
	m_dateSelectComboBox.InsertString(1,"���һ��");
	m_dateSelectComboBox.InsertString(2,"���һ��");
	m_dateSelectComboBox.InsertString(3,"���һ��");
	m_dateSelectComboBox.InsertString(4,"�������");
	m_dateSelectComboBox.InsertString(5,"���һ��");
	m_dateSelectComboBox.SetCurSel(0);
	m_projectNameEdit.SetWindowTextA(theApp.m_currentProject.GetProjectName());

	////////��ѯ�����ļ��������
	GridCtrlInit();
	/*Result res = m_signalController.LoadAllRecordedSignalBySearchCondition(theApp.m_currentProject.GetProjectName(), "", "", "", m_signalVector);
	if (res.GetIsSuccess()){
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
		return FALSE;
	}*/
	return TRUE;
}
void CSignalDataView::GridCtrlInit(){
	
	m_signalDataGridCtrl.SetEditable(false);
	m_signalDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_signalDataGridCtrl.SetRowCount(m_signalVector.size()+1); //��ʼΪn��
	m_signalDataGridCtrl.SetColumnCount(6); //��ʼ��Ϊ5��
	m_signalDataGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_signalDataGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_signalDataGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_signalDataGridCtrl.ExpandColumnsToFit(true);
	m_signalDataGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_signalDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
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
				Item.strText.Format(_T("��Ʒ����"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("��Ŀ����"), 0);
			}
			if (col == 2){
				Item.strText.Format(_T("ת��"), 1);
			}
			if (col == 3){
				Item.strText.Format(_T("�ɼ���ʼʱ��"), 2);
			}
			if (col == 4){
				Item.strText.Format(_T("�ɼ���ʼʱ��"), 3);
			}
			if (col == 5){
				Item.strText.Format(_T("����������"), 4);
			}
			m_signalDataGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = theApp.m_currentProject.GetProjectName();
		if (col == 1) strText = CommonUtil::GetFileNameFromFilePath(m_signalVector[row - 1].GetDataUrl());
		if (col == 2) strText = m_signalVector[row - 1].GetStartTime();
		if (col == 3) strText = m_signalVector[row - 1].GetEndTime();
		if (col == 4) strText = m_signalVector[row - 1].GetSignalType();
		if (col == 5) strText = m_signalVector[row - 1].GetProduct().GetProductName();
		Item.strText.Format(_T(strText), row);
		m_signalDataGridCtrl.SetItem(&Item);
	}
}

///��Ŀ��˫���¼�--��������Ŀ
void CSignalDataView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSignal g_signal = m_signalVector.at(pItem->iRow - 1);
	if (MessageBox("�Ƿ������ " + g_signal.GetSignalId(), "������", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////��ѡ�����Ŀ����ȫ��project����
	///�رմ���
	CDialogEx::OnOK();
}
void CSignalDataView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_signalVector.size()) return;
	TbSignal g_signal = m_signalVector.at(pItem->iRow - 1);
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
	CString strSearchProjectName; 
	CString strSearchProductName;
	CString strSearchRoatatingSpeed;

	

	m_projectNameEdit.GetWindowTextA(strSearchProjectName);
	m_productNameEdit.GetWindowTextA(strSearchProductName);
	m_rotatingSpeedEdit.GetWindowTextA(strSearchRoatatingSpeed);

	int testingIndex = m_dateSelectComboBox.GetCurSel();
	CString strStartTime  ;
	CString strEndTime = DateUtil::GetCurrentCStringTime();

	if (testingIndex == 1){ strStartTime = DateUtil::GetSeveralDaysAgoCStringDate(1); }
	if (testingIndex == 2){ strStartTime = DateUtil::GetSeveralDaysAgoCStringDate(7); }
	if (testingIndex == 3){ strStartTime = DateUtil::GetSeveralDaysAgoCStringDate(30); }
	if (testingIndex == 4){ strStartTime = DateUtil::GetSeveralDaysAgoCStringDate(182); }
	if (testingIndex == 5){ strStartTime = DateUtil::GetSeveralDaysAgoCStringDate(365); }
	
	////������ݼ���
	m_signalVector.clear();
	int projectId = theApp.m_currentProject.GetProjectId();
	Result res = m_signalController.FindAllRecordedSignalBySearchCondition(strSearchProjectName, strSearchProductName,strSearchRoatatingSpeed,
						strStartTime, strEndTime, m_signalVector);
	if (res.GetIsSuccess()){
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
	}



}
