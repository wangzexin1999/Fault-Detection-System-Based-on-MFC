#pragma once
#include "afxcmn.h"
#include "CherryTree.h"
#include "SensorController.h"
#include <vector>
#include "TbSensor.h"
using namespace std;
class CSignalSelectView : public CDialogEx
{
	DECLARE_DYNAMIC(CSignalSelectView)

public:
	CSignalSelectView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSignalSelectView();

// �Ի�������
	enum { IDD = IDD_DIALOG_SIGNAL_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	SensorController m_sensorController;
	vector<TbSensor>  m_sensorVector;
	TbSensor m_selectedSensor;
	TbSensor m_tempSelectedSensor;
	/**********************************************************************
	���������� ��ʼ��������ѡ������ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitSensorSelectTree();
	void InitSensorSelectedTree();
	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	CCherryTree m_treeSignalSelected;
	TbSensor & GetSelectedSensor();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkTreeSelectChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeSelectedChannel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	/**********************************************************************
	�������������òɼ����ڵĴ�����
	���������
	���������
	�� �� ֵ��
	����˵�������òɼ����ڵĴ�����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetSensor(TbSensor sensor);
};
