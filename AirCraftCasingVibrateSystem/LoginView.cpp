// LoginView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "LoginView.h"
#include "afxdialogex.h"
#include "TbDictionaryDao.h"
#include "TbTester.h"
// CLoginView �Ի���

IMPLEMENT_DYNAMIC(CLoginView, CDialogEx)

CLoginView::CLoginView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginView::IDD, pParent)
	
{

}

CLoginView::~CLoginView()
{
}

void CLoginView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOGNNAME, m_loginNameEdit);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_passWordEdit);
}


BEGIN_MESSAGE_MAP(CLoginView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginView::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginView::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginView ��Ϣ�������

/*ȷ����¼��ť**/
void CLoginView::OnBnClickedOk()
{

	CString  loginName,passWord;
	m_loginNameEdit.GetWindowTextA(loginName);
	m_passWordEdit.GetWindowTextA(passWord);

	loginName = "mst";
	passWord = "123456";

	TbTester tester;
	tester.SetLoginName(loginName);
	tester.SetPassWord(passWord);
	Result reslut = m_TbTesterControler.LoginCheck(tester);
	if (!reslut.GetIsSuccess()){
		AfxMessageBox(reslut.GetMessages());
	}
	else{
		theApp.m_currentProject.SetTester(tester);
		CDialogEx::OnOK();
	}
}

/*ȡ����¼��ť*/
void CLoginView::OnBnClickedButton1()
{
	CDialogEx::OnCancel();
}

/*������֮��رյ�ǰ����*/
void CLoginView::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnCancel();
	exit(0);
}
