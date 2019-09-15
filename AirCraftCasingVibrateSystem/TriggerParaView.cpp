// TriggerParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "TriggerParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

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
	DDX_Control(pDX, IDC_TRIGGERPARA_GRID, m_triggerParaGridCtrl);
}


BEGIN_MESSAGE_MAP(CTriggerParaView, CDialogEx)
END_MESSAGE_MAP()


// CTriggerParaView ��Ϣ�������


BOOL CTriggerParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GridCtrlInit();
	return TRUE;
}

void CTriggerParaView::GridCtrlInit()
{
	/////�����ǰ�Ѿ�������Ŀ,����ص�ǰ��Ŀ�����д���������
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}

	m_triggerParaGridCtrl.SetEditable(false);
	m_triggerParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_triggerParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //��ʼΪn��
	m_triggerParaGridCtrl.SetColumnCount(4); //��ʼ��Ϊ7��
	m_triggerParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_triggerParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_triggerParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_triggerParaGridCtrl.ExpandColumnsToFit(true);
	m_triggerParaGridCtrl.SetSingleRowSelection(true);
	//m_triggerParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_triggerParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_triggerParaGridCtrl.GetColumnCount(); col++)
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
			m_triggerParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = "����";
		if (col == 2) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerMagnitude());
		if (col == 3) strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerPolarity().GetDictValue();
		
		Item.strText=strText;
		m_triggerParaGridCtrl.SetItem(&Item);
	}
}
