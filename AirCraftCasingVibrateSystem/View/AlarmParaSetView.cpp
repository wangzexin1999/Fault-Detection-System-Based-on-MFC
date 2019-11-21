// AlarmParaSetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "AlarmParaSetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CAlarmParaSetView 对话框

IMPLEMENT_DYNAMIC(CAlarmParaSetView, CDialogEx)

CAlarmParaSetView::CAlarmParaSetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAlarmParaSetView::IDD, pParent)
{

}

CAlarmParaSetView::~CAlarmParaSetView()
{
}

void CAlarmParaSetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CHANNEL_ALARM, m_checkChannelAlarm);
	DDX_Control(pDX, IDC_CHECK_ALARM_LOG, m_checkAlarmLog);
	DDX_Control(pDX, IDC_CHECK_SOUND_ALARM, m_checkSoundAlarm);
	DDX_Control(pDX, IDC_EDIT_ALARM_LIMIT, m_editAlarmLimit);
}


BEGIN_MESSAGE_MAP(CAlarmParaSetView, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_CHANNEL_ALARM, &CAlarmParaSetView::OnBnClickedCheckChannelAlarm)
	ON_BN_CLICKED(IDC_CHECK_ALARM_LOG, &CAlarmParaSetView::OnBnClickedCheckAlarmLog)
	ON_BN_CLICKED(IDC_CHECK_SOUND_ALARM, &CAlarmParaSetView::OnBnClickedCheckSoundAlarm)
	ON_BN_CLICKED(ID_SAVR_ALARM_SET, &CAlarmParaSetView::OnBnClickedSavrAlarmSet)
END_MESSAGE_MAP()


// CAlarmParaSetView 消息处理程序


BOOL CAlarmParaSetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "..//IniAlarmSet.ini");
	int length = 10;
	LPSTR lpstrTemp = new char[length];

	GetPrivateProfileString(m_strAlarm, "channelAlarm", "", lpstrTemp, length, lpPath);
	m_bChannelAlarm = CommonUtil::CString2Int(lpstrTemp);					       // 曲线颜色
	m_checkChannelAlarm.SetCheck(m_bChannelAlarm);
	GetPrivateProfileString(m_strAlarm, "alarmLog", "", lpstrTemp, length, lpPath);
	m_bAlarmLog = CommonUtil::CString2Int(lpstrTemp);					       // 曲线颜色
	m_checkAlarmLog.SetCheck(m_bAlarmLog);
	GetPrivateProfileString(m_strAlarm, "soundAlarm", "", lpstrTemp, length, lpPath);
	m_bSoundAlarm = CommonUtil::CString2Int(lpstrTemp);					       // 曲线颜色
	m_checkSoundAlarm.SetCheck(m_bSoundAlarm);
	GetPrivateProfileString(m_strAlarm, "alarmLimit", "", lpstrTemp, length, lpPath);
	m_editAlarmLimit.SetWindowTextA(lpstrTemp);
	
	delete[] lpPath;
	delete[] lpstrTemp;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

// 
void CAlarmParaSetView::OnBnClickedCheckChannelAlarm()
{
	// TODO:  在此添加控件通知处理程序代码
	m_bChannelAlarm = m_checkChannelAlarm.GetCheck();
}


void CAlarmParaSetView::OnBnClickedCheckAlarmLog()
{
	// TODO:  在此添加控件通知处理程序代码
	m_bAlarmLog = m_checkAlarmLog.GetCheck();
}


void CAlarmParaSetView::OnBnClickedCheckSoundAlarm()
{
	// TODO:  在此添加控件通知处理程序代码
	m_bSoundAlarm = m_checkSoundAlarm.GetCheck();
}


void CAlarmParaSetView::OnBnClickedSavrAlarmSet()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strEditALarmLimit;
	m_editAlarmLimit.GetWindowTextA(strEditALarmLimit);
	m_iAlarmLimit = _ttoi(strEditALarmLimit);
	CDialog::OnOK();
}
