/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： TbCollectionPlan.h
内容摘要： 采集计划对应的数据库实体类
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-09-11
完成日期:
History:
1. Date:    2018-09-11         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
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

