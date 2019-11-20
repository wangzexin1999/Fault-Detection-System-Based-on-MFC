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
	return Result(true,"查询成功");
	*/
	return Result(false, "查询失败");
}

Result TestingDeviceController::DeleteByTestingDeviceId(TbTestingDevice testingDevice){
	//testingDevice.SetTestingDeviceStatus(-1);
	bool isSuccess = m_testingDeviceService.Update(testingDevice);
	if (isSuccess){
		return Result(true, "删除成功");
	}
	return Result(false, "删除失败");
}
Result TestingDeviceController::AddTestingDevice(TbTestingDevice testingDevice){
	//testingDevice.SetTestingDeviceStatus(0);
	bool isSuccess = m_testingDeviceService.AddTestingDevice(testingDevice);
	if(isSuccess){
		return Result(true, "添加成功");
	}
	return Result(false, "添加失败");
}

Result TestingDeviceController::UpdateTestingDevice(TbTestingDevice testingDevice){
	bool isSuccess = m_testingDeviceService.Update(testingDevice);
	if (isSuccess){
		return Result(true, "添加成功");
	}
	return Result(false, "添加失败");
}