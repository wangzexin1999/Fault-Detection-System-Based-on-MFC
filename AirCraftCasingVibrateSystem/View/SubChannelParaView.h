/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SubChannelParaView.h
����ժҪ�� ͨ���Ӳ�������.��Ҫʵ��ͨ���Ӳ�����ʾ��ͨ���Ӳ������á���Ӧ��ʵ�����ļ�ΪSubChannelParaView.cpp��
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


// CSubChannelParaView �Ի���

class CSubChannelParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CSubChannelParaView)

public:
	CSubChannelParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSubChannelParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SUB_CHANNEL_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
