// SersorParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaView.h"
#include "afxdialogex.h"
#include "TbTestingDevice.h"
#include "CommonUtil.h"
#include "TestingDeviceController.h"
// CollectionParaView 对话框

IMPLEMENT_DYNAMIC(CollectionParaView, CDialogEx)

CollectionParaView::CollectionParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CollectionParaView::IDD, pParent)
{

}

CollectionParaView::~CollectionParaView()
{
}

CComboBox m_collectionFrequencyCombo;
CComboBox m_collectionMethodCombo;
CComboBox m_analysisFrequencyCombo;
CComboBox m_triggerMethodCombo;
CComboBox m_dataBlockCountCombo;
CEdit m_triggerCountEdit;
CEdit m_delayBlockCountEdit;
CEdit m_collectionBatchEdit;

void CollectionParaView::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO1, m_collectionFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO2, m_analysisFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO3, m_collectionMethodCombo);
	DDX_Control(pDX, IDC_COMBO4, m_triggerMethodCombo);
	DDX_Control(pDX, IDC_COMBO5, m_dataBlockCountCombo);
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TRIGGERCOUNT, m_triggerCountEdit);
	DDX_Control(pDX, IDC_EDIT_DELAYBLOCKCOUNT, m_delayBlockCountEdit);
	DDX_Control(pDX, IDC_EDIT_COLLECTIONBATCHS, m_collectionBatchEdit);
}


BEGIN_MESSAGE_MAP(CollectionParaView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CollectionParaView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CollectionParaView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CollectionParaView::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CollectionParaView::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CollectionParaView::OnCbnSelchangeCombo5)
	ON_EN_CHANGE(IDC_EDIT_DELAYBLOCKCOUNT, &CollectionParaView::OnEnChangeEditDelayblockcount)
	ON_EN_CHANGE(IDC_EDIT_TRIGGERCOUNT, &CollectionParaView::OnEnChangeEditTriggercount)
	ON_EN_CHANGE(IDC_EDIT_COLLECTIONBATCHS, &CollectionParaView::OnEnChangeEditCollectionbatchs)
END_MESSAGE_MAP()


// CollectionParaView 消息处理程序

BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CollectionParaInfoInit();
	return TRUE; 
}
void CollectionParaView::GetSelectedTestingDevice(TbTestingDevice &testingDevice){
	int index = m_collectionFrequencyCombo.GetCurSel();
	//m_collectionFrequencyCombo.GetLBText(index, strInfo1);//通过索引获取对应的值
	testingDevice.SetCollectionFrequency(m_vcollectionFrequency[index]);

	index = m_analysisFrequencyCombo.GetCurSel();
	testingDevice.SetAnalysisFrequency(m_vanalysisFrequency[index]);

	index = m_triggerMethodCombo.GetCurSel();
	testingDevice.SetTriggerMethod(m_vtriggerMethod[index]);

	index = m_collectionMethodCombo.GetCurSel();
	testingDevice.SetCollectionMethod(m_vcollectionMethod[index]);

	index = m_dataBlockCountCombo.GetCurSel();
	testingDevice.SetDatablockCount(m_vdataBlockCount[index]);

	CString delayBlockCount, triggerCount, collectionBaths;

	m_collectionBatchEdit.GetWindowTextA(collectionBaths);
	m_delayBlockCountEdit.GetWindowTextA(delayBlockCount);
	m_triggerCountEdit.GetWindowTextA(triggerCount);
	testingDevice.SetCollectionBatchs(atoi(collectionBaths));
	testingDevice.SetDelayblockCount(atoi(delayBlockCount));
	testingDevice.SetTriggerCount(atoi(triggerCount));
	TestingDeviceController m_testingDeviceServiceController;
	Result res = m_testingDeviceServiceController.UpdateTestingDevice(testingDevice);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}

}

