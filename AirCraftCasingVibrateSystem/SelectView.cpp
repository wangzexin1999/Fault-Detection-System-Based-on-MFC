// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SelectView.h"
#include "afxdialogex.h"


// CSelectView �Ի���

IMPLEMENT_DYNAMIC(CSelectView, CDialogEx)

CSelectView::CSelectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectView::IDD, pParent)
{

}

CSelectView::~CSelectView()
{
}

void CSelectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_GRID_LINE, m_checkGridLine);
	DDX_Control(pDX, IDC_CHECK_STATISTIC_INF, m_checkStatisticInf);
	DDX_Control(pDX, IDC_CHECK_MAX_VALUE, m_ckeckMaxValue);
	DDX_Control(pDX, IDC_CHECK_MIN_VALUE, m_checkMinValue);
	DDX_Control(pDX, IDC_CHECK_EFFECTIVE_VALUE, m_checkEffectiveValue);
	DDX_Control(pDX, IDC_CHECK_MEAN_VALUE, m_checkMeanValue);
	DDX_Control(pDX, IDC_CHECK_PEAK_VALUE, m_checkPeakValue);
}


BEGIN_MESSAGE_MAP(CSelectView, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_GRID_LINE, &CSelectView::OnBnClickedCheckGridLine)
	ON_BN_CLICKED(IDC_CHECK_STATISTIC_INF, &CSelectView::OnBnClickedCheckStatisticInf)
	ON_BN_CLICKED(IDC_CHECK_MAX_VALUE, &CSelectView::OnBnClickedCheckMaxValue)
	ON_BN_CLICKED(IDC_CHECK_MIN_VALUE, &CSelectView::OnBnClickedCheckMinValue)
	ON_BN_CLICKED(IDC_CHECK_EFFECTIVE_VALUE, &CSelectView::OnBnClickedCheckEffectiveValue)
	ON_BN_CLICKED(IDC_CHECK_MEAN_VALUE, &CSelectView::OnBnClickedCheckMeanValue)
	ON_BN_CLICKED(IDC_CHECK_PEAK_VALUE, &CSelectView::OnBnClickedCheckPeakValue)
END_MESSAGE_MAP()


// CSelectView ��Ϣ�������


BOOL CSelectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitAttri(); //��ʼ��ͼ������
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSelectView::OnBnClickedCheckGridLine()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bGridline = m_checkGridLine.GetCheck();
}


void CSelectView::OnBnClickedCheckStatisticInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bStaValue = m_checkStatisticInf.GetCheck();
	StatisticInfCtrlIsEnable(m_bStaValue); // ����ͳ����Ϣ�ؼ��Ƿ����
}


void CSelectView::OnBnClickedCheckMaxValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMax = m_ckeckMaxValue.GetCheck();
}


void CSelectView::OnBnClickedCheckMinValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bMin = m_checkMinValue.GetCheck();
}


void CSelectView::OnBnClickedCheckEffectiveValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bEffectiveValue = m_checkEffectiveValue.GetCheck();
}


void CSelectView::OnBnClickedCheckMeanValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bAve = m_checkMeanValue.GetCheck();
}


void CSelectView::OnBnClickedCheckPeakValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_bPeak = m_checkPeakValue.GetCheck();
}


void CSelectView::StatisticInfCtrlIsEnable(bool bEnable)
{

	if (bEnable)
	{
		m_ckeckMaxValue.EnableWindow(TRUE);
		m_checkMinValue.EnableWindow(TRUE);
		m_checkEffectiveValue.EnableWindow(TRUE);
		m_checkMeanValue.EnableWindow(TRUE);
		m_checkPeakValue.EnableWindow(TRUE);
	}
	else
	{
		m_ckeckMaxValue.EnableWindow(FALSE);
		m_checkMinValue.EnableWindow(FALSE);
		m_checkEffectiveValue.EnableWindow(FALSE);
		m_checkMeanValue.EnableWindow(FALSE);
		m_checkPeakValue.EnableWindow(FALSE);
	}
}

void CSelectView::InitCtrlAndAttri(CString strFromINI, BOOL &bAttri,CButton &btnCtrl )
{
	btnCtrl.SetCheck(_ttoi(strFromINI));
	bAttri = _ttoi(strFromINI);

}


void CSelectView::InitAttri()
{
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "..\\IniFileNameTest.ini");
	int length = 10;
	LPSTR lpstrTemp = new char[length];

	GetPrivateProfileString(m_select, "bGridline", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bGridline, m_checkGridLine);
	GetPrivateProfileString(m_select, "bStaValue", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bStaValue, m_checkStatisticInf);
	GetPrivateProfileString(m_select, "bMax", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bMax, m_ckeckMaxValue);
	GetPrivateProfileString(m_select, "bMin", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bMin, m_checkMinValue);
	GetPrivateProfileString(m_select, "bAve", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bAve, m_checkMeanValue);
	GetPrivateProfileString(m_select, "bEffectiveValue", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bEffectiveValue, m_checkEffectiveValue);
	GetPrivateProfileString(m_select, "bPeakValue", "", lpstrTemp, length, lpPath);
	InitCtrlAndAttri(lpstrTemp, m_bPeakValue, m_checkMeanValue);
	StatisticInfCtrlIsEnable(m_bStaValue);
	delete[] lpstrTemp;
	delete[] lpPath;

	
}


void CSelectView::InitAttri2()
{

	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "..\\IniFileNameTest.ini");
	int length = 10;
	LPSTR lpstrTemp = new char[length];

	GetPrivateProfileString(m_select, "bGridline", "", lpstrTemp, length, lpPath);
	m_bGridline = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bStaValue", "", lpstrTemp, length, lpPath);
	m_bStaValue = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bMax", "", lpstrTemp, length, lpPath);
	m_bMax = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bMin", "", lpstrTemp, length, lpPath);
	m_bMin = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bAve", "", lpstrTemp, length, lpPath);
	m_bAve = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bEffectiveValue", "", lpstrTemp, length, lpPath);
	m_bEffectiveValue = _ttoi(lpstrTemp);
	GetPrivateProfileString(m_select, "bPeakValue", "", lpstrTemp, length, lpPath);
	m_bPeakValue = _ttoi(lpstrTemp);
	delete[] lpstrTemp;
	delete[] lpPath;
}