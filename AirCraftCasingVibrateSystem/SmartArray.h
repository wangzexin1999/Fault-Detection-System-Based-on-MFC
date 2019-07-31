
#pragma once

template <typename T>
class CSmartArray
{
public:
	CSmartArray();
	CSmartArray(int nElementSize);
	CSmartArray(CSmartArray<T> & t);
	virtual ~CSmartArray();

public:
	//////////////////////////////////////////////////////////////////////////
	void LockBuffer();
	void UnlockBuffer();

	//////////////////////////////////////////////////////////////////////////
	T * GetBuffer() const;
	int GetBufferElementSize() const;

public:
	//////////////////////////////////////////////////////////////////////////
	virtual void CreateBuffer(int nElementSize);					// ÷√¡„
	virtual void CreateBuffer(int nElementSize, T * pCopyBuffer);	// øΩ±¥pCopyBuffer
	virtual void DestroyBuffer();

	//////////////////////////////////////////////////////////////////////////
	virtual void AddBuffer(int nSize, T * pAddBuffer);
	virtual void ReadBuffer(T * pReadBuffer);
	virtual void ReadBuffer(T * pReadBuffer, int nStart, int nSize);
	virtual void WriteBuffer(T * pSrcBuffer);
	virtual void WriteBuffer(T * pSrcBuffer, int nSize);
	virtual void WriteBuffer(T * pSrcBuffer, int nStart, int nSize);
	virtual void WriteZeroBuffer();

public:
	//////////////////////////////////////////////////////////////////////////
	virtual void Clone(CSmartArray<T> & r);

protected:
	virtual void NewBuffer(int nElementSize);	// ÷√¡„
	virtual void DeleteBuffer();

protected:
	int m_nBufferElementSize;
	T * m_pBuffer;
	HANDLE m_hMutex;
};

template <typename T>
CSmartArray<T>::CSmartArray()
{
	m_nBufferElementSize = 0;
	m_pBuffer = NULL;
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
}

template <typename T>
CSmartArray<T>::CSmartArray(int nElementSize)
{
	m_nBufferElementSize = 0;
	m_pBuffer = NULL;
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);

	if (nElementSize > 0)
		CreateBuffer(nElementSize);
}

template <typename T>
CSmartArray<T>::CSmartArray(CSmartArray<T> & t)
{
	m_nBufferElementSize = t.GetBufferElementSize();
	m_pBuffer = NULL;
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);

	if (m_nBufferElementSize > 0)
	{
		m_pBuffer = new T[m_nBufferElementSize];
		t.ReadBuffer(m_pBuffer);
	}
}

template <typename T>
void CSmartArray<T>::Clone(CSmartArray<T> & r)
{
	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);
	m_nBufferElementSize = r.GetBufferElementSize();
	m_pBuffer = NULL;

	if (m_nBufferElementSize > 0)
	{
		m_pBuffer = new T[m_nBufferElementSize];
		r.ReadBuffer(m_pBuffer);
	}
}

template <typename T>
CSmartArray<T>::~CSmartArray()
{
	if (NULL != m_hMutex)
	{
		::CloseHandle( m_hMutex );
		m_hMutex = NULL;
	}
	DeleteBuffer();
}

template <typename T>
void CSmartArray<T>::CreateBuffer(int nElementSize)
{
	NewBuffer(nElementSize);
}

template <typename T>
void CSmartArray<T>::NewBuffer(int nElementSize)
{
	if (nElementSize <= 0)
	{
		ASSERT(FALSE);
		return;
	}

	if (m_nBufferElementSize != nElementSize)
	{
		DeleteBuffer();

		m_nBufferElementSize = nElementSize;
		m_pBuffer = new T[m_nBufferElementSize];
	}
	memset(m_pBuffer, 0, sizeof(T) * m_nBufferElementSize);
}

template <typename T>
void CSmartArray<T>::CreateBuffer(int nElementSize, T * pCopyBuffer)
{
	if (NULL == pCopyBuffer)
	{
		ASSERT(FALSE);
		return;
	}
	NewBuffer(nElementSize);
	WriteBuffer(pCopyBuffer);
}

template <typename T>
void CSmartArray<T>::DeleteBuffer()
{
	delete[] m_pBuffer;
	m_pBuffer = NULL;
	m_nBufferElementSize = 0;
}

template <typename T>
void CSmartArray<T>::DestroyBuffer()
{
	DeleteBuffer();
}

template <typename T>
void CSmartArray<T>::LockBuffer()
{
	WaitForSingleObject( m_hMutex, INFINITE );
}

template <typename T>
void CSmartArray<T>::UnlockBuffer()
{
	ReleaseMutex(m_hMutex);
}

template <typename T>
T * CSmartArray<T>::GetBuffer() const
{
	return m_pBuffer;
}

template <typename T>
int CSmartArray<T>::GetBufferElementSize() const
{
	return m_nBufferElementSize;
}

template <typename T>
void CSmartArray<T>::AddBuffer(int nSize, T * pAddBuffer)
{
	if (pAddBuffer == NULL || nSize <= 0)
	{
		ASSERT(FALSE);
		return;
	}

	// œ»±∏∑›
	int nOldBufferElementSize = m_nBufferElementSize;
	CSmartArray<T> old;
	if (nOldBufferElementSize > 0)
		old.CreateBuffer(nOldBufferElementSize, m_pBuffer);

	// –¬µƒª∫¥Ê≥§∂»
	int nNewBufferElementSize = m_nBufferElementSize + nSize;
	NewBuffer(nNewBufferElementSize);

	// œ»øΩ±¥æ…ª∫¥Ê
	if (nOldBufferElementSize > 0)
		old.ReadBuffer(m_pBuffer);

	// ‘ŸøΩ±¥–¬ª∫¥Ê
	WriteBuffer(pAddBuffer, nOldBufferElementSize, nSize);
}

template <typename T>
void CSmartArray<T>::ReadBuffer(T * pReadBuffer)
{
	ReadBuffer(pReadBuffer, 0, m_nBufferElementSize);
}

template <typename T>
void CSmartArray<T>::ReadBuffer(T * pReadBuffer, int nStart, int nSize)
{
	if (NULL == pReadBuffer || 
		nStart < 0 || nStart > m_nBufferElementSize - 1 || 
		nSize < 0 || nStart + nStart > m_nBufferElementSize)
	{
		ASSERT(FALSE);
		return;
	}

	memcpy(pReadBuffer, m_pBuffer + nStart, nSize * sizeof(T));
}

template <typename T>
void CSmartArray<T>::WriteBuffer(T * pSrcBuffer)
{
	WriteBuffer(pSrcBuffer, 0, m_nBufferElementSize);
}

template <typename T>
void CSmartArray<T>::WriteBuffer(T * pSrcBuffer, int nSize)
{
	WriteBuffer(pSrcBuffer, 0, nSize);
}

template <typename T>
void CSmartArray<T>::WriteBuffer(T * pSrcBuffer, int nStart, int nSize)
{
	if (pSrcBuffer == NULL || 
		nStart < 0 || nStart > m_nBufferElementSize - 1 || 
		nSize < 0 || nStart + nSize > m_nBufferElementSize)
	{
		ASSERT(FALSE);
		return;
	}

	memcpy(m_pBuffer + nStart, pSrcBuffer, nSize * sizeof(T));
}

template <typename T>
void CSmartArray<T>::WriteZeroBuffer()
{
	memset(m_pBuffer, 0, m_nBufferElementSize * sizeof(T));
}