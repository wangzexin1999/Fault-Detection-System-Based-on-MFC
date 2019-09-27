// RegisterView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "RegisterView.h"
#include "afxdialogex.h"


// CRegisterView �Ի���

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


// CRegisterView ��Ϣ�������


BOOL CRegisterView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CRegisterView::OnBnClickedRegister()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTester tester;
	CString str,str2;
	m_editRegisterLoginName.GetWindowTextA(str);
	// ��¼������Ϊ��
	tester.SetLoginName(str);
	// ��������
	m_editRegidterPost.GetWindowTextA(str);
	tester.SetTesterPost(str);
	// ���õ绰
	m_editRegisterTell.GetWindowTextA(str);
	tester.SetTesterTelephone(str);
	// ��������
	m_editRegisterPSW.GetWindowTextA(str);
	m_editRegisterQPSW.GetWindowTextA(str2);
	if (str != str2)
	{
		AfxMessageBox("�������벻һ��");
		return;
	}
	tester.SetPassWord(str);
	// ��������
	m_editRegisterName.GetWindowTextA(str);
	tester.SetTesterName(str);
	tester.SetTesterStatus(0);
	//����״̬
	Result result = m_testerController.AddTester(tester);
	if (!result.GetIsSuccess()){
		AfxMessageBox(result.GetMessages());
	}
	else{
		AfxMessageBox("����ϵ����Ա��׼����");
		CDialogEx::OnOK();
	}



}
