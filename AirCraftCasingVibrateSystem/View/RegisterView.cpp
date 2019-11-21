// RegisterView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "RegisterView.h"
#include "afxdialogex.h"


// CRegisterView 对话框

IMPLEMENT_DYNAMIC(CRegisterView, CDialogEx)

CRegisterView::CRegisterView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterView::IDD, pParent)
{

}

CRegisterView::~CRegisterView()
{
}

void CRegisterView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_REGISTER_USER_NAME, m_editRegisterLoginName);
	DDX_Control(pDX, IDC_EDIT_REGISTER_POST, m_editRegidterPost);
	DDX_Control(pDX, IDC_EDIT_REGISTER_TELL, m_editRegisterTell);
	DDX_Control(pDX, IDC_EDIT_REGISTER_NAME, m_editRegisterName);
	DDX_Control(pDX, IDC_EDIT_REGISTER_PSW, m_editRegisterPSW);
	DDX_Control(pDX, IDC_EDIT_REGISTER_QPSW, m_editRegisterQPSW);
}


BEGIN_MESSAGE_MAP(CRegisterView, CDialogEx)
	ON_BN_CLICKED(ID_REGISTER, &CRegisterView::OnBnClickedRegister)
END_MESSAGE_MAP()


// CRegisterView 消息处理程序


BOOL CRegisterView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CRegisterView::OnBnClickedRegister()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTester tester;
	CString str,str2;
	m_editRegisterLoginName.GetWindowTextA(str);
	// 登录名不能为空
	tester.SetLoginName(str);
	// 设置邮箱
	m_editRegidterPost.GetWindowTextA(str);
	tester.SetTesterPost(str);
	// 设置电话
	m_editRegisterTell.GetWindowTextA(str);
	tester.SetTesterTelephone(str);
	// 设置密码
	m_editRegisterPSW.GetWindowTextA(str);
	m_editRegisterQPSW.GetWindowTextA(str2);
	if (str != str2)
	{
		AfxMessageBox("两次密码不一致");
		return;
	}
	tester.SetPassWord(str);
	// 设置姓名
	m_editRegisterName.GetWindowTextA(str);
	tester.SetTesterName(str);
	tester.SetTesterStatus(0);
	//设置状态
	Result result = m_testerController.AddTester(tester);
	if (!result.GetIsSuccess()){
		AfxMessageBox(result.GetMessages());
	}
	else{
		AfxMessageBox("请联系管理员批准！！");
		CDialogEx::OnOK();
	}



}
