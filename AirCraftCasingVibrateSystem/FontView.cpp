// FontView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FontView.h"
#include "afxdialogex.h"


// CFontView �Ի���

IMPLEMENT_DYNAMIC(CFontView, CDialogEx)

CFontView::CFontView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFontView::IDD, pParent)
{

}

CFontView::~CFontView()
{
}

void CFontView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_XCOOR, m_xCoor);
	DDX_Control(pDX, IDC_BUTTON_YCOOR, m_yCoor);
	DDX_Control(pDX, IDC_BUTTON_CURSOR_VALUE, m_cursorValue);
	DDX_Control(pDX, IDC_BUTTON_X_UNIT, m_xUnit);
	DDX_Control(pDX, IDC_BUTTON_Y_UNIT, m_yUnit);
	DDX_Control(pDX, IDC_BUTTON_CURSOR_MARK, m_cursorMark);
	DDX_Control(pDX, IDC_BUTTON_STATISTIS_INF, m_statisticInf);
	DDX_Control(pDX, IDC_BUTTON_TEXT_INF, m_textNote);
	DDX_Control(pDX, IDC_BUTTON_PROJECT_INF, m_projectInf);
}


BEGIN_MESSAGE_MAP(CFontView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_XCOOR, &CFontView::OnBnClickedButtonXcoor)
	ON_BN_CLICKED(IDC_BUTTON_YCOOR, &CFontView::OnBnClickedButtonYcoor)
	ON_BN_CLICKED(IDC_BUTTON_CURSOR_VALUE, &CFontView::OnBnClickedButtonCursorValue)
	ON_BN_CLICKED(IDC_BUTTON_X_UNIT, &CFontView::OnBnClickedButtonXUnit)
	ON_BN_CLICKED(IDC_BUTTON_Y_UNIT, &CFontView::OnBnClickedButtonYUnit)
	ON_BN_CLICKED(IDC_BUTTON_CURSOR_MARK, &CFontView::OnBnClickedButtonCursorMark)
	ON_BN_CLICKED(IDC_BUTTON_STATISTIS_INF, &CFontView::OnBnClickedButtonStatistisInf)
	ON_BN_CLICKED(IDC_BUTTON_TEXT_INF, &CFontView::OnBnClickedButtonTextInf)
	ON_BN_CLICKED(IDC_BUTTON_PROJECT_INF, &CFontView::OnBnClickedButtonProjectInf)
END_MESSAGE_MAP()


// CFontView ��Ϣ�������


BOOL CFontView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


// X ��
void CFontView::OnBnClickedButtonXcoor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontXCoor = m_fontDlg.m_cf.lpLogFont;
	}
	
	
}

// Y��
void CFontView::OnBnClickedButtonYcoor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontYCoor = m_fontDlg.m_cf.lpLogFont;
	}
}

// ������
void CFontView::OnBnClickedButtonCursorValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontXCoor = m_fontDlg.m_cf.lpLogFont;
	}
}

// X�ᵥλ
void CFontView::OnBnClickedButtonXUnit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontXUnit = m_fontDlg.m_cf.lpLogFont;
	}
}

// Y�ᵥλ
void CFontView::OnBnClickedButtonYUnit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontYUnit = m_fontDlg.m_cf.lpLogFont;
	}
}

// ����ע
void CFontView::OnBnClickedButtonCursorMark()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontCursorValue = m_fontDlg.m_cf.lpLogFont;
	}
}

//ͳ����Ϣ
void CFontView::OnBnClickedButtonStatistisInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontStaValue = m_fontDlg.m_cf.lpLogFont;
	}
}

// �ı�ע��
void CFontView::OnBnClickedButtonTextInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontLegend = m_fontDlg.m_cf.lpLogFont;
	}
}

// ������Ϣ
void CFontView::OnBnClickedButtonProjectInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (IDOK == m_fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�����ȡ��ѡ����������Ʋ���ʾ���༭����   
		m_lFontLegend = m_fontDlg.m_cf.lpLogFont;
	}
}


