#pragma once


// CStatisticView �Ի���

class CStatisticView : public CDialogEx
{
	DECLARE_DYNAMIC(CStatisticView)

public:
	CStatisticView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStatisticView();

// �Ի�������
	enum { IDD = IDD_DIALOG1_DATA_STATISTIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
