#include "stdafx.h"
#include "ProjectService.h"

ProjectService::ProjectService()
{

}

ProjectService::~ProjectService()
{

}
bool ProjectService::AddProject(TbProject & project){
	/*1.����Ӳɼ��豸������*/

	m_testingDeviceParaDao.SetTableFieldValues(project.GetTestingDevicePara());

	m_testingDeviceParaDao.Insert(false);

	project.GetTestingDevicePara().SetTestingdeviceparaId(m_testingDeviceParaDao.m_testingDeviceParaId.GetInt());

	/*2.�����Ŀ��*/
	m_projectDao.SetTableFieldValues(project);
	m_projectDao.Insert(false);
	project.SetProjectId(m_projectDao.m_projectId.GetInt());

	/*3.��Ӵ�����������*/ 

	/*4.����ӵĴ�����������ֵ��project*/
	return true;
}

bool ProjectService::GetAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector){
	///1.������Ŀ�Ĳ�����Ա
	m_projectDao.m_testerId.SetValue(testerId);
	vector<TbProjectDao>  selectedValueVector;
	////2.��ѯ������Ա��������Ŀ
	//////2.1 ��װsql��ѯ����
	CString strSqlWhere = "tester_id ='" + CommonUtil::Int2CString(testerId) + "'";
	if (projectName != "") strSqlWhere += "and project_name like '%" + projectName+"%'";
	if (startTime != "") strSqlWhere += "and project_createtime >='" + startTime + "'";
	if (endTime != "") strSqlWhere += "and project_createtime <='" + endTime + "'";
	//////2.2 ����sql����ѯ����������������Ŀ
	bool isSuccess = m_projectDao.SelectObjectsByCondition(selectedValueVector, strSqlWhere);
	if (isSuccess){
		for (auto tbProjectDao : selectedValueVector){
			TbProject tbProject;
			tbProject.SetProjectId(tbProjectDao.m_projectId.GetInt());
			tbProject.GetTester().SetTesterId(tbProjectDao.m_testerId.GetInt());
			tbProject.SetProjectName(tbProjectDao.m_projectName.m_strValue);
			///���ü���豸����id
			tbProject.GetTestingDevicePara().SetTestingdeviceparaId(tbProjectDao.m_testingDeviceParaid.GetInt());
			///��ѯ����豸������Ϣ
			m_testingDeviceParaDao.m_testingDeviceParaId.SetValue(tbProjectDao.m_testingDeviceParaid.GetInt());
			isSuccess = m_testingDeviceParaDao.SelectByKey();
			if (isSuccess){
				////��װ��ѯ�����豸������Ϣ
				m_testingDeviceParaDao.GetTableFieldValues(tbProject.GetTestingDevicePara());
				////��ѯ�豸������Ϣ�еļ���豸
				m_testingDeviceDao.m_testingDeviceId.SetValue(tbProject.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
				isSuccess = m_testingDeviceDao.SelectByKey();
				if (isSuccess){
					///��װ����豸����
					m_testingDeviceDao.GetTableFieldValues(tbProject.GetTestingDevicePara().GetTestingdevice());
				}
			}
			tbProject.SetProjectCreateTime(tbProjectDao.m_projectCreatetime.m_strValue);
			////��ѯ������豸����Ϣ
			tbProject.GetDetectedDevice().SetDetecteddeviceId(tbProjectDao.m_detectedDeviceId.GetInt());
			m_detectedDeviceDao.m_detecteddeviceId.SetValue(tbProjectDao.m_detectedDeviceId.GetInt());
			isSuccess = m_detectedDeviceDao.SelectByKey();
			if (isSuccess){
				m_detectedDeviceDao.GetTableFieldValues(tbProject.GetDetectedDevice());
			}
			projectVector.push_back(tbProject);
		}
	}
	return isSuccess;
}