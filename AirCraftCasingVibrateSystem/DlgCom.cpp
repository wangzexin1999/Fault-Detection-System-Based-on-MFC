// DlgCom.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DlgCom.h"
#include "afxdialogex.h"


// CDlgCom �Ի���

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
	DDX_Control(pDX, IDC_DHTESTHARDWARE1, m_DHHardWare); //IDC_DHTESTHARDWARE1ΪCOM����ı�ʶ
}


BEGIN_MESSAGE_MAP(CDlgCom, CDialogEx)
END_MESSAGE_MAP()


// CDlgCom ��Ϣ�������
