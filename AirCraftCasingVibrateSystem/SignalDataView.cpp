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
	DDX_Control(pDX, IDC_SIGNALDATANAME_EDIT, m_singnalDataNameCtrl);
	DDX_Control(pDX, IDC_SIGNALDATASTARTTIME, m_signalDataStartTimeCtrl);
	DDX_Control(pDX, IDC_SIGNALDATAENDTIME, m_signalDataEndTimeCtrl);
	DDX_Control(pDX, IDC_DATESELECT_CHECK, m_dateSelectCheckBox);
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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	////��ʼ�����ڿؼ�
	m_signalDataStartTimeCtrl.SetFormat(_T("yyyy'- 'MM'- 'dd"));
	m_signalDataEndTimeCtrl.SetFormat(_T("yyyy'- 'MM'- 'dd"));
	///��ʼ����ʼ���ڿؼ�ʱ��Ϊһ��֮ǰ
	CTime aWeekAgo = DateUtil::GetAWeekAgoDate();
	m_signalDataStartTimeCtrl.SetTime(&aWeekAgo);

	////////��ѯ�����ļ��������
	int projectId = theApp.m_currentProject.GetProjectId();
	Result res = m_signalController.LoadAllRecordedSignalBySearchCondition(projectId, "", "", "", m_signalVector);
	if (res.GetIsSuccess()){
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
		return FALSE;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
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
				Item.strText.Format(_T("��Ŀ����"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("�ź�����"), 0);
			}
			if (col == 2){
				Item.strText.Format(_T("�ɼ���ʼʱ��"), 1);
			}
			if (col == 3){
				Item.strText.Format(_T("�ɼ�����ʱ��"), 2);
			}
			if (col == 4){
				Item.strText.Format(_T("�ź�����"), 3);
			}
			if (col == 5){
				Item.strText.Format(_T("��Ʒ"), 4);
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
		if (col == 5) strText = m_signalVector[row - 1].GetDetectedDevice().GetDetecteddeviceName();
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString searchSignalName;
	m_singnalDataNameCtrl.GetWindowTextA(searchSignalName);
	CTime ctStartTime, ctEndTime;
	CString signalStartCollectTime = "";
	CString signalEndCollectTime = "";
	m_signalDataStartTimeCtrl.GetTime(ctStartTime);
	m_signalDataEndTimeCtrl.GetTime(ctEndTime);
	if (m_dateSelectCheckBox.GetCheck()){
		///ѡ����ʹ�ò�ѯʱ��ʱ������ʼʱ�����ֹʱ�丳ֵ
		signalStartCollectTime = DateUtil::GetCStringTimeFormCTime(ctStartTime);
		signalEndCollectTime = DateUtil::GetCStringTimeFormCTime(ctEndTime);
	}
	////������ݼ���
	m_signalVector.clear();
	int projectId = theApp.m_currentProject.GetProjectId();
	Result res = m_signalController.LoadAllRecordedSignalBySearchCondition(projectId, searchSignalName, signalStartCollectTime, signalEndCollectTime, m_signalVector);
	if (res.GetIsSuccess()){
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
	}
}
