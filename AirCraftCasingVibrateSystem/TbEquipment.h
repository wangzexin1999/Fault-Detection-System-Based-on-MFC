#pragma once
#include <vector>
#include <atlstr.h>
using namespace std;
class TbEquipment
{
public:
	TbEquipment();
	TbEquipment(int equipmentId=0, CString ip="", CString createTime="", int status=0);
	~TbEquipment();
private:
	int m_equipmentId;
	CString m_ip;
	CString m_createTime;
	int m_status;
public:
	int GetEquipmentId();
	void SetEquipmentId(int equipmentId);

	CString GetIp();
	void SetIp(CString ip);

	CString GetCreateTime();
	void SetCreateTime(CString createTime);

	int GetStatus();
	void SetStatus(int status);

};