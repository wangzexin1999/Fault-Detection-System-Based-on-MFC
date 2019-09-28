#include "stdafx.h"
#include "SignalController.h"


SignalController::SignalController()
{
}


SignalController::~SignalController()
{

}

Result SignalController::FindAllRecordedSignalBySearchCondition(CString projectName, CString productType, CString rotatingSpeed, CString startTime, CString endTime, vector<TbRecordSignal> &signalVector){
	//vector<TbProject> projectVector;
	//vector<TbProduct> productVector;
 //	bool isSuccess;
	/////根据产品型号查询所有符合条件的产品
	//isSuccess = m_productService.GetAllProductBySearchCondition(TbProduct(0, "", productType), productVector);
	/////根据查到的产品id和项目名去查项目
	//if (!isSuccess){return Result(false, "产品查询失败"); }

	//for (auto product : productVector){
	//	TbProject searchProject;
	//	searchProject.SetProjectName(projectName);
	//	searchProject.SetProduct(product);
	//	isSuccess = m_projectService.GetAllProjectBySearchCondition(searchProject, startTime, endTime, projectVector);
	//	if (!isSuccess){ return Result(false, "项目查询失败"); }
	//}
	/////根据查询到的项目id
	//for (auto project : projectVector){
	//	///遍历项目集合，查询指定项目id的采样数据文件
	//	int projectId = project.GetProjectId();
	//	TbRecordSignal searchSignal;
	//	searchSignal.SetProjectId(projectId);
	//	isSuccess = m_signalService.GetAllRecordedSignalBySearchCondition(searchSignal, startTime, endTime, signalVector);
	//	if (!isSuccess){ return Result(false, "数据查询失败"); }
	//}

	//////遍历信号集合，删除重复的数据
	//vector<TbRecordSignal> res = signalVector;
	//for (int i = 0; i < signalVector.size();i++){
	//	for (vector<TbRecordSignal>::iterator it = res.begin()+1; it != res.end(); it++) {
	//		if (it->GetStartTime() == signalVector[i].GetStartTime() &&
	//			it->GetEndTime() == signalVector[i].GetEndTime() &&
	//			it->GetProductId() == signalVector[i].GetProductId() &&
	//			it->GetProjectId() == signalVector[i].GetProjectId() &&
	//			it->GetSensorId() != signalVector[i].GetSensorId()){
	//		    
	//			it = res.erase(it);
	//			it--;
	//		}
	//			//signalVector[i].SetSensorCount(signalVector[i].GetSensorCount());
	//	}
	//}

	//signalVector.clear();
	//res.swap(signalVector);
	//
	return Result(true, "信号加载成功");
}
Result SignalController::SaveSampleSignal(TbRecordSignal m_recordSignal){
	bool isSuccess = m_recordSignalService.AddRecordSignal(m_recordSignal);
	if (isSuccess) return Result(true,"采样数据保存成功");
	return Result(false, "采样数据保存失败");
}