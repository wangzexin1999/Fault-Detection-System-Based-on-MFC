// SersorParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaView.h"
#include "afxdialogex.h"
#include "TbTestingDevice.h"

// CollectionParaView �Ի���

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
END_MESSAGE_MAP()


// CollectionParaView ��Ϣ�������


BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CollectionParaInit();
	return TRUE; 
}

void CollectionParaView::CollectionParaInit(){
	////�õ�ȫ�ֵ���Ŀ����Ĳɼ��豸
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	Result res;
	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionFrequency, 0, "collectionfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("���زɼ�Ƶ��ʧ��");
	}
	else{
		for (int i = 0; i < m_vcollectionFrequency.size(); i++){
			TbDictionary collecionFrequency = m_vcollectionFrequency[i];
			m_collectionFrequencyCombo.InsertString(i, collecionFrequency.GetDictValue());
		}
		m_collectionFrequencyCombo.SetCurSel(0);
	}

	res = m_dictionaryController.FindAllBySearchCondition(m_vanalysisFrequency, 0, "analysisfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("���ط���Ƶ��ʧ��");
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
		AfxMessageBox("���زɼ���ʽʧ��");
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
		AfxMessageBox("��ѯ���ݿ���ʧ��");
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
		AfxMessageBox("��ѯ������ʽʧ��");
	}
	else{
		for (int i = 0; i < m_vtriggerMethod.size(); i++){
			TbDictionary triggerMethod = m_vtriggerMethod[i];
			m_triggerMethodCombo.InsertString(i, triggerMethod.GetDictValue());
		}
		m_triggerMethodCombo.SetCurSel(0);
	}
}