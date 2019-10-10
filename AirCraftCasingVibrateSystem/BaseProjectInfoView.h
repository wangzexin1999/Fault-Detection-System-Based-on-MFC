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
// BaseProjectInfoView �Ի���

class BaseProjectInfoView : public CDialogEx
{
	DECLARE_DYNAMIC(BaseProjectInfoView)

public:
	BaseProjectInfoView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BaseProjectInfoView();

// �Ի�������
	enum { IDD = IDD_PROJECTBASEINFO_DIALOG };

protected:

	vector<TbDictionary> m_vcollectionPlan;

	DictionaryController m_dictionaryController;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	vector<TbProduct> m_productVector;
	
	ProductController m_productController;

	CGridCtrl m_projectPlanGridCtrl;
	
	void GridCtrlInit();

	/**********************************************************************
	��������������豸���ĵ����¼�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);

	void SetGridCellCheck(int row,int col,bool isChecked);
	
	CString m_projectName;

	TbProduct m_selectedProduct;

	/**********************************************************************
	�����������Ƿ���ݵ�ǰ��Ŀ������Ŀ����Ϣ
	----------------------------------------------------------------------
	***********************************************************************/
	bool m_isEchoProjectData;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	/**********************************************************************
	�����������õ�ѡ�е���Ŀ�ɼ��ƻ�
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetSelectedCollectionPlan(vector<TbDictionary> &selectedPlan);
	CComboBox m_productCombo;
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancel();
	CEdit m_projectNameEdit;
	/**********************************************************************
	�����������õ���Ŀ�Ļ�����Ϣ
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void GetProjectBaseInfo(TbProject &project);

	/**********************************************************************
	����������������Ŀ�Ļ���״̬
	���������
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	void SetProjectEchoStatus(bool isEcho);
};
