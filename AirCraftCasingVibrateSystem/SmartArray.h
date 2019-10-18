/************************************************************************
Copyright (C), 2018-2020. ����������ѧ�˹�����ʵ����
�ļ����ƣ� SignalController.h
����ժҪ�� ����ģ�������� 
����˵�����ɻ���ϻ�񶯼��ϵͳ
��ǰ�汾�� 1.0
�� �ߣ� ������
�������ڣ� 2019-07-30
�������:
History:
1. Date:    2018-07-30         Author:������
Modification:
�޸ļ�¼ 1�� // �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
�޸����ڣ�
�� �� �ţ�
�� �� �ˣ�
�޸����ݣ�
************************************************************************/
#pragma once
#include "DataStructure.h"

template<typename T>
class SmartArray
{
private:
	LinearTable<T> m_smartArray;
public:
	SmartArray(int size = 1000){
		////��ʼ��ͼ������x��������
		this->m_smartArray.size = size;
		this->m_smartArray.index = 0;
		this->m_smartArray.data = (T*)malloc(sizeof(T)*this->m_smartArray.size);
	}


	SmartArray(const SmartArray &smartArray){
		*this = smartArray;
	}
	void operator=(const SmartArray &smartArray){
		////��ʼ������Ҷ����֮�����������
		this->m_smartArray.size = smartArray.m_smartArray.size;
		this->m_smartArray.index = smartArray.m_smartArray.index;
		this->m_smartArray.data = (T*)malloc(sizeof(T)* this->m_smartArray.size);
		////�������
		memcpy(this->m_smartArray.data, smartArray.m_smartArray.data, sizeof(T)*this->m_smartArray.index);
	}
	~SmartArray(){
		free(m_smartArray.data);
		m_smartArray.data = NULL;
	}
	/**********************************************************************
	����������������ģ�������������Ԫ��
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-08-20   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	void push_back(T t){
		if (m_smartArray.index >= m_smartArray.size){
			/////���鳤�Ȳ���ʱ����̬�������鳤��
			m_smartArray.size = 2 * m_smartArray.size;
			m_smartArray.data = (T *)realloc(m_smartArray.data, sizeof(T)* this->m_smartArray.size);
		}
		m_smartArray.data[m_smartArray.index++] = t;
	}
	/**********************************************************************
	�����������������
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-08-20   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	void clear(){
		m_smartArray.index = 0;
	}

	/**********************************************************************
	�����������õ����鳤��
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-08-20   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	int size(){
		return m_smartArray.index;
	}

	/**********************************************************************
	�����������õ���������
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸�����	 �汾��		�޸���		�޸�����
	2019-08-20   1.0		������		��ʼ��
	----------------------------------------------------------------------
	***********************************************************************/
	T * GetSmartArray(){
		return m_smartArray.data;
	}
};

