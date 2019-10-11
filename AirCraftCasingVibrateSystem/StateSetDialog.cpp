// StateSetDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StateSetDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Constant.h"
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
	DDX_Control(pDX, IDC_STATIC_CUR_PLAN_PARA, m_staticCurrentPlanPara);
}

BEGIN_MESSAGE_MAP(CStateSetDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONPLAN, &CStateSetDialog::OnCbnSelchangeComboCollectionplan)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_COLLECTIONPLANGRID, OnGridDblClick)
END_MESSAGE_MAP()

// CStateSetDialog 消息处理程序
void CStateSetDialog::OnCbnSelchangeComboCollectionplan()
{
	GridCtrlInit();
}

BOOL CStateSetDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	RefreshView();
	/*设置文本内容*/
	CString strPlanName;
	m_collectionPlanCombo.GetWindowTextA(strPlanName);
	int selectedIndex = m_collectionPlanCombo.GetCurSel();
	///根据选择的采集计划序号解析相应的采集计划对象
	if (!m_collectionPlanDoc.IsNull()){
		Value  doc;
		doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
		const Value & colectionPlans = doc["collectionPlans"].GetArray();
		///拿到采集计划的标题信息 
		const Value & planTitle = colectionPlans[selectedIndex]["planParaTitle"];
		m_staticCurrentPlanPara.SetWindowTextA(strPlanName+"--参数：");
	}

	return TRUE; 
}
void CStateSetDialog::GridCtrlInit()
{
	///删除所有的列表项
	m_collectionPlanGrid.DeleteAllItems();
	m_collectionPlanGrid.Refresh();
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
	if (m_collectionPlanDoc.IsNull())return;
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
	///1.解析项目表记录的json数据
	m_collectionPlanDoc.Parse(theApp.m_currentProject.GetCollectionPlans());
	if (m_collectionPlanDoc.HasParseError()){
		AfxMessageBox("采集计划加载失败");
		return;
	}
	///2.清空下拉列表的显示
	m_collectionPlanCombo.ResetContent();
	///3.重新初始化下拉框
	ComboBoxInit();
	///4.重新初始化显示列表
	GridCtrlInit();
}

HBRUSH CStateSetDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CUR_PLAN_PARA)
	{
		//设置显示字体

		CFont * cFont = new CFont;

		cFont->CreateFont(16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, 0,ANSI_CHARSET, 
			OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH&FF_SWISS, "黑体");
		pDC->SetTextColor(RGB(255, 0, 0));
		pWnd->SetFont(cFont); //设置字体
		delete cFont;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CStateSetDialog::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;


	CString strPlanName;
	m_collectionPlanCombo.GetWindowTextA(strPlanName);
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
	CString currentPlanPara = planParaContent[pItem->iRow - 1][0].GetString();


	m_staticCurrentPlanPara.SetWindowTextA(strPlanName + "--参数：" + planTitle[0].GetString() + ":" + currentPlanPara);
	theApp.m_collectionRotatingSpeed = currentPlanPara;
	CMainFrame *mainFram = (CMainFrame *)AfxGetMainWnd();
	mainFram->SendMessage(WM_SETTEXT);
	mainFram->SendMessage(StatusInfMessage);
}