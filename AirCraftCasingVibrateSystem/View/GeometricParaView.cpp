// GeometricParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeometricParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CGeometricParaView 对话框

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

// CGeometricParaView 消息处理程序


BOOL CGeometricParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GridCtrlInit();
	return TRUE;  
}


void CGeometricParaView::GridCtrlInit()
{
	/////如果当前已经打开了项目,则加载当前项目的所有传感器参数
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}

	m_geometricParaGridCtrl.SetEditable(false);
	m_geometricParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_geometricParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //初始为n行
	m_geometricParaGridCtrl.SetColumnCount(4); //初始化为7列
	m_geometricParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_geometricParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_geometricParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_geometricParaGridCtrl.ExpandColumnsToFit(true);
	m_geometricParaGridCtrl.SetSingleRowSelection(true);
	//m_geometricParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_geometricParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_geometricParaGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("通道号"), 0); }
			if (col == 1){ Item.strText.Format(_T("参加触发"), 1); }
			if (col == 2){ Item.strText.Format(_T("触发量级"), 2); }
			if (col == 3){ Item.strText.Format(_T("触发极性"), 3); }
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
		if (col == 1) strText = "保留";
		if (col == 2) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerMagnitude());
		if (col == 3) strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerPolarity().GetDictValue();

		Item.strText=strText;
		m_geometricParaGridCtrl.SetItem(&Item);
	}
}
void CGeometricParaView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){

	m_geometricParaGridCtrl.SetEditable(TRUE);

}