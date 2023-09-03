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
	/*3.���ͨ��������*/
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		project.GetChannelVector()[i].SetProjectId(project.GetProjectId());
		flag = m_channelService.AddChannel(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "ͨ����������ʧ��");
	}
	return Result(true, "��Ŀ�����ɹ�");
}

Result ProjectController::FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	////��ѯ��Ŀ�Ļ�����Ϣ
	bool flag = m_projectService.GetAllProjectBySearchCondition(project, startTime, endTime, projectVector);
	if (!flag)return Result(false, "��Ŀ����ʧ��");

	for (int i = 0; i < projectVector.size();i++){
		// ��ѯ��Ŀ�Ĳɼ��豸
		flag = m_collectionparasService.GetOneById(projectVector[i].GetCollectionparas());
		if (!flag)return Result(false, "�ɼ��豸����ʧ��");
		// ��ѯ��Ŀ�����д�����
		flag = m_channelService.GetALLSensorByProjectId(projectVector[i].GetProjectId(), projectVector[i].GetChannelVector());
		if (!flag)return Result(false, "ͨ������ʧ��");
		//  ��ѯ��Ŀ��Ӧ�Ĳ�Ʒ��Ϣ
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
	flag = m_channelService.GetALLSensorByProjectId(project.GetProjectId(), project.GetChannelVector());
	if (!flag)return Result(false, "����������ʧ��");//
	////��ѯ��Ŀ��Ӧ�Ĳ�Ʒ��Ϣ
	flag = m_productService.GetProductByID(project.GetProduct());//
	if (!flag)return Result(false, "��Ʒ����ʧ��");
	////��ѯ�û���Ϣ
	flag = m_userService.getOneById(project.GetUser());
	return Result(true, "��Ŀ���سɹ�");
}

Result  ProjectController::UpdateTime(TbProject project){
	bool flag = m_projectService.Update(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	return Result(false, "��Ŀ���³ɹ�");
}

Result ProjectController::Update(TbProject project){
	//1. ���ȸ�����Ŀ�Ļ�����Ϣ��
	bool flag = m_projectService.Update(project);
	if (!flag) return Result(false, "��Ŀ����ʧ��");
	//3. ����ͨ������
	for (int i = 0; i < project.GetChannelVector().size(); i++){
		project.GetChannelVector()[i].SetProjectId(project.GetProjectId());
		flag = m_channelService.Update(project.GetChannelVector()[i]);
		if (!flag) return Result(false, "��Ŀ����������ʧ��");
	}
	project.GetChannelVector().clear();
	m_channelService.GetALLSensorByProjectId(project.GetProjectId(), project.GetChannelVector());
	//4. ���²ɼ��豸����Ϣ�������
	flag = m_collectionparasService.Update(project.GetCollectionparas());
	if (flag) return Result(true, "��Ŀ���³ɹ�");
	return Result(false, "��Ŀ����ʧ��");
}
