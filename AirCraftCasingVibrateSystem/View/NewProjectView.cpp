// NewProjectView.cpp : ʵ���ļ�
#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbUser.h"
#include "Result.h"
#include "DateUtil.h"
#include "TbDictionary.h"
// CNewProjectView �Ի���

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


// CNewProjectView ��Ϣ�������
/*�½���Ŀ��ť*/
void CNewProjectView::OnBnClickedOk()
{
	// �õ���ǰ����豸�Ĳ���
	m_collectionParaPresetView.GetSelectedCollectionparas(m_collectionparas);
	// �õ����е�ͨ��
	m_vchannels.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vchannels);
	///��װproject����
	TbUser user = theApp.m_currentProject.GetUser();
	m_project.SetUser(user);
	m_project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetCollectionparas(m_collectionparas);
	m_project.SetChannelVector(m_vchannels);
	if (m_vchannels.size() < 4){
		MessageBox(TEXT("ͨ��������ƥ�䣡"), TEXT("��ʾ"), MB_YESNO);
		return;
	}	///������Ŀ����
	Result res = m_projectController.AddProject(m_project);
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

BOOL CNewProjectView::OnInitDialog()
{
	//����������Ϣѡ���
	int res = m_baseProjectInfoView.DoModal();
	if (res != IDOK){
		///���û�е��ȷ����ť����ֱ���˳�����
		this->OnCancel();
		return FALSE;
	}
	CDialogEx::OnInitDialog();
	///�õ��û�ѡ��ļƻ���Ϣ
	m_baseProjectInfoView.GetProjectBaseInfo(m_project);
	////���������Ĵ�����Ϣ

	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	m_projectNavigationTab.InsertItem(0, _T("�ɼ�����"));
	m_collectionParaPresetView.Create(IDD_DIALOG_COLLECTIONPARAPRESET, &m_projectNavigationTab);
	m_collectionParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_collectionParaPresetView);
	m_collectionParaPresetView.ShowWindow(SW_SHOW);

	m_projectNavigationTab.InsertItem(1, _T("ͨ������"));
	m_channelParaPresetView.SetProductId(m_project.GetProduct().GetProductId());
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	
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


void CNewProjectView::OnTcnSelchangeTabProjectnavigation(NMHDR *pNMHDR, LRESULT *pResult)
{
	//�ѵ�ǰ��ҳ����������
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_icurSelTabIndex = m_projectNavigationTab.GetCurSel();
	//���µ�ҳ����ʾ����
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


////��һ��
void CNewProjectView::OnBnClickedButtonLaststep()
{
	///�ж��Ƿ�Խ��
	if (m_icurSelTabIndex == 0) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex--;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}

////��һ��
void CNewProjectView::OnBnClickedButtonNextstep()
{
	m_project;
	if (m_icurSelTabIndex == 0) {
		// �õ���ǰ����豸�Ĳ���
		((ChannelParaPresetView *)m_pDialogVec[m_icurSelTabIndex])->SetProductId(m_project.GetProduct().GetProductId());
	}

	//if (m_icurSelTabIndex == 1) {
	//	// �õ����е�ͨ��
	//	m_channelParaPresetView.GetSelectedChannels(m_vsensors);
	//}
	//if (m_icurSelTabIndex >= m_newDialogIndex) {
	//	// �ɼ��ƻ����ڵ����һ��ʱ������Ӧ�Ĳɼ��ƻ��������
	//	CollectionPlanParaPresetView* collectionPlanPresetView = dynamic_cast<CollectionPlanParaPresetView*>(m_pDialogVec[m_icurSelTabIndex]);
	//	if (collectionPlanPresetView != NULL){
	//		collectionPlanPresetView->GetCollectionPlan(m_collectionPlans[m_icurSelTabIndex - m_newDialogIndex]);
	//	}
	//	AfxMessageBox(m_collectionPlans[m_icurSelTabIndex - m_newDialogIndex].GetPlanPara());
	//}
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
