/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� DeviceParaView.h
����ժҪ�� �豸��������.��Ҫʵ���豸��Ϣ��ʾ���豸��Ϣ�����á���Ӧ��ʵ�����ļ�ΪDeviceParaView.cpp��
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


// CDeviceParaView �Ի���

class CDeviceParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceParaView)

public:
	CDeviceParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeviceParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DEVICE_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
