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
	if (isSuccess) return Result(true, "�������ݼ��سɹ�");
	return Result(false, "�������ݼ���ʧ��");
}
Result SignalController::SaveCollectionSignal(TbSignal collectionSumsignal){
	bool isSuccess = m_signalService.SaveSignal(collectionSumsignal);
	if (isSuccess) return Result(true, "�ɼ����ݱ���ɹ�");
	return Result(false, "�ɼ����ݱ���ʧ��");
}
Result SignalController::FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &SignalVector){
	bool isSuccess = m_signalService.GetAllSignalBySearchCondition(searchEntity, SignalVector);
	if (isSuccess) return Result(true, "�ɼ����ݲ�ѯ�ɹ�");
	return Result(false, "�ɼ����ݲ�ѯʧ��");
}

//Result SignalController::SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &saveSignal){
//	bool isSuccess = m_signalService.AddSignalData(acquireSignal, saveSignal);
//	if (isSuccess) return Result(true, "���ݱ���ɹ�");
//	return Result(false, "���ݱ���ʧ��");
//}

//bool SumsignalController::SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
//	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
//	int saveCount = signalDataIterator->second.size();
//	int channelCount = acquireSignal.size();
//	double* saveData = new double[channelCount];
//	for (int i = 0; i < saveCount; i++){
//		////ѭ���ɼ����ݵĶ���ȥ��������
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
//		////ѭ���ɼ����ݵĶ���ȥ��������
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
	///��ǰ�ļ���ʣ�ֽ�������ʱ�����ö�ȡʣ���ֽ�
	if ((llfileSize - llStart) < llcollectionPoints*sizeof(double)){
		llcollectionPoints = (llfileSize - llStart) / sizeof(double);
	}

	fftwInputArray = new double[llcollectionPoints];
	inputStream.read((char*)fftwInputArray, llcollectionPoints*sizeof(double));
	return true;
}

Result SignalController::saveSumSignal(TbSumsignal sumSignal){
	bool isSuccess = m_signalService.saveSumSignal(sumSignal);
	if (isSuccess) return Result(true, "���źű���ɹ�");
	return Result(false, "���źű���ʧ��");
}
Result SignalController::saveSignal(TbSignal signal){
	bool isSuccess = m_signalService.SaveSignal(signal);
	if (isSuccess) return Result(true, "�źű���ɹ�");
	return Result(false, "�źű���ʧ��");
}

Result SignalController::updateSumSignal(TbSumsignal sumSignal){
	bool isSuccess = m_signalService.updateSumSignal(sumSignal);
	if (isSuccess) return Result(true, "���źŸ��³ɹ�");
	return Result(false, "���źŸ���ʧ��");
}

Result SignalController::SaveCollectionData2Binary(ofstream &outputStream, ThreadSafeQueue<double> & acquireSignal){
	int saveCount = acquireSignal.size();
	double* saveData = new double[saveCount];
	for (int i = 0; i < saveCount; i++){
		////ѭ���ɼ����ݵĶ���ȥ��������
		shared_ptr<DOUBLE> signal = acquireSignal.wait_and_pop();
		saveData[i] = *signal;
	}
	outputStream.write((const char*)saveData, sizeof(double)* saveCount);
	delete[] saveData;
	return Result(true, "success");
}


void SignalController::SaveSignalFileHeader(CString fileName, SignalFileHeader  signalInfoHeader){
	/*����ļ������ڴ����ļ�*/
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
	if (isSuccess) return Result(true, "�źŲ�ѯ�ɹ�");
	return Result(false, "�źŲ�ѯʧ��");
}

Result SignalController::GetSignalsBySumSignalId(CString sumSignalId, vector<TbSignal> &signals){
	bool isSuccess = m_signalService.GetSignalsBySumSignalId(sumSignalId, signals);
	if (isSuccess) return Result(true, "��ͨ���źŲ�ѯ�ɹ�");
	return Result(false, "��ͨ���źŲ�ѯʧ��");
}

//
//bool SumsignalController::GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader)
//{
//
//	/*����ļ������ڷ���false*/
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
