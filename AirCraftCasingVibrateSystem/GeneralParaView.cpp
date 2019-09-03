// GeneralParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CGeneralParaView 对话框

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


// CGeneralParaView 消息处理程序
BOOL CGeneralParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GridCtrlInit();
	return TRUE;   
}

void CGeneralParaView::GridCtrlInit()
{
	/////如果当前已经打开了项目,则加载当前项目的所有传感器参数
	if (theApp.m_currentProject.GetProjectId() != 0){
		m_sensorParaController.FindALLSensorParaByProjectId(theApp.m_currentProject);
	}
	m_generalParaGridCtrl.SetEditable(false);
	m_generalParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_generalParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorParaVector().size()+1); //初始为n行
	m_generalParaGridCtrl.SetColumnCount(7); //初始化为7列
	m_generalParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_generalParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_generalParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_generalParaGridCtrl.ExpandColumnsToFit(true);
	m_generalParaGridCtrl.SetSingleRowSelection(true);
	//m_generalParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_generalParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_generalParaGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){	Item.strText.Format(_T("通道号"), 0);}
			if (col == 1){Item.strText.Format(_T("通道状态"), 1);}
			if (col == 2){Item.strText.Format(_T("通道描述"), 2);}
			if (col == 3){Item.strText.Format(_T("窗类型"), 3);}
			if (col == 4){ Item.strText.Format(_T("灵敏度"), 4); }
			if (col == 5){ Item.strText.Format(_T("输入方式"), 5); }
			if (col == 6){ Item.strText.Format(_T("量程"), 6); }
			m_generalParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText; 
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText =  theApp.m_currentProject.GetSensorParaVector()[row-1].GetSensorStatus().GetDictValue();
		if (col == 2) strText = theApp.m_currentProject.GetSensorParaVector()[row-1].GetSensorDesc();
		if (col == 3) strText = theApp.m_currentProject.GetSensorParaVector()[row - 1].GetWindowType().GetDictValue();
		if (col == 4) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorParaVector()[row - 1].GetSensitivity());
		if (col == 5) strText = theApp.m_currentProject.GetSensorParaVector()[row - 1].GetInputMethod().GetDictValue();
		if (col == 6) strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorParaVector()[row - 1].GetMileageRange());
				
		Item.strText.Format(_T(strText), row);

		m_generalParaGridCtrl.SetItem(&Item);
	}
}