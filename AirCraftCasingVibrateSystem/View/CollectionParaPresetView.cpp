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
	//DDX_Control(pDX, IDC_COMBO_COLLECTIONFREQUENCY, m_sampleFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO_SAMPLEFREQUENCY, m_sampleFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONMETHOD, m_collectionMethodCombo);
	DDX_Control(pDX, IDC_COMBO_ANALYSISFREQUENCY, m_analysisFrequencyCombo);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONPOINT, m_collectionPointCombo);
	DDX_Control(pDX, IDC_EDIT_COLLECTIONTIMES, m_sampleBatchEdit);

}


BEGIN_MESSAGE_MAP(CollectionParaPresetView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONFREQUENCY, &CollectionParaPresetView::OnCbnSelchangeComboSamplefrequency)
END_MESSAGE_MAP()


// CollectionParaPresetView 消息处理程序


BOOL CollectionParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////查询所有可以选择的参数
	CollectionParaInfoInit();
	return TRUE; 
}

void CollectionParaPresetView::GetSelectedCollectionparas(TbCollectionparas &collectionparasPara){
	int index = m_sampleFrequencyCombo.GetCurSel();
	TbDictionary samplefrequency = m_DsampleFrequency[index];
	Document samplefrequency_doc;
	samplefrequency_doc.Parse(samplefrequency.GetDictValue());
	const Value& samplefrequency_content = samplefrequency_doc["content"];
	//collectionparasPara.SetSampleFrequency(samplefrequency_doc["content"].GetDouble());

	index = m_collectionMethodCombo.GetCurSel();
	collectionparasPara.SetCollectionMethod(m_vcollectionMethod[index]);
	CString  sampleBatch;

	m_sampleBatchEdit.GetWindowTextA(sampleBatch);
	collectionparasPara.SetSampleBatch(atoi(sampleBatch));
}

void CollectionParaPresetView::CollectionParaInfoInit(){
	Result res;
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

			sample.SetDictValue(title.GetString());
			//TbDictionary collecionFrequency = m_vcollectionFrequency[i];
			TbDictionary sampleFrequency = sample;
			m_sampleFrequencyCombo.InsertString(i, sampleFrequency.GetDictValue());
		}
		m_sampleFrequencyCombo.SetCurSel(0);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_DanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载分析频率失败");
	}
	else{
		int cursel = 0;
		for (int i = 0; i < m_DanalysisFrequency.size(); i++){
			TbDictionary analysis = m_DanalysisFrequency[i];
			Document doc;
			doc.Parse(analysis.GetDictValue());
			const Value& title = doc["title"];
			analysis.SetDictValue(title.GetString());

			TbDictionary analysisFrequency = analysis;
			m_analysisFrequencyCombo.InsertString(i, analysisFrequency.GetDictValue());

			int index = m_sampleFrequencyCombo.GetCurSel();
			TbDictionary collection = m_DsampleFrequency[index];
			Document collection_doc;
			collection_doc.Parse(collection.GetDictValue());
			const Value& collection_content = collection_doc["content"];


			if (doc["content"].GetDouble() == (collection_doc["content"].GetDouble() / theApp.FFTRATE))
			{
				//m_analysisFrequencyCombo.SetCurSel(i);
				cursel = i;
			}
		}
		m_analysisFrequencyCombo.SetCurSel(cursel);
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



	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionPoint, 0, "collectionpoint");

	if (!res.GetIsSuccess()){
		AfxMessageBox("加载采集点数失败");
	}
	else{
		for (int i = 0; i < m_vcollectionPoint.size(); i++){
			TbDictionary collectionPoint = m_vcollectionPoint[i];
			m_collectionPointCombo.InsertString(i, collectionPoint.GetDictValue());
		}
		m_collectionPointCombo.SetCurSel(0);
	}

}

void CollectionParaPresetView::OnCbnSelchangeComboSamplefrequency()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_sampleFrequencyCombo.GetCurSel();
	TbDictionary collection = m_DsampleFrequency[index];
	Document collection_doc;
	collection_doc.Parse(collection.GetDictValue());
	const Value& collection_content = collection_doc["content"];

	int cursel = 0;
	for (int i = 0; i < m_DanalysisFrequency.size(); i++){
		TbDictionary analysis = m_DanalysisFrequency[i];
		Document analysis_doc;
		analysis_doc.Parse(analysis.GetDictValue());
		const Value& analysis_content = analysis_doc["content"];
		if (analysis_doc["content"].GetDouble() == (collection_doc["content"].GetDouble() / theApp.FFTRATE))
		{
			cursel = i;
		}
	}
	m_analysisFrequencyCombo.SetCurSel(cursel);

}
