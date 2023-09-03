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

Result SignalController::FindAllSumSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &signalVector){
	bool isSuccess = m_signalService.FindAllSumSignalBySearchCondition(searchEntity, signalVector);
	if (isSuccess) return Result(true, "采样数据加载成功");
	return Result(false, "采样数据加载失败");
}
Result SignalController::SaveCollectionSignal(TbSignal collectionSumsignal){
	bool isSuccess = m_signalService.SaveSignal(collectionSumsignal);
	if (isSuccess) return Result(true, "采集数据保存成功");
	return Result(false, "采集数据保存失败");
}
Result SignalController::FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &SignalVector){
	bool isSuccess = m_signalService.GetAllSignalBySearchCondition(searchEntity, SignalVector);
	if (isSuccess) return Result(true, "采集数据查询成功");
	return Result(false, "采集数据查询失败");
}

//Result SignalController::SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSignal){
//	bool isSuccess = m_signalService.AddSignalData(acquireSignal, saveSignal);
//	if (isSuccess) return Result(true, "数据保存成功");
//	return Result(false, "数据保存失败");
//}

//bool SumsignalController::SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
//	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
//	int saveCount = signalDataIterator->second.size();
//	int channelCount = acquireSignal.size();
//	double* saveData = new double[channelCount];
//	for (int i = 0; i < saveCount; i++){
//		////循环采集数据的队列去保存数据
//		signalDataIterator = acquireSignal.begin();
//		for (int j = 0; j < channelCount; j++){
//			shared_ptr<DOUBLE> signal = signalDataIterator->second.wait_and_pop();
//			saveData[j] = *signal;
//			signalDataIterator++;
//		}
//		outputStream.write((const char*)saveData, sizeof(double)* channelCount);
//	}
//	delete[] saveData;
//	return false;
//}



//bool SumsignalController::SaveCollectionData2BinaryNEW(vector<ofstream>&voutputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
//	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
//	int saveCount = signalDataIterator->second.size();
//	int channelCount = acquireSignal.size();
//	double* saveData = new double[1];
//	//double saveData;
//	for (int i = 0; i < saveCount; i++){
//		////循环采集数据的队列去保存数据
//		signalDataIterator = acquireSignal.begin();
//		for (int j = 0; j < channelCount; j++){
//			shared_ptr<DOUBLE> signal = signalDataIterator->second.wait_and_pop();
//			saveData[0] = *signal;
//			signalDataIterator++;
//			CStdioFile FileWrite;
//			voutputStream[j].write((const char*)saveData, sizeof(double)* 1);
//		}
//		//outputStream.write((const char*)saveData, sizeof(double)* channelCount);
//	}
//	delete[] saveData;
//	return false;
//}

bool SignalController::GetCollectionData(ifstream &inputStream, long long llfileSize, long long llcollectionPoints, double*& fftwInputArray)
{
	long long llStart = inputStream.tellg();
	///当前文件所剩字节数不够时，设置读取剩余字节
	if ((llfileSize - llStart) < llcollectionPoints*sizeof(double)){
		llcollectionPoints = (llfileSize - llStart) / sizeof(double);
	}

	fftwInputArray = new double[llcollectionPoints];
	inputStream.read((char*)fftwInputArray, llcollectionPoints*sizeof(double));
	return true;
}

Result SignalController::saveSumSignal(TbSumsignal sumSignal){
	bool isSuccess = m_signalService.saveSumSignal(sumSignal);
	if (isSuccess) return Result(true, "总信号保存成功");
	return Result(false, "总信号保存失败");
}
Result SignalController::saveSignal(TbSignal signal){
	bool isSuccess = m_signalService.SaveSignal(signal);
	if (isSuccess) return Result(true, "信号保存成功");
	return Result(false, "信号保存失败");
}

Result SignalController::updateSumSignal(TbSumsignal sumSignal){
	bool isSuccess = m_signalService.updateSumSignal(sumSignal);
	if (isSuccess) return Result(true, "总信号更新成功");
	return Result(false, "总信号更新失败");
}

Result SignalController::SaveCollectionData2Binary(ofstream &outputStream, ThreadSafeQueue<double> & acquireSignal){
	int saveCount = acquireSignal.size();
	double* saveData = new double[saveCount];
	for (int i = 0; i < saveCount; i++){
		////循环采集数据的队列去保存数据
		shared_ptr<DOUBLE> signal = acquireSignal.wait_and_pop();
		saveData[i] = *signal;
	}
	outputStream.write((const char*)saveData, sizeof(double)* saveCount);
	delete[] saveData;
	return Result(true, "success");
}


void SignalController::SaveSignalFileHeader(CString fileName, SignalFileHeader  signalInfoHeader){
	/*如果文件不存在创建文件*/
	/*if (access(_T(fileName), 0))
	{
		std::ofstream  ofs(_T(fileName), std::ios::binary | std::ios::out | std::ios::app);
		ofs.close();
	}*/
	fstream fout;
	fout.open(fileName, std::ios_base::binary | fstream::out | fstream::in);
	fout.seekp(0, ios::cur);     
	fout.write((const char *)&signalInfoHeader, sizeof(SignalFileHeader));
	fout.flush();
	fout.close();
}

Result SignalController::GetSumSignalByProductId(int productId, vector<TbSumsignal> &sumSignalVec){
	bool isSuccess = m_signalService.GetSumSignalByProductId(productId, sumSignalVec);
	for (int i = 0; i < sumSignalVec.size(); i++){
		isSuccess = m_signalService.GetSignalsBySumSignalId(sumSignalVec[i].GetSumsignalId(), sumSignalVec[i].GetAllSignal());
		isSuccess = m_productService.GetById(sumSignalVec[i].GetProductId(), sumSignalVec[i].GetProduct());
	}
	if (isSuccess) return Result(true, "信号查询成功");
	return Result(false, "信号查询失败");
}

Result SignalController::GetSignalsBySumSignalId(CString sumSignalId, vector<TbSignal> &signals){
	bool isSuccess = m_signalService.GetSignalsBySumSignalId(sumSignalId, signals);
	if (isSuccess) return Result(true, "单通道信号查询成功");
	return Result(false, "单通道信号查询失败");
}

//
//bool SumsignalController::GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader)
//{
//
//	/*如果文件不存在返回false*/
//	if (access(_T(fileName), 0))
//	{
//		return false;
//	}
//	else
//	{
//		std::ifstream fs(_T(fileName), std::ios_base::binary | std::ios::in);
//		fs.read((char *)&signalInfoHeader, sizeof(SignalInfoHeader));
//		fs.close();
//	}
//	return true;
//}
