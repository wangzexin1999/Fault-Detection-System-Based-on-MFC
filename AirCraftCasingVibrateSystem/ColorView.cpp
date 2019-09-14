// ColorView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ColorView.h"
#include "afxdialogex.h"


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


// CColorView ��Ϣ�������

// ���ڱ���
void CColorView::OnBnClickedMfcbuttonWinBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colBKColor = GetColorDiag();
	SetMFCButtonColor(m_windowBGColor, colBKColor);
}

// ͼ�����򱳾�
void CColorView::OnBnClickedMfcbuttonGraphBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colGBKColor = GetColorDiag();
	SetMFCButtonColor(m_graphBGColor, colGBKColor);
}

// ��Ϣ������
void CColorView::OnBnClickedMfcbuttonInfBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colTBKColor = GetColorDiag();
	SetMFCButtonColor(m_infWinBGColor, colTBKColor);
}

// ����1
void CColorView::OnBnClickedMfcbuttonSeris1Bg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colSerie[0] = GetColorDiag();
	SetMFCButtonColor(m_series1Color, colSerie[0]);
}

// ����2
void CColorView::OnBnClickedMfcbuttonSeris2Bg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colSerie[1] = GetColorDiag();
	SetMFCButtonColor(m_series2Color, colSerie[1]);
}

// ����3
void CColorView::OnBnClickedMfcbuttonSeris33Bg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colSerie[2] = GetColorDiag();
	SetMFCButtonColor(m_series3Color, colSerie[2]);
}

// ����4
void CColorView::OnBnClickedMfcbuttonSeris4Bg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colSerie[3] = GetColorDiag();
	SetMFCButtonColor(m_series4Color, colSerie[3]);
}

// ����
void CColorView::OnBnClickedMfcbuttonGridBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colGridLineColor = GetColorDiag();
	SetMFCButtonColor(m_gridColor, colGridLineColor);
}

// ����
void CColorView::OnBnClickedMfcbuttonCoorBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colCoorColor = GetColorDiag();
	SetMFCButtonColor(m_coordinateColor, colCoorColor);
}

//�̶�
void CColorView::OnBnClickedMfcbuttonScaleBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colScale = GetColorDiag();
	SetMFCButtonColor(m_scaleColor, colScale);
}

//���
void CColorView::OnBnClickedMfcbuttonCurlorBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colCursor1 = GetColorDiag();
	SetMFCButtonColor(m_cursorColor, colCursor1);
}

//X��
void CColorView::OnBnClickedMfcbuttonXBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colXCoor= GetColorDiag();
	SetMFCButtonColor(m_xAxisColor, colBKColor);
}

//Y��
void CColorView::OnBnClickedMfcbuttonYBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colYCoor = GetColorDiag();
	SetMFCButtonColor(m_yAxisColor, colYCoor);
}

// ͳ����Ϣ
void CColorView::OnBnClickedMfcbuttonStatiscBg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	colStatisticInf = GetColorDiag();
	SetMFCButtonColor(m_statisticsInfColor, colStatisticInf);
	
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_statisticsInfColor.m_bDrawFocus = FALSE;
	m_statisticsInfColor.m_bHighlightChecked = FALSE;
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
