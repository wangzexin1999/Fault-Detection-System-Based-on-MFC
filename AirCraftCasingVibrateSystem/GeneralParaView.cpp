// GeneralParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

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
	DDX_GridControl(pDX, IDC_GENERAPARA_GRIDCTRL, m_generalParaGridCtrl);
}

BEGIN_MESSAGE_MAP(CGeneralParaView, CDialogEx)

END_MESSAGE_MAP()


// CGeneralParaView ��Ϣ�������
BOOL CGeneralParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE;   
}
void CGeneralParaView::GridCtrlInit()
{
	/////�����ǰ�Ѿ�������Ŀ,����ص�ǰ��Ŀ�����д���������
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}
	m_generalParaGridCtrl.SetEditable(false);
	m_generalParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_generalParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorParaVector().size()+1); //��ʼΪn��
	m_generalParaGridCtrl.SetColumnCount(21); //��ʼ��Ϊ5��
	m_generalParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_generalParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_generalParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_generalParaGridCtrl.ExpandColumnsToFit(true);
	m_generalParaGridCtrl.SetSingleRowSelection(true);
	//m_generalParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_generalParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_generalParaGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){	Item.strText.Format(_T("ͨ����"), 0);}
			if (col == 1){Item.strText.Format(_T("ͨ��״̬"), 1);}
			if (col == 2){Item.strText.Format(_T("��������"), 2);}
			if (col == 3){Item.strText.Format(_T("ͨ������"), 3);}
			if (col == 4){Item.strText.Format(_T("������"), 4);}
			if (col == 5){ Item.strText.Format(_T("����"), 5); }
			if (col == 6){ Item.strText.Format(_T("�μӴ���"), 6); }
			if (col == 7){ Item.strText.Format(_T("��������"), 7); }
			if (col == 8){ Item.strText.Format(_T("��������"), 8); }
			if (col == 8){ Item.strText.Format(_T("��������"), 8); }
			if (col == 9){ Item.strText.Format(_T("����"), 9); }
			if (col == 10){ Item.strText.Format(_T("����ϵ"), 10); }
			if (col == 11){ Item.strText.Format(_T("����"), 11); }
			if (col == 12){ Item.strText.Format(_T("�ο���ʶ"), 12); }
			if (col == 13){ Item.strText.Format(_T("���̵�λ"), 13); }
			if (col == 14){ Item.strText.Format(_T("������"), 14); }
			if (col == 15){ Item.strText.Format(_T("��̷�Χ"), 15); }
			if (col == 16){ Item.strText.Format(_T("��������"), 16); }
			if (col == 17){ Item.strText.Format(_T("���ֵ�λ"), 17); }
			if (col == 18){ Item.strText.Format(_T("���뷽ʽ"), 18); }
			if (col == 19){ Item.strText.Format(_T("�����˲�"), 19); }
			if (col == 20){ Item.strText.Format(_T("����Ƶ��"), 20); }
			m_generalParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText =  theApp.m_currentProject.GetSensorParaVector()[row-1].GetSensorStatus().GetDictValue();
		if (col == 2) strText = theApp.m_currentProject.GetSensorParaVector()[row-1].GetMessureType().GetDictValue();
		if (col == 3) strText = theApp.m_currentProject.GetSensorParaVector()[row-1].GetSensorDesc();
		if (col == 4) strText = theApp.m_currentProject.GetSensorParaVector()[row - 1].GetWindowType().GetDictValue();
		if (col == 5) strText = "���ұ�����";
		//if (col == 6) strText = theApp.m_currentProject.GetSensorParaVector()[row - 1].get;

		
		Item.strText.Format(_T(strText), row);
		m_generalParaGridCtrl.SetItem(&Item);
	}
}