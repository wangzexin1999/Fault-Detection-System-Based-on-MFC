#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{

}

Result SignalController::FindAllRecordedSignalBySearchCondition(CString projectName, CString productType, CString rotatingSpeed, CString startTime, CString endTime, vector<TbSignal> &signalVector){
	vector<TbProject> projectVector;
	vector<TbProduct> productVector;
 	bool isSuccess;
	///���ݲ�Ʒ�ͺŲ�ѯ���з��������Ĳ�Ʒ
	isSuccess = m_productService.GetAllProductBySearchCondition(TbProduct(0, "", productType), productVector);
	///���ݲ鵽�Ĳ�Ʒid����Ŀ��ȥ����Ŀ
	if (!isSuccess){return Result(false, "��Ʒ��ѯʧ��"); }

	for (auto product : productVector){
		TbProject searchProject;
		searchProject.SetProjectName(projectName);
		searchProject.SetProduct(product);
		isSuccess = m_projectService.GetAllProjectBySearchCondition(searchProject, startTime, endTime, projectVector);
		if (!isSuccess){ return Result(false, "��Ŀ��ѯʧ��"); }
	}
	///���ݲ�ѯ������Ŀid
	for (auto project : projectVector){
		///������Ŀ���ϣ���ѯָ����Ŀid�Ĳ��������ļ�
		int projectId = project.GetProjectId();
		TbSignal searchSignal;
		searchSignal.GetProject().SetProjectId(projectId);
		isSuccess = m_signalService.GetAllRecordedSignalBySearchCondition(searchSignal, startTime, endTime, signalVector);
		if (!isSuccess){ return Result(false, "���ݲ�ѯʧ��"); }
	}

	////�����źż��ϣ�ɾ���ظ�������
	vector<TbSignal> res = signalVector;
	for (int i = 0; i < signalVector.size();i++){
		for (vector<TbSignal>::iterator it = res.begin()+1; it != res.end(); it++) {
			if (it->GetStartTime() == signalVector[i].GetStartTime() &&
				it->GetEndTime() == signalVector[i].GetEndTime() &&
				it->GetProduct().GetProductId() == signalVector[i].GetProduct().GetProductId() &&
				it->GetProject().GetProjectId() == signalVector[i].GetProject().GetProjectId() &&
				it->GetSensor().GetSensorId() != signalVector[i].GetSensor().GetSensorId()){
			    
				it = res.erase(it);
				it--;
			}
				//signalVector[i].SetSensorCount(signalVector[i].GetSensorCount());
		}
	}

	signalVector.clear();
	res.swap(signalVector);
	return Result(true, "�źż��سɹ�");
}