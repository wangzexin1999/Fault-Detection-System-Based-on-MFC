/************************************************************************
�ļ����ƣ� TbCollectionPlan.h
����ժҪ�� �ɼ��ƻ���Ӧ�����ݿ�ʵ����
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

