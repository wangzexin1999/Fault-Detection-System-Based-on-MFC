#pragma once


// CollectionPlanManageView �Ի���

class CollectionPlanManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionPlanManageView)

public:
	CollectionPlanManageView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CollectionPlanManageView();

// �Ի�������
	enum { IDD = IDD_DIALOG_COLLECTIONPLANMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
