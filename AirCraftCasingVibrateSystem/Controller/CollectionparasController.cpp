#include "stdafx.h"
#include "CollectionparasController.h"


CollectionparasController::CollectionparasController()
{
}


CollectionparasController::~CollectionparasController()
{
}
Result CollectionparasController::FindAllCollectionparasBySearchCondition(CString collectionparasName, vector<TbCollectionparas> &collectionparasVector){
	collectionparasVector.clear();
	TbCollectionparas searchEntity;
	/*bool isSuccess = m_testingDeviceService.GetAllTestingDeviceBySearchCondition(testingDeviceName, testingDeviceVector);
	if (isSuccess){
	return Result(true,"查询成功");
	*/
	return Result(false, "查询失败");
}

Result CollectionparasController::DeleteByCollectionparasId(TbCollectionparas collectionparas){
	//testingDevice.SetTestingDeviceStatus(-1);
	bool isSuccess = m_collectionparasService.Update(collectionparas);
	if (isSuccess){
		return Result(true, "删除成功");
	}
	return Result(false, "删除失败");
}
Result CollectionparasController::AddCollectionparas(TbCollectionparas collectionparas){
	//testingDevice.SetTestingDeviceStatus(0);
	bool isSuccess = m_collectionparasService.AddCollectionparas(collectionparas);
	if(isSuccess){
		return Result(true, "添加成功");
	}
	return Result(false, "添加失败");
}

Result CollectionparasController::UpdateCollectionparas(TbCollectionparas collectionparas){
	bool isSuccess = m_collectionparasService.Update(collectionparas);
	if (isSuccess){
		return Result(true, "添加成功");
	}
	return Result(false, "添加失败");
}