#pragma once
#include "afxribbonpanel.h"

//¼Ì³ÐRibbonPanelµÄ×ÓÀà
class ChildRibbonPanel :public CMFCRibbonPanel
{
public:
	ChildRibbonPanel(void);
	~ChildRibbonPanel(void);
	//void SetPanelName(CString name);
	BOOL MyReplace(int nIndex, CMFCRibbonBaseElement* pElem);
};