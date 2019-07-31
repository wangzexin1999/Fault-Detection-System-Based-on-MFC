// SignalSelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "SignalSelectView.h"
#include "afxdialogex.h"


// CSignalSelectView 对话框

IMPLEMENT_DYNAMIC(CSignalSelectView, CDialogEx)

CSignalSelectView::CSignalSelectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSignalSelectView::IDD, pParent)
{

}

CSignalSelectView::~CSignalSelectView()
{
}

void CSignalSelectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_SELECT_CHANNEL, m_treeSignalSelect);
}


BEGIN_MESSAGE_MAP(CSignalSelectView, CDialogEx)

	ON_NOTIFY(NM_CLICK, IDC_TREE_SELECT_CHANNEL, &CSignalSelectView::OnNMClickTreePath)
END_MESSAGE_MAP()


// CSignalSelectView 消息处理程序


BOOL CSignalSelectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//*********************树形图*************************
	// 树的根节点的句柄   
	HBITMAP hDirBmp;
	hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	//hFileBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(IDB_BITMAP2));

	m_treeSignalSelect.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);

	CFont font;
	font.CreatePointFont(100, _T("Book Antiqua"));

	m_treeSignalSelect.SetFont(&font);
	m_treeSignalSelect.SetFocus();
	m_treeSignalSelect.SetBkColor(RGB(255, 255, 255));
	HTREEITEM hCurrent;



	hCurrent = m_treeSignalSelect.InsertItem(_T("FFT"), TVI_ROOT, TVI_LAST);
	m_treeSignalSelect.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);
	HTREEITEM hCurrent1;
	hCurrent1 = m_treeSignalSelect.InsertItem(_T("1-1"), hCurrent, TVI_LAST);
	hCurrent1 = m_treeSignalSelect.InsertItem(_T("1-1"), hCurrent, TVI_LAST);
	hCurrent1 = m_treeSignalSelect.InsertItem(_T("1-1"), hCurrent, TVI_LAST);
	hCurrent1 = m_treeSignalSelect.InsertItem(_T("1-1"), hCurrent, TVI_LAST);

	/*m_hRoot = NULL;
	AddSubDir(m_hRoot, m_sRootPath);*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

void CSignalSelectView::OnNMClickTreePath(NMHDR *pNMHDR, LRESULT *pResult)
{

	CString tmp;
	HTREEITEM hItem;
	CWnd *m_CWnd;
	m_CWnd = GetDlgItem(IDC_TREE_SELECT_CHANNEL);
	HBITMAP hDirBmp;
	hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(IDB_BMPSIGNALGREEN));
	hItem=m_treeSignalSelect.ClickhItem;
	if (hItem){
		m_treeSignalSelect.AddItemBitmap(hItem, hDirBmp, ppLastLeft);
	}
}