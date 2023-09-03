// NewProjectView.cpp : 实现文件
#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbUser.h"
#include "Result.h"
#include "DateUtil.h"
#include "TbDictionary.h"
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
	DDX_Control(pDX, IDC_TAB_PROJECT_NAVIGATION, m_projectNavigationTab);
}


BEGIN_MESSAGE_MAP(CNewProjectView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewProjectView::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PROJECT_NAVIGATION, &CNewProjectView::OnTcnSelchangeTabProjectnavigation)
	ON_BN_CLICKED(IDC_BUTTON_LASTSTEP, &CNewProjectView::OnBnClickedButtonLaststep)
	ON_BN_CLICKED(IDC_BUTTON_NEXTSTEP, &CNewProjectView::OnBnClickedButtonNextstep)
END_MESSAGE_MAP()


// CNewProjectView 消息处理程序
/*新建项目按钮*/
void CNewProjectView::OnBnClickedOk()
{
	// 得到当前检测设备的参数
	m_collectionParaPresetView.GetSelectedCollectionparas(m_collectionparas);
	// 得到所有的通道
	m_vchannels.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vchannels);
	///封装project对象
	TbUser user = theApp.m_currentProject.GetUser();
	m_project.SetUser(user);
	m_project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetCollectionparas(m_collectionparas);
	m_project.SetChannelVector(m_vchannels);
	if (m_vchannels.size() < 4){
		MessageBox(TEXT("通道数量不匹配！"), TEXT("提示"), MB_YESNO);
		return;
	}	///保存项目数据
	Result res = m_projectController.AddProject(m_project);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		CDialogEx::OnCancel();
	}
	else{
		///加载当前项目
		theApp.m_currentProject = m_project;
		AfxMessageBox(res.GetMessages());
		CDialogEx::OnOK();
	}
}

BOOL CNewProjectView::OnInitDialog()
{
	//弹出基本信息选择框
	int res = m_baseProjectInfoView.DoModal();
	if (res != IDOK){
		///如果没有点击确定按钮，则直接退出程序
		this->OnCancel();
		return FALSE;
	}
	CDialogEx::OnInitDialog();
	///得到用户选择的计划信息
	m_baseProjectInfoView.GetProjectBaseInfo(m_project);
	////创建基本的窗口信息

	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	m_projectNavigationTab.InsertItem(0, _T("采集设置"));
	m_collectionParaPresetView.Create(IDD_DIALOG_COLLECTIONPARAPRESET, &m_projectNavigationTab);
	m_collectionParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_collectionParaPresetView);
	m_collectionParaPresetView.ShowWindow(SW_SHOW);

	m_projectNavigationTab.InsertItem(1, _T("通道设置"));
	m_channelParaPresetView.SetProductId(m_project.GetProduct().GetProductId());
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	
	////记录动态创建的对话框的起始索引值
	m_newDialogIndex = m_projectNavigationTab.GetItemCount();
	int count = m_newDialogIndex;
	
	//设置当前选择的tab的索引
	m_icurSelTabIndex = 0;

	// 对话框屏幕居中
	ShowWindow(SW_NORMAL);
	CRect rtDesk;
	CRect rtDlg;
	::GetWindowRect(::GetDesktopWindow(), &rtDesk);
	GetWindowRect(&rtDlg);
	int iXpos = rtDesk.Width() / 2 - rtDlg.Width() / 2;
	int iYpos = rtDesk.Height() / 2 - rtDlg.Height() / 2;
	SetWindowPos(NULL, iXpos, iYpos, 0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER);
	return TRUE;  
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
	m_project;
	if (m_icurSelTabIndex == 0) {
		// 得到当前检测设备的参数
		((ChannelParaPresetView *)m_pDialogVec[m_icurSelTabIndex])->SetProductId(m_project.GetProduct().GetProductId());
	}

	//if (m_icurSelTabIndex == 1) {
	//	// 得到所有的通道
	//	m_channelParaPresetView.GetSelectedChannels(m_vsensors);
	//}
	//if (m_icurSelTabIndex >= m_newDialogIndex) {
	//	// 采集计划窗口点击下一步时，对相应的采集计划对象操作
	//	CollectionPlanParaPresetView* collectionPlanPresetView = dynamic_cast<CollectionPlanParaPresetView*>(m_pDialogVec[m_icurSelTabIndex]);
	//	if (collectionPlanPresetView != NULL){
	//		collectionPlanPresetView->GetCollectionPlan(m_collectionPlans[m_icurSelTabIndex - m_newDialogIndex]);
	//	}
	//	AfxMessageBox(m_collectionPlans[m_icurSelTabIndex - m_newDialogIndex].GetPlanPara());
	//}
	if (m_icurSelTabIndex == m_pDialogVec.size() - 1) {
		////最后一个页面的下一步,也即实现完成按钮的功能
		OnBnClickedOk();
		return;
	}
	///判断是否越界
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex++;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}
