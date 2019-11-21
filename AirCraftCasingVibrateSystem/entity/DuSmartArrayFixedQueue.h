
#pragma once
#include "SmartArray.h"
#include "DuMacro.h"
/************************************************************************/
// 此智能数组应用场合，实时采样缓存AD数据源
// 因为屏幕刷新需要拿实时数据，就从该缓存中拿，
// 但是实时采样缓存不能无限制的增加，所以设一个大小例如10s，所以该数组元素是固定的，
// 屏幕需要的数据该缓存中没有的话，只能到文件当中读取了。
// 当缓存没有添满的时候，该缓存第一个元素索引一直为0，
// 当该缓存添满了，模仿队列先进先出，依次向前移位，
// 例如0位置删除，1位置移到0位置，该缓存第一个元素索引累加。
/************************************************************************/

template <typename T>
class CDuSmartArrayFixedQueue
{
public:
	CDuSmartArrayFixedQueue();
	virtual ~CDuSmartArrayFixedQueue();

public:
	void CreateBuffer(int nElementSize);
	void DeleteBuffer();
	void AddBuffer(int nCount, T * pBuffer);
	void GetBuffer(T * pBuffer, long long nStart, int nCount);
    int       GetBufferElementMaxCount();
    long long GetBufferElementAddCount();

public:
	//////////////////////////////////////////////////////////////////////////
	// 在采样过程中，我有一个缓存链表，当我实时取数据时，先要判断是不是全部在缓存里，
	// 如果是则不需要操作文件，如果不够的话，需要实时读取文件，
	// 该函数计算大索引是否在缓存中
	BOOL IsInBuffer(long long nIndex);
	// 该函数计算需要从文件中读多少个数据，剩余的可以从缓存中读取。
	int GetNeedGetCountFromFile(long long nIndex, int nCount);

protected:
	// 缓存没有用完之前 m_nBufferElementAddCount < m_nBufferElementMaxCount
	// 用完之后 m_nBufferElementAddCount > m_nBufferElementMaxCount
	int m_nBufferElementMaxCount;           // 缓存元素最大个数
	long long m_nBufferElementAddCount;	    // 缓存元素累计添加个数
	T * m_pBuffer;                          // 缓存
};

template <typename T>
CDuSmartArrayFixedQueue<T>::CDuSmartArrayFixedQueue()
{
	m_nBufferElementAddCount = 0;
	m_nBufferElementMaxCount = 0;
	m_pBuffer = NULL;
}

template <typename T>
CDuSmartArrayFixedQueue<T>::~CDuSmartArrayFixedQueue()
{
	DeleteBuffer();
}

template <typename T>
void CDuSmartArrayFixedQueue<T>::CreateBuffer(int nElementSize)
{
	DU_MACRO_ASSERT_FALSE_RETURN(nElementSize > 0);

	if (m_nBufferElementMaxCount != nElementSize)
	{
		DeleteBuffer();
		m_nBufferElementMaxCount = nElementSize;
		m_pBuffer = new T[m_nBufferElementMaxCount];
	}
	memset(m_pBuffer, 0, sizeof(T) * m_nBufferElementMaxCount);

	m_nBufferElementAddCount = 0;
}

template <typename T>
void CDuSmartArrayFixedQueue<T>::AddBuffer(int nCount, T * pBuffer)
{
	DU_MACRO_ASSERT_FALSE_RETURN(nCount > 0);
	DU_MACRO_ASSERT_FALSE_RETURN(pBuffer);

	// 越界了，来的元素个数大于最大个数
	if (nCount >= m_nBufferElementMaxCount)
	{
        ASSERT(FALSE);
		memcpy(m_pBuffer, pBuffer + (nCount - m_nBufferElementMaxCount), m_nBufferElementMaxCount * sizeof(T));
		m_nBufferElementAddCount += nCount;
	}
	// 越界了，已有元素个数加上来的元素个数大于最大个数
	else if (m_nBufferElementAddCount + nCount > m_nBufferElementMaxCount)
	{
		// 此处特别注意，修改了多次。
		int nMoveCount = 0;
		if (m_nBufferElementAddCount < m_nBufferElementMaxCount)
			nMoveCount = static_cast<int>(m_nBufferElementAddCount + nCount - m_nBufferElementMaxCount);
		else
			nMoveCount = nCount;
		memmove(m_pBuffer, m_pBuffer + nMoveCount, sizeof(T) * (m_nBufferElementMaxCount - nMoveCount));
		memcpy(m_pBuffer + m_nBufferElementMaxCount - nCount, pBuffer, nCount * sizeof(T));
		m_nBufferElementAddCount += nCount;
	}
	else
	{
		memcpy(m_pBuffer + m_nBufferElementAddCount, pBuffer, nCount * sizeof(T));
		m_nBufferElementAddCount += nCount;
	}
}

template <typename T>
void CDuSmartArrayFixedQueue<T>::GetBuffer(T * pBuffer, long long nStart, int nCount)
{
	long long nBufferStart = 0;
    if (m_nBufferElementAddCount <= m_nBufferElementMaxCount)
        nBufferStart = 0;
    else
        nBufferStart = m_nBufferElementAddCount - m_nBufferElementMaxCount;

	DU_MACRO_ASSERT_NULL_RETURN(pBuffer);
	DU_MACRO_ASSERT_NULL_RETURN(nStart >= nBufferStart);
	DU_MACRO_ASSERT_NULL_RETURN(nCount <= m_nBufferElementMaxCount);
	DU_MACRO_ASSERT_NULL_RETURN(nStart + nCount <= m_nBufferElementAddCount);

	int nCopyStart = static_cast<int>(nStart - nBufferStart);
	memcpy(pBuffer, m_pBuffer + nCopyStart, nCount * sizeof(T));
}

template <typename T>
BOOL CDuSmartArrayFixedQueue<T>::IsInBuffer(long long nIndex)
{
	long long nStart = 0;
    if (m_nBufferElementAddCount <= m_nBufferElementMaxCount)
        nStart = 0;
    else
        nStart = m_nBufferElementAddCount - m_nBufferElementMaxCount;

	if (nIndex < nStart)
    {
		return FALSE;
    }
	if (nIndex >= m_nBufferElementAddCount)
    {
		return FALSE;
    }
	return TRUE;
}

template <typename T>
int CDuSmartArrayFixedQueue<T>::GetNeedGetCountFromFile(long long nIndex, int nCount)
{
	long long nStart = 0;
    if (m_nBufferElementAddCount <= m_nBufferElementMaxCount)
        nStart = 0;
    else
        nStart = m_nBufferElementAddCount - m_nBufferElementMaxCount;

	if (nIndex >= nStart)
    {
		return 0;
    }
	int nBetween = static_cast<int>(nStart - nIndex);
	return nCount < nBetween ? nCount : nBetween;
}

template <typename T>
void CDuSmartArrayFixedQueue<T>::DeleteBuffer()
{
	if (NULL != m_pBuffer)
	{
		delete[] m_pBuffer;
		m_pBuffer = NULL;
	}
	m_nBufferElementMaxCount = 0;
	m_nBufferElementAddCount = 0;
}

template <typename T>
long long CDuSmartArrayFixedQueue<T>::GetBufferElementAddCount()
{
    return m_nBufferElementAddCount;
}

template <typename T>
int CDuSmartArrayFixedQueue<T>::GetBufferElementMaxCount()
{
    return m_nBufferElementMaxCount;
}