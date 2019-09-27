// EngineerUnitView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "EngineerUnitView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// CEngineerUnitView 对话框

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


// CEngineerUnitView 消息处理程序



void CEngineerUnitView::GridCtrlInit()
{

	m_engineerUintManageGridCtrl.SetEditable(true);
	m_engineerUintManageGridCtrl.SetEditable(false);
	m_engineerUintManageGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_engineerUintManageGridCtrl.SetRowCount(m_vEngineerUint.size() + 1); //初始为n行
	m_engineerUintManageGridCtrl.SetColumnCount(2); //初始化为5列
	m_engineerUintManageGridCtrl.SetFixedRowCount(1); //表头为一行
	m_engineerUintManageGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_engineerUintManageGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_engineerUintManageGridCtrl.ExpandColumnsToFit(true);
	m_engineerUintManageGridCtrl.SetSingleRowSelection(true);
	m_engineerUintManageGridCtrl.SetRowCount(m_vEngineerUint.size() + 1); //初始为n行
	m_engineerUintManageGridCtrl.SetModified(FALSE);////初始状态
	//m_productManageGridCtrl.OnGridClick();
	for (int row = 0; row < m_engineerUintManageGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_engineerUintManageGridCtrl.GetColumnCount(); col++)
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
			if (col == 1){ Item.strText.Format(_T("单位名字"), 1); }
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

	// TODO:  在此添加额外的初始化
	m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
	GridCtrlInit();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

// 添加工程单位
void CEngineerUnitView::OnBnClickedButtonEuAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	m_engineerUintManageGridCtrl.InsertRow(CommonUtil::Int2CString(m_vEngineerUint.size() + 1));
	m_engineerUintManageGridCtrl.CheckAutoCenter();
	m_engineerUintManageGridCtrl.Refresh();
}

// 删除工程单位
void CEngineerUnitView::OnBnClickedButtonEuDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_selectedDictionary.GetDictId() == 0){
		AfxMessageBox("请选择需要删除的单位");
		return;
	}
	if (MessageBox("是否删除 " + m_selectedDictionary.GetDictValue(), "删除单位", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	Result res = m_dictionController.DeleteEUByEUId(m_selectedDictionary);
	if (res.GetIsSuccess()){
		m_selectedDictionary.SetDictId(0);
		// 清除
		m_vEngineerUint.clear();
		///删除成功之后刷新页面
		res = m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
		///重新加载表格
		GridCtrlInit();
	}
}

// 保存工程单位
void CEngineerUnitView::OnBnClickedEuSave()
{
	// TODO:  在此添加控件通知处理程序代码
	if (MessageBox("是否保存当前修改", "保存工程单位", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL) return;
	int rows = m_engineerUintManageGridCtrl.GetRowCount();
	int cols = m_engineerUintManageGridCtrl.GetColumnCount();
	/////遍历表格的所有数据进行保存
	Result res;
	for (int row = 1; row < rows; row++){
		TbDictionary dictionary;
		if (row < m_vEngineerUint.size() + 1){
			////对于需要更新的单元格，对检测产品id进行赋值
			dictionary.SetDictId(m_vEngineerUint[row - 1].GetDictId());
			dictionary.SetDictValue(m_vEngineerUint[row - 1].GetDictValue());
		}
		for (int col = 1; col < cols; col++){
			CString itemText = m_engineerUintManageGridCtrl.GetItemText(row, col);
			if (col == 1){ dictionary.SetDictValue(itemText); }
		}
		////如果修改了没保存
		if (dictionary.GetDictId() != 0 && dictionary != m_vEngineerUint[row - 1]){
			dictionary.SetDictName("engineeringunit");
			res = m_dictionController.UpdateDictionary(dictionary);
		}
		////如果添加了之后没有保存。
		if (dictionary.GetDictId() == 0){
			dictionary.SetDictName("engineeringunit");
			res = m_dictionController.AddDictionary(dictionary);
		}
		if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	}

	m_vEngineerUint.clear();
	///刷新表格
	res = m_dictionController.FindAllBySearchCondition(m_vEngineerUint, 0, "engineeringunit");
	if (!res.GetIsSuccess()){ AfxMessageBox(res.GetMessages()); }
	///重新加载表格
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