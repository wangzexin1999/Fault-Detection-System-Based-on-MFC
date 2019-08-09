#include "stdafx.h"
#include "EchoSignal.h"

EchoSignal::EchoSignal(int dataCount)
{
	////��ʼ��ͼ������x��������
	this->m_X.size = dataCount;
	this->m_X.index = 0;
	this->m_X.data = (double *)malloc(sizeof(double)*this->m_X.size);
	////��ʼ��ͼ������x��������
	this->m_Y.size = dataCount;
	this->m_Y.index = 0;
	this->m_Y.data = (double *)malloc(sizeof(double)*this->m_Y.size);
	////��ʼ������Ҷ����֮ǰ����������
	this->m_din.size = dataCount;
	this->m_din.index = 0;
	this->m_din.data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_din.size);
	////��ʼ������Ҷ����֮�����������
	this->m_dout.size = dataCount;
	this->m_dout.index = 0;
	this->m_dout.data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_dout.size);
}

void EchoSignal::operator = (const EchoSignal &echoSignal){
	////��ʼ��ͼ������x��������
	this->m_X.size = echoSignal.m_X.size;
	this->m_X.index = echoSignal.m_X.index;
	this->m_X.data = (double *)malloc(sizeof(double)*this->m_X.size);
	////��ʼ��ͼ������x��������
	this->m_Y.size = echoSignal.m_Y.size;
	this->m_Y.index = echoSignal.m_Y.index;
	this->m_Y.data = (double *)malloc(sizeof(double)*this->m_Y.size);
	////��ʼ������Ҷ����֮ǰ����������
	this->m_din.size = echoSignal.m_din.size;
	this->m_din.index = echoSignal.m_din.index;
	this->m_din.data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_din.size);
	////��ʼ������Ҷ����֮�����������
	this->m_dout.size = echoSignal.m_dout.size;
	this->m_dout.index = echoSignal.m_dout.index;
	this->m_dout.data = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_dout.size);
	////�������
	memcpy(this->m_X.data, echoSignal.m_X.data, sizeof(double)*this->m_X.index);
	memcpy(this->m_Y.data, echoSignal.m_Y.data, sizeof(double)*this->m_Y.index);
	memcpy(this->m_din.data, echoSignal.m_din.data, sizeof(fftw_complex)* this->m_din.index);
	memcpy(this->m_dout.data, echoSignal.m_dout.data, sizeof(fftw_complex)* this->m_dout.index);
}

EchoSignal::EchoSignal(const EchoSignal &echoSignal){
	*this = echoSignal;
}

EchoSignal::~EchoSignal()
{
	fftw_free(m_din.data);
	m_din.data = NULL;
	fftw_free(m_dout.data);
	m_dout.data = NULL;
	free(m_X.data);
	m_X.data = NULL;
	free(m_Y.data);
	m_Y.data = NULL;
}

int EchoSignal::GetDinLength(){
	return m_din.index;
}
int EchoSignal::GetXLength(){
	return m_X.index;
}
int EchoSignal::GetYLength(){
	return m_Y.index;
}
void EchoSignal::ClearSignalData(){
	m_din.index = 0;
	m_dout.index = 0;
	m_X.index = 0;
	m_Y.index = 0;
}
void EchoSignal::PushToDin(double inData){
	if (m_din.index >= m_din.size){
		/////���鳤�Ȳ���ʱ����̬�������鳤��
		m_din.size = 2 * m_din.size;
		fftw_complex *dintemp = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_din.size);
		memcpy(dintemp, m_din.data, sizeof(fftw_complex)*m_din.size);
		////��ָ������ָ���´���������
		m_din.data = dintemp;
		/////��Ӧ�ĸı�Dout�ĳ���
		m_dout.size *= 2;
		fftw_complex *douttemp = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)* this->m_din.size);
		memcpy(dintemp, m_dout.data, sizeof(fftw_complex)*m_dout.size);
		m_dout.data = douttemp;
	}
	m_din.data[m_din.index++][0] = inData;
}
void EchoSignal::UpdateDin(int index, double data){
	////�ܾ�Խ�����
	if (index < 0 || index >= m_din.size)	{ return; }
	m_din.data[index][0] = data;
}
void EchoSignal::UpdateDout(int index, double data){
	////�ܾ�Խ�����
	if (index < 0 || index >= m_dout.size)	{ return; }
	m_dout.data[index][0] = data;
}
void EchoSignal::PushToX(double xdata){
	if (m_X.index >= m_X.size){
		/////���鳤�Ȳ���ʱ����̬�������鳤��
		m_X.size *= 2;
		double *temp = (double *)malloc(sizeof(double)*this->m_X.size);
		memcpy(temp, m_X.data, sizeof(double)*m_X.size);
		///��ָ������ָ���¿��ٵĿռ�
		m_X.data = temp;
		////��Ӧ�ĸı�Y����ĳ���
		m_Y.size *= 2;
		double *yTemp = (double *)malloc(sizeof(double)*this->m_Y.size);
		memcpy(yTemp, m_Y.data, sizeof(double)*m_Y.size);
		m_Y.data = yTemp;
	};
	m_X.data[m_X.index++] = xdata;
}
void EchoSignal::PushToY(double ydata){
	if (m_Y.index >= m_Y.size){
		/////���鳤�Ȳ���ʱ����̬�������鳤��
		m_Y.size *= 2;
		double *temp = (double *)malloc(sizeof(double)*this->m_Y.size);
		memcpy(temp, m_Y.data, sizeof(double)*m_Y.size);
		/*///free��ԭ����ָ������
		free(m_Y.data);*/
		///��ָ������ָ���¿��ٵĿռ�
		m_Y.data = temp;
	};
	m_Y.data[m_Y.index++] = ydata;
}

void EchoSignal::UpdateY(int index, double data){
	if (index < 0 || index >= m_Y.size)	{ return; }
	m_Y.data[index] = data;
}

double * EchoSignal::GetXArray(){
	return m_X.data;
}
double * EchoSignal::GetYArray(){
	return m_Y.data;
}

fftw_complex * EchoSignal::GetDinArray(){
	return  m_din.data;
}

fftw_complex * EchoSignal::GetDoutArray(){
	return m_dout.data;
}