#pragma once
#include "StateSetDialog.h"
// CStateSetDockPanelView

class CStateSetDockPanelView : public CDockablePane
{
	DECLARE_DYNAMIC(CStateSetDockPanelView)

public:

	CStateSetDockPanelView();
	
	virtual ~CStateSetDockPanelView();

public:
//	CStateSetView m_stateSetView;
	CStateSetDialog m_stateSetDialog;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void RefreshView();
};


