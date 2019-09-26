/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� ChannelParaView.h
����ժҪ�� ͨ����������.��Ҫʵ������ͨ��������������Ҫ��ͨ���Ӳ�����ͨ�ò��������β�����������
			��Ӧ��ʵ�����ļ�ΪChannelParaView.cpp��
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
#include "DeviceParaView.h"
#include "ChannelParaDialog.h"

// CChannelParaView

class CChannelParaView : public CDockablePane
{
	DECLARE_DYNAMIC(CChannelParaView)

public:
	CChannelParaView();
	virtual ~CChannelParaView();
	void RefreshView();

private:
	CMFCTabCtrl m_tab;
	CChannelParaDialog m_channelParaDialog;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//void ShowPane(BOOL bShow, BOOL bDelay, BOOL bActivate);
};


