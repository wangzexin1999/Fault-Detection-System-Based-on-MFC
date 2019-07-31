// GeometricParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeometricParaView.h"
#include "afxdialogex.h"


// CGeometricParaView 对话框

IMPLEMENT_DYNAMIC(CGeometricParaView, CDialogEx)

CGeometricParaView::CGeometricParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeometricParaView::IDD, pParent)
{

}

CGeometricParaView::~CGeometricParaView()
{
}

void CGeometricParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGeometricParaView, CDialogEx)
END_MESSAGE_MAP()


// CGeometricParaView 消息处理程序
