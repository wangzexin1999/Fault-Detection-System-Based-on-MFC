// SersorParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SersorParaView.h"
#include "afxdialogex.h"


// CSersorParaView �Ի���

IMPLEMENT_DYNAMIC(CSersorParaView, CDialogEx)

CSersorParaView::CSersorParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSersorParaView::IDD, pParent)
{

}

CSersorParaView::~CSersorParaView()
{
}

void CSersorParaView::DoDataExchange(CDataExchange* pDX)
{

	DDX_Control(pDX, IDC_COMBO1, m_cbSamplingFrequency);
	DDX_Control(pDX, IDC_COMBO2, m_cbAnalysisFrequency);
	DDX_Control(pDX, IDC_COMBO3, m_cbSamplingMethod);
	DDX_Control(pDX, IDC_COMBO4, m_cbTriggerMode);
	DDX_Control(pDX, IDC_COMBO5, m_cbDataBlocks);
	DDX_Control(pDX, IDC_COMBO6, m_cbDelayBlocks);
	DDX_Control(pDX, IDC_COMBO7, m_cbTriggerTimes);
	DDX_Control(pDX, IDC_COMBO8, m_cbSamplingTimes);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSersorParaView, CDialogEx)
END_MESSAGE_MAP()


// CSersorParaView ��Ϣ�������


BOOL CSersorParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	m_cbSamplingFrequency.AddString(_T("1.28Hz"));
	m_cbSamplingFrequency.AddString(_T("1.28Hz"));
	m_cbSamplingFrequency.AddString(_T("1.28Hz"));

	m_cbSamplingFrequency.SetCurSel(1);

	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.SetCurSel(1);

	m_cbSamplingMethod.AddString(_T("����"));
	m_cbSamplingMethod.AddString(_T("˲̬"));
	m_cbSamplingMethod.AddString(_T("��������"));
	m_cbSamplingMethod.SetCurSel(1);


	m_cbTriggerMode.AddString(_T("���ɲɼ�"));
	m_cbTriggerMode.AddString(_T("���ɲɼ�"));
	m_cbTriggerMode.AddString(_T("���ɲɼ�"));
	m_cbTriggerMode.SetCurSel(1);

	m_cbDataBlocks.AddString(_T("���ɲɼ�"));
	m_cbDataBlocks.AddString(_T("���ɲɼ�"));
	m_cbDataBlocks.AddString(_T("���ɲɼ�"));
	m_cbDataBlocks.SetCurSel(1);

	m_cbDelayBlocks.AddString(_T("1"));
	m_cbDelayBlocks.AddString(_T("2"));
	m_cbDelayBlocks.AddString(_T("3"));
	m_cbDelayBlocks.SetCurSel(1);

	m_cbTriggerTimes.AddString(_T("0"));
	m_cbTriggerTimes.AddString(_T("1"));
	m_cbTriggerTimes.AddString(_T("2"));
	m_cbTriggerTimes.SetCurSel(1);

	m_cbSamplingTimes.AddString(_T("0"));
	m_cbSamplingTimes.AddString(_T("1"));
	m_cbSamplingTimes.AddString(_T("2"));
	m_cbSamplingTimes.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
