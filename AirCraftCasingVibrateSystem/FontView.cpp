// FontView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "FontView.h"
#include "afxdialogex.h"

#include "FileUtil.h"
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
	InitAttri(); // ��ʼ����Ա�������������������С
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


// X ��
void CFontView::OnBnClickedButtonXcoor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	

	// ��������Ի��򣬳�ʼѡ��������Ϊ�����塱   
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť��  
		m_lFontXCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXCoor.m_lFontSize = fontDlg.GetSize();
	}
	
	
}

// Y��
void CFontView::OnBnClickedButtonYcoor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť��  
		m_lFontYCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontYCoor.m_lFontSize = fontDlg.GetSize();
	}
}

// ������
void CFontView::OnBnClickedButtonCursorValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť��  
		m_lFontXCoor.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXCoor.m_lFontSize = fontDlg.GetSize();
	}
}

// X�ᵥλ
void CFontView::OnBnClickedButtonXUnit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());

	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�� 
		m_lFontXUnit.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontXUnit.m_lFontSize = fontDlg.GetSize();
	}
}

// Y�ᵥλ
void CFontView::OnBnClickedButtonYUnit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť��
		m_lFontYUnit.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontYUnit.m_lFontSize = fontDlg.GetSize();
	}
}

// ����ע
void CFontView::OnBnClickedButtonCursorMark()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť��  
		m_lFontCursorValue.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontCursorValue.m_lFontSize = fontDlg.GetSize();
	}
}

//ͳ����Ϣ
void CFontView::OnBnClickedButtonStatistisInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�� 
		m_lFontStaValue.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontStaValue.m_lFontSize = fontDlg.GetSize();
	}
}

// �ı�ע��
void CFontView::OnBnClickedButtonTextInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť�� 
		m_lFontLegend.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontLegend.m_lFontSize = fontDlg.GetSize();
	}
}

// ������Ϣ
void CFontView::OnBnClickedButtonProjectInf()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFontDialog fontDlg(&InitFontDialog());
	if (IDOK == fontDlg.DoModal())
	{
		// ����û�ѡ��������Ի����OK��ť  
		m_lFontLegend.m_lFont = *(fontDlg.m_cf.lpLogFont);
		m_lFontLegend.m_lFontSize = fontDlg.GetSize();
	}
}


// ����ؼ���Ĭ��ѡ��
LOGFONT CFontView::InitFontDialog()
{
	  
	LOGFONT lf;             // LOGFONT����   
	// ��lf�����ֽ�����   
	memset(&lf, 0, sizeof(LOGFONT));
	// ��lf�е�Ԫ����������Ϊ�����塱   
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T("����"));
	return lf;
}

void CFontView::InitFont(FontAttri &fonAttri, CString strInput)
{
	// ��������
	LOGFONT lf;             // LOGFONT����   
	// ��lf�����ֽ�����   
	memset(&lf, 0, sizeof(LOGFONT));
	CString strExtractSub[] = { "", "" };
	char sepator = ',';  // �ָ���
	AfxExtractSubString(strExtractSub[0], strInput, 0, sepator);
	AfxExtractSubString(strExtractSub[1], strInput, 1, sepator);
	// ��lf�е�Ԫ��������  
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T(strExtractSub[0]));
	fonAttri.m_lFont = lf;
	// ��ʼ�������С
	fonAttri.m_lFontSize = _ttoi(strExtractSub[1]);
}


void CFontView::InitAttri()
{

	// ��������
	LOGFONT lf;             // LOGFONT����   
	// ��lf�����ֽ�����   
	memset(&lf, 0, sizeof(LOGFONT));

	// ����Ĭ�ϵ�����
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "..\\IniFileNameTest.ini");  // ini �����ļ�·��
	int length = 15;  // ����
	LPSTR lpstrTemp = new char[length];
	GetPrivateProfileString(m_font, "lFontXCoor", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontXCoor, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontYCoor", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontYCoor, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontXUnit", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontXUnit, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontYUnit", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontYUnit, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontCursorValue", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontCursorValue, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontStaValue", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontStaValue, lpstrTemp);
	GetPrivateProfileString(m_font, "lFontLegend", "", lpstrTemp, length, lpPath);
	InitFont(m_lFontLegend, lpstrTemp);
	delete[] lpstrTemp;
	delete[] lpPath;

}