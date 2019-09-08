#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
// StableStatusParaPresetView �Ի���

class StableStatusParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(StableStatusParaPresetView)

public:
	StableStatusParaPresetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StableStatusParaPresetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_STABLESTATUSPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_stableStatusGridCtrl;
	void GridCtrlInit();
	DECLARE_MESSAGE_MAP()

	/**********************************************************************
	����������ת�ٵȲ������ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	/**********************************************************************
	�������������ñ���еĶ�ѡ���ѡ��״̬
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetGridCellCheck(int row, int col, bool isChecked);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
};
