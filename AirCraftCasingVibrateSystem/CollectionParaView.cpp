// SersorParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaView.h"
#include "afxdialogex.h"
#include "TbTestingDevice.h"
#include "CommonUtil.h"
#include "TestingDeviceController.h"
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
	ON_CBN_SELCHANGE(IDC_COMBO1, &CollectionParaView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CollectionParaView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CollectionParaView::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CollectionParaView::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CollectionParaView::OnCbnSelchangeCombo5)
	ON_EN_CHANGE(IDC_EDIT_DELAYBLOCKCOUNT, &CollectionParaView::OnEnChangeEditDelayblockcount)
	ON_EN_CHANGE(IDC_EDIT_TRIGGERCOUNT, &CollectionParaView::OnEnChangeEditTriggercount)
	ON_EN_CHANGE(IDC_EDIT_COLLECTIONBATCHS, &CollectionParaView::OnEnChangeEditCollectionbatchs)
END_MESSAGE_MAP()


// CollectionParaView ��Ϣ�������

BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CollectionParaInfoInit();
	return TRUE; 
}
void CollectionParaView::GetSelectedTestingDevice(TbTestingDevice &testingDevice){
	int index = m_collectionFrequencyCombo.GetCurSel();
	//m_collectionFrequencyCombo.GetLBText(index, strInfo1);//ͨ��������ȡ��Ӧ��ֵ
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
	////�����������ѡ��
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	Result res;
	int curSel = 0;
	res = m_dictionaryController.FindAllBySearchCondition(m_vcollectionFrequency, 0, "collectionfrequency");
	if (!res.GetIsSuccess()){
		AfxMessageBox("���زɼ�Ƶ��ʧ��");
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
		AfxMessageBox("���ط���Ƶ��ʧ��");
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
		AfxMessageBox("���زɼ���ʽʧ��");
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
		AfxMessageBox("��ѯ���ݿ���ʧ��");
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
		AfxMessageBox("��ѯ������ʽʧ��");
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
	///1.ɾ�������������ѡ������
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
	///2.�ɼ��������³�ʼ��
	CollectionParaInfoInit();
}

void CollectionParaView::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnCbnSelchangeCombo4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnCbnSelchangeCombo5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}


void CollectionParaView::OnEnChangeEditDelayblockcount()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnEnChangeEditTriggercount()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}



void CollectionParaView::OnEnChangeEditCollectionbatchs()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbTestingDevice testingDevice = theApp.m_currentProject.GetTestingDevice();
	GetSelectedTestingDevice(testingDevice);
}
