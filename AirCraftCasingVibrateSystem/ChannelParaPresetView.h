#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
#include "afxwin.h"
#include "AdvantechDaqController.h"
using namespace  std;
// ChannelParaPresetView �Ի���

class ChannelParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(ChannelParaPresetView)

public:
	ChannelParaPresetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChannelParaPresetView();

// �Ի�������
	enum { IDD =IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_channelParaGridCtrl;
	vector<CString> m_vchannelId;
	DictionaryController m_dictionController; 
	vector<TbDictionary> m_vwindowTypes;
	vector<TbDictionary> m_vinputMethods;
	AdvantechDaqController m_advantechDaqController;
	CComboBox m_startChannelCombo;
	CComboBox m_endChannelCombo;
	DECLARE_MESSAGE_MAP()
	/**********************************************************************
	������������ʼ�����ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GridCtrlInit();
	/**********************************************************************
	������������ʼ�����ؼ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void ChannelComboInit();
	/**********************************************************************
	����������ͨ���������ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	����������ͨ����������˫���¼���˫�����ÿ��޸���Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	�������������ñ���ж�ѡ���ѡ��״̬
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetGridCellCheck(int row, int col, bool isChecked);
	virtual BOOL OnInitDialog();
	/**********************************************************************
	�����������õ�ѡ�����������ͨ��
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/

	
	afx_msg void OnCbnSelchangeComboStartChannel();
	afx_msg void OnCbnSelchangeComboEndChannel();
public:
	void GetSelectedChannels(vector<TbSensor> & vsensors);

};
