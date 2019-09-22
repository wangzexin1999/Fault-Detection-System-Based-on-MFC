// GraphAttributeView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GraphAttributeView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
// CGraphAttributeView �Ի���

IMPLEMENT_DYNAMIC(CGraphAttributeView, CDialogEx)

CGraphAttributeView::CGraphAttributeView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGraphAttributeView::IDD, pParent)
{

}

CGraphAttributeView::~CGraphAttributeView()
{
}

void CGraphAttributeView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_GRAPH_ATTR, m_tabGraphAttribute);
	DDX_Control(pDX, IDC_CHECK_APP_ALL_WIN, m_appAllWinodw);
}


BEGIN_MESSAGE_MAP(CGraphAttributeView, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_GRAPH_ATTR, &CGraphAttributeView::OnSelchangeTabGraphAttr)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CGraphAttributeView ��Ϣ�������


BOOL CGraphAttributeView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tabGraphAttribute.InsertItem(0, _T("��ɫ"));
	m_tabGraphAttribute.InsertItem(1, _T("����"));
	//m_tabGraphAttribute.InsertItem(2, _T("����"));
	m_tabGraphAttribute.InsertItem(3, _T("ѡ��"));
	//m_tabGraphAttribute.InsertItem(4, _T("����"));
	
	//���������Ի���  
	m_colorView.Create(IDD_DIALOG_CORLOR, &m_tabGraphAttribute);
	m_fontView.Create(IDD_DIALOG_FONT, &m_tabGraphAttribute);
	//m_lineView.Create(IDD_DIALOG_LINE, &m_tabGraphAttribute);
	m_selectView.Create(IDD_DIALOG_SELECT, &m_tabGraphAttribute);
	m_coordinateView.Create(IDD_DIALOG_COORDINATE, &m_tabGraphAttribute);
	//�趨��Tab����ʾ�ķ�Χ  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;
	//m_tabSystemPara.MoveWindow(tabRect);
	m_colorView.MoveWindow(&tabRect);
	m_fontView.MoveWindow(&tabRect);
	//m_lineView.MoveWindow(&tabRect);
	m_selectView.MoveWindow(&tabRect);
	//m_coordinateView.MoveWindow(&tabRect);
	
	//�ѶԻ������ָ�뱣������
	pDialog[0] = &m_colorView;
	pDialog[1] = &m_fontView;
	//pDialog[2] = &m_lineView;
	pDialog[3] = &m_selectView;
	//pDialog[4] = &m_coordinateView;
	//��ʾ��ʼҳ��  
	m_colorView.ShowWindow(SW_SHOW);
	m_fontView.ShowWindow(SW_HIDE);
	//m_lineView.ShowWindow(SW_HIDE);
	m_selectView.ShowWindow(SW_HIDE);
	//m_coordinateView.ShowWindow(SW_HIDE);
	m_tabGraphAttribute.SetCurSel(0);
	m_CurSelTab = 0;
	// Ĭ��Ӧ��ͬ���ʹ���ѡ��
	m_appAllWinodw.SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CGraphAttributeView::OnSelchangeTabGraphAttr(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�õ��µ�ҳ������
	//pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	//�õ��µ�ҳ������
	m_CurSelTab = m_tabGraphAttribute.GetCurSel();
	//���µ�ҳ����ʾ����
	
	switch (m_CurSelTab){
	case 0:
		m_colorView.ShowWindow(SW_SHOW);
		m_fontView.ShowWindow(SW_HIDE);
		//m_lineView.ShowWindow(SW_HIDE);
		m_selectView.ShowWindow(SW_HIDE);
		//m_coordinateView.ShowWindow(SW_HIDE);
		break; // ��ѡ��
	case 1:
		m_colorView.ShowWindow(SW_HIDE);
		m_fontView.ShowWindow(SW_SHOW);
		//m_lineView.ShowWindow(SW_HIDE);
		m_selectView.ShowWindow(SW_HIDE);
		//m_coordinateView.ShowWindow(SW_HIDE);
		
		break; // ��ѡ��
	case 2:
		m_colorView.ShowWindow(SW_HIDE);
		m_fontView.ShowWindow(SW_HIDE);
	//	m_lineView.ShowWindow(SW_SHOW);
		m_selectView.ShowWindow(SW_SHOW);
		//m_coordinateView.ShowWindow(SW_HIDE);
		break; // ��ѡ��
	case 3:
		m_colorView.ShowWindow(SW_HIDE);
		m_fontView.ShowWindow(SW_HIDE);
		//m_lineView.ShowWindow(SW_HIDE);
		m_selectView.ShowWindow(SW_SHOW);
		//m_coordinateView.ShowWindow(SW_HIDE);
		break; // ��ѡ��case 1:
	case 4:
		m_colorView.ShowWindow(SW_HIDE);
		m_fontView.ShowWindow(SW_HIDE);
		//m_lineView.ShowWindow(SW_HIDE);
		m_selectView.ShowWindow(SW_HIDE);
		//m_coordinateView.ShowWindow(SW_SHOW);
		break; // ��ѡ��

		// ������������������ case ���
	default: // ��ѡ��
		break;
	}
	
	
	
	*pResult = 0;
}


