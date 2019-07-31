/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SersorParaView.h
����ժҪ�� ��������������.��Ҫʵ�ִ�����������ʾ�ʹ������������á���Ӧ��ʵ�����ļ�ΪSersorParaView.cpp��
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


// CSersorParaView �Ի���

class CSersorParaView : public CDialogEx
{
	DECLARE_DYNAMIC(CSersorParaView)

public:
	CSersorParaView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSersorParaView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SERSOR_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox  m_cbSamplingFrequency;
	CComboBox  m_cbAnalysisFrequency;
	CComboBox  m_cbSamplingMethod;
	CComboBox  m_cbTriggerMode;
	CComboBox  m_cbDataBlocks;
	CComboBox  m_cbDelayBlocks;
	CComboBox  m_cbTriggerTimes;
	CComboBox  m_cbSamplingTimes;
};
