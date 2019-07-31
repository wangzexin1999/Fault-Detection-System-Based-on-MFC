#include "stdafx.h"
#include "TbDetectedDeviceDao.h"


TbDetectedDeviceDao::TbDetectedDeviceDao()
{
	this->m_strTableName = "tb_detecteddevice";
	m_key = &m_detecteddeviceId;
	SetVectorAndField("detecteddevice_id", "int", m_detecteddeviceId);
	SetVectorAndField("detecteddevice_name", "int", m_detecteddeviceName);
	SetVectorAndField("detecteddevice_type", "int", m_detecteddeviceType);
}


TbDetectedDeviceDao::~TbDetectedDeviceDao()
{
}
TbDetectedDeviceDao::TbDetectedDeviceDao(const TbDetectedDeviceDao & detectedDevice){
	this->m_strTableName = "tb_detecteddevice";
	m_key = &m_detecteddeviceId;
	SetVectorAndField("detecteddevice_id", "int", m_detecteddeviceId);
	SetVectorAndField("detecteddevice_name", "int", m_detecteddeviceName);
	SetVectorAndField("detecteddevice_type", "int", m_detecteddeviceType);
	operator = (detectedDevice);
}

bool TbDetectedDeviceDao::SelectObjectsByCondition(vector<TbDetectedDeviceDao> &selectedValueVector, CString strSqlQueryWhere){
	 return SelectObjectsByCondition(selectedValueVector, 0, 0, strSqlQueryWhere);
}

 bool TbDetectedDeviceDao::SelectObjectsByCondition(vector<TbDetectedDeviceDao> &selectedValueVector, int iStartNumber, int iRecordCount, CString strSqlQueryWhere){
	 vector<CString> tmpDetectedObjecIDs;
	 TbDetectedDeviceDao detectedDevice;
	 if (detectedDevice.GetKeyIdList(tmpDetectedObjecIDs, strSqlQueryWhere, iStartNumber, iRecordCount))
	 {
		 for (int iStart = 0; iStart < tmpDetectedObjecIDs.size(); iStart++)
		 {
			 detectedDevice.m_detecteddeviceId.m_strValue = tmpDetectedObjecIDs[iStart];
			 if (detectedDevice.SelectByKey())
			 {
				 selectedValueVector.push_back(detectedDevice);
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
 void TbDetectedDeviceDao::GetTableFieldValues(TbDetectedDevice &detectedDevice){
	 detectedDevice.SetDetecteddeviceId(m_detecteddeviceId.GetInt());
	 detectedDevice.SetDetecteddeviceName(m_detecteddeviceName.m_strValue);
	 detectedDevice.SetDetecteddeviceType(m_detecteddeviceType.m_strValue);
 }
