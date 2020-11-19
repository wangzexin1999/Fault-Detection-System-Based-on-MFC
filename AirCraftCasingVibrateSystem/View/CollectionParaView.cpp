// SersorParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaView.h"
#include "afxdialogex.h"
#include "TbCollectionparas.h"
#include "CommonUtil.h"
#include "CollectionparasController.h"
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
	DDX_Control(pDX, IDC_EDIT_COLLECTION_TIMES, m_sampleBatchEdit);
}

BEGIN_MESSAGE_MAP(CollectionParaView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CollectionParaView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CollectionParaView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CollectionParaView::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTION_POINTS, &CollectionParaView::OnCbnSelchangeComboCollectionPoints)
	ON_EN_CHANGE(IDC_EDIT_COLLECTION_TIMES, &CollectionParaView::OnEnChangeEditSampleBatch)
END_MESSAGE_MAP()


// CollectionParaView 消息处理程序

BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CollectionParaInfoInit();
	return TRUE; 
}


void CollectionParaView::SaveCollectionparas(TbCollectionparas &collectionparas){

	int index = m_sampleFrequencyCombo.GetCurSel();
	TbDictionary samplefrequency = m_DsampleFrequency[index];
	Document samplefrequency_doc;
	samplefrequency_doc.Parse(samplefrequency.GetDictValue());
	const Value& samplefrequency_content = samplefrequency_doc["content"];
	collectionparas.SetSampleFrequency(samplefrequency_doc["content"].GetDouble());


	index = m_analysisFrequencyCombo.GetCurSel();
	TbDictionary analysisfrequency = m_DanalysisFrequency[index];
	Document analysisfrequency_doc;
	analysisfrequency_doc.Parse(analysisfrequency.GetDictValue());
	const Value& analysisfrequency_content = analysisfrequency_doc["content"];
	collectionparas.SetAnalysisFrequency(analysisfrequency_doc["content"].GetDouble());

	index = m_collectionMethodCombo.GetCurSel();
	collectionparas.SetCollectionMethod(m_vcollectionMethod[index]);


	index = m_collectionPointCombo.GetCurSel();
	collectionparas.SetCollectionPoint(m_vcollectionPoint[index]);

	CString sampleBatch;
	m_sampleBatchEdit.GetWindowTextA(sampleBatch);
	collectionparas.SetSampleBatch(atoi(sampleBatch));
	CollectionparasController m_collectionparasServiceController;
	Result res = m_collectionparasServiceController.UpdateCollectionparas(collectionparas);
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
	TbCollectionparas collectionparas = theApp.m_currentProject.GetCollectionparas();
	Result res;
	int curSel = 0;
	res = m_dictionaryController.FindAllBySearchCondition(m_DsampleFrequency, 0, "samplefrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集频率失败");
	}
	else{
		for (int i = 0; i < m_DsampleFrequency.size(); i++){

			TbDictionary sample = m_DsampleFrequency[i];
			Document doc;
			doc.Parse(sample.GetDictValue());
			const Value& title = doc["title"];
			const Value& content = doc["content"];
			sample.SetDictValue(title.GetString());
			//TbDictionary collecionFrequency = m_vsampleFrequency[i];
			TbDictionary sampleFrequency = sample;
			m_sampleFrequencyCombo.InsertString(i, sampleFrequency.GetDictValue());
			if (collectionparas.GetSampleFrequency() == doc["content"].GetDouble()){
				curSel = i;
			}
		}
		m_sampleFrequencyCombo.SetCurSel(curSel);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_DanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载分析频率失败");
	}
	else{
		curSel = 0;
		for (int i = 0; i < m_DanalysisFrequency.size(); i++){

			TbDictionary analysis = m_DanalysisFrequency[i];
			Document doc;
			doc.Parse(analysis.GetDictValue());
			const Value& title = doc["title"];
			const Value& content = doc["content"];
			analysis.SetDictValue(title.GetString());
			//TbDictionary analysisFrequency = m_vanalysisFrequency[i];
			TbDictionary analysisFrequency = analysis;
			m_analysisFrequencyCombo.InsertString(i, analysisFrequency.GetDictValue());
			if (collectionparas.GetAnalysisFrequency() == doc["content"].GetDouble()){
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
			if (collectionMethod.GetDictId() == collectionparas.GetCollectionMethod().GetDictId()){
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
			if (collectionPoint.GetDictId() == collectionparas.GetCollectionPoint().GetDictId()){
				curSel = i;
			}
		}
		m_collectionPointCombo.SetCurSel(curSel);
	}
	m_sampleBatchEdit.SetWindowTextA(CommonUtil::Int2CString(collectionparas.GetSampleBatch()));
	
}

void CollectionParaView::RefreshView(){
	///1.删除所有下拉框的选项，并清空
	m_sampleFrequencyCombo.ResetContent();
	m_DsampleFrequency.clear();
	m_collectionMethodCombo.ResetContent();
	m_vcollectionMethod.clear();
	m_analysisFrequencyCombo.ResetContent();
	m_DanalysisFrequency.clear();
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
	m_jsonUtil.GetValueFromJsonString(m_DsampleFrequency[index].GetDictValue(), "content", sampleFre);
	for (int i = 0; i < m_DanalysisFrequency.size(); i++){
		m_jsonUtil.GetValueFromJsonString(m_DanalysisFrequency[i].GetDictValue(), "content", analysisFre);
		if (analysisFre.GetDouble() == (sampleFre.GetDouble() / 2.56)){
			m_analysisFrequencyCombo.SetCurSel(i);
			analysisFrequencyCurSel = i;
		}
	}
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}


void CollectionParaView::OnCbnSelchangeCombo2()
{
	int index_sample = m_sampleFrequencyCombo.GetCurSel();
	int index_analysis = m_analysisFrequencyCombo.GetCurSel();
	Value sampleFre;
	Value analysisFre;
	m_jsonUtil.GetValueFromJsonString(m_DsampleFrequency[index_sample].GetDictValue(), "content", sampleFre);
	m_jsonUtil.GetValueFromJsonString(m_DanalysisFrequency[index_analysis].GetDictValue(), "content", analysisFre);
	if (analysisFre.GetDouble() <= (sampleFre.GetDouble() / 2.56))
	{
		m_analysisFrequencyCombo.SetCurSel(index_analysis);
	}
	else
	{
		m_analysisFrequencyCombo.SetCurSel(analysisFrequencyCurSel);
	}
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}


void CollectionParaView::OnCbnSelchangeCombo3()
{
	// TODO:  在此添加控件通知处理程序代码
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}

void CollectionParaView::OnCbnSelchangeComboCollectionPoints()
{
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}


void CollectionParaView::OnEnChangeEditSampleBatch()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}
