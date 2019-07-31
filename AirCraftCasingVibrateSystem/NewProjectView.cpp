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
	DDX_Control(pDX, IDC_COMBO_DETECTEDDEVICE, m_detectedDeviceCombo);
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
	int detectedIndex = m_detectedDeviceCombo.GetCurSel();

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
		AfxMessageBox("请选择被检测设备");
		return;
	}
	TbTester tester = theApp.m_currentProject.GetTester();

	TbDetectedDevice detectedDevice;
	detectedDevice.SetDetecteddeviceId(m_detectedDeviceVector[detectedIndex].m_detecteddeviceId.GetInt());

	TbProject project;
	project.SetProjectName(projectName);
	project.SetDetectedDevice(detectedDevice);
	project.SetTester(tester);
	project.SetProjectCreateTime(DateUtil::GetCurrentTimeCString());
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
	m_detectedDeviceCombo.ResetContent();
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

	/*2.调用ProjectController去查询被检测设备的下拉列表的数据*/

	res = m_projectController.LoadAllDetectedDevice(m_detectedDeviceVector);
	if (res.GetIsSuccess()){
		int i = 0;
		m_detectedDeviceCombo.InsertString(i,"暂不选择2");
		for (auto detectedDevice : m_detectedDeviceVector){
			m_detectedDeviceCombo.InsertString(++i,detectedDevice.m_detecteddeviceName.m_strValue);
		}
		m_detectedDeviceCombo.SetCurSel(0);
	}
	else
	{
		AfxMessageBox(res.GetMessages());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
