#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "TbTestingDevice.h"
#include "TestingDeviceController.h"
#include <vector>
#include "afxwin.h"
using namespace std;
// CDetectDeviceManageView �Ի���
class CDetectDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectDeviceManageView)

public:
	CDetectDeviceManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetectDeviceManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECT_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_testingDeviceGridCtrl;
	void GridCtrlInit();
	vector<TbTestingDevice> m_vtestingDevice;
	TestingDeviceController m_testingDeviceController;
	CEdit m_testingDeviceNameEdit;
	TbTestingDevice m_selectedTestingDevice;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSearchButton();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	/**********************************************************************
	��������������豸����ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedDeleteButton();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedSaveButton();
};