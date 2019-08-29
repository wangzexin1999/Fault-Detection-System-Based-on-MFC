// CollectionDataInfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "CollectionDataInfoDlg.h"
#include "afxdialogex.h"


// CollectionDataInfoDlg �Ի���

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


// CollectionDataInfoDlg ��Ϣ�������


void CollectionDataInfoDlg::OnBnClickedOk()
{
	m_collectionRotatingSpeedEdit.GetWindowTextA(theApp.m_collectionRotatingSpeed); 
	CDialogEx::OnOK();
}

void CollectionDataInfoDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();

}
