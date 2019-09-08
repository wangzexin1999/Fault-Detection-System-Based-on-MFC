// NewProjectView.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "AirCraftCasingVibrateSystem.h"

#include "NewProjectView.h"
#include "afxdialogex.h"
#include "TbProject.h"
#include "TbTester.h"
#include "Result.h"
#include "DateUtil.h"
// CNewProjectView �Ի���

IMPLEMENT_DYNAMIC(CNewProjectView, CDialogEx)

CNewProjectView::CNewProjectView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewProjectView::IDD, pParent)
{
	
}

CNewProjectView::~CNewProjectView()
{

}

void CNewProjectView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PROJECTOPERATORLIST_TREE, m_projectOperatorTreeCtrl);
	DDX_Control(pDX, IDC_TAB_PROJECTNAVIGATION, m_projectNavigationTab);
}


BEGIN_MESSAGE_MAP(CNewProjectView, CDialogEx)
	ON_BN_CLICKED(IDOK, &CNewProjectView::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PROJECTNAVIGATION, &CNewProjectView::OnTcnSelchangeTabProjectnavigation)
	ON_BN_CLICKED(IDC_BUTTON_LASTSTEP, &CNewProjectView::OnBnClickedButtonLaststep)
	ON_BN_CLICKED(IDC_BUTTON_NEXTSTEP, &CNewProjectView::OnBnClickedButtonNextstep)
END_MESSAGE_MAP()


// CNewProjectView ��Ϣ�������
/*�½���Ŀ��ť*/
void CNewProjectView::OnBnClickedOk()
{
	/*CString projectName;
	m_projectNameEdit.GetWindowTextA(projectName);
	if (projectName == ""){ AfxMessageBox("��Ŀ������Ϊ��"); return;}
	int detectedIndex = m_productCombo.GetCurSel();

	if (detectedIndex > 0) {
	detectedIndex--;
	}
	else{
	AfxMessageBox("��ѡ���Ʒ");
	return;
	}
	TbTester tester = theApp.m_currentProject.GetTester();

	TbProduct product;
	product.SetProductId(m_productVector[detectedIndex].GetProductId());

	TbProject project;
	project.SetProjectName(projectName);
	project.SetProduct(product);
	project.SetTester(tester);
	project.SetProjectCreateTime(DateUtil::GetCurrentCStringTime());

	project.GetTestingDevicePara().GetTestingdevice().SetTestingdeviceId(1);
	Result res = m_projectController.AddProject(project);

	if (!res.GetIsSuccess()){
	AfxMessageBox(res.GetMessages());
	}
	else{
	AfxMessageBox(res.GetMessages());
	CDialogEx::OnOK();
	}*/
}

BOOL CNewProjectView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	///����tab����
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_projectNavigationTab.InsertItem(0, _T("������Ϣ"));
	m_projectNavigationTab.InsertItem(1, _T("�ɼ�����"));
	m_projectNavigationTab.InsertItem(2, _T("ͨ������"));
	m_projectNavigationTab.InsertItem(3, _T("ƽ�Ȳɼ�״̬��������"));
	//����ͨ��������ʾ����ͼ  
	m_baseProjectInfoView.Create(IDD_PROJECTBASEINFO_DIALOG, &m_projectNavigationTab);
	m_collectionParaPresetView.Create(IDD_DIALOG_COLLECTIONPARAPRESET, &m_projectNavigationTab);
	m_channelParaPresetView.Create(IDD_DIALOG_CHANNELPARAPRESET, &m_projectNavigationTab);
	m_stableStatusParaPresetView.Create(IDD_DIALOG_STABLESTATUSPRESET, &m_projectNavigationTab);
	//�趨��Tab����ʾ�ķ�Χ  
	CRect tabRect;
	GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 22;
	tabRect.bottom -= 1;

	//m_tabSystemPara.MoveWindow(tabRect);
	m_baseProjectInfoView.MoveWindow(&tabRect);
	m_collectionParaPresetView.MoveWindow(&tabRect);
	m_channelParaPresetView.MoveWindow(&tabRect);
	m_stableStatusParaPresetView.MoveWindow(&tabRect);

	//�ѶԻ������ָ�뱣������
	m_pDialogVec.push_back(&m_baseProjectInfoView);
	m_pDialogVec.push_back(&m_collectionParaPresetView);
	m_pDialogVec.push_back(&m_channelParaPresetView);
	m_pDialogVec.push_back(&m_stableStatusParaPresetView);
	//��ʾ��ʼҳ��  
	m_baseProjectInfoView.ShowWindow(SW_SHOW);
	m_collectionParaPresetView.ShowWindow(SW_HIDE);
	m_channelParaPresetView.ShowWindow(SW_HIDE);
	m_stableStatusParaPresetView.ShowWindow(SW_HIDE);
	//��ǰѡ���tab������
	m_icurSelTabIndex = 0;

	////��ʼ�����οؼ�
	//InitProjectOperatorTree();
	////��ʼ�����ؼ�

	//GridCtrlInit();
	
	/*2.����ProjectControllerȥ��ѯ��Ʒ�������б������*/
	Result res = m_projectController.LoadAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		int i = 0;
	/*	m_productCombo.InsertString(i,"�ݲ�ѡ��2");
		for (auto product : m_productVector){
			m_productCombo.InsertString(++i,product.GetProductType());
		}
		m_productCombo.SetCurSel(0);*/
	}
	else
	{
		AfxMessageBox(res.GetMessages());
	}
	return TRUE;  
}

