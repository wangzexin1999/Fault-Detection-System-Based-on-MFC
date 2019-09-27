#pragma once
#include "GridCtrl_src/GridCtrl.h"
#include "NewCellTypes/GridCellCheck.h"
#include "NewCellTypes/GridCellCombo.h"
#include "ProductController.h"
#include "afxwin.h"
// CProductManageView �Ի���

class CProductManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CProductManageView)

public:
	CProductManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProductManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETECTED_DEVICE_MANAGE };
public:
	ProductController m_productController;
	vector<TbProduct>  m_vTbProduct;
	TbProduct m_selectedProduct;
public:
	CGridCtrl m_productManageGridCtrl;

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
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
