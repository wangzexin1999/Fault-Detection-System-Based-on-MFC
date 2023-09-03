// BaseProjectInfoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "BaseProjectInfoView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"
// BaseProjectInfoView �Ի���
IMPLEMENT_DYNAMIC(BaseProjectInfoView, CDialogEx)

BaseProjectInfoView::BaseProjectInfoView(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseProjectInfoView::IDD, pParent)
{
	///1.Ĭ�ϲ�������Ŀ������
	m_isEchoProjectData = false;
}

BaseProjectInfoView::~BaseProjectInfoView()
{
}

void BaseProjectInfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_productCombo);
	DDX_Control(pDX, IDC_EDIT_PROJECTNAME, m_projectNameEdit);
}


BEGIN_MESSAGE_MAP(BaseProjectInfoView, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_OK, &BaseProjectInfoView::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &BaseProjectInfoView::OnBnClickedButtonCancel)
	ON_CBN_SELCHANGE(IDC_COMBO_PRODUCT, &BaseProjectInfoView::OnCbnSelchangeComboProduct)
END_MESSAGE_MAP()


BOOL BaseProjectInfoView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (m_isEchoProjectData){
		/// ������Ŀ��
		m_projectNameEdit.SetWindowTextA(theApp.m_currentProject.GetProjectName());
		SetWindowTextA("��Ŀ����");
	}
	Result res = m_productController.FindAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		///����ѯ���Ĳ�Ʒ��ʼ����������
		for (int i = 0; i < m_productVector.size(); i++){
			m_productCombo.InsertString(i, m_productVector[i].GetProductName());
			if (m_isEchoProjectData &&
				m_productVector[i] == theApp.m_currentProject.GetProduct()){
				///���Բ�Ʒ��������Ʒ��������Ϊ����ѡ
				m_productCombo.SetCurSel(i);
				CEdit *pEdit = (CEdit*)m_productCombo.GetWindow(GW_CHILD);
				pEdit->EnableWindow(FALSE);
				///�ҵ��Ļ��ԵĲ�Ʒ����������ѭ��
				break;
			}
		}
	}else{
		AfxMessageBox(res.GetMessages());
	}
	m_productCombo.SetCurSel(0);
	return TRUE;  
}

void BaseProjectInfoView::OnBnClickedButtonOk()
{
	m_projectNameEdit.GetWindowTextA(m_projectName);
	if (m_projectName == ""){ AfxMessageBox("��Ŀ������Ϊ��"); return; }
	int detectedIndex = m_productCombo.GetCurSel();
	///��Ʒδѡ��״̬
	if (detectedIndex < 0) {
		AfxMessageBox("��ѡ���Ʒ");
		return;
	}
	m_selectedProduct = m_productVector[detectedIndex];
	CDialogEx::OnOK();
}


void BaseProjectInfoView::OnBnClickedButtonCancel()
{
	CDialogEx::OnCancel();
}
void BaseProjectInfoView::GetProjectBaseInfo(TbProject &project){
	project.SetProjectName(m_projectName);
	project.SetProduct(m_selectedProduct);
}
void BaseProjectInfoView::SetProjectEchoStatus(bool isEcho){
	m_isEchoProjectData = isEcho;
}

void BaseProjectInfoView::OnCbnSelchangeComboProduct()
{
	int detectedIndex = m_productCombo.GetCurSel();
	m_selectedProduct = m_productVector[detectedIndex];
}



void BaseProjectInfoView::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CDialogEx::OnOK();
	OnBnClickedButtonOk();
}
