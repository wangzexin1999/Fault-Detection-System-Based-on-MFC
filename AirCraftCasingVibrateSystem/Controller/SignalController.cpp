#include "stdafx.h"
#include "SignalController.h"
#include "FileUtil.h"
#include <io.h>
SignalController::SignalController()
{
}


SignalController::~SignalController()
{

}

Result SignalController::FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector){
	bool isSuccess = m_recordSignalService.FindAllRecordSignalBySearchCondition(searchEntity,signalVector);
	if (isSuccess) return Result(true, "采样数据加载失败");
	return Result(false, "采样数据加载失败");
}
Result SignalController::SaveSampleSignal(TbRecordSignal m_recordSignal){
	bool isSuccess = m_recordSignalService.AddRecordSignal(m_recordSignal);
	if (isSuccess) return Result(true,"采样数据保存成功");
	return Result(false, "采样数据保存失败");
}
Result SignalController::SaveCollectionSignal(TbSignal collectionSignal){
	bool isSuccess = m_signalService.AddSignal(collectionSignal);
	if (isSuccess) return Result(true, "采集数据保存成功");
	return Result(false, "采集数据保存失败");
}
Result SignalController::FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &signalVector){
	bool isSuccess = m_signalService.GetAllSignalBySearchCondition(searchEntity, signalVector);
	if (isSuccess) return Result(true, "采集数据查询成功");
	return Result(false, "采集数据查询失败");
}

Result SignalController::SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSignal){
	bool isSuccess = m_signalService.AddSignalData(acquireSignal, saveSignal);
	if (isSuccess) return Result(true, "数据保存成功");
	return Result(false,"数据保存失败");
}

bool SignalController::SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
	int saveCount = signalDataIterator->second.size();
	int channelCount = acquireSignal.size();
	double* saveData = new double[channelCount];
	for (int i = 0; i < saveCount; i++){
		////循环采集数据的队列去保存数据
		signalDataIterator = acquireSignal.begin();
		for (int j = 0; j < channelCount; j++){
			shared_ptr<DOUBLE> signal = signalDataIterator->second.wait_and_pop();
			saveData[j] = *signal;
			signalDataIterator++;
		}
		outputStream.write((const char*)saveData, sizeof(double)* channelCount);
	}
	delete[] saveData;
	return false;
}

bool SignalController::GetCollectionData(ifstream &inputStream, long long llReadSize, vector<double>& vSignal, long long llStart = 0, long long llend = 0)
{
	/*计算总的数*/
	inputStream.seekg(sizeof(SignalInfoHeader), std::ios_base::end);
	long long llFileSize = inputStream.tellg()/sizeof(double);
	inputStream.seekg(sizeof(SignalInfoHeader));
	if ((llFileSize - llStart) <= llReadSize)
	{
		double* dpReadData = new double[(llFileSize - llStart)];
		inputStream.read((char*)dpReadData, (llFileSize - llStart)*sizeof(double));
		for (int i = 0; i < (llFileSize-llStart); i++)
		{
			/*读不够size的部分*/
			vSignal.push_back(dpReadData[i]);
		}
		delete[] dpReadData;
	}
	else
	{
		double* dpReadData = new double[llReadSize];
		inputStream.read((char*)dpReadData, llReadSize * sizeof(double));
		for (int i = 0; i < llReadSize; i++)
		{
			/*readSize*/
			vSignal.push_back(dpReadData[i]);
		}
		delete[] dpReadData;
	}

}

void SignalController::SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader){
	/*如果文件不存在创建文件*/
	if (access(_T(fileName), 0))
	{
		std::ofstream  ofs(_T(fileName), std::ios::binary | std::ios::out | std::ios::app);
		ofs.close();
	}
	fstream fout;
	fout.open(fileName, std::ios_base::binary | fstream::out | fstream::in);
	fout.seekp(0, ios::cur);
	fout.write((const char *)&signalInfoHeader, sizeof(SignalInfoHeader));
	fout.flush();
	fout.close();
}


bool SignalController::GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader)
{

	/*如果文件不存在返回false*/
	if (access(_T(fileName), 0))
	{
		return false;
	}
	else
	{
		std::ifstream fs(_T(fileName), std::ios_base::binary | std::ios::in);
		fs.read((char *)&signalInfoHeader, sizeof(SignalInfoHeader));
		fs.close();
	}
	return true;
}
