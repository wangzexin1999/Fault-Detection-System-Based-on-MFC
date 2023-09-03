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
	DDX_Control(pDX, IDC_EDIT_COLLECTIONTIMES, m_sampleBatchEdit);

	DDX_Control(pDX, IDC_EDIT1, m_lineEdit);
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
	collectionparasPara.SetSampleFrequency(std::make_pair(index,theApp.m_listSampleFreq[index]));
	CString line;
	m_lineEdit.GetWindowTextA(line);
	collectionparasPara.SetLine(CommonUtil::CString2Int(line));

	//index = m_collectionMethodCombo.GetCurSel();
	//collectionparasPara.SetCollectionMethod(m_vcollectionMethod[index]);
	CString  sampleBatch;
	m_sampleBatchEdit.GetWindowTextA(sampleBatch);
	collectionparasPara.SetSampleBatch(atoi(sampleBatch));
}

void CollectionParaPresetView::CollectionParaInfoInit(){

	theApp.m_listSampleFreq.clear();
	m_dhTestHardWareController.GetSampleFreqList(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_listSampleFreq);
	for (int i = 0; i < theApp.m_listSampleFreq.size(); i++){
		m_sampleFrequencyCombo.InsertString(i, CommonUtil::Int2CString(theApp.m_listSampleFreq[i]));
	}
	m_sampleFrequencyCombo.SetCurSel(0);
	m_lineEdit.SetWindowTextA(CommonUtil::Int2CString(theApp.m_listSampleFreq[0]/2.56));
}

void CollectionParaPresetView::OnCbnSelchangeComboSamplefrequency()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_sampleFrequencyCombo.GetCurSel();
	m_lineEdit.SetWindowTextA(CommonUtil::Int2CString(theApp.m_listSampleFreq[index] / 2.56));
}
