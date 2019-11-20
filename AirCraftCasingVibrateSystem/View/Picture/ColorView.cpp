// ColorView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ColorView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Constant.h"
// CColorView �Ի���

IMPLEMENT_DYNAMIC(CColorView, CDialogEx)

CColorView::CColorView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorView::IDD, pParent)
{

}

CColorView::~CColorView()
{
}

void CColorView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_WIN_BG, m_windowBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_GRAPH_BG, m_graphBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_INF_BG, m_infWinBGColor);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS1_BG, m_series1Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS2_BG, m_series2Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS33_BG, m_series3Color);
	DDX_Control(pDX, IDC_MFCBUTTON_SERIS4_BG, m_series4Color);
	DDX_Control(pDX, IDC_MFCBUTTON_GRID_BG, m_gridColor);
	DDX_Control(pDX, IDC_MFCBUTTON_COOR_BG, m_coordinateColor);
	DDX_Control(pDX, IDC_MFCBUTTON_SCALE_BG, m_scaleColor);
	DDX_Control(pDX, IDC_MFCBUTTON_CURLOR_BG, m_cursorColor);
	DDX_Control(pDX, IDC_MFCBUTTON_X_BG, m_xAxisColor);
	DDX_Control(pDX, IDC_MFCBUTTON_Y_BG, m_yAxisColor);
	DDX_Control(pDX, IDC_MFCBUTTON_STATISC_BG, m_statisticsInfColor);
}


BEGIN_MESSAGE_MAP(CColorView, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON_WIN_BG, &CColorView::OnBnClickedMfcbuttonWinBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_GRAPH_BG, &CColorView::OnBnClickedMfcbuttonGraphBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_INF_BG, &CColorView::OnBnClickedMfcbuttonInfBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS1_BG, &CColorView::OnBnClickedMfcbuttonSeris1Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS2_BG, &CColorView::OnBnClickedMfcbuttonSeris2Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS33_BG, &CColorView::OnBnClickedMfcbuttonSeris33Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SERIS4_BG, &CColorView::OnBnClickedMfcbuttonSeris4Bg)
	ON_BN_CLICKED(IDC_MFCBUTTON_GRID_BG, &CColorView::OnBnClickedMfcbuttonGridBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_COOR_BG, &CColorView::OnBnClickedMfcbuttonCoorBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_SCALE_BG, &CColorView::OnBnClickedMfcbuttonScaleBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_CURLOR_BG, &CColorView::OnBnClickedMfcbuttonCurlorBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_X_BG, &CColorView::OnBnClickedMfcbuttonXBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_Y_BG, &CColorView::OnBnClickedMfcbuttonYBg)
	ON_BN_CLICKED(IDC_MFCBUTTON_STATISC_BG, &CColorView::OnBnClickedMfcbuttonStatiscBg)
END_MESSAGE_MAP()


// CColorView ��Ϣ��������

// ���ڱ���
void CColorView::OnBnClickedMfcbuttonWinBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colBKColor = GetColorDiag();
	SetMFCButtonColor(m_windowBGColor, m_colBKColor);
}

// ͼ�����򱳾�
void CColorView::OnBnClickedMfcbuttonGraphBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colGBKColor = GetColorDiag();
	SetMFCButtonColor(m_graphBGColor, m_colGBKColor);
}

// ��Ϣ������
void CColorView::OnBnClickedMfcbuttonInfBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colTBKColor = GetColorDiag();
	SetMFCButtonColor(m_infWinBGColor, m_colTBKColor);
}

// ����1
void CColorView::OnBnClickedMfcbuttonSeris1Bg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colSerie[0] = GetColorDiag();
	SetMFCButtonColor(m_series1Color, m_colSerie[0]);
}

// ����2
void CColorView::OnBnClickedMfcbuttonSeris2Bg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colSerie[1] = GetColorDiag();
	SetMFCButtonColor(m_series2Color, m_colSerie[1]);
}

// ����3
void CColorView::OnBnClickedMfcbuttonSeris33Bg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colSerie[2] = GetColorDiag();
	SetMFCButtonColor(m_series3Color, m_colSerie[2]);
}

// ����4
void CColorView::OnBnClickedMfcbuttonSeris4Bg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colSerie[3] = GetColorDiag();
	SetMFCButtonColor(m_series4Color, m_colSerie[3]);
}

// ����
void CColorView::OnBnClickedMfcbuttonGridBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colGridLineColor = GetColorDiag();
	SetMFCButtonColor(m_gridColor, m_colGridLineColor);
}

// ����
void CColorView::OnBnClickedMfcbuttonCoorBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colCoorColor = GetColorDiag();
	SetMFCButtonColor(m_coordinateColor, m_colCoorColor);
}

//�̶�
void CColorView::OnBnClickedMfcbuttonScaleBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colScale = GetColorDiag();
	SetMFCButtonColor(m_scaleColor, m_colScale);
}

//���
void CColorView::OnBnClickedMfcbuttonCurlorBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colCursor1 = GetColorDiag();
	SetMFCButtonColor(m_cursorColor, m_colCursor1);
}

//X��
void CColorView::OnBnClickedMfcbuttonXBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colXCoor = GetColorDiag();
	SetMFCButtonColor(m_xAxisColor, m_colBKColor);
}

