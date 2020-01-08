#include "StdAfx.h"
#include "ChildRibbonPanel.h"


ChildRibbonPanel::ChildRibbonPanel(void)
{
}


ChildRibbonPanel::~ChildRibbonPanel(void)
{
}

BOOL ChildRibbonPanel::MyReplace(int nIndex, CMFCRibbonBaseElement* pElem)
{

	//在这里进行名字转行赋值
	//m_strName = name;
	//return ReplaceByID(uiCmdID, pElem);
	ASSERT_VALID(this);
	ASSERT_VALID(pElem);

	if (nIndex < 0 || nIndex >= m_arElements.GetSize())
	{
		ASSERT(FALSE);
		return FALSE;
	}

	CMFCRibbonBaseElement* pOldElem = m_arElements[nIndex];
	ASSERT_VALID(pOldElem);

	pElem->CopyFrom(*pOldElem);
	m_arElements[nIndex] = pElem;

	delete pOldElem;
	return TRUE;
	
}