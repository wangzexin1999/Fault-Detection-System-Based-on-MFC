// ProductManageView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ProductManageView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CProductManageView 对话框

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


// CProductManageView 消息处理程序


BOOL CProductManageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 查询所有产品
	Result res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();  // 初始化表控件

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CProductManageView::GridCtrlInit()
{
	m_productManageGridCtrl.SetEditable(true);
	m_productManageGridCtrl.SetEditable(false);
	m_productManageGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_productManageGridCtrl.SetRowCount(m_vTbProduct.size()+1); //初始为n行
	m_productManageGridCtrl.SetColumnCount(3); //初始化为5列
	m_productManageGridCtrl.SetFixedRowCount(1); //表头为一行
	m_productManageGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_productManageGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_productManageGridCtrl.ExpandColumnsToFit(true);
	m_productManageGridCtrl.SetSingleRowSelection(true);
	m_productManageGridCtrl.SetRowCount(m_vTbProduct.size() + 1); //初始为n行
	m_productManageGridCtrl.SetModified(FALSE);////初始状态
	//m_productManageGridCtrl.OnGridClick();
	for (int row = 0; row < m_productManageGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_productManageGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("序号"), 0); }
			if (col == 1){ Item.strText.Format(_T("产品名字"), 1); }
			if (col == 2){ Item.strText.Format(_T("产品类型"), 2); }
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
	// TODO:  在此添加控件通知处理程序代码
	m_productManageGridCtrl.InsertRow(CommonUtil::Int2CString(m_vTbProduct.size() + 1));
	m_productManageGridCtrl.CheckAutoCenter();
	m_productManageGridCtrl.Refresh();
}


void CProductManageView::OnBnClickedDeleteProductButton()
{
	// TODO:  在此添加控件通知处理程序代码

	if (m_selectedProduct.GetProductId() == 0){
	AfxMessageBox("请选择需要删除的产品");
	return;
	}
	if (MessageBox("是否删除 " + m_selectedProduct.GetProductName(), "删除产品", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_productController.DeleteByProductId(m_selectedProduct);
	if (res.GetIsSuccess()){
		m_selectedProduct.SetProductId(0);
		// 清除
		m_vTbProduct.clear();
	///删除成功之后刷新页面
		res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///重新加载表格
	GridCtrlInit();
	}
}


void CProductManageView::OnBnClickedSaveProduct()
{
	// TODO:  在此添加控件通知处理程序代码
	if (MessageBox("是否保存当前修改", "保存产品", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_productManageGridCtrl.GetRowCount();
	int cols = m_productManageGridCtrl.GetColumnCount();
	/////遍历表格的所有数据进行保存
	Result res;
	for (int row = 1; row < rows; row++){
		TbProduct product;
		if (row < m_vTbProduct.size() + 1){
			////对于需要更新的单元格，对检测产品id进行赋值
			product.SetProductId(m_vTbProduct[row - 1].GetProductId());
			product.SetProductType(m_vTbProduct[row - 1].GetProductType());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_productManageGridCtrl.GetItemText(row, col);
			if (col == 1){ product.SetProductName(itemText); }
			if (col == 2){ product.SetProductType(itemText); }
		}
		////如果修改了没保存
		if (product.GetProductId() != 0 && product != m_vTbProduct[row - 1]){
			res = m_productController.UpdateProduct(product);
		}
		////如果添加了之后没有保存。
		if (product.GetProductId() == 0){
			res = m_productController.AddProduct(product);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}

	m_vTbProduct.clear();
	///刷新表格
	res = m_productController.FindAllProduct(m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///重新加载表格
	GridCtrlInit();
}


void CProductManageView::OnBnClickedBtnSearchProduct()
{
	// TODO:  在此添加控件通知处理程序代码
	TbProduct product;

	CString strProductName = "";
	m_productEdit.GetWindowTextA(strProductName);
	product.SetProductName(strProductName);
	m_vTbProduct.clear();
	Result res = m_productController.FindProductByProductName(product, m_vTbProduct);
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	GridCtrlInit();
}
