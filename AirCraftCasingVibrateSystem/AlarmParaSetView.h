#pragma once


// CAlarmParaSetView �Ի���

class CAlarmParaSetView : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarmParaSetView)

public:
	CAlarmParaSetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAlarmParaSetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_ALARM_PARA_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
