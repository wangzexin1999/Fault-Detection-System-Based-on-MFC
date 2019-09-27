// ProductManageView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProductManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CProductManageView �Ի���

IMPLEMENT_DYNAMIC(CProductManageView, CDialogEx)

CProductManageView::CProductManageView(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProductManageView::IDD, pParent)
{

}

CProductManageView::~CProductManageView()
{
}

void CProductManageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_PRODUCT_MANAGE, m_productManageGridCtrl);
	DDX_Control(pDX, IDC_EDIT1, m_productEdit);
}


BEGIN_MESSAGE_MAP(CProductManageView, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_PRODUCT_MANAGE, OnGridDblClick)
	ON_NOTIFY(NM_CLICK, IDC_PRODUCT_MANAGE, OnGridClick)
	ON_BN_CLICKED(IDC_BUTTON2, &CProductManageView::OnBnClickedAddProductButton)
	ON_BN_CLICKED(IDC_BUTTON3, &CProductManageView::OnBnClickedDeleteProductButton)
	ON_BN_CLICKED(ID_SAVE_PRODUCT, &CProductManageView::OnBnClickedSaveProduct)
	ON_BN_CLICKED(IDC_BTN_SEARCH_PRODUCT, &CProductManageView::OnBnClickedBtnSearchProduct)
END_MESSAGE_MAP()


// CProductManageView ��Ϣ�������


BOOL CProductManageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// ��ѯ���в�Ʒ
	Result res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();  // ��ʼ����ؼ�

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CProductManageView::GridCtrlInit()
{
	m_productManageGridCtrl.SetEditable(true);
	m_productManageGridCtrl.SetEditable(false);
	m_productManageGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_productManageGridCtrl.SetRowCount(m_vTbProduct.size()+1); //��ʼΪn��
	m_productManageGridCtrl.SetColumnCount(3); //��ʼ��Ϊ5��
	m_productManageGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_productManageGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_productManageGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_productManageGridCtrl.ExpandColumnsToFit(true);
	m_productManageGridCtrl.SetSingleRowSelection(true);
	m_productManageGridCtrl.SetRowCount(m_vTbProduct.size() + 1); //��ʼΪn��
	m_productManageGridCtrl.SetModified(FALSE);////��ʼ״̬
	//m_productManageGridCtrl.OnGridClick();
	for (int row = 0; row < m_productManageGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_productManageGridCtrl.GetColumnCount(); col++)
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
			if (col == 1){ Item.strText.Format(_T("��Ʒ����"), 1); }
			if (col == 2){ Item.strText.Format(_T("��Ʒ����"), 2); }
			m_productManageGridCtrl.SetItem(&Item);
			continue;
		}
		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

		CString strText;
		if (col == 0) strText = CommonUtil::Int2CString(row);
		if (col == 1) strText = m_vTbProduct[row - 1].GetProductName();
		if (col == 2) strText = m_vTbProduct[row - 1].GetProductType();
		Item.strText = strText;
		m_productManageGridCtrl.SetItem(&Item);
	}

}


void CProductManageView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_productManageGridCtrl.SetEditable(TRUE);
}

void CProductManageView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow == 0 || pItem->iRow > m_vTbProduct.size()) return;
	m_selectedProduct = m_vTbProduct.at(pItem->iRow - 1);
}

void CProductManageView::OnBnClickedAddProductButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_productManageGridCtrl.InsertRow(CommonUtil::Int2CString(m_vTbProduct.size() + 1));
	m_productManageGridCtrl.CheckAutoCenter();
	m_productManageGridCtrl.Refresh();
}


void CProductManageView::OnBnClickedDeleteProductButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	if (m_selectedProduct.GetProductId() == 0){
	AfxMessageBox("��ѡ����Ҫɾ���Ĳ�Ʒ");
	return;
	}
	if (MessageBox("�Ƿ�ɾ�� " + m_selectedProduct.GetProductName(), "ɾ����Ʒ", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_productController.DeleteByProductId(m_selectedProduct);
	if (res.GetIsSuccess()){
		m_selectedProduct.SetProductId(0);
		// ���
		m_vTbProduct.clear();
	///ɾ���ɹ�֮��ˢ��ҳ��
		res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///���¼��ر��
	GridCtrlInit();
	}
}


void CProductManageView::OnBnClickedSaveProduct()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox("�Ƿ񱣴浱ǰ�޸�", "�����Ʒ", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_productManageGridCtrl.GetRowCount();
	int cols = m_productManageGridCtrl.GetColumnCount();
	/////���������������ݽ��б���
	Result res;
	for (int row = 1; row < rows; row++){
		TbProduct product;
		if (row < m_vTbProduct.size() + 1){
			////������Ҫ���µĵ�Ԫ�񣬶Լ���Ʒid���и�ֵ
			product.SetProductId(m_vTbProduct[row - 1].GetProductId());
			product.SetProductType(m_vTbProduct[row - 1].GetProductType());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_productManageGridCtrl.GetItemText(row, col);
			if (col == 1){ product.SetProductName(itemText); }
			if (col == 2){ product.SetProductType(itemText); }
		}
		////����޸���û����
		if (product.GetProductId() != 0 && product != m_vTbProduct[row - 1]){
			res = m_productController.UpdateProduct(product);
		}
		////��������֮��û�б��档
		if (product.GetProductId() == 0){
			res = m_productController.AddProduct(product);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}

	m_vTbProduct.clear();
	///ˢ�±��
	res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///���¼��ر��
	GridCtrlInit();
}


void CProductManageView::OnBnClickedBtnSearchProduct()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TbProduct product;

	CString strProductName = "";
	m_productEdit.GetWindowTextA(strProductName);
	product.SetProductName(strProductName);
	m_vTbProduct.clear();
	Result res = m_productController.FindProductByProductName(product, m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();
}
