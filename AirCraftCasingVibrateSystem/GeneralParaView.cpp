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
	m_generalParaGridCtrl.SetColumnCount(21); //初始化为5列
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
			if (col == 2){Item.strText.Format(_T("测量类型"), 2);}
			if (col == 3){Item.strText.Format(_T("通道描述"), 3);}
			if (col == 4){Item.strText.Format(_T("窗类型"), 4);}
			if (col == 5){ Item.strText.Format(_T("窗宽"), 5); }
			if (col == 6){ Item.strText.Format(_T("参加触发"), 6); }
			if (col == 7){ Item.strText.Format(_T("触发量级"), 7); }
			if (col == 8){ Item.strText.Format(_T("触发极性"), 8); }
			if (col == 8){ Item.strText.Format(_T("触发极性"), 8); }
			if (col == 9){ Item.strText.Format(_T("测点号"), 9); }
			if (col == 10){ Item.strText.Format(_T("坐标系"), 10); }
			if (col == 11){ Item.strText.Format(_T("方向"), 11); }
			if (col == 12){ Item.strText.Format(_T("参考标识"), 12); }
			if (col == 13){ Item.strText.Format(_T("工程单位"), 13); }
			if (col == 14){ Item.strText.Format(_T("灵敏度"), 14); }
			if (col == 15){ Item.strText.Format(_T("里程范围"), 15); }
			if (col == 16){ Item.strText.Format(_T("积分类型"), 16); }
			if (col == 17){ Item.strText.Format(_T("积分单位"), 17); }
			if (col == 18){ Item.strText.Format(_T("输入方式"), 18); }
			if (col == 19){ Item.strText.Format(_T("抗混滤波"), 19); }
			if (col == 20){ Item.strText.Format(_T("上限频率"), 20); }
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
		if (col == 5) strText = "暂且保留了";
		//if (col == 6) strText = theApp.m_currentProject.GetSensorParaVector()[row - 1].get;

		
		Item.strText.Format(_T(strText), row);
		m_generalParaGridCtrl.SetItem(&Item);
	}
}