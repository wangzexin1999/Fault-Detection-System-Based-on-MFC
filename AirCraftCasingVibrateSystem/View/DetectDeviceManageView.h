#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "TbCollectionparas.h"
#include "CollectionparasController.h"
#include <vector>
#include "afxwin.h"
using namespace std;
// CDetectDeviceManageView 对话框
class CDetectDeviceManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CDetectDeviceManageView)

public:
	CDetectDeviceManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetectDeviceManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECT_DEVICE_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CGridCtrl m_collectionparasGridCtrl;
	void GridCtrlInit();
	vector<TbCollectionparas> m_vcollectionparas;
	CollectionparasController m_collectionparasController;
	CEdit m_collectionparasNameEdit;
	TbCollectionparas m_selectedCollectionparas;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSearchButton();
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);

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
	afx_msg void OnBnClickedDeleteButton();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedSaveButton();
};
