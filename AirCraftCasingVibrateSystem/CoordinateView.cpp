// CoordinateView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CoordinateView.h"
#include "afxdialogex.h"


// CCoordinateView �Ի���

IMPLEMENT_DYNAMIC(CCoordinateView, CDialogEx)

CCoordinateView::CCoordinateView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCoordinateView::IDD, pParent)
{

}

CCoordinateView::~CCoordinateView()
{
}

void CCoordinateView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCoordinateView, CDialogEx)
END_MESSAGE_MAP()


// CCoordinateView ��Ϣ�������
