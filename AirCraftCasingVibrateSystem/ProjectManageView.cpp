#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProjectManageView.h"
#include "afxdialogex.h"


// CProjectManageView 对话框

IMPLEMENT_DYNAMIC(CProjectManageView, CDialogEx)

CProjectManageView::CProjectManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProjectManageView::IDD, pParent)
	
{

}

CProjectManageView::~CProjectManageView()
{

}

void CProjectManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GRIDCTRL_PROJECT, m_projectGrid);
	DDX_Control(pDX, IDC_EDIT_PROSEARCHNAME, m_proSearchNameEdit);
	DDX_Control(pDX, IDC_DATESEARCH_CHECKBOX, m_dateSelectCheckBox);
	DDX_Control(pDX, IDC_PROSTARTTIME, m_proStartTimeCtrl);
	DDX_Control(pDX, IDC_PROENDTIME, m_proEndTimeCtrl);
}


BEGIN_MESSAGE_MAP(CProjectManageView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CProjectManageView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SEARCHBUTTON, &CProjectManageView::OnBnClickedSearchbutton)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_PROJECT, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_PROJECT, OnGridClick)
END_MESSAGE_MAP()


// CProjectManageView 消息处理程序
void CProjectManageView::GridCtrlInit(){

	m_projectGrid.SetEditable(false);
	m_projectGrid.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_projectGrid.SetRowCount(m_projectVector.size()+1); //初始为n行
	m_projectGrid.SetColumnCount(5); //初始化为5列
	m_projectGrid.SetFixedRowCount(1); //表头为一行
	m_projectGrid.SetRowResize(TRUE); ///自动设置行和列的大小
	m_projectGrid.SetListMode(true); ////在选定一个单元格时，选择整行
	m_projectGrid.ExpandColumnsToFit(true);
	m_projectGrid.SetSingleRowSelection(true);
	//m_projectGrid.OnGridClick();
	for (int row = 0; row < m_projectGrid.GetRowCount(); row++)
	for (int col = 0; col < m_projectGrid.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;

		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			if (col==0){
				Item.strText.Format(_T("项目序号"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("项目名称"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("项目创建时间"), 2);
			}
			if (col == 3){
				Item.strText.Format(_T("检测设备"), 3);
			}
			if (col == 4){
				Item.strText.Format(_T("被检测设备"), 4);
			}
			m_projectGrid.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(m_projectVector[row - 1].GetProjectId());
		if (col == 1) strText = m_projectVector[row - 1].GetProjectName();
		if (col == 2) strText = m_projectVector[row - 1].GetProjectCreateTime();
		if (col == 3) strText = m_projectVector[row - 1].GetTestingDevicePara().GetTestingdevice().GetTestingdeviceIp();
		if (col == 4) strText = m_projectVector[row - 1].GetDetectedDevice().GetDetecteddeviceName();
		Item.strText.Format(_T(strText), row);
		m_projectGrid.SetItem(&Item);  

	}

}


BOOL CProjectManageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	////初始化日期控件
	m_proStartTimeCtrl.SetFormat(_T("yyyy'- 'MM'- 'dd"));
	m_proEndTimeCtrl.SetFormat(_T("yyyy'- 'MM'- 'dd"));
	///初始化开始日期控件时间为一周之前
	CTime aWeekAgo = DateUtil::GetAWeekAgoDate();
	m_proStartTimeCtrl.SetTime(&aWeekAgo);

	int testerId = theApp.m_currentProject.GetTester().GetTesterId();
	
	Result res = m_projectController.LoadAllProjectBySearchCondition(testerId, "", "", "", m_projectVector);
	if (res.GetIsSuccess()){
		TRACE("\n项目个数为:%d\n", m_projectVector.size());
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
		return FALSE;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

///打开项目按钮
void CProjectManageView::OnBnClickedOk()
{
	if (MessageBox("是否打开项目 " + m_selectedProject.GetProjectName(), "打开项目", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////将选择的项目赋给全局project对象。
	theApp.m_currentProject = m_selectedProject;
	
	AfxMessageBox("项目加载成功");
	CDialogEx::OnOK();
}

///搜索按钮
void CProjectManageView::OnBnClickedSearchbutton()
{
	///1.获取查询的项目名
	CString proSearchName;
	m_proSearchNameEdit.GetWindowTextA(proSearchName);
	
	///2.获取项目查询  开始时间和结束时间
	
	CTime ctStartTime, ctEndTime;
	m_proStartTimeCtrl.GetTime(ctStartTime);
	m_proEndTimeCtrl.GetTime(ctEndTime);
	CString proStartTime = "";
	CString proEndTime  = "";

	if (m_dateSelectCheckBox.GetCheck()){
		///选择了使用查询时间时，给起始时间和终止时间赋值
		proStartTime = DateUtil::GetCStringTimeFormCTime(ctStartTime);
		proEndTime = DateUtil::GetCStringTimeFormCTime(ctEndTime);
	}
	////清空项目集合
	m_projectVector.clear();
	int testerId = theApp.m_currentProject.GetTester().GetTesterId();
	Result res = m_projectController.LoadAllProjectBySearchCondition(testerId, proSearchName, proStartTime, proEndTime, m_projectVector);
	if (res.GetIsSuccess()){
		TRACE("\n项目个数为:%d\n", m_projectVector.size());
		GridCtrlInit();
	}
	else{
		AfxMessageBox(res.GetMessages());
	}
}

///项目的双击事件--》打开新项目
void CProjectManageView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{

	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_projectVector.size()) return;
	TbProject g_project = m_projectVector.at(pItem->iRow -1);
	if (MessageBox("是否打开项目 " + g_project.GetProjectName(), "打开项目", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	////将选择的项目赋给全局project对象。
	theApp.m_currentProject = g_project;
//	AfxMessageBox("项目加载成功");
	///关闭窗口
	CDialogEx::OnOK();
}
void CProjectManageView::OnGridClick(NMHDR *pNotifyStruct, LRESULT * /*pResult*/ )
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_projectVector.size()) return;
	m_selectedProject = m_projectVector.at(pItem->iRow - 1);
}
