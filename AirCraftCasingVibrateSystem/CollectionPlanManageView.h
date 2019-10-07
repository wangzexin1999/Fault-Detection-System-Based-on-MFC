#pragma once


// CollectionPlanManageView 对话框

class CollectionPlanManageView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionPlanManageView)

public:
	CollectionPlanManageView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionPlanManageView();

// 对话框数据
	enum { IDD = IDD_DIALOG_COLLECTIONPLANMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
