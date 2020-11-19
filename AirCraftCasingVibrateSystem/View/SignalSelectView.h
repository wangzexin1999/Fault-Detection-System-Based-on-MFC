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
	CSignalSelectView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSignalSelectView();

// 对话框数据
	enum { IDD = IDD_DIALOG_SIGNAL_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	ChannelController m_channelController;
	vector<TbChannel>  m_channelVector;
	TbChannel m_selectedChannel;
	TbChannel m_tempSelectedChannel;
	/**********************************************************************
	功能描述： 初始化传感器选择的树控件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
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
	功能描述：设置采集窗口的传感器
	输入参数：
	输出参数：
	返 回 值：
	其它说明：设置采集窗口的传感器
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetChannel(TbChannel channel);
	/**********************************************************************
	功能描述：得到采集窗口选择的传感器
	输入参数：
	输出参数：
	返 回 值：
	其它说明：设置采集窗口的传感器
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetChannel(TbChannel & channel);
};
