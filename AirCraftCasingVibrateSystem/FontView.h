#pragma once


// CFontView �Ի���

class CFontView : public CDialogEx
{
	DECLARE_DYNAMIC(CFontView)
public:
	LOGFONT lFontXCoor;
	LOGFONT lFontYCoor;
	LOGFONT lFontXUnit;
	LOGFONT lFontYUnit;
	LOGFONT lFontCursorValue;
	LOGFONT lFontStaValue;
	LOGFONT lFontLegend;
public:
	CFontView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFontView();

// �Ի�������
	enum { IDD = IDD_DIALOG_FONT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
