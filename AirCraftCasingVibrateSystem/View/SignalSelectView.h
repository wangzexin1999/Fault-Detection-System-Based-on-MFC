#pragma once
#include "afxcmn.h"
#include "CherryTree.h"
#include "ChannelController.h"
#include <vector>
#include "TbChannel.h"
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
	ChannelController m_channelController;
	vector<TbChannel>  m_channelVector;
	TbChannel m_selectedChannel;
	TbChannel m_tempSelectedChannel;
	/**********************************************************************
	���������� ��ʼ��������ѡ������ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void InitChannelSelectTree();
	void InitChannelSelectedTree();
	DECLARE_MESSAGE_MAP()
public:
	CCherryTree m_treeSignalSelect;
	CCherryTree m_treeSignalSelected;
	TbChannel & GetSelectedChannel();
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
	void SetChannel(TbChannel channel);
	/**********************************************************************
	�����������õ��ɼ�����ѡ��Ĵ�����
	���������
	���������
	�� �� ֵ��
	����˵�������òɼ����ڵĴ�����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannel(TbChannel & channel);
};
