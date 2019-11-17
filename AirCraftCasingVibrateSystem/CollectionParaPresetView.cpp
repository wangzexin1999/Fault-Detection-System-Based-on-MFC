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
	DDX_Control(pDX, IDC_COMBO_COLLECTIONPOINT, m_collectionPointCombo);
	DDX_Control(pDX, IDC_EDIT_COLLECTIONTIMES, m_collectionTimesEdit);

}


BEGIN_MESSAGE_MAP(CollectionParaPresetView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONFREQUENCY, &CollectionParaPresetView::OnCbnSelchangeComboCollectionfrequency)
END_MESSAGE_MAP()


// CollectionParaPresetView 消息处理程序


BOOL CollectionParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////查询所有可以选择的参数
	CollectionParaInfoInit();
	return TRUE; 
}
void CollectionParaPresetView::GetSelectedTestingDevice(TbTestingDevice &testingDevicePara){
	int index = m_collectionFrequencyCombo.GetCurSel();
	testingDevicePara.SetCollectionFrequency(m_vcollectionFrequency[index]);

	index = m_analysisFrequencyCombo.GetCurSel();
	testingDevicePara.SetAnalysisFrequency(m_vanalysisFrequency[index]);

	index = m_collectionPointCombo.GetCurSel(); 
	testingDevicePara.SetCollectionPoint(m_vcollectionPoint[index]);

	index = m_collectionMethodCombo.GetCurSel();
	testingDevicePara.SetCollectionMethod(m_vcollectionMethod[index]);
	CString  collectionTimes;

	m_collectionTimesEdit.GetWindowTextA(collectionTimes);
	testingDevicePara.SetCollectionTimes(atoi(collectionTimes));
}

void CollectionParaPresetView::CollectionParaInfoInit(){
	Result res;
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
		}
		m_collectionFrequencyCombo.SetCurSel(0);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("加载分析频率失败");
	}
	else{
		int cursel = 0;
		for (int i = 0; i < m_vanalysisFrequency.size(); i++){
			TbDictionary analysis = m_vanalysisFrequency[i];
			Document doc;
			doc.Parse(analysis.GetDictValue());
			const Value& title = doc["title"];
			analysis.SetDictValue(title.GetString());

			TbDictionary analysisFrequency = analysis;
			m_analysisFrequencyCombo.InsertString(i, analysisFrequency.GetDictValue());

			int index = m_collectionFrequencyCombo.GetCurSel();
			TbDictionary collection = m_vcollectionFrequency[index];
			Document collection_doc;
			collection_doc.Parse(collection.GetDictValue());
			const Value& collection_content = collection_doc["content"];


			if (doc["content"].GetDouble() == (collection_doc["content"].GetDouble() / 2.56))
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

void CollectionParaPresetView::OnCbnSelchangeComboCollectionfrequency()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_collectionFrequencyCombo.GetCurSel();
	TbDictionary collection = m_vcollectionFrequency[index];
	Document collection_doc;
	collection_doc.Parse(collection.GetDictValue());
	const Value& collection_content = collection_doc["content"];

	int cursel = 0;
	for (int i = 0; i < m_vanalysisFrequency.size(); i++){
		TbDictionary analysis = m_vanalysisFrequency[i];
		Document analysis_doc;
		analysis_doc.Parse(analysis.GetDictValue());
		const Value& analysis_content = analysis_doc["content"];
		if (analysis_doc["content"].GetDouble() == (collection_doc["content"].GetDouble() / 2.56))
		{
			cursel = i;
		}
	}
	m_analysisFrequencyCombo.SetCurSel(cursel);

}
