
#pragma once
#include "TbCollectionparas.h"
#include "Result.h"
#include <vector>
#include "CollectionparasService.h"
using namespace  std;
class CollectionparasController
{

private:
	CollectionparasService m_collectionparasService;
public:
	CollectionparasController();
	~CollectionparasController();

	/**********************************************************************
	���������� ���ݲ�ѯ�������زɼ��豸
	��������� ����豸���ƣ���ѯ���ļ���豸���� 
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllCollectionparasBySearchCondition(CString collectionparasName, vector<TbCollectionparas> &collectionparasVector);

	/**********************************************************************
	���������� ���ݼ���豸idɾ������豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result DeleteByCollectionparasId(TbCollectionparas collectionparas);

	/**********************************************************************
	���������� �������豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddCollectionparas(TbCollectionparas collectionparas);

	/**********************************************************************
	���������� ���¼���豸
	��������� ����豸
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result UpdateCollectionparas(TbCollectionparas collectionparas);

};

