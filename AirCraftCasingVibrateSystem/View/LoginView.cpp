// LoginView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "LoginView.h"
#include "afxdialogex.h"
#include "TbDictionaryDao.h"
#include "TbUser.h"
#include "RegisterView.h"
// CLoginView �Ի���

IMPLEMENT_DYNAMIC(CLoginView, CDialogEx)

CLoginView::CLoginView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginView::IDD, pParent){

}

CLoginView::~CLoginView(){
}

void CLoginView::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOGNNAME, m_loginNameEdit);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_passWordEdit);
}


BEGIN_MESSAGE_MAP(CLoginView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginView::OnBnClickedOk)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_LOGINVIEW_REGISTER, &CLoginView::OnBnClickedButtonLoginviewRegister)
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

	TbUser user;
	user.SetLoginName(loginName);
	user.SetPassWord(passWord);
	Result reslut = m_TbUserControler.LoginCheck(user);
	if (!reslut.GetIsSuccess()){
		AfxMessageBox(reslut.GetMessages());
	}
	else{
		theApp.m_currentProject.SetUser(user);
		CDialogEx::OnOK();
	}
}

/*������֮��رյ�ǰ����*/
void CLoginView::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnCancel();
	exit(0);
}


void CLoginView::OnBnClickedButtonLoginviewRegister()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	CRegisterView registerView;
	registerView.DoModal();

}
