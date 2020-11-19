/************************************************************************
�ļ����ƣ� TriggerParaView.h
����ժҪ�� ������������.��Ҫʵ�ִ���������ʾ�ʹ����������á���Ӧ��ʵ�����ļ�ΪTriggerParaView.cpp��

************************************************************************/
#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "ChannelParaController.h"
// CTriggerParaView �Ի���

class CTriggerParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CTriggerParaView)

public:
	CTriggerParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTriggerParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_TRIGGER_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_triggerParaGridCtrl;
	ChannelParaController m_channelParaController;
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	void GridCtrlInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
