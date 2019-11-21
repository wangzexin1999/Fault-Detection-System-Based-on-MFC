#include "stdafx.h"
#include "TestingDeviceController.h"


TestingDeviceController::TestingDeviceController()
{
}


TestingDeviceController::~TestingDeviceController()
{
}
Result TestingDeviceController::FindAllTestingDeviceBySearchCondition(CString testingDeviceName, vector<TbTestingDevice> &testingDeviceVector){
	testingDeviceVector.clear();
	TbTestingDevice searchEntity;
	
	/*bool isSuccess = m_testingDeviceService.GetAllTestingDeviceBySearchCondition(testingDeviceName, testingDeviceVector);
	if (isSuccess){
	return Result(true,"��ѯ�ɹ�");
	*/
	return Result(false, "��ѯʧ��");
}

Result TestingDeviceController::DeleteByTestingDeviceId(TbTestingDevice testingDevice){
	//testingDevice.SetTestingDeviceStatus(-1);
	bool isSuccess = m_testingDeviceService.Update(testingDevice);
	if (isSuccess){
		return Result(true, "ɾ���ɹ�");
	}
	return Result(false, "ɾ��ʧ��");
}
Result TestingDeviceController::AddTestingDevice(TbTestingDevice testingDevice){
	//testingDevice.SetTestingDeviceStatus(0);
	bool isSuccess = m_testingDeviceService.AddTestingDevice(testingDevice);
	if(isSuccess){
		return Result(true, "��ӳɹ�");
	}
	return Result(false, "���ʧ��");
}

Result TestingDeviceController::UpdateTestingDevice(TbTestingDevice testingDevice){
	bool isSuccess = m_testingDeviceService.Update(testingDevice);
	if (isSuccess){
		return Result(true, "��ӳɹ�");
	}
	return Result(false, "���ʧ��");
}