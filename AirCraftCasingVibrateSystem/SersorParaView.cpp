// SersorParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SersorParaView.h"
#include "afxdialogex.h"


// CSersorParaView 对话框

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


// CSersorParaView 消息处理程序


BOOL CSersorParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	m_cbSamplingFrequency.AddString(_T("1.28Hz"));
	m_cbSamplingFrequency.AddString(_T("1.28Hz"));
	m_cbSamplingFrequency.AddString(_T("1.28Hz"));

	m_cbSamplingFrequency.SetCurSel(1);

	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.AddString(_T("1.28Hz"));
	m_cbAnalysisFrequency.SetCurSel(1);

	m_cbSamplingMethod.AddString(_T("连续"));
	m_cbSamplingMethod.AddString(_T("瞬态"));
	m_cbSamplingMethod.AddString(_T("触发连续"));
	m_cbSamplingMethod.SetCurSel(1);


	m_cbTriggerMode.AddString(_T("自由采集"));
	m_cbTriggerMode.AddString(_T("自由采集"));
	m_cbTriggerMode.AddString(_T("自由采集"));
	m_cbTriggerMode.SetCurSel(1);

	m_cbDataBlocks.AddString(_T("自由采集"));
	m_cbDataBlocks.AddString(_T("自由采集"));
	m_cbDataBlocks.AddString(_T("自由采集"));
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
	// 异常:  OCX 属性页应返回 FALSE
}
