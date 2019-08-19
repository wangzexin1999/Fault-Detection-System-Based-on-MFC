#include "stdafx.h"
#include "TbTestingDeviceDao.h"


TbTestingDeviceDao::TbTestingDeviceDao()
{
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_testingDeviceId;
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("testingdevice_name", "CString", m_testingDeviceName);
	SetVectorAndField("testingdevice_borndate", "CString", m_testingDeviceBornDate);
	SetVectorAndField("testingdevice_importdate", "CString", m_testingDevicImportDate);
	SetVectorAndField("testingdevice_status", "int", m_testingDevicStatus);

	
}
TbTestingDeviceDao::TbTestingDeviceDao(const TbTestingDeviceDao &testingDevice){
	this->m_strTableName = "tb_testingdevice";
	m_key = &m_testingDeviceId;
	SetVectorAndField("testingdevice_id", "int", m_testingDeviceId);
	SetVectorAndField("testingdevice_ip", "CString", m_testingDeviceIp);
	SetVectorAndField("testingdevice_name", "CString", m_testingDeviceName);
	SetVectorAndField("testingdevice_borndate", "CString", m_testingDeviceBornDate);
	SetVectorAndField("testingdevice_importdate", "CString", m_testingDevicImportDate);
	SetVectorAndField("testingdevice_status", "int", m_testingDevicStatus);

	operator = (testingDevice);
}

TbTestingDeviceDao::~TbTestingDeviceDao()
{
}

bool TbTestingDeviceDao::SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, CString strSqlQueryWhere){
	return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

bool TbTestingDeviceDao::SelectObjectsByCondition(vector<TbTestingDeviceDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	vector<CString> tmpDetectedObjecIDs;
	TbTestingDeviceDao testingDevice;
	if (testingDevice.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	{
		for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		{
			testingDevice.m_testingDeviceId.m_strValue = tmpDetectedObjecIDs[iStart];
			if (testingDevice.SelectByKey())
			{
				selectedValueVector.push_back(testingDevice);
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
void TbTestingDeviceDao::GetTableFieldValues(TbTestingDevice &testingDevice){
	testingDevice.SetTestingdeviceId(m_testingDeviceId.GetInt());
	testingDevice.SetTestingdeviceIp(m_testingDeviceIp.m_strValue);
	testingDevice.SetTestingdeviceName(m_testingDeviceName.m_strValue);
	testingDevice.SetTestingdeviceBorndate(m_testingDeviceBornDate.m_strValue);
	testingDevice.SetTestingdeviceImportdate(m_testingDevicImportDate.m_strValue);
	testingDevice.SetTestingDeviceStatus(m_testingDevicStatus.GetInt());
}
void TbTestingDeviceDao::SetTableFieldValues(TbTestingDevice testingDevice){
	m_testingDeviceId.SetValue(testingDevice.GetTestingdeviceId());
	m_testingDeviceIp.m_strValue = testingDevice.GetTestingdeviceIp();
	m_testingDeviceName.m_strValue = testingDevice.GetTestingdeviceName();
	m_testingDevicImportDate.m_strValue = testingDevice.GetTestingdeviceImportdate();
	m_testingDeviceBornDate.m_strValue = testingDevice.GetTestingdeviceBorndate();
	m_testingDevicStatus.SetValue(testingDevice.GetTestingDeviceStatus());
}