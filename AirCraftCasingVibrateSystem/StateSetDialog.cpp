// StateSetDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "StateSetDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Constant.h"
// CStateSetDialog �Ի���

IMPLEMENT_DYNAMIC(CStateSetDialog, CDialogEx)

CStateSetDialog::CStateSetDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStateSetDialog::IDD, pParent)
{
}

CStateSetDialog::~CStateSetDialog()
{
}

void CStateSetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_COLLECTIONPLANGRID, m_collectionPlanGrid);
	DDX_Control(pDX, IDC_COMBO_COLLECTIONPLAN, m_collectionPlanCombo);
	DDX_Control(pDX, IDC_STATIC_CUR_PLAN_PARA, m_staticCurrentPlanPara);
}

BEGIN_MESSAGE_MAP(CStateSetDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_COLLECTIONPLAN, &CStateSetDialog::OnCbnSelchangeComboCollectionplan)
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_DBLCLK, IDC_COLLECTIONPLANGRID, OnGridDblClick)
END_MESSAGE_MAP()

// CStateSetDialog ��Ϣ�������
void CStateSetDialog::OnCbnSelchangeComboCollectionplan()
{
	GridCtrlInit();
}

BOOL CStateSetDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	RefreshView();
	/*�����ı�����*/
	CString strPlanName;
	m_collectionPlanCombo.GetWindowTextA(strPlanName);
	int selectedIndex = m_collectionPlanCombo.GetCurSel();
	///����ѡ��Ĳɼ��ƻ���Ž�����Ӧ�Ĳɼ��ƻ�����
	if (!m_collectionPlanDoc.IsNull()){
		Value  doc;
		doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
		const Value & colectionPlans = doc["collectionPlans"].GetArray();
		///�õ��ɼ��ƻ��ı�����Ϣ 
		const Value & planTitle = colectionPlans[selectedIndex]["planParaTitle"];
		m_staticCurrentPlanPara.SetWindowTextA(strPlanName+"--������");
	}

	return TRUE; 
}
void CStateSetDialog::GridCtrlInit()
{
	///ɾ�����е��б���
	m_collectionPlanGrid.DeleteAllItems();
	m_collectionPlanGrid.Refresh();
	///�õ���ǰѡ�еĲɼ��ƻ����
	int selectedIndex = m_collectionPlanCombo.GetCurSel();
	if (selectedIndex < 0) return;
	///����ѡ��Ĳɼ��ƻ���Ž�����Ӧ�Ĳɼ��ƻ�����
	Value  doc;
	doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
	const Value & colectionPlans = doc["collectionPlans"].GetArray();

	///�õ��ɼ��ƻ��ı�����Ϣ 
	const Value & planTitle = colectionPlans[selectedIndex]["planParaTitle"];
	///�õ��ɼ��ƻ��Ĳ�����Ϣ
	const Value & planParaContent = colectionPlans[selectedIndex]["planParaContent"];
	m_collectionPlanGrid.SetEditable(true);
	// 2. �����Ϣ
	m_collectionPlanGrid.SetEditable(true);
	m_collectionPlanGrid.SetEditable(true);
	m_collectionPlanGrid.SetEditable(false);
	m_collectionPlanGrid.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_collectionPlanGrid.SetRowCount(planParaContent.Size() + 1); //��ʼΪn��
	m_collectionPlanGrid.SetColumnCount(planTitle.Size()); //��ʼ��Ϊ3��
	m_collectionPlanGrid.SetFixedRowCount(1); //��ͷΪһ��
	m_collectionPlanGrid.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_collectionPlanGrid.SetColumnResize(TRUE);
	m_collectionPlanGrid.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_collectionPlanGrid.ExpandColumnsToFit(true);
	m_collectionPlanGrid.SetSingleRowSelection(true);

	//m_collectionPlanGrid.OnGridClick();
	for (int row = 0; row < m_collectionPlanGrid.GetRowCount(); row++){
		for (int col = 0; col < m_collectionPlanGrid.GetColumnCount(); col++)
		{
			//���ñ����ʾ����
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			///���ñ�ͷ����
			if (row == 0){
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				Item.strText.Format(_T(planTitle[col].GetString()));
				m_collectionPlanGrid.SetItem(&Item);
				continue;
			}

			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

			CString strText = planParaContent[row-1][col].GetString();
			Item.strText = strText;
			m_collectionPlanGrid.SetItem(&Item);
		}
	}
}
void  CStateSetDialog::ComboBoxInit(){
	if (m_collectionPlanDoc.IsNull())return;
	///������Ŀ�����
	Value  doc;
	doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
	const Value & colectionPlans = doc["collectionPlans"].GetArray();

	for (int i = 0; i < colectionPlans.Size(); i++){
		string planName = colectionPlans[i]["planName"].GetString();
		m_collectionPlanCombo.InsertString(i, planName.c_str());
	}
	m_collectionPlanCombo.SetCurSel(0);
}

void CStateSetDialog::RefreshView(){
	///1.������Ŀ���¼��json����
	m_collectionPlanDoc.Parse(theApp.m_currentProject.GetCollectionPlans());
	if (m_collectionPlanDoc.HasParseError()){
		AfxMessageBox("�ɼ��ƻ�����ʧ��");
		return;
	}
	///2.��������б����ʾ
	m_collectionPlanCombo.ResetContent();
	///3.���³�ʼ��������
	ComboBoxInit();
	///4.���³�ʼ����ʾ�б�
	GridCtrlInit();
}

HBRUSH CStateSetDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CUR_PLAN_PARA)
	{
		//������ʾ����

		CFont * cFont = new CFont;

		cFont->CreateFont(16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, 0,ANSI_CHARSET, 
			OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH&FF_SWISS, "����");
		pDC->SetTextColor(RGB(255, 0, 0));
		pWnd->SetFont(cFont); //��������
		delete cFont;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CStateSetDialog::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;


	CString strPlanName;
	m_collectionPlanCombo.GetWindowTextA(strPlanName);
	///�õ���ǰѡ�еĲɼ��ƻ����
	int selectedIndex = m_collectionPlanCombo.GetCurSel();
	if (selectedIndex < 0) return;
	///����ѡ��Ĳɼ��ƻ���Ž�����Ӧ�Ĳɼ��ƻ�����
	Value  doc;
	doc.CopyFrom(m_collectionPlanDoc, m_collectionPlanDoc.GetAllocator());
	const Value & colectionPlans = doc["collectionPlans"].GetArray();

	///�õ��ɼ��ƻ��ı�����Ϣ 
	const Value & planTitle = colectionPlans[selectedIndex]["planParaTitle"];
	///�õ��ɼ��ƻ��Ĳ�����Ϣ
	const Value & planParaContent = colectionPlans[selectedIndex]["planParaContent"];
	CString currentPlanPara = planParaContent[pItem->iRow - 1][0].GetString();


	m_staticCurrentPlanPara.SetWindowTextA(strPlanName + "--������" + planTitle[0].GetString() + ":" + currentPlanPara);
	theApp.m_collectionRotatingSpeed = currentPlanPara;
	CMainFrame *mainFram = (CMainFrame *)AfxGetMainWnd();
	mainFram->SendMessage(WM_SETTEXT);
	mainFram->SendMessage(StatusInfMessage);
}