// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SelectView.h"
#include "afxdialogex.h"


// CSelectView �Ի���

IMPLEMENT_DYNAMIC(CSelectView, CDialogEx)

CSelectView::CSelectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectView::IDD, pParent)
{

}

CSelectView::~CSelectView()
{
}

void CSelectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectView, CDialogEx)
END_MESSAGE_MAP()


// CSelectView ��Ϣ�������
