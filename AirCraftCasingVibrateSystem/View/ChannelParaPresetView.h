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
// CMyDialog 对话框

//#include "MainFrm.h" 
using namespace  std;
// ChannelParaPresetView 对话框

class ChannelParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(ChannelParaPresetView)

public:
	ChannelParaPresetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChannelParaPresetView();
	void GetParamSelectValue(string strMachineIP);
	int BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator);
	CString m_strSenseCoef;
	
// 对话框数据+
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
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
	功能描述：初始化表格控件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GridCtrlInit();
	/**********************************************************************
	功能描述：初始化表格控件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void ChannelComboInit();
	/**********************************************************************
	功能描述：通道参数表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	/**********************************************************************
	功能描述：通道参数表格的双击事件，双击设置可修改信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);


	/**********************************************************************
	功能描述：设置表格中多选框的选中状态
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetGridCellCheck(int row, int col, bool isChecked);

	

	virtual BOOL OnInitDialog();
	/**********************************************************************
	功能描述：得到选择的所有所有通道
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/

	
	afx_msg void OnCbnSelchangeComboStartChannel();
	afx_msg void OnCbnSelchangeComboEndChannel();
public:
	void GetSelectedChannels(vector<TbChannel> & vchannels);
	bool GetGridCellCheck(int row, int col);
	void SetProductId(int productTypeId);
};
