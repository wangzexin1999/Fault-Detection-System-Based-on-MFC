#pragma once
class TbTestingDevice
{
public:
	TbTestingDevice();
	~TbTestingDevice();

protected:
	int m_testingdeviceId;
	CString m_testingdeviceIp;
	CString m_testingdeviceName;
	CString m_testingdeviceBorndate;
	CString m_testingdeviceImportdate;

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
};

