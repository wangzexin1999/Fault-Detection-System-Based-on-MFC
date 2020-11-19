#include "stdafx.h"
#include "SumsignalController.h"
#include "FileUtil.h"
#include <io.h>
SumsignalController::SumsignalController()
{
}


SumsignalController::~SumsignalController()
{

}

Result SumsignalController::FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector){
	bool isSuccess = m_recordSignalService.FindAllRecordSignalBySearchCondition(searchEntity,signalVector);
	if (isSuccess) return Result(true, "�������ݼ��سɹ�");
	return Result(false, "�������ݼ���ʧ��");
}
Result SumsignalController::SaveSampleSignal(TbRecordSignal m_recordSignal){
	bool isSuccess = m_recordSignalService.AddRecordSignal(m_recordSignal);
	if (isSuccess) return Result(true,"�������ݱ���ɹ�");
	return Result(false, "�������ݱ���ʧ��");
}
Result SumsignalController::SaveCollectionSignal(TbSumsignal collectionSumsignal){
	bool isSuccess = m_SumsignalService.AddSignal(collectionSumsignal);
	if (isSuccess) return Result(true, "�ɼ����ݱ���ɹ�");
	return Result(false, "�ɼ����ݱ���ʧ��");
}
Result SumsignalController::FindAllSignalBySearchCondition(TbSumsignal searchEntity, vector<TbSumsignal> &sumsignalVector){
	bool isSuccess = m_SumsignalService.GetAllSignalBySearchCondition(searchEntity, sumsignalVector);
	if (isSuccess) return Result(true, "�ɼ����ݲ�ѯ�ɹ�");
	return Result(false, "�ɼ����ݲ�ѯʧ��");
}

Result SumsignalController::SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSumsignal &saveSumsignal){
	bool isSuccess = m_SumsignalService.AddSignalData(acquireSignal, saveSumsignal);
	if (isSuccess) return Result(true, "���ݱ���ɹ�");
	return Result(false,"���ݱ���ʧ��");
}

bool SumsignalController::SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
	int saveCount = signalDataIterator->second.size();
	int channelCount = acquireSignal.size();
	double* saveData = new double[channelCount];
	for (int i = 0; i < saveCount; i++){
		////ѭ���ɼ����ݵĶ���ȥ��������
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



bool SumsignalController::SaveCollectionData2BinaryNEW(vector<ofstream>&voutputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal){
	map<CString, ThreadSafeQueue<double>>::iterator signalDataIterator = acquireSignal.begin();
	int saveCount = signalDataIterator->second.size();
	int channelCount = acquireSignal.size();
	double* saveData = new double[1];
	//double saveData;
	for (int i = 0; i < saveCount; i++){
		////ѭ���ɼ����ݵĶ���ȥ��������
		signalDataIterator = acquireSignal.begin();
		for (int j = 0; j < channelCount; j++){
			shared_ptr<DOUBLE> signal = signalDataIterator->second.wait_and_pop();
			saveData[0] = *signal;
			signalDataIterator++;
			CStdioFile FileWrite;
			voutputStream[j].write((const char*)saveData, sizeof(double)* 1);
		}
		//outputStream.write((const char*)saveData, sizeof(double)* channelCount);
	}
	delete[] saveData;
	return false;
}







bool SumsignalController::GetCollectionData(ifstream &inputStream, long long llfileSize, long long llStart, long long llcollectionPoints, vector<double>& vSignal)
{
	///��ǰ�ļ���ʣ�ֽ�������ʱ�����ö�ȡʣ���ֽ�
	if ((llfileSize - llStart) < llcollectionPoints*sizeof(double)){ llcollectionPoints = (llfileSize - llStart) / sizeof(double); }
	double* dpReadData = new double[llcollectionPoints];
	inputStream.read((char*)dpReadData, llcollectionPoints*sizeof(double));
	for (int i = 0; i < llcollectionPoints; i++)
	{
		/*������size�Ĳ���*/
		vSignal.push_back(dpReadData[i]);
	}
	delete[] dpReadData;
	return false;
}

void SumsignalController::SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader){
	/*����ļ������ڴ����ļ�*/
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


bool SumsignalController::GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader)
{

	/*����ļ������ڷ���false*/
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
