// ProjectSetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProjectSetView.h"
#include "afxdialogex.h"
#include "DateUtil.h"

// ProjectSetView �Ի���

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

// ProjectSetView ��Ϣ�������

BOOL ProjectSetView::OnInitDialog()
{
	//����������Ϣѡ���
	m_baseProjectInfoView.SetProjectEchoStatus(true);
	int res = m_baseProjectInfoView.DoModal();
	if (res != IDOK){
		///���û�е��ȷ����ť����ֱ���˳�����
		this->OnCancel();
		return FALSE;
	}
	CDialogEx::OnInitDialog();
	///�õ��û�ѡ��ļƻ���Ϣ
	m_project = theApp.m_currentProject;
	m_baseProjectInfoView.GetProjectBaseInfo(m_project);
	////���������Ĵ�����Ϣ

	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	m_projectNavigationTab.InsertItem(1, _T("ͨ������"));
	m_channelParaPresetView.SetProductId(m_project.GetProduct().GetProductId());
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_SHOW);

	////��¼��̬�����ĶԻ������ʼ����ֵ
	m_newDialogIndex = m_projectNavigationTab.GetItemCount();
	int count = m_newDialogIndex;
	//���õ�ǰѡ���tab������
	m_icurSelTabIndex = 0;

	// �Ի�����Ļ����
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
	///�ж��Ƿ�Խ��
	if (m_icurSelTabIndex == 0) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex--;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}


void ProjectSetView::OnBnClickedButtonNextstep()
{
	if (m_icurSelTabIndex == m_pDialogVec.size() - 1) {
		////���һ��ҳ�����һ��,Ҳ��ʵ����ɰ�ť�Ĺ���
		OnBnClickedOk();
		return;
	}
	///�ж��Ƿ�Խ��
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex++;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}


void ProjectSetView::OnBnClickedOk()
{
	// �õ����е�ͨ��
	m_vchannels.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vchannels);
	///��װproject����
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	if (m_project.GetChannelVector().size() != m_vchannels.size()){
		AfxMessageBox("ͨ������Ҫ��֮ǰ����һ��");
		return;
	}
	for (int i = 0; i < m_project.GetChannelVector().size(); i++){
		m_vchannels[i].SetId(m_project.GetChannelVector()[i].GetId());
	}
	m_project.SetChannelVector(m_vchannels);
	///������Ŀ����
	Result res = m_projectController.Update(m_project);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
		CDialogEx::OnCancel();
	}
	else{
		///���ص�ǰ��Ŀ
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
	//�ѵ�ǰ��ҳ����������
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_icurSelTabIndex = m_projectNavigationTab.GetCurSel();
	//���µ�ҳ����ʾ����
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	*pResult = 0;
}