//Y��
void CColorView::OnBnClickedMfcbuttonYBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colYCoor = GetColorDiag();
	SetMFCButtonColor(m_yAxisColor, m_colYCoor);
}

// ͳ����Ϣ
void CColorView::OnBnClickedMfcbuttonStatiscBg()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	m_colStatisticInf = GetColorDiag();
	SetMFCButtonColor(m_statisticsInfColor, m_colStatisticInf);
	
}

//����û�ѡ�����ɫ
COLORREF CColorView::GetColorDiag()
{

	COLORREF color = RGB(255, 0, 0);      // ��ɫ�Ի���ĳ�ʼ��ɫΪ��ɫ  
	CColorDialog colorDlg(color);
	colorDlg.DoModal();
	return colorDlg.GetColor();
}

// ���ð�ť��ɫ
void CColorView::SetMFCButtonColor(CMFCButton & btn, COLORREF color)
{
	btn.SetFaceColor(color);//������ɫ
	btn.m_bTransparent = FALSE;//���ò�͸��
	btn.m_bDontUseWinXPTheme = TRUE;//���ò�����xp����
	btn.m_bDrawFocus = FALSE;//���þ۽���
	btn.SetFocus();
	btn.m_nFlatStyle = CMFCButton::BUTTONSTYLE_FLAT;//����Win10��ƽЧ��
	
}

BOOL CColorView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	// ����Ĭ����ɫ
	InitAttri();
	 // ���ð�ťĬ����ɫ
	 SetMFCButtonColor(m_series1Color, m_colSerie[0]);
	 SetMFCButtonColor(m_windowBGColor, m_colBKColor);
	 SetMFCButtonColor(m_graphBGColor, m_colGBKColor);
	 SetMFCButtonColor(m_infWinBGColor, m_colTBKColor);
	 SetMFCButtonColor(m_gridColor, m_colGridLineColor);
	 SetMFCButtonColor(m_coordinateColor, m_colCoorColor);
	 SetMFCButtonColor(m_cursorColor, m_colCursor1);
	 SetMFCButtonColor(m_cursorColor, m_colCursor2);
	 SetMFCButtonColor(m_scaleColor, m_colScale);
	 SetMFCButtonColor(m_xAxisColor, m_colXCoor);
	 SetMFCButtonColor(m_yAxisColor, m_colYCoor);
	 SetMFCButtonColor(m_statisticsInfColor, m_colStatisticInf);

	 
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CColorView::InitAttri()
{
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, INIFilePath);
	int length = 10;
	LPSTR lpstrTemp = new char[length];

	GetPrivateProfileString(m_color, "colSerie", "", lpstrTemp, length, lpPath);
	m_colSerie[0] = CommonUtil::CString2Long(lpstrTemp);					       // ������ɫ
	GetPrivateProfileString(m_color, "colBKColor", "", lpstrTemp, length, lpPath);
	m_colBKColor = CommonUtil::CString2Long(lpstrTemp);                   // ������ɫ
	GetPrivateProfileString(m_color, "colGBKColor", "", lpstrTemp, length, lpPath);
	m_colGBKColor = CommonUtil::CString2Long(lpstrTemp);                  // ͼ����������ɫ
	GetPrivateProfileString(m_color, "colTBKColor", "", lpstrTemp, length, lpPath);
	m_colTBKColor = CommonUtil::CString2Long(lpstrTemp);                  // ��Ϣ��������ɫ
	GetPrivateProfileString(m_color, "colGridLineColor", "", lpstrTemp, length, lpPath);
	m_colGridLineColor = CommonUtil::CString2Long(lpstrTemp);              // ��������ɫ
	GetPrivateProfileString(m_color, "colCoorColor", "", lpstrTemp, length, lpPath);
	m_colCoorColor = CommonUtil::CString2Long(lpstrTemp);                  // ��������ɫ
	GetPrivateProfileString(m_color, "colCursor1", "", lpstrTemp, length, lpPath);
	m_colCursor1 = CommonUtil::CString2Long(lpstrTemp);                    // ���1��ɫ
	GetPrivateProfileString(m_color, "colCursor1", "", lpstrTemp, length, lpPath);
	m_colCursor2 = CommonUtil::CString2Long(lpstrTemp);                    // ���2��ɫ
	GetPrivateProfileString(m_color, "colScale", "", lpstrTemp, length, lpPath);
	m_colScale = CommonUtil::CString2Long(lpstrTemp);						// �̶���ɫ
	GetPrivateProfileString(m_color, "colXCoor", "", lpstrTemp, length, lpPath);
	m_colXCoor = CommonUtil::CString2Long(lpstrTemp);						// X������ɫ
	GetPrivateProfileString(m_color, "colYCoor", "", lpstrTemp, length, lpPath);
	m_colYCoor = CommonUtil::CString2Long(lpstrTemp);					// Y������ɫ
	GetPrivateProfileString(m_color, "colStatisticInf", "", lpstrTemp, length, lpPath);
	m_colStatisticInf = CommonUtil::CString2Long(lpstrTemp);               // ͳ����Ϣ��ɫ
	delete[] lpPath;
	delete[] lpstrTemp;
}