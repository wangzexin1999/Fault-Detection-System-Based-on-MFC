#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"

// BaseProjectInfoView �Ի���

class BaseProjectInfoView : public CDialogEx
{
	DECLARE_DYNAMIC(BaseProjectInfoView)

public:
	BaseProjectInfoView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BaseProjectInfoView();

// �Ի�������
	enum { IDD = IDD_PROJECTBASEINFO_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	CGridCtrl m_projectPlanGridCtrl;
	
	void GridCtrlInit();

	/**********************************************************************
	��������������豸���ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	void SetGridCellCheck(int row,int col,bool isChecked);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
