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

bool ProjectService::GetAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime, vector<TbProject> &projectVector){
	///1.������Ŀ�Ĳ�����Ա
	m_projectDao.m_testerId.SetValue(project.GetTester().GetTesterId());
	vector<TbProjectDao>  selectedValueVector;
	////2.��ѯ������Ա��������Ŀ
	//////2.1 ��װsql��ѯ����
	CString strSqlWhere = "1 = 1 ";
	if (project.GetTester().GetTesterId() != 0) strSqlWhere += " and tester_id ='" + CommonUtil::Int2CString(project.GetTester().GetTesterId()) + "'";
	if (project.GetProjectName() != "") strSqlWhere += " and project_name like '%" + project.GetProjectName() + "%'";
	if (project.GetProduct().GetProductId() != 0) strSqlWhere += " and product_id =" + CommonUtil::Int2CString(project.GetProduct().GetProductId());
	if (startTime != "") strSqlWhere += " and project_createtime >='" + startTime + "'";
	if (endTime != "") strSqlWhere += " and project_createtime <='" + endTime + "'";
	if (project.GetProjectStatus() != 0) strSqlWhere += " and project_status =" + CommonUtil::Int2CString(project.GetProjectStatus());
	//////2.2 ����sql����ѯ����������������Ŀ
	bool isSuccess = m_projectDao.SelectObjectsByCondition(selectedValueVector, strSqlWhere);
	if (isSuccess){
		for (auto tbProjectDao : selectedValueVector){
			TbProject tbProject;
			tbProjectDao.GetTableFieldValues(tbProject);
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
			////��ѯ��Ʒ����Ϣ
			tbProject.GetProduct().SetProductId(tbProjectDao.m_productId.GetInt());
			m_productDao.m_productId.SetValue(tbProjectDao.m_productId.GetInt());
			isSuccess = m_productDao.SelectByKey();
			if (isSuccess){
				m_productDao.GetTableFieldValues(tbProject.GetProduct());
			}
			////��ѯ�û���Ϣ
			m_testerDao.m_key->SetValue(tbProject.GetTester().GetTesterId());
			isSuccess = m_testerDao.SelectByKey();
			if (isSuccess) m_testerDao.GetTableFieldValues(tbProject.GetTester());
			////��ѯ���д�����������Ϣ

			projectVector.push_back(tbProject);
		}
	}
	return isSuccess;
}

