// ChannelParaDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaDialog.h"
#include "afxdialogex.h"

// CChannelParaDialog �Ի���

IMPLEMENT_DYNAMIC(CChannelParaDialog, CDialogEx)

CChannelParaDialog::CChannelParaDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChannelParaDialog::IDD, pParent){
}

CChannelParaDialog::~CChannelParaDialog(){}

void CChannelParaDialog::RefreshDlg(){
	m_generalParaView.GridCtrlInit();
	m_triggerParaView.GridCtrlInit();
	m_geometricParaView.GridCtrlInit();
}
void CChannelParaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_channelTab);
}

BEGIN_MESSAGE_MAP(CChannelParaDialog, CDialogEx)
	
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CChannelParaDialog::OnTcnSelchangeTab1)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CChannelParaDialog ��Ϣ�������

BOOL CChannelParaDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_channelTab.InsertItem(0, _T("ͨ�ò���"));
	m_channelTab.InsertItem(1, _T("��������"));
	m_channelTab.InsertItem(2, _T("���β���"));
	//����ͨ��������ʾ����ͼ  
	m_generalParaView.Create(IDD_DIALOG_GENERAL_PARA, &m_channelTab);
	m_triggerParaView.Create(IDD_DIALOG_TRIGGER_PARA, &m_channelTab);
	m_geometricParaView.Create(IDD_DIALOG_GEOMETRIC_PARA, &m_channelTab);
	
	//�趨��Tab����ʾ�ķ�Χ  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	//m_tabSystemPara.MoveWindow(tabRect);
	m_generalParaView.MoveWindow(&tabRect);
	m_triggerParaView.MoveWindow(&tabRect);
	m_geometricParaView.MoveWindow(&tabRect);
	//�ѶԻ������ָ�뱣������
	pDialog[0] = &m_generalParaView;
	pDialog[1] = &m_triggerParaView;
	pDialog[2] = &m_geometricParaView;
	//��ʾ��ʼҳ��  
	m_generalParaView.ShowWindow(SW_SHOW);
	m_triggerParaView.ShowWindow(SW_HIDE);
	m_geometricParaView.ShowWindow(SW_HIDE);
	m_CurSelTab = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CChannelParaDialog::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ѵ�ǰ��ҳ����������
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	
	m_CurSelTab = m_channelTab.GetCurSel();
	//���µ�ҳ����ʾ����
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void CChannelParaDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO:  �ڴ˴������Ϣ����������
}
