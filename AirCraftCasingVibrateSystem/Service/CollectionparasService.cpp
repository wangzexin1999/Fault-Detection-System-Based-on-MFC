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


///���ݲ�ѯ������ѯ���м���豸
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
	//�õ���ǰ�����id
	bool isSuccess = collectionparasDao.Insert(false);
	collectionparas.SetId(collectionparasDao.m_id.GetInt());
	return isSuccess;
}
bool CollectionparasService::GetOneById(TbCollectionparas &searchEntity){
	m_collectionparasDao.m_id.SetValue(searchEntity.GetId());
	bool isSuccess = m_collectionparasDao.SelectByKey();
	if (isSuccess){
		m_collectionparasDao.GetTableFieldValues(searchEntity);
		///��ѯTbTestingDevice�ĸ�������id��Ӧ���ֵ���ʵ��ֵ
		////��ѯ�ɼ�Ƶ�ʶ�Ӧid���ֵ����
		//m_collectionparasDao.GetTableFieldValues(searchEntity.GetSampleFrequency());

		//m_dictionaryDao.m_key->SetValue(searchEntity.GetSampleFrequency());
		//m_dictionaryDao.SelectByKey();
		//m_dictionaryDao.GetTableFieldValues(searchEntity.GetSampleFrequency());
		////��ѯ�ɼ�������Ӧ��id���ֵ����
	}
	return isSuccess;
}

bool CollectionparasService::Delete(TbCollectionparas collectionparas){
	CString strWhere = "1=1 ";
	if (collectionparas.GetId() != 0) strWhere += "and id =" + CommonUtil::Int2CString(collectionparas.GetId()) + "'";
	if (collectionparas.GetEquipmentId() != 0)  strWhere += "and equipment_id like'%" + CommonUtil::Int2CString(collectionparas.GetEquipmentId()) + "%'";
	return  m_collectionparasDao.DeleteByCondition(strWhere);
}