// GeometricParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeometricParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CGeometricParaView �Ի���

IMPLEMENT_DYNAMIC(CGeometricParaView, CDialogEx)

CGeometricParaView::CGeometricParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeometricParaView::IDD, pParent)
{

}

CGeometricParaView::~CGeometricParaView()
{
}

void CGeometricParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GEOMETRICPARA_GRIDCTRL, m_geometricParaGridCtrl);
}


BEGIN_MESSAGE_MAP(CGeometricParaView, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_GEOMETRICPARA_GRIDCTRL, OnGridDblClick)
END_MESSAGE_MAP()

// CGeometricParaView ��Ϣ�������


BOOL CGeometricParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GridCtrlInit();
	return TRUE;  
}


void CGeometricParaView::GridCtrlInit()
{
	/////�����ǰ�Ѿ�������Ŀ,����ص�ǰ��Ŀ�����д���������
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}

	m_geometricParaGridCtrl.SetEditable(false);
	m_geometricParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_geometricParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //��ʼΪn��
	m_geometricParaGridCtrl.SetColumnCount(4); //��ʼ��Ϊ7��
	m_geometricParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_geometricParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_geometricParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_geometricParaGridCtrl.ExpandColumnsToFit(true);
	m_geometricParaGridCtrl.SetSingleRowSelection(true);
	//m_geometricParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_geometricParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_geometricParaGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("ͨ����"), 0); }
			if (col == 1){ Item.strText.Format(_T("�μӴ���"), 1); }
			if (col == 2){ Item.strText.Format(_T("��������"), 2); }
			if (col == 3){ Item.strText.Format(_T("��������"), 3); }
			m_geometricParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		//if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 0)
		{
			strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetChannelId();
			m_geometricParaGridCtrl.SetItemState(row, col, GVIS_READONLY);
		}
		if (col == 1) strText = "����";
		if (col == 2) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerMagnitude());
		if (col == 3) strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerPolarity().GetDictValue();

		Item.strText=strText;
		m_geometricParaGridCtrl.SetItem(&Item);
	}
}
void CGeometricParaView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){

	m_geometricParaGridCtrl.SetEditable(TRUE);

}