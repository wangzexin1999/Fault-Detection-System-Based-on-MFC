#pragma once


// CollectionParaPresetView 对话框

class CollectionParaPresetView : public CDialogEx
{
	DECLARE_DYNAMIC(CollectionParaPresetView)

public:
	CollectionParaPresetView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CollectionParaPresetView();

// 对话框数据
	enum { IDD = IDD_DIALOG_COLLECTIONPARAPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
