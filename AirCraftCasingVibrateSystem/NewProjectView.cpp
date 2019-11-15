// NewProjectView.cpp : ʵ���ļ�
#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
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
	m_collectionParaPresetView.GetSelectedTestingDevice(m_testingDevice);
	// �õ����е�ͨ��
	m_vsensors.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vsensors);
	
	////��װ�ɼ��ƻ�����
	Document plansDoc;
	//��÷�����
	Document::AllocatorType & allocator = plansDoc.GetAllocator();
	//rootΪkObjectType
	Value root(kObjectType);
	//�ɼ��ƻ�������
	Value collectionPlans(kArrayType);
	Value planEntity_default(kObjectType);

	for (int i = m_newDialogIndex; i < m_pDialogVec.size(); i++){
		CollectionPlanParaPresetView* collectionPlanPresetView = dynamic_cast<CollectionPlanParaPresetView*>(m_pDialogVec[i]);
		if (collectionPlanPresetView != NULL){
			Value planEntity(kObjectType);
			collectionPlanPresetView->GetCollectionPlan(planEntity, allocator);

			Value Array_z(kArrayType);
			if (planEntity["planParaContent"].GetArray().Size()==0)
			{
				CString v_planName = planEntity["planName"].GetString();
				AfxMessageBox(_T("��ѡ��")+v_planName + _T("���Ĳ���"));
				return;
			}
			
			collectionPlans.PushBack(planEntity, allocator);

			if (i == m_newDialogIndex)
			{
				collectionPlanPresetView->GetDefaultCollectionPlan(planEntity_default, allocator);

			}
		}
	}
	root.AddMember("collectionPlans", collectionPlans, allocator);

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	root.Accept(writer);

	StringBuffer buffer_default;
	Writer<StringBuffer> writer_default(buffer_default);
	planEntity_default.Accept(writer_default);

	std::string result = buffer.GetString();
	std::string result_default = buffer_default.GetString();
	///����Ŀ�������òɼ�
	m_project.SetCollectionPlans(result.c_str());
	m_project.SetCollectionStatus(result_default.c_str());

	///��װproject����
	TbTester tester = theApp.m_currentProject.GetTester();
	m_project.SetTester(tester);
	m_project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetTestingDevice(m_testingDevice);
	m_project.SetSensorVector(m_vsensors);
	///������Ŀ����
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
	vector<TbDictionary> selectedCollctionPlans;
	m_baseProjectInfoView.GetSelectedCollectionPlan(selectedCollctionPlans);

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
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	
	////��¼��̬�����ĶԻ������ʼ����ֵ
	m_newDialogIndex = m_projectNavigationTab.GetItemCount();
	int count = m_newDialogIndex;
	for (auto plan : selectedCollctionPlans){
		// �����û�ѡ��ļƻ�������Ӧ�Ĵ���
		Document doc;
		doc.Parse(plan.GetDictValue());
		const Value& planName = doc["planName"];
		CollectionPlanParaPresetView * collectionParaPresetView = new CollectionPlanParaPresetView(plan);
		m_projectNavigationTab.InsertItem(count++, planName.GetString());
		collectionParaPresetView->Create(IDD_DIALOG_STABLESTATUSPRESET, &m_projectNavigationTab);
		collectionParaPresetView->MoveWindow(&tabRect);
		m_pDialogVec.push_back(collectionParaPresetView);
		// �������ڶ�Ӧ�Ĳɼ��ƻ�����
	}
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

void CNewProjectView::GridCtrlInit(){
	m_projectOperatorDataGridCtrl.SetEditable(false);
	m_projectOperatorDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_projectOperatorDataGridCtrl.SetRowCount(8); //��ʼΪn��
	m_projectOperatorDataGridCtrl.SetColumnCount(3); //��ʼ��Ϊ5��
	m_projectOperatorDataGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_projectOperatorDataGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_projectOperatorDataGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_projectOperatorDataGridCtrl.ExpandColumnsToFit(true);
	m_projectOperatorDataGridCtrl.SetSingleRowSelection(true);
	for (int row = 0; row < m_projectOperatorDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_projectOperatorDataGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		if (row == 0 ) //��(0��0)��
		{
			if (col == 0){
				Item.strText.Format(_T("ת�����"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("ת��ֵ"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("��ע"), 2);
			}
		}

		else if (col < 1) //����0�б�ͷ��ʾ
		{
			if (row < m_projectOperatorDataGridCtrl.GetRowCount())
			{
				Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
				Item.strText.Format(_T("��%d��"), row);
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

	//if (m_icurSelTabIndex == 0) {
	//	// �õ���ǰ����豸�Ĳ���
	//	m_collectionParaPresetView.GetSelectedTestingDevicePara(m_testingDevicePara);
	//}

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
