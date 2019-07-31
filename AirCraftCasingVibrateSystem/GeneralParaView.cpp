// GeneralParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"


// CGeneralParaView �Ի���

IMPLEMENT_DYNAMIC(CGeneralParaView, CDialogEx)

CGeneralParaView::CGeneralParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeneralParaView::IDD, pParent)
{

}

CGeneralParaView::~CGeneralParaView()
{
}

void CGeneralParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_GENERAL_PARA, m_generalParaList);
}


BEGIN_MESSAGE_MAP(CGeneralParaView, CDialogEx)
END_MESSAGE_MAP()


// CGeneralParaView ��Ϣ�������


BOOL CGeneralParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// ��ʼ���б�
	m_generalParaList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	CRect rect;
	m_generalParaList.GetClientRect(rect);
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
	strArray.Add(_T("ͨ��״̬"));
	strArray.Add(_T("��������"));
	strArray.Add(_T("ͨ������"));
	strArray.Add(_T("������"));
	strArray.Add(_T("����"));	
	for (int i = 0; i < 7; i++)
	{
		m_generalParaList.InsertColumn(arr[i][0], strArray.GetAt(i), arr[i][1], arr[i][2]);
	}


	/*for (int i = 0; i < length; i++)
	{

	}*/
	m_generalParaList.InsertItem(0, _T(""));   //��һ�У���һ��
	m_generalParaList.SetItemText(0, 1, _T("1-1"));//��һ�У��ڶ���
	m_generalParaList.SetItemText(0, 2, _T("NO"));
	m_generalParaList.SetItemText(0, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(0, 4, _T("ˮƽ"));
	m_generalParaList.SetItemText(0, 5, _T("���δ�"));

	m_generalParaList.InsertItem(1, _T(""));   //�ڶ��У���һ��
	m_generalParaList.SetItemText(1, 1, _T("1-2"));//��һ�У��ڶ���
	m_generalParaList.SetItemText(1, 2, _T("NO"));
	m_generalParaList.SetItemText(1, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(1, 4, _T("��ֱ"));
	m_generalParaList.SetItemText(1, 5, _T("���δ�"));

	m_generalParaList.InsertItem(2, _T(""));   //�ڶ��У���һ��
	m_generalParaList.SetItemText(2, 1, _T("1-3"));//��һ�У��ڶ���
	m_generalParaList.SetItemText(2, 2, _T("NO"));
	m_generalParaList.SetItemText(2, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(2, 4, _T("��ѹ��"));
	m_generalParaList.SetItemText(2, 5, _T("���δ�"));


	m_generalParaList.InsertItem(3, _T(""));   //�ڶ��У���һ��
	m_generalParaList.SetItemText(3, 1, _T("1-4"));//��һ�У��ڶ���
	m_generalParaList.SetItemText(3, 2, _T("NO"));//�ڶ��У��ڶ���
	m_generalParaList.SetItemText(3, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(3, 4, _T("��ڱ�"));
	m_generalParaList.SetItemText(3, 5, _T("���δ�"));

	m_generalParaList.InsertItem(4, _T(""));   //�ڶ��У���һ��
	m_generalParaList.SetItemText(4, 1, _T("1-5"));//�ڶ��У��ڶ���
	m_generalParaList.SetItemText(4, 2, _T("NO"));//�ڶ��У��ڶ���
	m_generalParaList.SetItemText(4, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(4, 4, _T("����"));
	m_generalParaList.SetItemText(4, 5, _T("���δ�"));

	m_generalParaList.InsertItem(5, _T(""));   //�ڶ��У���һ��
	m_generalParaList.SetItemText(5, 1, _T("1-6"));//�ڶ��У��ڶ���
	m_generalParaList.SetItemText(5, 2, _T("NO"));//�ڶ��У��ڶ���
	m_generalParaList.SetItemText(5, 3, _T("��ѹ����"));
	m_generalParaList.SetItemText(5, 4, _T("����"));
	m_generalParaList.SetItemText(5, 5, _T("���δ�"));
	


	LOGFONT   logfont;//���Ū�����Ա,ȫ�ֱ���,��̬��Ա  
	CFont   *pfont1 = m_generalParaList.GetFont();
	pfont1->GetLogFont(&logfont);
	logfont.lfHeight = logfont.lfHeight * 1.3;   //��������޸�����ĸ߱���
	logfont.lfWidth = logfont.lfWidth * 1.3;   //��������޸�����Ŀ����
	static   CFont   font1;
	font1.CreateFontIndirect(&logfont);
	m_generalParaList.SetFont(&font1);
	font1.Detach();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
