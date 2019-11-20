/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� TriggerParaView.h
����ժҪ�� ������������.��Ҫʵ�ִ���������ʾ�ʹ����������á���Ӧ��ʵ�����ļ�ΪTriggerParaView.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ����
�������ڣ� 2019-05-24
�������:
History:
1. Date:    2018-05-24         Author:����
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "SensorParaController.h"
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
	SensorParaController m_sensorParaController;
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	void GridCtrlInit();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
};
