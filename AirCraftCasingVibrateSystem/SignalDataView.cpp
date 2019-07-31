// SignalDataView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalDataView.h"
#include "afxdialogex.h"


// CSignalDataView 对话框

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


// CSignalDataView 消息处理程序


BOOL CSignalDataView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	///查询数据文件表格数据


	///初始化表格控件
	GridCtrlInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
void CSignalDataView::GridCtrlInit(){
	
	m_signalDataGridCtrl.SetEditable(false);
	m_signalDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_signalDataGridCtrl.SetRowCount(6); //初始为n行
	m_signalDataGridCtrl.SetColumnCount(5); //初始化为5列
	m_signalDataGridCtrl.SetFixedRowCount(1); //表头为一行
	m_signalDataGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_signalDataGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_signalDataGridCtrl.ExpandColumnsToFit(true);
	m_signalDataGridCtrl.SetSingleRowSelection(true);

	for (int row = 0; row < m_signalDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_signalDataGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		if (row == 0 && col == 0) //第(0，0)格
		{
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			Item.strText.Format(_T("报表显示"), col);
		}
		else if (row < 1) //设置0行表头显示
		{
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			Item.strText.Format(_T(" 项目%d"), col);
		}
		else if (col < 1) //设置0列表头显示
		{
			if (row < m_signalDataGridCtrl.GetRowCount())
			{
				Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
				Item.strText.Format(_T("第%d次"), row);
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