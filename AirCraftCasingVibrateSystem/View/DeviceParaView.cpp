// DeviceParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DeviceParaView.h"
#include "afxdialogex.h"


// CDeviceParaView �Ի���

IMPLEMENT_DYNAMIC(CDeviceParaView, CDialogEx)

CDeviceParaView::CDeviceParaView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceParaView::IDD, pParent)
{

}

CDeviceParaView::~CDeviceParaView()
{
}

void CDeviceParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeviceParaView, CDialogEx)
END_MESSAGE_MAP()


// CDeviceParaView ��Ϣ�������
