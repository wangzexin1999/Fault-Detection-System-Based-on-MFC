#pragma once
#include "afxribbonpanel.h"

//�̳�RibbonPanel������
class ChildRibbonPanel :public CMFCRibbonPanel
{
public:
	ChildRibbonPanel(void);
	~ChildRibbonPanel(void);
	//void SetPanelName(CString name);
	BOOL MyReplace(int nIndex, CMFCRibbonBaseElement* pElem);
};