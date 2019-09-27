/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SystemParaView.h
����ժҪ�� ϵͳ��������.��Ҫʵ��ϵͳ������ʾ��ϵͳ�������á���Ӧ��ʵ�����ļ�ΪSystemParaView.cpp��
			��Ҫ��Ϊ�������֣�һ�Ǵ����������������豸����
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
#include "SystemParaDialog.h"

// CSystemParaView

class CSystemParaView : public CDockablePane
{
	DECLARE_DYNAMIC(CSystemParaView)

public:
	CSystemParaView();
	virtual ~CSystemParaView();
public:

	CSystemParaDialog   m_systemParaDialog;
	void RefreshView();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


