// NewProjectView.cpp : 实现文件
//

#include "stdafx.h"

#include "AirCraftCasingVibrateSystem.h"

#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
#include "Result.h"
#include "DateUtil.h"
// CNewProjectView 对话框

IMPLEMENT_DYNAMIC(CNewProjectView, CDialogEx)

CNewProjectView::CNewProjectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewProjectView::IDD, pParent)
{
	
}

CNewProjectView::~CNewProjectView()
{

}

void CNewProjectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PROJECTOPERATORLIST_TREE, m_projectOperatorTreeCtrl);
	DDX_Control(pDX, IDC_TAB_PROJECTNAVIGATION, m_projectNavigationTab);
}


BEGIN_MESSAGE_MAP(CNewProjectView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewProjectView::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PROJECTNAVIGATION, &CNewProjectView::OnTcnSelchangeTabProjectnavigation)
	ON_BN_CLICKED(IDC_BUTTON_LASTSTEP, &CNewProjectView::OnBnClickedButtonLaststep)
	ON_BN_CLICKED(IDC_BUTTON_NEXTSTEP, &CNewProjectView::OnBnClickedButtonNextstep)
END_MESSAGE_MAP()


// CNewProjectView 消息处理程序
/*新建项目按钮*/
void CNewProjectView::OnBnClickedOk()
{
	/*CString projectName;
	m_projectNameEdit.GetWindowTextA(projectName);
	if (projectName == ""){ AfxMessageBox("项目名不能为空"); return;}
	int detectedIndex = m_productCombo.GetCurSel();

	if (detectedIndex > 0) {
	detectedIndex--;
	}
	else{
	AfxMessageBox("请选择产品");
	return;
	}
	TbTester tester = theApp.m_currentProject.GetTester();

	TbProduct product;
	product.SetProductId(m_productVector[detectedIndex].GetProductId());

	TbProject project;
	project.SetProjectName(projectName);
	project.SetProduct(product);
	project.SetTester(tester);
	project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());

	project.GetTestingDevicePara().GetTestingdevice().SetTestingdeviceId(1);
	Result res = m_projectController.AddProject(project);

	if (!res.GetIsSuccess()){
	AfxMessageBox(res.GetMessages());
	}
	else{
	AfxMessageBox(res.GetMessages());
	CDialogEx::OnOK();
	}*/
}

BOOL CNewProjectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	///创建tab窗口
	// TODO:  在此添加额外的初始化
	m_projectNavigationTab.InsertItem(0, _T("基本信息"));
	m_projectNavigationTab.InsertItem(1, _T("采集设置"));
	m_projectNavigationTab.InsertItem(2, _T("通道设置"));
	m_projectNavigationTab.InsertItem(3, _T("平稳采集状态参数设置"));
	//创建通道参数显示的试图  
	m_baseProjectInfoView.Create(IDD_PROJECTBASEINFO_DIALOG, &m_projectNavigationTab);
	m_collectionParaPresetView.Create(IDD_DIALOG_COLLECTIONPARAPRESET, &m_projectNavigationTab);
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNELPARAPRESET, &m_projectNavigationTab);
	m_stableStatusParaPresetView.Create(IDD_DIALOG_STABLESTATUSPRESET, &m_projectNavigationTab);
	//设定在Tab内显示的范围  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	//m_tabSystemPara.MoveWindow(tabRect);
	m_baseProjectInfoView.MoveWindow(&tabRect);
	m_collectionParaPresetView.MoveWindow(&tabRect);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_stableStatusParaPresetView.MoveWindow(&tabRect);

	//把对话框对象指针保存起来
	m_pDialogVec.push_back(&m_baseProjectInfoView);
	m_pDialogVec.push_back(&m_collectionParaPresetView);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_pDialogVec.push_back(&m_stableStatusParaPresetView);
	//显示初始页面  
	m_baseProjectInfoView.ShowWindow(SW_SHOW);
	m_collectionParaPresetView.ShowWindow(SW_HIDE);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	m_stableStatusParaPresetView.ShowWindow(SW_HIDE);
	//当前选择的tab的索引
	m_icurSelTabIndex = 0;

	////初始化树形控件
	//InitProjectOperatorTree();
	////初始化表格控件

	//GridCtrlInit();
	
	/*2.调用ProjectController去查询产品的下拉列表的数据*/
	Result res = m_projectController.LoadAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		int i = 0;
	/*	m_productCombo.InsertString(i,"暂不选择2");
		for (auto product : m_productVector){
			m_productCombo.InsertString(++i,product.GetProductType());
		}
		m_productCombo.SetCurSel(0);*/
	}
	else
	{
		AfxMessageBox(res.GetMessages());
	}
	return TRUE;  
}

void CNewProjectView::InitProjectOperatorTree(){
	m_projectOperatorTreeCtrl.DeleteAllItems();

	// 树的根节点的句柄   
	HBITMAP hDirBmp;
	hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	m_projectOperatorTreeCtrl.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);
	CFont font;
	font.CreatePointFont(100, _T("Book Antiqua"));

	m_projectOperatorTreeCtrl.SetFont(&font);
	m_projectOperatorTreeCtrl.SetFocus();
	m_projectOperatorTreeCtrl.SetBkColor(RGB(255, 255, 255));

	HTREEITEM hCurrent;
	HTREEITEM childItem;
	HBITMAP childBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(IDB_BMPSIGNALGREEN));
	
	hCurrent = m_projectOperatorTreeCtrl.InsertItem(_T("通道选择"), TVI_ROOT, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);

	hCurrent = m_projectOperatorTreeCtrl.InsertItem(_T("转速"), TVI_ROOT, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);

	/*childItem = m_projectOperatorTreeCtrl.InsertItem(_T("转速"), hCurrent, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(childItem, childBmp, ppLastLeft);*/

}
void CNewProjectView::GridCtrlInit(){
	m_projectOperatorDataGridCtrl.SetEditable(false);
	m_projectOperatorDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_projectOperatorDataGridCtrl.SetRowCount(8); //初始为n行
	m_projectOperatorDataGridCtrl.SetColumnCount(3); //初始化为5列
	m_projectOperatorDataGridCtrl.SetFixedRowCount(1); //表头为一行
	m_projectOperatorDataGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_projectOperatorDataGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_projectOperatorDataGridCtrl.ExpandColumnsToFit(true);
	m_projectOperatorDataGridCtrl.SetSingleRowSelection(true);
	for (int row = 0; row < m_projectOperatorDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_projectOperatorDataGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		if (row == 0 ) //第(0，0)格
		{
			if (col == 0){
				Item.strText.Format(_T("转速序号"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("转速值"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("备注"), 2);
			}
		}

		else if (col < 1) //设置0列表头显示
		{
			if (row < m_projectOperatorDataGridCtrl.GetRowCount())
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
		m_projectOperatorDataGridCtrl.SetItem(&Item);
	}
}

void CNewProjectView::OnTcnSelchangeTabProjectnavigation(NMHDR *pNMHDR, LRESULT *pResult)
{
	//把当前的页面隐藏起来
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_icurSelTabIndex = m_projectNavigationTab.GetCurSel();
	//把新的页面显示出来
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


////上一步
void CNewProjectView::OnBnClickedButtonLaststep()
{
	///判断是否越界
	if (m_icurSelTabIndex == 0) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex--;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}

////下一步
void CNewProjectView::OnBnClickedButtonNextstep()
{
	///判断是否越界
	if (m_icurSelTabIndex == m_pDialogVec.size()-1) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex++;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}
