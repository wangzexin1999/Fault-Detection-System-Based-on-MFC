// NewProjectView.cpp : 实现文件
//

#include "stdafx.h"

#include "AirCraftCasingVibrateSystem.h"

#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
#include "Result.h"
#include "DateUtil.h"
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
	DDX_Control(pDX, IDC_COMBO_TESTINGDEVICE, m_testingDeviceCombo);
	DDX_Control(pDX, IDC_COMBO_DETECTEDDEVICE, m_productCombo);
	DDX_Control(pDX, IDC_EDIT_PROJECTNAME, m_projectNameEdit);
}


BEGIN_MESSAGE_MAP(CNewProjectView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewProjectView::OnBnClickedOk)
END_MESSAGE_MAP()


// CNewProjectView 消息处理程序
/*新建项目按钮*/
void CNewProjectView::OnBnClickedOk()
{
	CString projectName;
	m_projectNameEdit.GetWindowTextA(projectName);
	if (projectName == ""){ AfxMessageBox("项目名不能为空"); return;}
	int testingIndex = m_testingDeviceCombo.GetCurSel();
	int detectedIndex = m_productCombo.GetCurSel();

	if (testingIndex > 0) {
		testingIndex--;
	}
	else{
		AfxMessageBox("请选择检测设备");
		return;
	}
	if (detectedIndex > 0) {
		detectedIndex--;
	}
	else{
		AfxMessageBox("请选择产品");
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
	/*1.调用ProjectController去查询检测设备的下拉列表的数据*/
	m_testingDeviceCombo.ResetContent();
	m_productCombo.ResetContent();
	Result res = m_projectController.LoadAllTestingDevice(m_testingDeviceVector);
	if (res.GetIsSuccess()){
		int i = 0;
		m_testingDeviceCombo.InsertString(i, "暂不选择1");
		for (auto testingDevice : m_testingDeviceVector){
			m_testingDeviceCombo.InsertString(++i,testingDevice.m_testingDeviceIp.m_strValue);
		}
		m_testingDeviceCombo.SetCurSel(0);
	}
	else{
		AfxMessageBox(res.GetMessages());
	}

	/*2.调用ProjectController去查询产品的下拉列表的数据*/

	res = m_projectController.LoadAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		int i = 0;
		m_productCombo.InsertString(i,"暂不选择2");
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
