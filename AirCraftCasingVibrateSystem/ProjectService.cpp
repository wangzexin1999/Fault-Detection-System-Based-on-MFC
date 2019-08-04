#include "stdafx.h"
#include "ProjectService.h"

ProjectService::ProjectService()
{

}

ProjectService::~ProjectService()
{

}
bool ProjectService::AddProject(TbProject & project){
	/*1.先添加采集设备参数表*/

	m_testingDeviceParaDao.SetTableFieldValues(project.GetTestingDevicePara());

	m_testingDeviceParaDao.Insert(false);

	project.GetTestingDevicePara().SetTestingdeviceparaId(m_testingDeviceParaDao.m_testingDeviceParaId.GetInt());

	/*2.添加项目表*/
	m_projectDao.SetTableFieldValues(project);
	m_projectDao.Insert(false);
	project.SetProjectId(m_projectDao.m_projectId.GetInt());

	/*3.添加传感器参数表*/ 

	/*4.将添加的传感器参数赋值给project*/
	return true;
}

bool ProjectService::GetAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector){
	///1.设置项目的测试人员
	m_projectDao.m_testerId.SetValue(testerId);
	vector<TbProjectDao>  selectedValueVector;
	////2.查询测试人员的所有项目
	//////2.1 封装sql查询条件
	CString strSqlWhere = "tester_id ='" + CommonUtil::Int2CString(testerId) + "'";
	if (projectName != "") strSqlWhere += "and project_name like '%" + projectName+"%'";
	if (startTime != "") strSqlWhere += "and project_createtime >='" + startTime + "'";
	if (endTime != "") strSqlWhere += "and project_createtime <='" + endTime + "'";
	//////2.2 根据sql语句查询符合条件的所有项目
	bool isSuccess = m_projectDao.SelectObjectsByCondition(selectedValueVector, strSqlWhere);
	if (isSuccess){
		for (auto tbProjectDao : selectedValueVector){
			TbProject tbProject;
			tbProject.SetProjectId(tbProjectDao.m_projectId.GetInt());
			tbProject.GetTester().SetTesterId(tbProjectDao.m_testerId.GetInt());
			tbProject.SetProjectName(tbProjectDao.m_projectName.m_strValue);
			///设置检测设备参数id
			tbProject.GetTestingDevicePara().SetTestingdeviceparaId(tbProjectDao.m_testingDeviceParaid.GetInt());
			///查询检测设备参数信息
			m_testingDeviceParaDao.m_testingDeviceParaId.SetValue(tbProjectDao.m_testingDeviceParaid.GetInt());
			isSuccess = m_testingDeviceParaDao.SelectByKey();
			if (isSuccess){
				////封装查询到的设备参数信息
				m_testingDeviceParaDao.GetTableFieldValues(tbProject.GetTestingDevicePara());
				////查询设备参数信息中的检测设备
				m_testingDeviceDao.m_testingDeviceId.SetValue(tbProject.GetTestingDevicePara().GetTestingdevice().GetTestingdeviceId());
				isSuccess = m_testingDeviceDao.SelectByKey();
				if (isSuccess){
					///封装检测设备对象
					m_testingDeviceDao.GetTableFieldValues(tbProject.GetTestingDevicePara().GetTestingdevice());
				}
			}
			tbProject.SetProjectCreateTime(tbProjectDao.m_projectCreatetime.m_strValue);
			////查询被检测设备的信息
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