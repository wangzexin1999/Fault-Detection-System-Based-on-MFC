/************************************************************************
Copyright (C), 2018-2020. 哈尔滨理工大学人工智能实验室
文件名称： SignalController.h
内容摘要： 智能模板数组类 
其它说明：飞机机匣振动检测系统
当前版本： 1.0
作 者： 马善涛
创建日期： 2019-07-30
完成日期:
History:
1. Date:    2018-07-30         Author:马善涛
Modification:
修改记录 1： // 修改历史记录，包括修改日期、修改者及修改内容
修改日期：
版 本 号：
修 改 人：
修改内容：
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
		////初始化图表数据x坐标数组
		this->m_smartArray.size = size;
		this->m_smartArray.index = 0;
		this->m_smartArray.data = (T*)malloc(sizeof(T)*this->m_smartArray.size);
	}


	SmartArray(const SmartArray &smartArray){
		*this = smartArray;
	}
	void operator=(const SmartArray &smartArray){
		////初始化傅里叶处理之后的数据数组
		this->m_smartArray.size = smartArray.m_smartArray.size;
		this->m_smartArray.index = smartArray.m_smartArray.index;
		this->m_smartArray.data = (T*)malloc(sizeof(T)* this->m_smartArray.size);
		////深拷贝代码
		memcpy(this->m_smartArray.data, smartArray.m_smartArray.data, sizeof(T)*this->m_smartArray.index);
	}
	~SmartArray(){
		free(m_smartArray.data);
		m_smartArray.data = NULL;
	}
	/**********************************************************************
	功能描述：向智能模板数组的最后插入元素
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-08-20   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	void push_back(T t){
		if (m_smartArray.index >= m_smartArray.size){
			/////数组长度不够时，动态扩充数组长度
			m_smartArray.size = 2 * m_smartArray.size;
			m_smartArray.data = (T *)realloc(m_smartArray.data, sizeof(T)* this->m_smartArray.size);
		}
		m_smartArray.data[m_smartArray.index++] = t;
	}
	/**********************************************************************
	功能描述：清空数组
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-08-20   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	void clear(){
		m_smartArray.index = 0;
	}

	/**********************************************************************
	功能描述：得到数组长度
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-08-20   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	int size(){
		return m_smartArray.index;
	}

	/**********************************************************************
	功能描述：得到智能数组
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期	 版本号		修改人		修改内容
	2019-08-20   1.0		马善涛		初始化
	----------------------------------------------------------------------
	***********************************************************************/
	T * GetSmartArray(){
		return m_smartArray.data;
	}
};

