// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。
// AirCraftCasingVibrateSystem.cpp : 定义应用程序的类行为。

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "AirCraftCasingVibrateSystem.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "AirCraftCasingVibrateSystemDoc.h"
#include "AirCraftCasingVibrateSystemView.h"
#include "LoginView.h"
#include "FileUtil.h"
#include "Constant.h"
#include "ProjectController.h"
#include "TbProject.h"
#include "DateUtil.h"
#ifdef _DEBUGE	
#define new DEBUG_NEW
#endif


// CAirCraftCasingVibrateSystemApp

BEGIN_MESSAGE_MAP(CAirCraftCasingVibrateSystemApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CAirCraftCasingVibrateSystemApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CAirCraftCasingVibrateSystemApp 构造
CAirCraftCasingVibrateSystemApp::CAirCraftCasingVibrateSystemApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("AirCraftCasingVibrateSystem.AppID.NoVersion"));

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CAirCraftCasingVibrateSystemApp 对象

CAirCraftCasingVibrateSystemApp theApp;


// CAirCraftCasingVibrateSystemApp 初始化

BOOL CAirCraftCasingVibrateSystemApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	/*redis 传输*/
	/*if (!m_redisCon->Connect("127.0.0.1", 6379))
	{
		printf("connect error!\n");
		//return 0;
	}*/
	// 创建远程服务器连接
	m_cli = httplib::Client(_T(ServerHttpAddress), ServerHttpPort);
	///设置mysql数据库信息
	const char user[] = "root";         //username
	const char pswd[] = "oxygen";         //password
	const char host[] = "39.107.96.16";    //or"127.0.0.1" 39.107.96.162
	const char table[] = "aircraftfaultdetectdb";        //database
	unsigned int port = 3306;           //server port
	/*连接远程数据库*/
	theApp.PDsql.SetMysql(host, user, pswd, table);
	theApp.PDsql.OpenSql();
	/*连接本地数据库*/
	const char localUser[] = "root";         //local username
	const char localPswd[] = "123456";         //local password
	const char localHost[] = "127.0.0.1";    //local ip "127.0.0.1" 
	const char localTable[] = "aircraftfaultdetectdb";        //local database
	theApp.m_conPDLocalSql.SetMysql(localHost, localUser, localPswd, localTable);
	theApp.m_conPDLocalSql.OpenSql();
	/*如果连接不到服务器，则建立本地连接*/
	if (theApp.PDsql.m_mysql.host == NULL)
	{
		theApp.PDsql = theApp.m_conPDLocalSql;
	}

	//弹出登录窗口
	CLoginView loginView;
	// 如果点击取消了，程序停止
	if (loginView.DoModal() == CancelLogin)	{return FALSE;}

	// 根据当前登录用户，加载用户最后一次使用的项目
	ProjectController projectController;

	projectController.FindLastOpenProjectByUser(theApp.m_currentProject);
	if (theApp.m_currentProject.GetProjectId() != 0){
		theApp.m_currentProject.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
		projectController.Update(theApp.m_currentProject);
	}

	// 从文件中读取数据->内存（模拟数据）
	CFileUtil fileUtil;
	fileUtil.ReadFile(_T(""), tempRead);

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	
	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO:  应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 注册应用程序的文档模板。  文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_AirCraftCasingVTYPE,
		RUNTIME_CLASS(CAirCraftCasingVibrateSystemDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CAirCraftCasingVibrateSystemView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// 创建主 MDI 框架窗口
	CMainFrame* pMainFrame = new CMainFrame();

	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	

	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	///设置程序一开始不创建窗口
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	
	///根据最近一次打开的项目的传感器数量，创建指定数量的采集窗口
	CMainFrame*pFrame = (CMainFrame*)m_pMainWnd;
	pFrame->CreateCaptureWindow(theApp.m_currentProject.GetSensorVector());
	pFrame->MDITile(MDITILE_VERTICAL);//纵向平铺

	// 调度在命令行中指定的命令。  如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 主窗口已初始化，因此显示它并对其进行更新
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	return TRUE;
}

int CAirCraftCasingVibrateSystemApp::ExitInstance()
{
	//TODO:  处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CAirCraftCasingVibrateSystemApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CAirCraftCasingVibrateSystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CAirCraftCasingVibrateSystemApp 自定义加载/保存方法

void CAirCraftCasingVibrateSystemApp::PreLoadState()
{
	/*BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);*/
	//GetContextMenuManager()->AddMenu(_T("View右键"), IDR_MENU_RIGHT_KEY);
}

void CAirCraftCasingVibrateSystemApp::LoadCustomState()
{
}

void CAirCraftCasingVibrateSystemApp::SaveCustomState()
{
}

// CAirCraftCasingVibrateSystemApp 消息处理程序



