// BaseProjectInfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "BaseProjectInfoView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"
// BaseProjectInfoView 对话框
IMPLEMENT_DYNAMIC(BaseProjectInfoView, CDialogEx)

BaseProjectInfoView::BaseProjectInfoView(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseProjectInfoView::IDD, pParent)
{
	///1.默认不回显项目的数据
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
		/// 回显项目名
		m_projectNameEdit.SetWindowTextA(theApp.m_currentProject.GetProjectName());
		SetWindowTextA("项目设置");
	}
	Result res = m_productController.FindAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		///将查询到的产品初始化到下拉框
		for (int i = 0; i < m_productVector.size(); i++){
			m_productCombo.InsertString(i, m_productVector[i].GetProductName());
			if (m_isEchoProjectData &&
				m_productVector[i] == theApp.m_currentProject.GetProduct()){
				///回显产品，并将产品下拉框置为不可选
				m_productCombo.SetCurSel(i);
				CEdit *pEdit = (CEdit*)m_productCombo.GetWindow(GW_CHILD);
				pEdit->EnableWindow(FALSE);
				///找到的回显的产品，即可跳出循环
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
	if (m_projectName == ""){ AfxMessageBox("项目名不能为空"); return; }
	int detectedIndex = m_productCombo.GetCurSel();
	///产品未选择状态
	if (detectedIndex < 0) {
		AfxMessageBox("请选择产品");
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
	// TODO:  在此添加专用代码和/或调用基类
	CDialogEx::OnOK();
	OnBnClickedButtonOk();
}
