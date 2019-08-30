// NewProjectView.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "AirCraftCasingVibrateSystem.h"

#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
#include "Result.h"
#include "DateUtil.h"
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
	DDX_Control(pDX, IDC_COMBO_TESTINGDEVICE, m_testingDeviceCombo);
	DDX_Control(pDX, IDC_COMBO_DETECTEDDEVICE, m_productCombo);
	DDX_Control(pDX, IDC_EDIT_PROJECTNAME, m_projectNameEdit);
}


BEGIN_MESSAGE_MAP(CNewProjectView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewProjectView::OnBnClickedOk)
END_MESSAGE_MAP()


// CNewProjectView ��Ϣ�������
/*�½���Ŀ��ť*/
void CNewProjectView::OnBnClickedOk()
{
	CString projectName;
	m_projectNameEdit.GetWindowTextA(projectName);
	if (projectName == ""){ AfxMessageBox("��Ŀ������Ϊ��"); return;}
	int testingIndex = m_testingDeviceCombo.GetCurSel();
	int detectedIndex = m_productCombo.GetCurSel();

	if (testingIndex > 0) {
		testingIndex--;
	}
	else{
		AfxMessageBox("��ѡ�����豸");
		return;
	}
	if (detectedIndex > 0) {
		detectedIndex--;
	}
	else{
		AfxMessageBox("��ѡ���Ʒ");
		return;
	}
	TbTester tester = theApp.m_currentProject.GetTester();

	TbProduct product;
	product.SetProductId(m_productVector[detectedIndex].GetProductId());

	TbProject project;
	project.SetProjectName(projectName);
	project.SetProduct(product);
	project.SetTester(tester);
	project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());
	int m = m_testingDeviceVector[testingIndex].m_testingDeviceId.GetInt();
	project.GetTestingDevicePara().GetTestingdevice().SetTestingdeviceId(m_testingDeviceVector[testingIndex].m_testingDeviceId.GetInt());
	Result res = m_projectController.AddProject(project);

	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
	else{
		AfxMessageBox(res.GetMessages());
		CDialogEx::OnOK();
	}
}

BOOL CNewProjectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*1.����ProjectControllerȥ��ѯ����豸�������б������*/
	m_testingDeviceCombo.ResetContent();
	m_productCombo.ResetContent();
	Result res = m_projectController.LoadAllTestingDevice(m_testingDeviceVector);
	if (res.GetIsSuccess()){
		int i = 0;
		m_testingDeviceCombo.InsertString(i, "�ݲ�ѡ��1");
		for (auto testingDevice : m_testingDeviceVector){
			m_testingDeviceCombo.InsertString(++i,testingDevice.m_testingDeviceIp.m_strValue);
		}
		m_testingDeviceCombo.SetCurSel(0);
	}
	else{
		AfxMessageBox(res.GetMessages());
	}

	/*2.����ProjectControllerȥ��ѯ��Ʒ�������б������*/

	res = m_projectController.LoadAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		int i = 0;
		m_productCombo.InsertString(i,"�ݲ�ѡ��2");
		for (auto product : m_productVector){
			m_productCombo.InsertString(++i,product.GetProductType());
		}
		m_productCombo.SetCurSel(0);
	}
	else
	{
		AfxMessageBox(res.GetMessages());
	}
	return TRUE;  
}
