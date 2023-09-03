// ProjectSetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProjectSetView.h"
#include "afxdialogex.h"
#include "DateUtil.h"

// ProjectSetView 对话框

IMPLEMENT_DYNAMIC(ProjectSetView, CDialogEx)

ProjectSetView::ProjectSetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(ProjectSetView::IDD, pParent)
{

}

ProjectSetView::~ProjectSetView()
{
}

void ProjectSetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_PROJECT_NAVIGATION, m_projectNavigationTab);
}

BEGIN_MESSAGE_MAP(ProjectSetView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LASTSTEP, &ProjectSetView::OnBnClickedButtonLaststep)
	ON_BN_CLICKED(IDC_BUTTON_NEXTSTEP, &ProjectSetView::OnBnClickedButtonNextstep)
	ON_BN_CLICKED(IDOK, &ProjectSetView::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ProjectSetView::OnBnClickedCancel)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PROJECT_NAVIGATION, &ProjectSetView::OnTcnSelchangeTabProjectNavigation)
END_MESSAGE_MAP()

// ProjectSetView 消息处理程序

BOOL ProjectSetView::OnInitDialog()
{
	//弹出基本信息选择框
	m_baseProjectInfoView.SetProjectEchoStatus(true);
	int res = m_baseProjectInfoView.DoModal();
	if (res != IDOK){
		///如果没有点击确定按钮，则直接退出程序
		this->OnCancel();
		return FALSE;
	}
	CDialogEx::OnInitDialog();
	///得到用户选择的计划信息
	m_project = theApp.m_currentProject;
	m_baseProjectInfoView.GetProjectBaseInfo(m_project);
	////创建基本的窗口信息

	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	m_projectNavigationTab.InsertItem(1, _T("通道设置"));
	m_channelParaPresetView.SetProductId(m_project.GetProduct().GetProductId());
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_SHOW);

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


void ProjectSetView::OnBnClickedButtonLaststep()
{
	///判断是否越界
	if (m_icurSelTabIndex == 0) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex--;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}


void ProjectSetView::OnBnClickedButtonNextstep()
{
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


void ProjectSetView::OnBnClickedOk()
{
	// 得到所有的通道
	m_vchannels.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vchannels);
	///封装project对象
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	if (m_project.GetChannelVector().size() != m_vchannels.size()){
		AfxMessageBox("通道数量要与之前保持一致");
		return;
	}
	for (int i = 0; i < m_project.GetChannelVector().size(); i++){
		m_vchannels[i].SetId(m_project.GetChannelVector()[i].GetId());
	}
	m_project.SetChannelVector(m_vchannels);
	///更新项目数据
	Result res = m_projectController.Update(m_project);
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


void ProjectSetView::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void ProjectSetView::OnTcnSelchangeTabProjectNavigation(NMHDR *pNMHDR, LRESULT *pResult)
{
	//把当前的页面隐藏起来
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_icurSelTabIndex = m_projectNavigationTab.GetCurSel();
	//把新的页面显示出来
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	*pResult = 0;
}
