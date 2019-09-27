// StateSetDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StateSetDialog.h"
#include "afxdialogex.h"


// CStateSetDialog 对话框

IMPLEMENT_DYNAMIC(CStateSetDialog, CDialogEx)

CStateSetDialog::CStateSetDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStateSetDialog::IDD, pParent)
{

}

CStateSetDialog::~CStateSetDialog()
{
}

void CStateSetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_COLLECTIONPLANGRID, m_collectionPlanGrid);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONPLAN, m_collectionPlanCombo);
}


BEGIN_MESSAGE_MAP(CStateSetDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONPLAN, &CStateSetDialog::OnCbnSelchangeComboCollectionplan)
END_MESSAGE_MAP()


// CStateSetDialog 消息处理程序


void CStateSetDialog::OnCbnSelchangeComboCollectionplan()
{

}

BOOL CStateSetDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	RefreshView();
	return TRUE; 
}
void CStateSetDialog::GridCtrlInit()
{
	///得到当前选中的采集计划序号
	int selectedIndex = m_collectionPlanCombo.GetCurSel();
	if (selectedIndex < 0) return;
	///根据选择的采集计划序号解析相应的采集计划对象
	Value  doc;
	doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
	const Value & colectionPlans = doc["collectionPlans"].GetArray();

	///拿到采集计划的标题信息 
	const Value & planTitle = colectionPlans[selectedIndex]["planParaTitle"];
	///拿到采集计划的参数信息
	const Value & planParaContent = colectionPlans[selectedIndex]["planParaContent"];
	m_collectionPlanGrid.SetEditable(true);
	// 2. 获得信息
	m_collectionPlanGrid.SetEditable(true);
	m_collectionPlanGrid.SetEditable(true);
	m_collectionPlanGrid.SetEditable(false);
	m_collectionPlanGrid.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_collectionPlanGrid.SetRowCount(planParaContent.Size() + 1); //初始为n行
	m_collectionPlanGrid.SetColumnCount(planTitle.Size()); //初始化为3列
	m_collectionPlanGrid.SetFixedRowCount(1); //表头为一行
	m_collectionPlanGrid.SetRowResize(TRUE); ///自动设置行和列的大小
	m_collectionPlanGrid.SetColumnResize(TRUE);
	m_collectionPlanGrid.SetListMode(true); ////在选定一个单元格时，选择整行
	m_collectionPlanGrid.ExpandColumnsToFit(true);

	m_collectionPlanGrid.SetSingleRowSelection(true);
	//m_collectionPlanGrid.OnGridClick();
	for (int row = 0; row < m_collectionPlanGrid.GetRowCount(); row++){
		for (int col = 0; col < m_collectionPlanGrid.GetColumnCount(); col++)
		{
			//设置表格显示属性
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			///设置表头内容
			if (row == 0){
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(planTitle[col].GetString()));
				m_collectionPlanGrid.SetItem(&Item);
				continue;
			}

			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

			CString strText = planParaContent[row-1][col].GetString();
			Item.strText = strText;
			m_collectionPlanGrid.SetItem(&Item);
		}
	}
}
void  CStateSetDialog::ComboBoxInit(){
	///解析项目对象的
	Value  doc;
	doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
	const Value & colectionPlans = doc["collectionPlans"].GetArray();

	for (int i = 0; i < colectionPlans.Size(); i++){
		string planName = colectionPlans[i]["planName"].GetString();
		m_collectionPlanCombo.InsertString(i, planName.c_str());
	}
	m_collectionPlanCombo.SetCurSel(0);
}

void CStateSetDialog::RefreshView(){
	if (theApp.m_currentProject.GetCollectionPlans() != ""){
		m_collectionPlanDoc.Parse(theApp.m_currentProject.GetCollectionPlans());
		ComboBoxInit();
		GridCtrlInit();
	}
}