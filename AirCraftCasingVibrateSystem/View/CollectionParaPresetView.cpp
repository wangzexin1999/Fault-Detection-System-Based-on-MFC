// CollectionParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaPresetView.h"
#include "afxdialogex.h"


// CollectionParaPresetView �Ի���

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
	DDX_Control(pDX, IDC_EDIT_COLLECTIONTIMES, m_collectionTimesEdit);

}


BEGIN_MESSAGE_MAP(CollectionParaPresetView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONFREQUENCY, &CollectionParaPresetView::OnCbnSelchangeComboSamplefrequency)
END_MESSAGE_MAP()


// CollectionParaPresetView ��Ϣ�������


BOOL CollectionParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////��ѯ���п���ѡ��Ĳ���
	CollectionParaInfoInit();
	return TRUE; 
}
void CollectionParaPresetView::GetSelectedTestingDevice(TbTestingDevice &testingDevicePara){
	int index = m_sampleFrequencyCombo.GetCurSel();
	testingDevicePara.SetSampleFrequency(m_vsampleFrequency[index]);

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
	res = m_dictionaryController.FindAllBySearchCondition(m_vsampleFrequency, 0, "samplefrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("���زɼ�Ƶ��ʧ��");
	}
	else{
		for (int i = 0; i < m_vsampleFrequency.size(); i++){
			TbDictionary sample = m_vsampleFrequency[i];
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

	res = m_dictionaryController.FindAllBySearchCondition(m_vanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("���ط���Ƶ��ʧ��");
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

			int index = m_sampleFrequencyCombo.GetCurSel();
			TbDictionary collection = m_vsampleFrequency[index];
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
		AfxMessageBox("���زɼ���ʽʧ��");
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
		AfxMessageBox("���زɼ�����ʧ��");
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int index = m_sampleFrequencyCombo.GetCurSel();
	TbDictionary collection = m_vsampleFrequency[index];
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
