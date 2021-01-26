#include "stdafx.h"
#include "CollectionparasService.h"
#include "CommonUtil.h"

CollectionparasService::CollectionparasService()
{
}


CollectionparasService::~CollectionparasService()
{

}

bool CollectionparasService::GetAllCollectionparas(vector<TbCollectionparasDao> & tbTestingVec){
	return m_collectionparasDao.SelectObjectsByCondition(tbTestingVec, "1=1");
}


///根据查询条件查询所有检测设备
bool  CollectionparasService::GetAllCollectionparasBySearchCondition(TbCollectionparas searchEntity, vector<TbCollectionparas> &collectionparasVector){
	CString strWhere = "collectionparas_status != -1 ";
	if (searchEntity.GetEquipmentId() != 0)  strWhere += "and equipment_id like'%" + CommonUtil::Int2CString(searchEntity.GetEquipmentId()) + "%'";
	if (searchEntity.GetId() != 0) strWhere += "and id =" + CommonUtil::Int2CString(searchEntity.GetId()) + "'";
	vector<TbCollectionparasDao>  tbTestingDviceDaoVec;
	bool isSuccess = m_collectionparasDao.SelectObjectsByCondition(tbTestingDviceDaoVec, strWhere);
	if (isSuccess){
		for (auto collectionparasDao : tbTestingDviceDaoVec){
			TbCollectionparas collectionparas;
			collectionparasDao.GetTableFieldValues(collectionparas);
			collectionparasVector.push_back(collectionparas);
		}
	}
	return isSuccess;
}

bool CollectionparasService::Update(TbCollectionparas collectionparas){
	m_collectionparasDao.SetTableFieldValues(collectionparas);
	bool isSuccess = m_collectionparasDao.UpdateByKey();
	return isSuccess;
}

bool CollectionparasService::AddCollectionparas(TbCollectionparas & collectionparas){
	TbCollectionparasDao collectionparasDao;
	collectionparasDao.SetTableFieldValues(collectionparas);
	//得到当前插入的id
	bool isSuccess = collectionparasDao.Insert(false);
	collectionparas.SetId(collectionparasDao.m_id.GetInt());
	return isSuccess;
}
bool CollectionparasService::GetOneById(TbCollectionparas &searchEntity){
	m_collectionparasDao.m_id.SetValue(searchEntity.GetId());
	bool isSuccess = m_collectionparasDao.SelectByKey();
	if (isSuccess){
		m_collectionparasDao.GetTableFieldValues(searchEntity);
		///查询TbTestingDevice的各个参数id对应的字典表的实体值
		////查询采集频率对应id的字典对象
		//m_collectionparasDao.GetTableFieldValues(searchEntity.GetSampleFrequency());

		//m_dictionaryDao.m_key->SetValue(searchEntity.GetSampleFrequency());
		//m_dictionaryDao.SelectByKey();
		//m_dictionaryDao.GetTableFieldValues(searchEntity.GetSampleFrequency());
		////查询采集点数对应的id的字典对象
	}
	return isSuccess;
}

bool CollectionparasService::Delete(TbCollectionparas collectionparas){
	CString strWhere = "1=1 ";
	if (collectionparas.GetId() != 0) strWhere += "and id =" + CommonUtil::Int2CString(collectionparas.GetId()) + "'";
	if (collectionparas.GetEquipmentId() != 0)  strWhere += "and equipment_id like'%" + CommonUtil::Int2CString(collectionparas.GetEquipmentId()) + "%'";
	return  m_collectionparasDao.DeleteByCondition(strWhere);
}