// StatisticView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StatisticView.h"
#include "afxdialogex.h"


// CStatisticView �Ի���

IMPLEMENT_DYNAMIC(CStatisticView, CDialogEx)

CStatisticView::CStatisticView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStatisticView::IDD, pParent)
{

}

CStatisticView::~CStatisticView()
{
}

void CStatisticView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStatisticView, CDialogEx)
END_MESSAGE_MAP()


// CStatisticView ��Ϣ�������
