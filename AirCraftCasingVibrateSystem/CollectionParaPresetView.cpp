// CollectionParaPresetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaPresetView.h"
#include "afxdialogex.h"


// CollectionParaPresetView 对话框

IMPLEMENT_DYNAMIC(CollectionParaPresetView, CDialogEx)

CollectionParaPresetView::CollectionParaPresetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CollectionParaPresetView::IDD, pParent)
{

}

CollectionParaPresetView::~CollectionParaPresetView()
{
}

void CollectionParaPresetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONFREQUENCY, m_collectionFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONMETHOD, m_collectionMethodCombo);
	DDX_Control(pDX, IDC_COMBO_ANALYSISFREQUENCY, m_analysisFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO_TRIGGERMETHOD, m_triggerMethodCombo);
	DDX_Control(pDX, IDC_COMBO_DATABLOCKCOUNT, m_dataBlockCountCombo);
	DDX_Control(pDX, IDC_EDIT_TRIGGERCOUNT, m_triggerCountEdit);
	DDX_Control(pDX, IDC_EDIT_DELAYBLOCKCOUNT, m_delayBlockCountEdit);
	DDX_Control(pDX, IDC_EDIT_COLLECTIONBATCH, m_collectionBatchEdit);
}


BEGIN_MESSAGE_MAP(CollectionParaPresetView, CDialogEx)
END_MESSAGE_MAP()


// CollectionParaPresetView 消息处理程序


BOOL CollectionParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////查询所有可以选择的参数
	Result res;

	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionFrequency, 0, "collectionfrequency");
	if (!res.GetIsSuccess()){ 
		AfxMessageBox("加载采集频率失败"); 
	}else{
		for (int i = 0; i < m_vcollectionFrequency.size();i++){
			TbDictionary collecionFrequency = m_vcollectionFrequency[i];
			m_collectionFrequencyCombo.InsertString(i,collecionFrequency.GetDictValue());
		}
		m_collectionFrequencyCombo.SetCurSel(0);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载分析频率失败");
	}
	else{
		for (int i = 0; i < m_vanalysisFrequency.size(); i++){
			TbDictionary analysisFrequency = m_vanalysisFrequency[i];
			m_analysisFrequencyCombo.InsertString(i, analysisFrequency.GetDictValue());
		}
		m_analysisFrequencyCombo.SetCurSel(0);
	}
	
	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionMethod, 0, "collectionmethod");

	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集方式失败");
	}
	else{
		for (int i = 0; i < m_vcollectionMethod.size(); i++){
			TbDictionary collectionMethod = m_vcollectionMethod[i];
			m_collectionMethodCombo.InsertString(i, collectionMethod.GetDictValue());
		}
		m_collectionMethodCombo.SetCurSel(0);
	}

	
	res = m_dictionaryController.FindAllBySearchCondition(m_vdataBlockCount, 0, "datablockcount");
	
	if (!res.GetIsSuccess()){
		AfxMessageBox("查询数据块数失败");
	}
	else{
		for (int i = 0; i < m_vdataBlockCount.size(); i++){
			TbDictionary dataBlockCount = m_vdataBlockCount[i];
			m_dataBlockCountCombo.InsertString(i, dataBlockCount.GetDictValue());
		}
		m_dataBlockCountCombo.SetCurSel(0);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vtriggerMethod, 0, "triggermethod");

	if (!res.GetIsSuccess()){
		AfxMessageBox("查询触发方式失败");
	}
	else{
		for (int i = 0; i < m_vtriggerMethod.size(); i++){
			TbDictionary triggerMethod = m_vtriggerMethod[i];
			m_triggerMethodCombo.InsertString(i, triggerMethod.GetDictValue());
		}
		m_triggerMethodCombo.SetCurSel(0);
	}

	return TRUE; 
}
void CollectionParaPresetView::GetSelectedTestingDevice(TbTestingDevice &testingDevicePara){
	int index = m_collectionFrequencyCombo.GetCurSel();
	testingDevicePara.SetCollectionFrequency(m_vcollectionFrequency[index]);

	index = m_analysisFrequencyCombo.GetCurSel();
	testingDevicePara.SetAnalysisFrequency(m_vanalysisFrequency[index]);

	index = m_triggerMethodCombo.GetCurSel(); 
	testingDevicePara.SetTriggerMethod(m_vtriggerMethod[index]);

	index = m_collectionMethodCombo.GetCurSel();
	testingDevicePara.SetCollectionMethod(m_vcollectionMethod[index]);

	index = m_dataBlockCountCombo.GetCurSel();
	testingDevicePara.SetDatablockCount(m_vdataBlockCount[index]);

	CString delayBlockCount, triggerCount, collectionBaths;

	m_collectionBatchEdit.GetWindowTextA(collectionBaths);
	m_delayBlockCountEdit.GetWindowTextA(delayBlockCount);
	m_triggerCountEdit.GetWindowTextA(triggerCount);
	testingDevicePara.SetCollectionBatchs(atoi(collectionBaths));
	testingDevicePara.SetDelayblockCount(atoi(delayBlockCount));
	testingDevicePara.SetTriggerCount(atoi(triggerCount));
}