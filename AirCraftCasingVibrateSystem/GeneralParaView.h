/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ͨ�ò�������.��Ҫʵ��ͨ�ò�����ʾ��ͨ�ò������á���Ӧ��ʵ�����ļ�ΪGeneralParaView.cpp��
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
#include "afxcmn.h"


// CGeneralParaView �Ի���

class CGeneralParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CGeneralParaView)

public:
	CGeneralParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGeneralParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_GENERAL_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_generalParaList;
};
