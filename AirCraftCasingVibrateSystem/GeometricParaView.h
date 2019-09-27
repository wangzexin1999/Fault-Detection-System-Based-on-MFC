/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeometricParaView.h
����ժҪ�� ���β�������.��Ҫʵ�ּ��β�����ʾ�ͼ��β������á���Ӧ��ʵ�����ļ�ΪGeometricParaView.cpp��
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

// CGeometricParaView �Ի���

class CGeometricParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CGeometricParaView)

public:
	CGeometricParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGeometricParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_GEOMETRIC_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_geometricParaGridCtrl;
	SensorParaController m_sensorParaController;
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	void GridCtrlInit();
};
