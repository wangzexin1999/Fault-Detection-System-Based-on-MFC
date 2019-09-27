// EngineerUnitView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "EngineerUnitView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CEngineerUnitView �Ի���

IMPLEMENT_DYNAMIC(CEngineerUnitView, CDialogEx)

CEngineerUnitView::CEngineerUnitView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEngineerUnitView::IDD, pParent)
{

}

CEngineerUnitView::~CEngineerUnitView()
{
}

void CEngineerUnitView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_CUSTOM_EU, m_engineerUintManageGridCtrl);
}


BEGIN_MESSAGE_MAP(CEngineerUnitView, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EU_ADD, &CEngineerUnitView::OnBnClickedButtonEuAdd)
	ON_BN_CLICKED(IDC_BUTTON_EU_DELETE, &CEngineerUnitView::OnBnClickedButtonEuDelete)
	ON_BN_CLICKED(ID_EU_SAVE, &CEngineerUnitView::OnBnClickedEuSave)
	ON_NOTIFY(NM_DBLCLK, IDC_CUSTOM_EU, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_CUSTOM_EU, OnGridClick)
END_MESSAGE_MAP()


// CEngineerUnitView ��Ϣ�������



void CEngineerUnitView::GridCtrlInit()
{

	m_engineerUintManageGridCtrl.SetEditable(true);
	m_engineerUintManageGridCtrl.SetEditable(false);
	m_engineerUintManageGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_engineerUintManageGridCtrl.SetRowCount(m_vEngineerUint.size() + 1); //��ʼΪn��
	m_engineerUintManageGridCtrl.SetColumnCount(2); //��ʼ��Ϊ5��
	m_engineerUintManageGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_engineerUintManageGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_engineerUintManageGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_engineerUintManageGridCtrl.ExpandColumnsToFit(true);
	m_engineerUintManageGridCtrl.SetSingleRowSelection(true);
	m_engineerUintManageGridCtrl.SetRowCount(m_vEngineerUint.size() + 1); //��ʼΪn��
	m_engineerUintManageGridCtrl.SetModified(FALSE);////��ʼ״̬
	//m_productManageGridCtrl.OnGridClick();
	for (int row = 0; row < m_engineerUintManageGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_engineerUintManageGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("���"), 0); }
			if (col == 1){ Item.strText.Format(_T("��λ����"), 1); }
			m_engineerUintManageGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = m_vEngineerUint[row - 1].GetDictValue();
		Item.strText = strText;
		m_engineerUintManageGridCtrl.SetItem(&Item);
	}

}

BOOL CEngineerUnitView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
	GridCtrlInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

// ��ӹ��̵�λ
void CEngineerUnitView::OnBnClickedButtonEuAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_engineerUintManageGridCtrl.InsertRow(CommonUtil::Int2CString(m_vEngineerUint.size() + 1));
	m_engineerUintManageGridCtrl.CheckAutoCenter();
	m_engineerUintManageGridCtrl.Refresh();
}

// ɾ�����̵�λ
void CEngineerUnitView::OnBnClickedButtonEuDelete()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_selectedDictionary.GetDictId() == 0){
		AfxMessageBox("��ѡ����Ҫɾ���ĵ�λ");
		return;
	}
	if (MessageBox("�Ƿ�ɾ�� " + m_selectedDictionary.GetDictValue(), "ɾ����λ", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_dictionController.DeleteEUByEUId(m_selectedDictionary);
	if (res.GetIsSuccess()){
		m_selectedDictionary.SetDictId(0);
		// ���
		m_vEngineerUint.clear();
		///ɾ���ɹ�֮��ˢ��ҳ��
		res = m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///���¼��ر��
		GridCtrlInit();
	}
}

// ���湤�̵�λ
void CEngineerUnitView::OnBnClickedEuSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox("�Ƿ񱣴浱ǰ�޸�", "���湤�̵�λ", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_engineerUintManageGridCtrl.GetRowCount();
	int cols = m_engineerUintManageGridCtrl.GetColumnCount();
	/////���������������ݽ��б���
	Result res;
	for (int row = 1; row < rows; row++){
		TbDictionary dictionary;
		if (row < m_vEngineerUint.size() + 1){
			////������Ҫ���µĵ�Ԫ�񣬶Լ���Ʒid���и�ֵ
			dictionary.SetDictId(m_vEngineerUint[row - 1].GetDictId());
			dictionary.SetDictValue(m_vEngineerUint[row - 1].GetDictValue());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_engineerUintManageGridCtrl.GetItemText(row, col);
			if (col == 1){ dictionary.SetDictValue(itemText); }
		}
		////����޸���û����
		if (dictionary.GetDictId() != 0 && dictionary != m_vEngineerUint[row - 1]){
			dictionary.SetDictName("engineeringunit");
			res = m_dictionController.UpdateDictionary(dictionary);
		}
		////��������֮��û�б��档
		if (dictionary.GetDictId() == 0){
			dictionary.SetDictName("engineeringunit");
			res = m_dictionController.AddDictionary(dictionary);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}

	m_vEngineerUint.clear();
	///ˢ�±��
	res = m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///���¼��ر��
	GridCtrlInit();
}


void CEngineerUnitView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_engineerUintManageGridCtrl.SetEditable(TRUE);
}

void CEngineerUnitView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_vEngineerUint.size()) return;
	m_selectedDictionary = m_vEngineerUint.at(pItem->iRow - 1);
}