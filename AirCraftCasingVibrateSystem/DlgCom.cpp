// DlgCom.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DlgCom.h"
#include "afxdialogex.h"


// CDlgCom 对话框

IMPLEMENT_DYNAMIC(CDlgCom, CDialogEx)

CDlgCom::CDlgCom(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCom::IDD, pParent)
{

}

CDlgCom::~CDlgCom()
{
}

void CDlgCom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DHTESTHARDWARE1, m_DHHardWare); //IDC_DHTESTHARDWARE1为COM组件的标识
}


BEGIN_MESSAGE_MAP(CDlgCom, CDialogEx)
END_MESSAGE_MAP()


// CDlgCom 消息处理程序
