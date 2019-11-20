// NewProjectView.cpp : 实现文件
#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
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
	m_collectionParaPresetView.GetSelectedTestingDevice(m_testingDevice);
	// 得到所有的通道
	m_vsensors.clear();
	m_channelParaPresetView.GetSelectedChannels(m_vsensors);
	
	////封装采集计划参数
	Document plansDoc;
	//获得分配器
	Document::AllocatorType & allocator = plansDoc.GetAllocator();
	//root为kObjectType
	Value root(kObjectType);
	//采集计划的内容
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
				AfxMessageBox(_T("请选择“")+v_planName + _T("”的参数"));
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
	///给项目对象设置采集
	m_project.SetCollectionPlans(result.c_str());
	m_project.SetCollectionStatus(result_default.c_str());

	///封装project对象
	TbTester tester = theApp.m_currentProject.GetTester();
	m_project.SetTester(tester);
	m_project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
	m_project.SetTestingDevice(m_testingDevice);
	m_project.SetSensorVector(m_vsensors);
	///保存项目数据
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
	vector<TbDictionary> selectedCollctionPlans;
	m_baseProjectInfoView.GetSelectedCollectionPlan(selectedCollctionPlans);

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
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET, &m_projectNavigationTab);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	
	////记录动态创建的对话框的起始索引值
	m_newDialogIndex = m_projectNavigationTab.GetItemCount();
	int count = m_newDialogIndex;
	for (auto plan : selectedCollctionPlans){
		// 根据用户选择的计划创建相应的窗口
		Document doc;
		doc.Parse(plan.GetDictValue());
		const Value& planName = doc["planName"];
		CollectionPlanParaPresetView * collectionParaPresetView = new CollectionPlanParaPresetView(plan);
		m_projectNavigationTab.InsertItem(count++, planName.GetString());
		collectionParaPresetView->Create(IDD_DIALOG_STABLESTATUSPRESET, &m_projectNavigationTab);
		collectionParaPresetView->MoveWindow(&tabRect);
		m_pDialogVec.push_back(collectionParaPresetView);
		// 创建窗口对应的采集计划对象
	}
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

	//if (m_icurSelTabIndex == 0) {
	//	// 得到当前检测设备的参数
	//	m_collectionParaPresetView.GetSelectedTestingDevicePara(m_testingDevicePara);
	//}

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
