#include "stdafx.h"
#include "ProjectController.h"


ProjectController::ProjectController()
{

}


ProjectController::~ProjectController()
{
}
Result ProjectController::FindAllCollectionparas(vector<TbCollectionparasDao> & tbTestingVec){
	bool flag = m_collectionparasService.GetAllCollectionparas(tbTestingVec);
	if (flag){
		return Result(true, "����豸����ʧ��");
	}
	else{
		return Result(false, "����豸����ʧ��");
	}

}

Result ProjectController::AddProject(TbProject &project){
	project.SetProjectStatus(2);
	/*1.����Ӳɼ��豸������*/
	bool flag = m_collectionparasService.AddCollectionparas(project.GetCollectionparas());
	if (!flag) return Result(false, "�ɼ���������ʧ��");
	/*2.�����Ŀ��*/
	flag = m_projectService.AddProject(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	/*3.��Ӵ�����������*/
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		//project.GetSensorVector()[i].SetProjectId(project.GetProjectId());
		project.GetChannelVector()[i].SetCollectionparasId(project.GetCollectionparas().GetId());
		flag = m_channelService.AddChannel(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "����������ʧ��");
	}
	return Result(true, "��Ŀ�����ɹ�");
}

Result ProjectController::FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	////��ѯ��Ŀ�Ļ�����Ϣ
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (!flag)return Result(false, "��Ŀ����ʧ��");

	for (int i = 0; i < projectVector.size();i++){
		////��ѯ��Ŀ�Ĳɼ��豸
		flag = m_collectionparasService.GetOneById(projectVector[i].GetCollectionparas());
		if (!flag)return Result(false, "�ɼ��豸����ʧ��");
		////��ѯ��Ŀ�����д�����
		//flag = m_sensorService.GetALLSensorByProjectId(projectVector[i].GetProjectId(), projectVector[i].GetSensorVector());
		flag = m_channelService.GetAllChannelByCollectionparasId(projectVector[i].GetCollectionparas().GetId(), projectVector[i].GetChannelVector());
		if (!flag)return Result(false, "����������ʧ��");
		////��ѯ��Ŀ��Ӧ�Ĳ�Ʒ��Ϣ
		flag = m_productService.GetProductByID(projectVector[i].GetProduct());
		if (!flag)return Result(false, "��Ʒ����ʧ��");
		////��ѯ�û���Ϣ
		flag = m_userService.getOneById(projectVector[i].GetUser());
		if (!flag)return Result(false, "�û�����ʧ��");

	}
	return Result(true, "��Ŀ���سɹ�");
}

Result ProjectController::FindLastOpenProjectByUser(TbProject &project){
	///������Ŀ������Ϣ
	bool flag = m_projectService.GetLastOpenProjectByUser(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	///������Ŀ������Ϣ
	////��ѯ��Ŀ�Ĳɼ��豸
	flag = m_collectionparasService.GetOneById(project.GetCollectionparas());
	if (!flag)return Result(false, "�ɼ��豸����ʧ��");
	////��ѯ��Ŀ�����д�����
	//flag = m_sensorService.GetALLSensorByProjectId(project.GetProjectId(), project.GetSensorVector());
	flag = m_channelService.GetAllChannelByCollectionparasId(project.GetCollectionparas().GetId(), project.GetChannelVector());
	if (!flag)return Result(false, "����������ʧ��");
	////��ѯ��Ŀ��Ӧ�Ĳ�Ʒ��Ϣ
	flag = m_productService.GetProductByID(project.GetProduct());
	if (!flag)return Result(false, "��Ʒ����ʧ��");
	////��ѯ�û���Ϣ
	flag = m_userService.getOneById(project.GetUser());

	return Result(true, "��Ŀ���سɹ�");
}

Result ProjectController::Update(TbProject project){
	//1. ���ȸ�����Ŀ�Ļ�����Ϣ��
	bool flag = m_projectService.Update(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	//2. ɾ����Ŀ��Ӧ�����д�����
	TbChannel condition;
	condition.SetCollectionparasId(project.GetCollectionparas().GetId());
	//condition.SetProjectId(project.GetProjectId());
	flag = m_channelService.Delete(condition);
	if (!flag) return Result(false, "��Ŀ����������ʧ��");
	//3. �������еĴ���������
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		//project.GetSensorVector()[i].SetProjectId(project.GetProjectId());
		project.GetChannelVector()[i].SetCollectionparasId(project.GetCollectionparas().GetId());
		flag = m_channelService.AddChannel(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "��Ŀ����������ʧ��");
	}
	//4. ���²ɼ��豸����Ϣ�������
	flag = m_collectionparasService.Update(project.GetCollectionparas());
	if (flag) return Result(true, "��Ŀ���³ɹ�");
	return Result(false, "��Ŀ����ʧ��");
}
