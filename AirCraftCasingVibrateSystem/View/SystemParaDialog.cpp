// SystemParaDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SystemParaDialog.h"
#include "afxdialogex.h"


// CSystemParaDialog �Ի���

IMPLEMENT_DYNAMIC(CSystemParaDialog, CDialogEx)

CSystemParaDialog::CSystemParaDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSystemParaDialog::IDD, pParent)
{

}

CSystemParaDialog::~CSystemParaDialog()
{
}

void CSystemParaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SYSTEM_PARA, m_tabSystemPara);
}


BEGIN_MESSAGE_MAP(CSystemParaDialog, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SYSTEM_PARA, &CSystemParaDialog::OnTcnSelchangeTabSystemPara)
END_MESSAGE_MAP()


// CSystemParaDialog ��Ϣ�������


BOOL CSystemParaDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//ΪTab Control��������ҳ��  
	m_tabSystemPara.InsertItem(0, _T("�ɼ�����"));
	m_tabSystemPara.InsertItem(1, _T("�豸����"));
	//���������Ի���  
	m_channelPara.Create(IDD_DIALOG_SERSOR_PARA, &m_tabSystemPara);
	m_devicePara.Create(IDD_DIALOG_DEVICE_PARA, &m_tabSystemPara);
	//�趨��Tab����ʾ�ķ�Χ  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;
	//m_tabSystemPara.MoveWindow(tabRect);
	m_channelPara.MoveWindow(&tabRect);
	m_devicePara.MoveWindow(&tabRect);
	//�ѶԻ������ָ�뱣������
	pDialog[0] = &m_channelPara;
	pDialog[1] = &m_devicePara;
	//��ʾ��ʼҳ��  
	m_channelPara.ShowWindow(SW_SHOW);
	m_devicePara.ShowWindow(SW_HIDE);
	m_CurSelTab = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void CSystemParaDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	
	//GetDlgItem(IDC_TAB_SYSTEM_PARA)->MoveWindow(tabRect, TRUE);
	//m_tabSystemPara.MoveWindow(tabRect);
	// TODO:  �ڴ˴������Ϣ����������
}


void CSystemParaDialog::OnTcnSelchangeTabSystemPara(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�ѵ�ǰ��ҳ����������
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_CurSelTab = m_tabSystemPara.GetCurSel();
	//���µ�ҳ����ʾ����
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	
	*pResult = 0;
}
void CSystemParaDialog::RefreshView(){
	m_channelPara.RefreshView();
}