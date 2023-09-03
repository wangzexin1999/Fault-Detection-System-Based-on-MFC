// SersorParaView.cpp : 实现文件
//
#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionParaView.h"
#include "afxdialogex.h"
#include "TbCollectionparas.h"
#include "CommonUtil.h"
#include "CollectionparasController.h"
#include <sstream> 
// CollectionParaView 对话框

IMPLEMENT_DYNAMIC(CollectionParaView, CDialogEx)

CollectionParaView::CollectionParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CollectionParaView::IDD, pParent){
}

CollectionParaView::~CollectionParaView()
{
}  

void CollectionParaView::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO_FREQ, m_sampleFrequencyCombo);
	//DDX_Control(pDX, IDC_COMBO3, m_collectionMethodCombo);
	//DDX_Control(pDX, IDC_COMBO_COLLECTION_POINTS, m_collectionPointCombo);
	DDX_Control(pDX, IDC_COMBO_CLOCKMODE, m_ComboSampleClock);
	DDX_Control(pDX, IDC_EDIT_COLLECTION_TIMES, m_sampleBatchEdit);
	DDX_Control(pDX, IDC_EDIT1, m_line);
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CollectionParaView, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CollectionParaView::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CollectionParaView::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CollectionParaView::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTION_POINTS, &CollectionParaView::OnCbnSelchangeComboCollectionPoints)
	ON_CBN_SELCHANGE(IDC_COMBO_CLOCKMODE, &CollectionParaView::OnCbnSelchangeComboClock)
	ON_EN_CHANGE(IDC_EDIT_COLLECTION_TIMES, &CollectionParaView::OnEnChangeEditSampleBatch)
	ON_EN_CHANGE(IDC_EDIT1, &CollectionParaView::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO_FREQ, &CollectionParaView::OnCbnSelchangeComboFreq)
END_MESSAGE_MAP()

// CollectionParaView 消息处理程序

BOOL CollectionParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CollectionParaInfoInit();
	m_dhTestHardWareController.GetSampleParam(theApp.m_pHardWare,m_SampleParam);
	InitSampleClock();
	
	theApp.m_pHardWare->SetSampleMode(m_SampleParam.m_nSampleMode, &lReturnValue);
	theApp.m_pHardWare->SetSampleTrigMode(m_SampleParam.m_nSampleTrigMode, &lReturnValue);
	theApp.m_pHardWare->SetTrigBlockCount(m_SampleParam.m_nSampleBlockSize, &lReturnValue);
	theApp.m_pHardWare->SetTrigDelayCount(m_SampleParam.m_nSampleDelayPoints, &lReturnValue);
	m_line.SetWindowTextA(CommonUtil::Int2CString(theApp.m_currentProject.GetCollectionparas().GetLine()));
	m_sampleFrequencyCombo.SetCurSel(theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().first);
	return TRUE; 
}

void CollectionParaView::SaveCollectionparas(TbCollectionparas &collectionparas){
	CString strChoosed;
	int index = m_sampleFrequencyCombo.GetCurSel();
	m_sampleFrequencyCombo.GetLBText(index, strChoosed);
	collectionparas.SetSampleFrequency(std::make_pair(index, CommonUtil::CString2Int(strChoosed))); //samplefrequency_doc["content"].GetDouble()

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

void CollectionParaView::InitSampleClock()
{
	m_ComboSampleClock.ResetContent();
	m_ComboSampleClock.AddString("内部时钟");
	m_ComboSampleClock.AddString("外部时钟");

	int nSampleClock = m_SampleParam.m_nSampleClkMode;
	m_ComboSampleClock.SetCurSel(nSampleClock);
}

void CollectionParaView::OnCbnSelchangeComboClock()
{
	string strSampleParam;
	long lReturnValue;
	CString strText;
	m_ComboSampleClock.GetLBText(m_ComboSampleClock.GetCurSel(), strText);
	if (strText == "内部时钟")
	{
		m_SampleParam.m_nSampleClkMode = 0;
	}
	else
	{
		m_SampleParam.m_nSampleClkMode = 1;
	}
	//设置采样参数
	theApp.m_pHardWare->SetSampleClockMode(m_SampleParam.m_nSampleClkMode, &lReturnValue);
}

void CollectionParaView::CollectionParaInfoInit(){
	////解析下拉框的选项
	TbCollectionparas collectionparas = theApp.m_currentProject.GetCollectionparas();
	theApp.m_listSampleFreq.clear();
	m_dhTestHardWareController.GetSampleFreqList(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_listSampleFreq);
	for (int i = 0; i < theApp.m_listSampleFreq.size(); i++){
		m_sampleFrequencyCombo.InsertString(i, CommonUtil::Int2CString(theApp.m_listSampleFreq[i]));
	}
	m_sampleFrequencyCombo.SetCurSel(theApp.m_currentProject.GetCollectionparas().GetSampleFrequency().first);
	m_line.SetWindowTextA(CommonUtil::Int2CString(theApp.m_currentProject.GetCollectionparas().GetLine()));
}

void CollectionParaView::RefreshView(){
	///1.删除所有下拉框的选项，并清空
	m_sampleFrequencyCombo.ResetContent();
	//m_collectionMethodCombo.ResetContent();
	//m_collectionPointCombo.ResetContent();
	///2.采集参数重新初始化
	CollectionParaInfoInit();
}

void CollectionParaView::OnCbnSelchangeCombo1()
{
	string strSampleParam;
	long lReturnValue;
	CString strText;
	m_sampleFrequencyCombo.GetLBText(m_sampleFrequencyCombo.GetCurSel(), strText);
	float fltSampleFrequency = atof(strText);
	m_SampleParam.m_fltSampleFrequency = fltSampleFrequency;
	//设置采样参数
	////取消设置采集参数
}


void CollectionParaView::OnCbnSelchangeCombo2()
{
	int index_sample = m_sampleFrequencyCombo.GetCurSel();
	Value sampleFre;
	Value analysisFre;
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}

void CollectionParaView::OnCbnSelchangeCombo3()
{
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}

void CollectionParaView::OnCbnSelchangeComboCollectionPoints()
{
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}

void CollectionParaView::OnEnChangeEditSampleBatch()
{
	SaveCollectionparas(theApp.m_currentProject.GetCollectionparas());
}

void CollectionParaView::updateCollectionPara(){
	Result res = m_colletionParasController.UpdateCollectionparas(theApp.m_currentProject.GetCollectionparas());

	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
}
void CollectionParaView::OnEnChangeEdit1()
{
	CString line;
	m_line.GetWindowTextA(line);
	theApp.m_currentProject.GetCollectionparas().SetLine(CommonUtil::CString2Int(line));
	updateCollectionPara();
}

void CollectionParaView::OnCbnSelchangeComboFreq()
{
	int index = m_sampleFrequencyCombo.GetCurSel();
	CString val;
	m_sampleFrequencyCombo.GetLBText(index,val);
	theApp.m_currentProject.GetCollectionparas().SetSampleFrequency(std::make_pair(index,CommonUtil::CString2Int(val)));
	for (int i = 0; i < theApp.m_currentProject.GetChannelVector().size(); i++){
		theApp.m_currentProject.GetChannelVector()[i].SetXMax(CommonUtil::CString2Int(val));
	}
	updateCollectionPara();
}
