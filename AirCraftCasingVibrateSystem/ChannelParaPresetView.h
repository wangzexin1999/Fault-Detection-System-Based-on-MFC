#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
using namespace  std;
// ChannelParaPresetView �Ի���

class ChannelParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(ChannelParaPresetView)

public:
	ChannelParaPresetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChannelParaPresetView();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANNELPARAPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_channelParaGridCtrl;

	DictionaryController m_dictionController; 
	vector<TbDictionary> m_vwindowTypes;
	vector<TbDictionary> m_vinputMethods;

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
public:
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
	void GetSelectedChannels(vector<TbSensor> & vsensors);
};
