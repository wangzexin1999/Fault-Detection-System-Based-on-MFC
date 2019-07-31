
#pragma once
#include "SmartArray.h"
#include "DuMacro.h"
/************************************************************************/
// ����������Ӧ�ó��ϣ�ʵʱ��������AD����Դ
// ��Ϊ��Ļˢ����Ҫ��ʵʱ���ݣ��ʹӸû������ã�
// ����ʵʱ�������治�������Ƶ����ӣ�������һ����С����10s�����Ը�����Ԫ���ǹ̶��ģ�
// ��Ļ��Ҫ�����ݸû�����û�еĻ���ֻ�ܵ��ļ����ж�ȡ�ˡ�
// ������û��������ʱ�򣬸û����һ��Ԫ������һֱΪ0��
// ���û��������ˣ�ģ�¶����Ƚ��ȳ���������ǰ��λ��
// ����0λ��ɾ����1λ���Ƶ�0λ�ã��û����һ��Ԫ�������ۼӡ�
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
	// �ڲ��������У�����һ��������������ʵʱȡ����ʱ����Ҫ�ж��ǲ���ȫ���ڻ����
	// ���������Ҫ�����ļ�����������Ļ�����Ҫʵʱ��ȡ�ļ���
	// �ú�������������Ƿ��ڻ�����
	BOOL IsInBuffer(long long nIndex);
	// �ú���������Ҫ���ļ��ж����ٸ����ݣ�ʣ��Ŀ��Դӻ����ж�ȡ��
	int GetNeedGetCountFromFile(long long nIndex, int nCount);

protected:
	// ����û������֮ǰ m_nBufferElementAddCount < m_nBufferElementMaxCount
	// ����֮�� m_nBufferElementAddCount > m_nBufferElementMaxCount
	int m_nBufferElementMaxCount;           // ����Ԫ��������
	long long m_nBufferElementAddCount;	    // ����Ԫ���ۼ���Ӹ���
	T * m_pBuffer;                          // ����
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

	// Խ���ˣ�����Ԫ�ظ�������������
	if (nCount >= m_nBufferElementMaxCount)
	{
        ASSERT(FALSE);
		memcpy(m_pBuffer, pBuffer + (nCount - m_nBufferElementMaxCount), m_nBufferElementMaxCount * sizeof(T));
		m_nBufferElementAddCount += nCount;
	}
	// Խ���ˣ�����Ԫ�ظ�����������Ԫ�ظ�������������
	else if (m_nBufferElementAddCount + nCount > m_nBufferElementMaxCount)
	{
		// �˴��ر�ע�⣬�޸��˶�Ρ�
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