/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� GeneralParaView.h
����ժҪ�� ����豸���ݿ���Ӧ��ʵ����󡣶�Ӧ��ʵ�����ļ�ΪTbTestingDevice.cpp��
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-07-24
�������:
History:
1. Date:    2018-07-24         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
class TbTestingDevice
{
public:
	TbTestingDevice(int testingdeviceId = 0);
	~TbTestingDevice();
	
	bool operator == (TbTestingDevice testingDevice);
	bool operator != (TbTestingDevice testingDevice);
protected:
	int m_testingdeviceId;
	CString m_testingdeviceIp;
	CString m_testingdeviceName;
	CString m_testingdeviceBorndate;
	CString m_testingdeviceImportdate;
	int m_testingdeviceStatus;

public:
	int GetTestingdeviceId();

	void SetTestingdeviceId(int testingdeviceId);

	CString GetTestingdeviceIp();

	void SetTestingdeviceIp(CString testingdeviceIp);

	CString GetTestingdeviceName();

	void SetTestingdeviceName(CString testingdeviceName);

	CString GetTestingdeviceBorndate();

	void SetTestingdeviceBorndate(CString testingdeviceBorndate);
	CString GetTestingdeviceImportdate();
	void SetTestingdeviceImportdate(CString testingdeviceImportdate);

	void SetTestingDeviceStatus(int status);
	int GetTestingDeviceStatus();

};

