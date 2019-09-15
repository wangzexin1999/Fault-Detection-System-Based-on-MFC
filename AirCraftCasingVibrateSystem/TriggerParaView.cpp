// TriggerParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "TriggerParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CTriggerParaView 对话框

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


// CTriggerParaView 消息处理程序


BOOL CTriggerParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GridCtrlInit();
	return TRUE;
}

void CTriggerParaView::GridCtrlInit()
{
	/////如果当前已经打开了项目,则加载当前项目的所有传感器参数
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}

	m_triggerParaGridCtrl.SetEditable(false);
	m_triggerParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_triggerParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //初始为n行
	m_triggerParaGridCtrl.SetColumnCount(4); //初始化为7列
	m_triggerParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_triggerParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_triggerParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_triggerParaGridCtrl.ExpandColumnsToFit(true);
	m_triggerParaGridCtrl.SetSingleRowSelection(true);
	//m_triggerParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_triggerParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_triggerParaGridCtrl.GetColumnCount(); col++)
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
			m_triggerParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = "保留";
		if (col == 2) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerMagnitude());
		if (col == 3) strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetTriggerPolarity().GetDictValue();
		
		Item.strText=strText;
		m_triggerParaGridCtrl.SetItem(&Item);
	}
}
