#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "DictionaryController.h"
#include <vector>
#include "afxwin.h"
#include "DHTestHardWareController.h"
#include "ChannelParaController.h"
#include "CDHTestHardWare.h"
#include <utility>
#include "TbSensor.h"
#include "TestController.h"
#include "SensorController.h"
// CMyDialog �Ի���

//#include "MainFrm.h" 
using namespace  std;
// ChannelParaPresetView �Ի���

class ChannelParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(ChannelParaPresetView)

public:
	ChannelParaPresetView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChannelParaPresetView();
	void GetParamSelectValue(string strMachineIP);
	int BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator);
	CString m_strSenseCoef;
	
// �Ի�������+
	enum { IDD =IDD_DIALOG_CHANNEL_PARA_SELECT_AND_SET };
private:
	//class CDHTestHardWare *m_pHardWare;
	//class CDlgCom * m_pComDialog;
	//class CMainFrame *m_pMain;
	int m_productId = 0;
	TestController m_testController;
	SensorController m_sensorController;
	std::vector<TbTestlocation> m_testLocationVec;
	std::vector<TbSensor> m_sensorVec;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CGridCtrl m_channelParaGridCtrl;
	vector<CString> m_vchannelCode;
	DictionaryController m_dictionController; 

	vector<TbDictionary> m_vwindowTypes;
	vector<TbDictionary> m_vinputMethods;
	DHTestHardWareController m_dhTestHardWareController;
	//
	vector<TbDictionary> m_ComboFullValue;
	vector<TbDictionary> m_ComboUpFreq;
	vector<TbDictionary> m_ComboInputMode;
	vector<TbDictionary> m_ComboelcValue;


	CComboBox m_startChannelCombo;
	CComboBox m_endChannelCombo;
	vector<vector<int>>  m_vmeasuringRange;
	ChannelParaController m_channelParaController;
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
	void GetSelectedChannels(vector<TbChannel> & vchannels);
	bool GetGridCellCheck(int row, int col);
	void SetProductId(int productTypeId);
};
