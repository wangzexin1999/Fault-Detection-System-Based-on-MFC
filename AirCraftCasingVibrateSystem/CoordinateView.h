#pragma once


// CCoordinateView �Ի���

class CCoordinateView : public CDialogEx
{
	DECLARE_DYNAMIC(CCoordinateView)

public:
	CCoordinateView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCoordinateView();

// �Ի�������
	enum { IDD = IDD_DIALOG_COORDINATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
