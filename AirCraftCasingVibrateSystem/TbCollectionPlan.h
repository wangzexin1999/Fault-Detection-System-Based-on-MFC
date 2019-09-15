/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� TbCollectionPlan.h
����ժҪ�� �ɼ��ƻ���Ӧ�����ݿ�ʵ����
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-09-11
�������:
History:
1. Date:    2018-09-11         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
class TbCollectionPlan
{
private:
	int m_id;
	
	int m_planId;
	CString m_planPara;
	int m_projectId;

public:
	TbCollectionPlan(int id = 0,int m_planId = 0,CString planPara="",int projectId=0);
	~TbCollectionPlan();

	void SetId(int id);
	int GetId();
	void SetPlanId(int planId);
	int GetPlanId();
	void SetPlanPara(CString planPara);
	CString GetPlanPara();

	void SetProjectId(int projectId);
	int GetProjectId();

};

