#pragma once
#include "BaseProjectInfoView.h"
#include "ChannelParaPresetView.h"
#include "TbProject.h"
#include "CollectionPlanParaPresetView.h"
#include "afxcmn.h"

class ProjectSetView : public CDialogEx
{
	DECLARE_DYNAMIC(ProjectSetView)

public:
	ProjectSetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ProjectSetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_PROJECTSET };

protected:
	BaseProjectInfoView m_baseProjectInfoView;
	ChannelParaPresetView m_channelParaPresetView;
	int m_icurSelTabIndex;
	int m_newDialogIndex;
	TbProject m_project;
	vector<CDialog*> m_pDialogVec;  //��������Ի������ָ��
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_projectNavigationTab;
	/**********************************************************************
	���������� �����һ���İ�ť
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedButtonLaststep();
	/**********************************************************************
	���������� �����һ���İ�ť
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedButtonNextstep();
	/**********************************************************************
	���������� ���ȷ���İ�ť
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedOk();
	/**********************************************************************
	���������� ���ȡ���İ�ť
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnBnClickedCancel();
	/**********************************************************************
	���������� tab�����������¼����л���ǰ��ʾ�Ĵ���
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnTcnSelchangeTabProjectNavigation(NMHDR *pNMHDR, LRESULT *pResult);
};