void CGraphAttributeView::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//д�����ļ�
	Write2INIFile();
	CDialogEx::OnClose();
}


void  CGraphAttributeView::Write2INIFile()
{

	PTSTR lpPath = new char[MAX_PATH];

	strcpy(lpPath, "..//IniFileGraphAttri.ini");

	// ��ɫ
	WritePrivateProfileString(m_colorView.m_color, "colSerie", CommonUtil::Long2CString(m_colorView.m_colSerie[0]), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colBKColor", CommonUtil::Long2CString(m_colorView.m_colBKColor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colGBKColor", CommonUtil::Long2CString(m_colorView.m_colGBKColor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colTBKColor", CommonUtil::Long2CString(m_colorView.m_colTBKColor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colGridLineColor", CommonUtil::Long2CString(m_colorView.m_colGridLineColor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colCoorColor", CommonUtil::Long2CString(m_colorView.m_colCoorColor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colCursor1", CommonUtil::Long2CString(m_colorView.m_colCursor1), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colScale", CommonUtil::Long2CString(m_colorView.m_colScale), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colXCoor", CommonUtil::Long2CString(m_colorView.m_colXCoor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colYCoor", CommonUtil::Long2CString(m_colorView.m_colYCoor), lpPath);
	WritePrivateProfileString(m_colorView.m_color, "colStatisticInf", CommonUtil::Long2CString(m_colorView.m_colStatisticInf), lpPath);
	// ����
	CString strSepator = ",";
	WritePrivateProfileString(m_fontView.m_font, "lFontXCoor",
		m_fontView.m_lFontXCoor.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontXCoor.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontYCoor",
		m_fontView.m_lFontYCoor.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontYCoor.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontXUnit",
		m_fontView.m_lFontXUnit.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontXUnit.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontYUnit",
		m_fontView.m_lFontYUnit.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontYUnit.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontCursorValue",
		m_fontView.m_lFontCursorValue.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontCursorValue.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontStaValue",
		m_fontView.m_lFontStaValue.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontStaValue.m_lFontSize), lpPath);
	WritePrivateProfileString(m_fontView.m_font, "lFontLegend",
		m_fontView.m_lFontLegend.m_lFont.lfFaceName + strSepator + CommonUtil::Int2CString(m_fontView.m_lFontLegend.m_lFontSize), lpPath);

	// ѡ��
	WritePrivateProfileString(m_selectView.m_select, "bGridline", CommonUtil::Int2CString(m_selectView.m_bGridline), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bStaValue", CommonUtil::Int2CString(m_selectView.m_bStaValue), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bMax", CommonUtil::Int2CString(m_selectView.m_bMax), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bMin", CommonUtil::Int2CString(m_selectView.m_bMin), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bAve", CommonUtil::Int2CString(m_selectView.m_bAve), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bPeak", CommonUtil::Int2CString(m_selectView.m_bPeak), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bEffectiveValue", CommonUtil::Int2CString(m_selectView.m_bEffectiveValue), lpPath);
	WritePrivateProfileString(m_selectView.m_select, "bPeakValue", CommonUtil::Int2CString(m_selectView.m_bPeakValue), lpPath);
	delete[] lpPath;
}