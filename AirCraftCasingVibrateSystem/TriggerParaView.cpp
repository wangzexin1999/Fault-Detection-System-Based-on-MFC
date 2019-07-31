// TriggerParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "TriggerParaView.h"
#include "afxdialogex.h"


// CTriggerParaView �Ի���

IMPLEMENT_DYNAMIC(CTriggerParaView, CDialogEx)

CTriggerParaView::CTriggerParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTriggerParaView::IDD, pParent)
{

}

CTriggerParaView::~CTriggerParaView()
{
}

void CTriggerParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TRIGGER_PARA, m_triggerParaList);
}


BEGIN_MESSAGE_MAP(CTriggerParaView, CDialogEx)
END_MESSAGE_MAP()


// CTriggerParaView ��Ϣ�������


BOOL CTriggerParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_triggerParaList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CRect rect;
	m_triggerParaList.GetClientRect(rect);
	int nWidth = rect.Width();
	int arr[][3] = {
		0, LVCFMT_CENTER, (UINT)(10 / 50.0 * 4),
		1, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		2, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		3, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		4, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		5, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
		6, LVCFMT_CENTER, (UINT)(nWidth / 50.0 * 4),
	};
	CStringArray strArray;
	strArray.Add(_T(""));
	strArray.Add(_T("ͨ����"));
	strArray.Add(_T("�μӴ���"));
	strArray.Add(_T("��������"));
	strArray.Add(_T("��������"));
	
	for (int i = 0; i < 5; i++)
	{
		m_triggerParaList.InsertColumn(arr[i][0], strArray.GetAt(i), arr[i][1], arr[i][2]);
	}


	/*for (int i = 0; i < length; i++)
	{

	}*/
	m_triggerParaList.InsertItem(0, _T(""));   //��һ�У���һ��
	m_triggerParaList.SetItemText(0, 1, _T("1-1"));//��һ�У��ڶ���
	m_triggerParaList.SetItemText(0, 2, _T("��"));
	m_triggerParaList.SetItemText(0, 3, _T("33%"));
	m_triggerParaList.SetItemText(0, 4, _T("����ֵ"));
	

	m_triggerParaList.InsertItem(1, _T(""));   //�ڶ��У���һ��
	m_triggerParaList.SetItemText(1, 1, _T("1-2"));//��һ�У��ڶ���
	m_triggerParaList.SetItemText(1, 2, _T("��"));
	m_triggerParaList.SetItemText(1, 3, _T("33%"));
	m_triggerParaList.SetItemText(1, 4, _T("����ֵ"));
	

	m_triggerParaList.InsertItem(2, _T(""));   //�ڶ��У���һ��
	m_triggerParaList.SetItemText(2, 1, _T("1-3"));//��һ�У��ڶ���
	m_triggerParaList.SetItemText(2, 2, _T("��"));
	m_triggerParaList.SetItemText(2, 3, _T("33%"));
	m_triggerParaList.SetItemText(2, 4, _T("����ֵ"));
	


	m_triggerParaList.InsertItem(3, _T(""));   //�ڶ��У���һ��
	m_triggerParaList.SetItemText(3, 1, _T("1-4"));//��һ�У��ڶ���
	m_triggerParaList.SetItemText(3, 2, _T("��"));//�ڶ��У��ڶ���
	m_triggerParaList.SetItemText(3, 3, _T("33%"));
	m_triggerParaList.SetItemText(3, 4, _T("����ֵ"));
	

	m_triggerParaList.InsertItem(4, _T(""));   //�ڶ��У���һ��
	m_triggerParaList.SetItemText(4, 1, _T("1-5"));//�ڶ��У��ڶ���
	m_triggerParaList.SetItemText(4, 2, _T("��"));//�ڶ��У��ڶ���
	m_triggerParaList.SetItemText(4, 3, _T("33%"));
	m_triggerParaList.SetItemText(4, 4, _T("����ֵ"));
	

	m_triggerParaList.InsertItem(5, _T(""));   //�ڶ��У���һ��
	m_triggerParaList.SetItemText(5, 1, _T("1-6"));//�ڶ��У��ڶ���
	m_triggerParaList.SetItemText(5, 2, _T("��"));//�ڶ��У��ڶ���
	m_triggerParaList.SetItemText(5, 3, _T("33%"));
	m_triggerParaList.SetItemText(5, 4, _T("����ֵ"));
	



	LOGFONT   logfont;//���Ū�����Ա,ȫ�ֱ���,��̬��Ա  
	CFont   *pfont1 = m_triggerParaList.GetFont();
	pfont1->GetLogFont(&logfont);
	logfont.lfHeight = logfont.lfHeight * 1.3;   //��������޸�����ĸ߱���
	logfont.lfWidth = logfont.lfWidth * 1.3;   //��������޸�����Ŀ����
	static   CFont   font1;
	font1.CreateFontIndirect(&logfont);
	m_triggerParaList.SetFont(&font1);
	font1.Detach();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
