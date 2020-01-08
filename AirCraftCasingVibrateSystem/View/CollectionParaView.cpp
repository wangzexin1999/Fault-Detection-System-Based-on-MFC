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

void CollectionParaView::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO1, m_sampleFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO2, m_analysisFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO3, m_collectionMethodCombo);
	DDX_Control(pDX, IDC_COMBO_COLLECTION_POINTS, m_collectionPointCombo);
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COLLECTION_TIMES, m_collectionTimesEdit);
}

BEGIN_MESSAGE_MAP(CollectionParaView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CollectionParaView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CollectionParaView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CollectionParaView::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTION_POINTS, &CollectionParaView::OnCbnSelchangeComboCollectionPoints)
	ON_EN_CHANGE(IDC_EDIT_COLLECTION_TIMES, &CollectionParaView::OnEnChangeEditCollectionTimes)
END_MESSAGE_MAP()


// CollectionParaView 消息处理程序

BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CollectionParaInfoInit();
	return TRUE; 
}


void CollectionParaView::SaveTestingDevice(TbTestingDevice &testingDevice){
	int index = m_sampleFrequencyCombo.GetCurSel();
	testingDevice.SetSampleFrequency(m_vsampleFrequency[index]);

	index = m_analysisFrequencyCombo.GetCurSel();
	testingDevice.SetAnalysisFrequency(m_vanalysisFrequency[index]);

	index = m_collectionMethodCombo.GetCurSel();
	testingDevice.SetCollectionMethod(m_vcollectionMethod[index]);


	index = m_collectionPointCombo.GetCurSel();
	testingDevice.SetCollectionPoint(m_vcollectionPoint[index]);

	CString collectionTimes;
	m_collectionTimesEdit.GetWindowTextA(collectionTimes);
	testingDevice.SetCollectionTimes(atoi(collectionTimes));
	TestingDeviceController m_testingDeviceServiceController;
	Result res = m_testingDeviceServiceController.UpdateTestingDevice(testingDevice);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}

	///调整坐标系的大小
	for (int i = 0; i < theApp.m_vsignalCaptureView.size(); i++){
		theApp.m_vsignalCaptureView[i]->SetChartXYCoordinateLen();
	}
}

void CollectionParaView::CollectionParaInfoInit(){
	////解析下拉框的选项
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	Result res;
	int curSel = 0;
	res = m_dictionaryController.FindAllBySearchCondition(m_vsampleFrequency, 0, "samplefrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集频率失败");
	}
	else{
		for (int i = 0; i < m_vsampleFrequency.size(); i++){

			TbDictionary sample = m_vsampleFrequency[i];
			Document doc;
			doc.Parse(sample.GetDictValue());
			const Value& title = doc["title"];
			sample.SetDictValue(title.GetString());
			//TbDictionary collecionFrequency = m_vsampleFrequency[i];
			TbDictionary sampleFrequency = sample;
			m_sampleFrequencyCombo.InsertString(i, sampleFrequency.GetDictValue());
			if (testingDevice.GetSampleFrequency().GetDictId() == sampleFrequency.GetDictId()){
				curSel = i;
			}
		}
		m_sampleFrequencyCombo.SetCurSel(curSel);
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
	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionPoint, 0, "collectionpoint");

	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集点数失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_vcollectionPoint.size(); i++){
			TbDictionary collectionPoint = m_vcollectionPoint[i];
			m_collectionPointCombo.InsertString(i, collectionPoint.GetDictValue());
			if (collectionPoint.GetDictId() == testingDevice.GetCollectionPoint().GetDictId()){
				curSel = i;
			}
		}
		m_collectionPointCombo.SetCurSel(curSel);
	}
	m_collectionTimesEdit.SetWindowTextA(CommonUtil::Int2CString(testingDevice.GetCollectionTimes()));
	
}

void CollectionParaView::RefreshView(){
	///1.删除所有下拉框的选项，并清空
	m_sampleFrequencyCombo.ResetContent();
	m_vsampleFrequency.clear();
	m_collectionMethodCombo.ResetContent();
	m_vcollectionMethod.clear();
	m_analysisFrequencyCombo.ResetContent();
	m_vanalysisFrequency.clear();
	m_collectionPointCombo.ResetContent();
	m_vcollectionPoint.clear();
	///2.采集参数重新初始化
	CollectionParaInfoInit();
}

void CollectionParaView::OnCbnSelchangeCombo1()
{
	int index = m_sampleFrequencyCombo.GetCurSel();
	Value sampleFre;
	Value analysisFre;
	m_jsonUtil.GetValueFromJsonString(m_vsampleFrequency[index].GetDictValue(), "content", sampleFre);
	for (int i = 0; i < m_vanalysisFrequency.size(); i++){
		m_jsonUtil.GetValueFromJsonString(m_vanalysisFrequency[i].GetDictValue(), "content", analysisFre);
		if (analysisFre.GetDouble() == (sampleFre.GetDouble() / 2.56)){
			m_analysisFrequencyCombo.SetCurSel(i);
			analysisFrequencyCurSel = i;
		}
	}
	SaveTestingDevice(theApp.m_currentProject.GetTestingDevice());
}


void CollectionParaView::OnCbnSelchangeCombo2()
{
	int index_sample = m_sampleFrequencyCombo.GetCurSel();
	int index_analysis = m_analysisFrequencyCombo.GetCurSel();
	Value sampleFre;
	Value analysisFre;
	m_jsonUtil.GetValueFromJsonString(m_vsampleFrequency[index_sample].GetDictValue(), "content", sampleFre);
	m_jsonUtil.GetValueFromJsonString(m_vanalysisFrequency[index_analysis].GetDictValue(), "content", analysisFre);
	if (analysisFre.GetDouble() <= (sampleFre.GetDouble() / 2.56))
	{
		m_analysisFrequencyCombo.SetCurSel(index_analysis);
	}
	else
	{
		m_analysisFrequencyCombo.SetCurSel(analysisFrequencyCurSel);
	}
	SaveTestingDevice(theApp.m_currentProject.GetTestingDevice());
}


void CollectionParaView::OnCbnSelchangeCombo3()
{
	// TODO:  在此添加控件通知处理程序代码
	SaveTestingDevice(theApp.m_currentProject.GetTestingDevice());
}

void CollectionParaView::OnCbnSelchangeComboCollectionPoints()
{
	SaveTestingDevice(theApp.m_currentProject.GetTestingDevice());
}


void CollectionParaView::OnEnChangeEditCollectionTimes()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	SaveTestingDevice(theApp.m_currentProject.GetTestingDevice());
}
