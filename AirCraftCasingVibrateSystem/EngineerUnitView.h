/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� EngineerUintView.h
����ժҪ�� ���̵�λ����.��Ҫʵ�ֹ��̵�λ��CRUD����Ӧ��ʵ�����ļ�ΪEngineerUintView.cpp��
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


// CEngineerUnitView �Ի���

class CEngineerUnitView : public CDialogEx
{
	DECLARE_DYNAMIC(CEngineerUnitView)

public:
	CEngineerUnitView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEngineerUnitView();

// �Ի�������
	enum { IDD = IDD_DIALOG_ENGINEER_UINT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
