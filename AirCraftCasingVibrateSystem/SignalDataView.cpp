// SignalDataView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView �Ի���

IMPLEMENT_DYNAMIC(CSignalDataView, CDialogEx)

CSignalDataView::CSignalDataView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalDataView::IDD, pParent)
{

}

CSignalDataView::~CSignalDataView()
{
}

void CSignalDataView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_SIGNALDATA_GRIDCTRL, m_signalDataGridCtrl);
	DDX_Control(pDX, IDC_SIGNALDATANAME_EDIT, m_singnalDataNameCtrl);
	DDX_Control(pDX, IDC_SIGNALDATASTARTTIME, m_signalDataStartTimeCtrl);
	DDX_Control(pDX, IDC_SIGNALDATAENDTIME, m_signalDataEndTimeCtrl);
}


BEGIN_MESSAGE_MAP(CSignalDataView, CDialogEx)

	//ON_NOTIFY(NM_DBLCLK, IDC_SIGNALDATA_GRIDCTRL, OnGridDblClick)
END_MESSAGE_MAP()


// CSignalDataView ��Ϣ�������


BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	///��ѯ�����ļ��������


	///��ʼ�����ؼ�
	GridCtrlInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
void CSignalDataView::GridCtrlInit(){
	
	m_signalDataGridCtrl.SetEditable(false);
	m_signalDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_signalDataGridCtrl.SetRowCount(6); //��ʼΪn��
	m_signalDataGridCtrl.SetColumnCount(5); //��ʼ��Ϊ5��
	m_signalDataGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_signalDataGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_signalDataGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_signalDataGridCtrl.ExpandColumnsToFit(true);
	m_signalDataGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_signalDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		if (row == 0 && col == 0) //��(0��0)��
		{
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			Item.strText.Format(_T("������ʾ"), col);
		}
		else if (row < 1) //����0�б�ͷ��ʾ
		{
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			Item.strText.Format(_T(" ��Ŀ%d"), col);
		}
		else if (col < 1) //����0�б�ͷ��ʾ
		{
			if (row < m_signalDataGridCtrl.GetRowCount())
			{
				Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
				Item.strText.Format(_T("��%d��"), row);
			}
		}
		else
		{
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			Item.strText.Format(_T(""), 2);
		}
		m_signalDataGridCtrl.SetItem(&Item);
	}
}