void CollectionParaView::CollectionParaInfoInit(){
	////解析下拉框的选项
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	Result res;
	int curSel = 0;
	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionFrequency, 0, "collectionfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集频率失败");
	}
	else{
		for (int i = 0; i < m_vcollectionFrequency.size(); i++){

			TbDictionary collection = m_vcollectionFrequency[i];
			Document doc;
			doc.Parse(collection.GetDictValue());
			const Value& title = doc["title"];
			collection.SetDictValue(title.GetString());
			//TbDictionary collecionFrequency = m_vcollectionFrequency[i];
			TbDictionary collecionFrequency = collection;
			m_collectionFrequencyCombo.InsertString(i, collecionFrequency.GetDictValue());
			if (testingDevice.GetCollectionFrequency().GetDictId() == collecionFrequency.GetDictId()){
				curSel = i;
			}
		}
		m_collectionFrequencyCombo.SetCurSel(curSel);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载分析频率失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_vanalysisFrequency.size(); i++){

			TbDictionary analysis = m_vanalysisFrequency[i];
			Document doc;
			doc.Parse(analysis.GetDictValue());
			const Value& title = doc["title"];
			analysis.SetDictValue(title.GetString());
			//TbDictionary analysisFrequency = m_vanalysisFrequency[i];
			TbDictionary analysisFrequency = analysis;
			m_analysisFrequencyCombo.InsertString(i, analysisFrequency.GetDictValue());
			if (testingDevice.GetAnalysisFrequency().GetDictId()==analysisFrequency.GetDictId()){
				curSel = i;
			}
		}
		m_analysisFrequencyCombo.SetCurSel(curSel);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionMethod, 0, "collectionmethod");

	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集方式失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_vcollectionMethod.size(); i++){
			TbDictionary collectionMethod = m_vcollectionMethod[i];
			m_collectionMethodCombo.InsertString(i, collectionMethod.GetDictValue());
			if (collectionMethod.GetDictId()==testingDevice.GetCollectionMethod().GetDictId()){
				curSel = i;
			}
		}
		m_collectionMethodCombo.SetCurSel(curSel);
	}


	res = m_dictionaryController.FindAllBySearchCondition(m_vdataBlockCount, 0, "datablockcount");

	if (!res.GetIsSuccess()){
		AfxMessageBox("查询数据块数失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_vdataBlockCount.size(); i++){
			TbDictionary dataBlockCount = m_vdataBlockCount[i];
			m_dataBlockCountCombo.InsertString(i, dataBlockCount.GetDictValue());
			if (dataBlockCount.GetDictId() == testingDevice.GetDatablockCount().GetDictId()){
				curSel = i;
			}
		}
		m_dataBlockCountCombo.SetCurSel(curSel);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vtriggerMethod, 0, "triggermethod");

	if (!res.GetIsSuccess()){
		AfxMessageBox("查询触发方式失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_vtriggerMethod.size(); i++){
			TbDictionary triggerMethod = m_vtriggerMethod[i];
			m_triggerMethodCombo.InsertString(i, triggerMethod.GetDictValue());
			if (triggerMethod.GetDictId() == testingDevice.GetTriggerMethod().GetDictId()){
				curSel = i;
			}
		}
		m_triggerMethodCombo.SetCurSel(curSel);
	}
	m_delayBlockCountEdit.SetWindowTextA(CommonUtil::Int2CString(testingDevice.GetDelayblockCount()));
	m_collectionBatchEdit.SetWindowTextA(CommonUtil::Int2CString(testingDevice.GetCollectionBatchs()));
	m_triggerCountEdit.SetWindowTextA(CommonUtil::Int2CString(testingDevice.GetTriggerCount()));
}

void CollectionParaView::RefreshView(){
	///1.删除所有下拉框的选项，并清空
	m_collectionFrequencyCombo.ResetContent();
	m_vcollectionFrequency.clear();
	m_collectionMethodCombo.ResetContent();
	m_vcollectionMethod.clear();
	m_analysisFrequencyCombo.ResetContent();
	m_vanalysisFrequency.clear();
	m_dataBlockCountCombo.ResetContent();
	m_vdataBlockCount.clear();
	m_triggerMethodCombo.ResetContent();
	m_vtriggerMethod.clear();
	///2.采集参数重新初始化
	CollectionParaInfoInit();
}

void CollectionParaView::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo2()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo3()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnCbnSelchangeCombo4()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo5()
{
	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnEnChangeEditDelayblockcount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnEnChangeEditTriggercount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnEnChangeEditCollectionbatchs()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}
