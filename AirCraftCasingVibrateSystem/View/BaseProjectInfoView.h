#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include "TbDictionary.h"
#include <iostream>
#include "ProductController.h"
#include "DictionaryController.h"
#include <vector>
#include "afxwin.h"
#include "TbProject.h"

using namespace std;
using namespace rapidjson;
// BaseProjectInfoView 对话框

class BaseProjectInfoView : public CDialogEx
{
	DECLARE_DYNAMIC(BaseProjectInfoView)

public:
	BaseProjectInfoView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BaseProjectInfoView();

// 对话框数据
	enum { IDD = IDD_PROJECTBASEINFO_DIALOG };

protected:

	vector<TbDictionary> m_vcollectionPlan;

	DictionaryController m_dictionaryController;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	vector<TbProduct> m_productVector;
	
	ProductController m_productController;

	CGridCtrl m_projectPlanGridCtrl;
	
	void GridCtrlInit();

	/**********************************************************************
	功能描述：检测设备表格的单击事件
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	void SetGridCellCheck(int row,int col,bool isChecked);
	
	CString m_projectName;

	TbProduct m_selectedProduct;

	/**********************************************************************
	功能描述：是否根据当前项目回显项目的信息
	----------------------------------------------------------------------
	***********************************************************************/
	bool m_isEchoProjectData;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	/**********************************************************************
	功能描述：得到选中的项目采集计划
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetSelectedCollectionPlan(vector<TbDictionary> &selectedPlan);
	CComboBox m_productCombo;
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancel();
	CEdit m_projectNameEdit;
	/**********************************************************************
	功能描述：得到项目的基本信息
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void GetProjectBaseInfo(TbProject &project);

	/**********************************************************************
	功能描述：设置项目的回显状态
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	void SetProjectEchoStatus(bool isEcho);
};
