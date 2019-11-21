// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����
// AirCraftCasingVibrateSystem.cpp : ����Ӧ�ó��������Ϊ��

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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CAirCraftCasingVibrateSystemApp ����
CAirCraftCasingVibrateSystemApp::CAirCraftCasingVibrateSystemApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("AirCraftCasingVibrateSystem.AppID.NoVersion"));

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CAirCraftCasingVibrateSystemApp ����

CAirCraftCasingVibrateSystemApp theApp;


// CAirCraftCasingVibrateSystemApp ��ʼ��

BOOL CAirCraftCasingVibrateSystemApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	/*redis ����*/
	/*if (!m_redisCon->Connect("127.0.0.1", 6379))
	{
		printf("connect error!\n");
		//return 0;
	}*/
	// ����Զ�̷���������
	m_cli = httplib::Client(_T(ServerHttpAddress), ServerHttpPort);
	///����mysql���ݿ���Ϣ
	const char user[] = "root";         //username
	const char pswd[] = "oxygen";         //password
	const char host[] = "39.107.96.16";    //or"127.0.0.1" 39.107.96.162
	const char table[] = "aircraftfaultdetectdb";        //database
	unsigned int port = 3306;           //server port
	/*����Զ�����ݿ�*/
	theApp.PDsql.SetMysql(host, user, pswd, table);
	theApp.PDsql.OpenSql();
	/*���ӱ������ݿ�*/
	const char localUser[] = "root";         //local username
	const char localPswd[] = "123456";         //local password
	const char localHost[] = "127.0.0.1";    //local ip "127.0.0.1" 
	const char localTable[] = "aircraftfaultdetectdb";        //local database
	theApp.m_conPDLocalSql.SetMysql(localHost, localUser, localPswd, localTable);
	theApp.m_conPDLocalSql.OpenSql();
	/*������Ӳ�����������������������*/
	if (theApp.PDsql.m_mysql.host == NULL)
	{
		theApp.PDsql = theApp.m_conPDLocalSql;
	}

	//������¼����
	CLoginView loginView;
	// ������ȡ���ˣ�����ֹͣ
	if (loginView.DoModal() == CancelLogin)	{return FALSE;}

	// ���ݵ�ǰ��¼�û��������û����һ��ʹ�õ���Ŀ
	ProjectController projectController;

	projectController.FindLastOpenProjectByUser(theApp.m_currentProject);
	if (theApp.m_currentProject.GetProjectId() != 0){
		theApp.m_currentProject.SetProjectUpdateTime(DateUtil::GetCurrentCStringTime());
		projectController.Update(theApp.m_currentProject);
	}

	// ���ļ��ж�ȡ����->�ڴ棨ģ�����ݣ�
	CFileUtil fileUtil;
	fileUtil.ReadFile(_T(""), tempRead);

	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	
	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_AirCraftCasingVTYPE,
		RUNTIME_CLASS(CAirCraftCasingVibrateSystemDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CAirCraftCasingVibrateSystemView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame();

	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	

	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	///���ó���һ��ʼ����������
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	
	///�������һ�δ򿪵���Ŀ�Ĵ���������������ָ�������Ĳɼ�����
	CMainFrame*pFrame = (CMainFrame*)m_pMainWnd;
	pFrame->CreateCaptureWindow(theApp.m_currentProject.GetSensorVector());
	pFrame->MDITile(MDITILE_VERTICAL);//����ƽ��

	// ��������������ָ�������  ���
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	return TRUE;
}

int CAirCraftCasingVibrateSystemApp::ExitInstance()
{
	//TODO:  �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CAirCraftCasingVibrateSystemApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void CAirCraftCasingVibrateSystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CAirCraftCasingVibrateSystemApp �Զ������/���淽��

void CAirCraftCasingVibrateSystemApp::PreLoadState()
{
	/*BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);*/
	//GetContextMenuManager()->AddMenu(_T("View�Ҽ�"), IDR_MENU_RIGHT_KEY);
}

void CAirCraftCasingVibrateSystemApp::LoadCustomState()
{
}

void CAirCraftCasingVibrateSystemApp::SaveCustomState()
{
}

// CAirCraftCasingVibrateSystemApp ��Ϣ�������



