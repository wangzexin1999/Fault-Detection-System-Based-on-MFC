#pragma once


// CGraphicAttributeView �Ի���

class CGraphicAttributeView : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphicAttributeView)

public:
	CGraphicAttributeView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGraphicAttributeView();

// �Ի�������
	enum { IDD = IDD_DIALOG_GRAPHIC_ATTRIBUTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
