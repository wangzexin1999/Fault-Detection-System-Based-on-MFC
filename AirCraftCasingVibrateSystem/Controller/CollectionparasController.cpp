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
	return Result(true,"��ѯ�ɹ�");
	*/
	return Result(false, "��ѯʧ��");
}

Result CollectionparasController::DeleteByCollectionparasId(TbCollectionparas collectionparas){
	//testingDevice.SetTestingDeviceStatus(-1);
	bool isSuccess = m_collectionparasService.Update(collectionparas);
	if (isSuccess){
		return Result(true, "ɾ���ɹ�");
	}
	return Result(false, "ɾ��ʧ��");
}
Result CollectionparasController::AddCollectionparas(TbCollectionparas collectionparas){
	//testingDevice.SetTestingDeviceStatus(0);
	bool isSuccess = m_collectionparasService.AddCollectionparas(collectionparas);
	if(isSuccess){
		return Result(true, "��ӳɹ�");
	}
	return Result(false, "���ʧ��");
}

Result CollectionparasController::UpdateCollectionparas(TbCollectionparas collectionparas){
	bool isSuccess = m_collectionparasService.Update(collectionparas);
	if (isSuccess){
		return Result(true, "��ӳɹ�");
	}
	return Result(false, "���ʧ��");
}