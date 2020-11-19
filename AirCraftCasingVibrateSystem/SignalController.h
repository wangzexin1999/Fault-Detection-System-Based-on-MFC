#pragma once

#include "Result.h"
#include "TbSignal.h"
#include "SignalService.h"
#include "ProjectService.h"
#include "ProductService.h"
#include "TbRecordSignal.h"
#include "RecordSignalService.h"
#include "ThreadSafeQueue.h"
#include "AcquiredSignal.h"
#include <fstream>
#include <map>
using namespace std;




class SignalController
{

private:
	SignalService m_SignalService;
	ProjectService m_projectService;
	RecordSignalService m_recordSignalService;
	ProductService m_productService;


public:
	SignalController();
	~SignalController();

	/**********************************************************************
	功能描述：根据查询条件查询所有的记录数据
	输入参数： 项目名称 ，产品名称，转速，信号采集时间，信号
	采集时间：信号的集合。
	返 回 值：Result对象
	其它说明：查询采样数据文件，主要针对产品的型号和转速进行查询
	***********************************************************************/
	Result FindAllRecordSignalBySearchCondition(TbRecordSignal searchEntity, vector<TbRecordSignal> &signalVector);

	/**********************************************************************
	功能描述：保存采样的数据
	输入参数：当前窗口的id，传感器的id
	***********************************************************************/
	Result SaveSampleSignal(TbRecordSignal m_recordSignal);

	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	***********************************************************************/
	Result SaveCollectionSignal(TbSignal m_collectionSignal);


	/**********************************************************************
	功能描述：根据查询条件查询所有的采集数据
	返 回 值：Result对象
	其它说明：查询采集数据
	***********************************************************************/
	Result FindAllSignalBySearchCondition(TbSignal searchEntity, vector<TbSignal> &sumsignalVector);

	/**********************************************************************
	功能描述：保存采集的数据
	输入参数：当前窗口的id，传感器的id
	***********************************************************************/
	Result SaveSignalData(map<CString, ThreadSafeQueue<double>> & acquireSignal, TbSignal &savesumsignal);

	/**********************************************************************
	功能描述： 保存采样数据为二进制文件
	输入参数：outputStream--输出流；acquireSigna--采集信号
	***********************************************************************/
	//bool SaveCollectionData2Binary(ofstream &outputStream, map<CString, ThreadSafeQueue<double>> & acquireSigna);

	/**********************************************************************
	功能描述： 得到采集数据
	输入参数：inputStream--输入流；
	llStart--开始位置，默认是从头开始；llend--结束位置，默认是文件结尾
	输出参数：vSignal--信号；
	返 回 值： true--继续；false--读完了
	***********************************************************************/
	bool GetCollectionData(ifstream &inputStream, long long llfileSize, long long llStart, long long llReadSize, vector<double>& vSumsignal);

	/**********************************************************************
	功能描述： 保存采样数据的二进制文件头部信息
	输入参数：outputStream--输出流；signalInfoHeader--采集信号信息头
	***********************************************************************/
	//void SaveCollectionDataHeadInfo(CString fileName, SignalInfoHeader  signalInfoHeader);

	/**********************************************************************
	功能描述：获得采集数据的二进制文件头部信息
	输入参数：fileName--文件路径
	输出参数： signalInfoHeader--头信息
	返 回 值： ture--成功； false--打开文件失败
	***********************************************************************/
	//bool GetCollectionDataHeadInfo(CString fileName, SignalInfoHeader& signalInfoHeader);



	//bool SaveCollectionData2BinaryNEW(vector<ofstream>&voutputStream, map<CString, ThreadSafeQueue<double>> & acquireSignal);

};

