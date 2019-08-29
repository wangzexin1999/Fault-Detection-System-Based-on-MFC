// CollectionDataInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionDataInfoDlg.h"
#include "afxdialogex.h"


// CollectionDataInfoDlg 对话框

IMPLEMENT_DYNAMIC(CollectionDataInfoDlg, CDialogEx)

CollectionDataInfoDlg::CollectionDataInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CollectionDataInfoDlg::IDD, pParent)
{

}

CollectionDataInfoDlg::~CollectionDataInfoDlg()
{
}

void CollectionDataInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROTATINGSPEED_EDIT, m_collectionRotatingSpeedEdit);
}


BEGIN_MESSAGE_MAP(CollectionDataInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CollectionDataInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CollectionDataInfoDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CollectionDataInfoDlg 消息处理程序


void CollectionDataInfoDlg::OnBnClickedOk()
{
	m_collectionRotatingSpeedEdit.GetWindowTextA(theApp.m_collectionRotatingSpeed); 
	CDialogEx::OnOK();
}

void CollectionDataInfoDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();

}
