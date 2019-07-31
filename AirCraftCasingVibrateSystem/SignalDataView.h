#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include<vector>
#include "TbSignal.h"
using namespace std;
// CSignalDataView 对话框

class CSignalDataView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalDataView)

public:
	CSignalDataView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalDataView();
	
// 对话框数据
	enum { IDD = IDD_DIALOG_OPEN_DATA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_signalDataGridCtrl;
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()
	CEdit m_singnalDataNameCtrl;
	CDateTimeCtrl m_signalDataStartTimeCtrl;
	CDateTimeCtrl m_signalDataEndTimeCtrl;
	vector<TbSignal> m_signalVector;
public:
	virtual BOOL OnInitDialog();
};