void CNewProjectView::InitProjectOperatorTree(){
	m_projectOperatorTreeCtrl.DeleteAllItems();

	// ���ĸ��ڵ�ľ��   
	HBITMAP hDirBmp;
	hDirBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(ID_BMPSIGNALRED));
	m_projectOperatorTreeCtrl.ModifyStyle(0, TVS_TRACKGROUPSELECT | TVS_SINGLECLICKEXPAND | TVS_HASBUTTONS | TVS_HASLINES);
	CFont font;
	font.CreatePointFont(100, _T("Book Antiqua"));

	m_projectOperatorTreeCtrl.SetFont(&font);
	m_projectOperatorTreeCtrl.SetFocus();
	m_projectOperatorTreeCtrl.SetBkColor(RGB(255, 255, 255));

	HTREEITEM hCurrent;
	HTREEITEM childItem;
	HBITMAP childBmp = ::LoadBitmap(_AtlBaseModule.m_hInstResource, MAKEINTRESOURCE(IDB_BMPSIGNALGREEN));
	
	hCurrent = m_projectOperatorTreeCtrl.InsertItem(_T("ͨ��ѡ��"), TVI_ROOT, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);

	hCurrent = m_projectOperatorTreeCtrl.InsertItem(_T("ת��"), TVI_ROOT, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(hCurrent, hDirBmp, ppLastLeft);

	/*childItem = m_projectOperatorTreeCtrl.InsertItem(_T("ת��"), hCurrent, TVI_LAST);
	m_projectOperatorTreeCtrl.AddItemBitmap(childItem, childBmp, ppLastLeft);*/

}
void CNewProjectView::GridCtrlInit(){
	m_projectOperatorDataGridCtrl.SetEditable(false);
	m_projectOperatorDataGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_projectOperatorDataGridCtrl.SetRowCount(8); //��ʼΪn��
	m_projectOperatorDataGridCtrl.SetColumnCount(3); //��ʼ��Ϊ5��
	m_projectOperatorDataGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_projectOperatorDataGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_projectOperatorDataGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_projectOperatorDataGridCtrl.ExpandColumnsToFit(true);
	m_projectOperatorDataGridCtrl.SetSingleRowSelection(true);
	for (int row = 0; row < m_projectOperatorDataGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_projectOperatorDataGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		if (row == 0 ) //��(0��0)��
		{
			if (col == 0){
				Item.strText.Format(_T("ת�����"), 0);
			}
			if (col == 1){
				Item.strText.Format(_T("ת��ֵ"), 1);
			}
			if (col == 2){
				Item.strText.Format(_T("��ע"), 2);
			}
		}

		else if (col < 1) //����0�б�ͷ��ʾ
		{
			if (row < m_projectOperatorDataGridCtrl.GetRowCount())
			{
				Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
				Item.strText.Format(_T("��%d��"), row);
			}
		}
		else
		{
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			Item.strText.Format(_T(""), 2);
		}
		m_projectOperatorDataGridCtrl.SetItem(&Item);
	}
}

void CNewProjectView::OnTcnSelchangeTabProjectnavigation(NMHDR *pNMHDR, LRESULT *pResult)
{
	//�ѵ�ǰ��ҳ����������
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_icurSelTabIndex = m_projectNavigationTab.GetCurSel();
	//���µ�ҳ����ʾ����
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	*pResult = 0;
}


////��һ��
void CNewProjectView::OnBnClickedButtonLaststep()
{
	///�ж��Ƿ�Խ��
	if (m_icurSelTabIndex == 0) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex--;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}

////��һ��
void CNewProjectView::OnBnClickedButtonNextstep()
{
	///�ж��Ƿ�Խ��
	if (m_icurSelTabIndex == m_pDialogVec.size()-1) return;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_HIDE);
	m_icurSelTabIndex++;
	m_pDialogVec[m_icurSelTabIndex]->ShowWindow(SW_SHOW);
	m_projectNavigationTab.SetCurFocus(m_icurSelTabIndex);
}
