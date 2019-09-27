#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "ProductController.h"
#include "afxwin.h"
// CProductManageView 对话框

class CProductManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CProductManageView)

public:
	CProductManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProductManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECTED_DEVICE_MANAGE };
public:
	ProductController m_productController;
	vector<TbProduct>  m_vTbProduct;
	TbProduct m_selectedProduct;
public:
	CGridCtrl m_productManageGridCtrl;

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
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	afx_msg void OnBnClickedAddProductButton();
	afx_msg void OnBnClickedDeleteProductButton();
	afx_msg void OnBnClickedSaveProduct();
	CEdit m_productEdit;
	afx_msg void OnBnClickedBtnSearchProduct();
};
