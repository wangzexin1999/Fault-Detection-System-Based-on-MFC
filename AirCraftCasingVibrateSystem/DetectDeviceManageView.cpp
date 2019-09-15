// DetectDeviceManageView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "DetectDeviceManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CDetectDeviceManageView �Ի���

IMPLEMENT_DYNAMIC(CDetectDeviceManageView, CDialogEx)

CDetectDeviceManageView::CDetectDeviceManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDetectDeviceManageView::IDD, pParent)
{

}

CDetectDeviceManageView::~CDetectDeviceManageView()
{
}

void CDetectDeviceManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_TESTINGDEVICE_GRIDCTRL, m_testingDeviceGridCtrl);
	DDX_Control(pDX, IDC_TESTINGDEVICENAME_EDIT, m_testingDeviceNameEdit);
}


BEGIN_MESSAGE_MAP(CDetectDeviceManageView, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, &CDetectDeviceManageView::OnBnClickedSearchButton)
	ON_NOTIFY(NM_DBLCLK, IDC_TESTINGDEVICE_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_TESTINGDEVICE_GRIDCTRL, OnGridClick)
	ON_BN_CLICKED(ID_DELETE_BUTTON, &CDetectDeviceManageView::OnBnClickedDeleteButton)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CDetectDeviceManageView::OnBnClickedAddButton)
	ON_BN_CLICKED(ID_SAVE_BUTTON, &CDetectDeviceManageView::OnBnClickedSaveButton)
END_MESSAGE_MAP()


// CDetectDeviceManageView ��Ϣ�������


BOOL CDetectDeviceManageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	////��ȡ����豸������
	Result res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("",m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	////��ʼ��GridCtrl�ؼ�
	GridCtrlInit();
	return TRUE;  
}

void CDetectDeviceManageView::GridCtrlInit(){
	m_testingDeviceGridCtrl.SetEditable(true);
	m_testingDeviceGridCtrl.SetEditable(false);
	m_testingDeviceGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_testingDeviceGridCtrl.SetRowCount(m_vtestingDevice.size()+1); //��ʼΪn��
	m_testingDeviceGridCtrl.SetColumnCount(5); //��ʼ��Ϊ5��
	m_testingDeviceGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_testingDeviceGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_testingDeviceGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_testingDeviceGridCtrl.ExpandColumnsToFit(true);
	m_testingDeviceGridCtrl.SetSingleRowSelection(true);
	m_testingDeviceGridCtrl.SetRowCount(m_vtestingDevice.size() + 1); //��ʼΪn��
	m_testingDeviceGridCtrl.SetModified(FALSE);////��ʼ״̬
	//m_testingDeviceGridCtrl.OnGridClick();
	for (int row = 0; row < m_testingDeviceGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_testingDeviceGridCtrl.GetColumnCount(); col++)
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
			if (col == 1){ Item.strText.Format(_T("����豸IP"), 1); }
			if (col == 2){ Item.strText.Format(_T("����豸����"), 2); }
			if (col == 3){ Item.strText.Format(_T("����豸����ʱ��"), 3); }
			if (col == 4){ Item.strText.Format(_T("����豸����ʱ��"), 4); }
			m_testingDeviceGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = m_vtestingDevice[row - 1].GetTestingdeviceIp();
		if (col == 2) strText = m_vtestingDevice[row - 1].GetTestingdeviceName();
		if (col == 3) strText = m_vtestingDevice[row - 1].GetTestingdeviceBorndate();
		if (col == 4) strText = m_vtestingDevice[row - 1].GetTestingdeviceImportdate();

		Item.strText=strText;
		m_testingDeviceGridCtrl.SetItem(&Item);
	}
}

void CDetectDeviceManageView::OnBnClickedSearchButton()
{
	CString testingDeviceName="";
	m_testingDeviceNameEdit.GetWindowTextA(testingDeviceName);
	Result res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition(testingDeviceName, m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();
}
void CDetectDeviceManageView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_vtestingDevice.size()) return;
	m_selectedTestingDevice = m_vtestingDevice.at(pItem->iRow - 1);
}

void CDetectDeviceManageView::OnBnClickedDeleteButton(){
	if (m_selectedTestingDevice.GetTestingdeviceId() == 0){
		AfxMessageBox("��ѡ����Ҫɾ�����豸");
		return;
	}
	if (MessageBox("�Ƿ�ɾ�� " + m_selectedTestingDevice.GetTestingdeviceName(), "ɾ���豸", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_testingDeviceController.DeleteByTestingDeviceId(m_selectedTestingDevice);
	if (res.GetIsSuccess()){
		m_selectedTestingDevice.SetTestingdeviceId(0);
		///ɾ���ɹ�֮��ˢ��ҳ��
		res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///���¼��ر��
		GridCtrlInit();
	}

}

void CDetectDeviceManageView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_testingDeviceGridCtrl.SetEditable(TRUE);
}

///��Ӽ���豸��ť
void CDetectDeviceManageView::OnBnClickedAddButton()
{
	m_testingDeviceGridCtrl.InsertRow(CommonUtil::Int2CString(m_vtestingDevice.size() + 1));
	m_testingDeviceGridCtrl.Refresh();
}


void CDetectDeviceManageView::OnBnClickedSaveButton(){
	if (MessageBox("�Ƿ񱣴浱ǰ�޸�", "�����豸", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_testingDeviceGridCtrl.GetRowCount();
	int cols = m_testingDeviceGridCtrl.GetColumnCount();
	///���������������ݽ��б���
	Result res;
	for (int row = 1; row < rows; row++){
		TbTestingDevice testingDevice;
		if (row < m_vtestingDevice.size() + 1){
			////������Ҫ���µĵ�Ԫ�񣬶Լ���豸id���и�ֵ
			testingDevice.SetTestingdeviceId(m_vtestingDevice[row-1].GetTestingdeviceId()); 
			testingDevice.SetTestingDeviceStatus(m_vtestingDevice[row - 1].GetTestingDeviceStatus());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_testingDeviceGridCtrl.GetItemText(row, col);
			if (col == 1){testingDevice.SetTestingdeviceIp(itemText);}
			if (col == 2){testingDevice.SetTestingdeviceName(itemText);}
			if (col == 3){ testingDevice.SetTestingdeviceBorndate(itemText); }
			if (col == 4){ testingDevice.SetTestingdeviceImportdate(itemText); }
		}
		////����޸���û����
		if (testingDevice.GetTestingdeviceId() != 0 && testingDevice != m_vtestingDevice[row - 1]){
			res = m_testingDeviceController.UpdateTestingDevice(testingDevice);
		}
		////��������֮��û�б��档
		if (testingDevice.GetTestingdeviceId()== 0){
			res = m_testingDeviceController.AddTestingDevice(testingDevice);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}
	///ˢ�±��
	res = m_testingDeviceController.FindAllTestingDeviceBySearchCondition("", m_vtestingDevice);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///���¼��ر��
	GridCtrlInit();
}
