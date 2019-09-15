// BaseProjectInfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "BaseProjectInfoView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"
// BaseProjectInfoView 对话框
/*
{
"planName": "平稳状态",
"planIntro": "平稳状态下的采集",
"planPara": ["转速", "备注"]
}
*/
IMPLEMENT_DYNAMIC(BaseProjectInfoView, CDialogEx)

BaseProjectInfoView::BaseProjectInfoView(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseProjectInfoView::IDD, pParent)
{

}

BaseProjectInfoView::~BaseProjectInfoView()
{
}

void BaseProjectInfoView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_PROJECTPLAN_GRID, m_projectPlanGridCtrl);
	DDX_Control(pDX, IDC_COMBO_PRODUCT, m_productCombo);
	DDX_Control(pDX, IDC_EDIT_PROJECTNAME, m_projectNameEdit);
}


BEGIN_MESSAGE_MAP(BaseProjectInfoView, CDialogEx)

	ON_NOTIFY(NM_CLICK, IDC_PROJECTPLAN_GRID, OnGridClick)

	ON_BN_CLICKED(IDC_BUTTON_OK, &BaseProjectInfoView::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &BaseProjectInfoView::OnBnClickedButtonCancel)
END_MESSAGE_MAP()


// BaseProjectInfoView 消息处理程序
void BaseProjectInfoView::GridCtrlInit()
{
	m_projectPlanGridCtrl.SetEditable(true);
	m_projectPlanGridCtrl.SetEditable(false);
	m_projectPlanGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_projectPlanGridCtrl.SetRowCount(m_collectionPlanVec.size()+1); //初始为n行
	m_projectPlanGridCtrl.SetColumnCount(4); //初始化为5列
	m_projectPlanGridCtrl.SetFixedRowCount(1); //表头为一行
	m_projectPlanGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_projectPlanGridCtrl.SetColumnResize(TRUE);
	m_projectPlanGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_projectPlanGridCtrl.ExpandColumnsToFit(true);

	m_projectPlanGridCtrl.SetSingleRowSelection(true);
	//m_projectPlanGridCtrl.OnGridClick();
	for (int row = 0; row < m_projectPlanGridCtrl.GetRowCount(); row++){
		CString planName;
		CString planIntro;
		if (row > 0){
			// 1.解析doc
			Document doc;
			doc.Parse(m_collectionPlanVec[row-1].GetDictValue());
			// 2. 获得信息
			planName = ((string)doc["planName"].GetString()).c_str();
			planIntro = ((string)doc["planIntro"].GetString()).c_str();
		}
		for (int col = 0; col < m_projectPlanGridCtrl.GetColumnCount(); col++)
		{
			//设置表格显示属性
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			///设置表头内容
			if (row == 0){
				Item.nFormat = DT_CENTER | DT_WORDBREAK;
				if (col == 0){
					m_projectPlanGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
				}
				if (col == 1){
					Item.strText.Format(_T("序号"), 1);
				}
				if (col == 2){
					Item.strText.Format(_T("计划名称"), 2);
				}
				if (col == 3){
					Item.strText.Format(_T("介绍"), 3);
				}
				m_projectPlanGridCtrl.SetItem(&Item);
				continue;
			}
		
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

			CString strText;
			if (col == 0){ m_projectPlanGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
			if (col == 1) strText = CommonUtil::Int2CString(row);
			if (col == 2) strText = planName;
			if (col == 3) strText = planIntro;
			Item.strText=strText;
			m_projectPlanGridCtrl.SetItem(&Item);
		}
	}
	SetGridCellCheck(1,0,true);
	/*CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(0, 0);
	pCell->SetCheck(TRUE);*/
}

BOOL BaseProjectInfoView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_dictionaryController.FindAllBySearchCondition(m_collectionPlanVec, 0, "collectionplan");
	Result res = m_productController.FindAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		///将查询到的产品初始化到下拉框
		for (int i = 0; i < m_productVector.size(); i++){
			m_productCombo.InsertString(i, m_productVector[i].GetProductName());
		}
	}else{
		AfxMessageBox(res.GetMessages());
	}
	GridCtrlInit();
	return TRUE;  
}

void BaseProjectInfoView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///获得选中的单选框的状态
	if (!m_projectPlanGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///全选按钮
		for (int row = 1; row < m_projectPlanGridCtrl.GetRowCount();row++){
			SetGridCellCheck(row,0,!isChecked);
		}
	}
}
void BaseProjectInfoView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_projectPlanGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked); 
}

void BaseProjectInfoView::GetSelectedCollectionPlan(vector<TbDictionary> &selectedPlan){
	for (int row = 1; row < m_projectPlanGridCtrl.GetRowCount(); row++){
		if (!m_projectPlanGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_projectPlanGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, 0);
		if (pCell->GetCheck()){
			selectedPlan.push_back(m_collectionPlanVec[row - 1]);
		}
	}
}

void BaseProjectInfoView::OnBnClickedButtonOk()
{
	CString projectName;
	m_projectNameEdit.GetWindowTextA(projectName);
	if (projectName == ""){ AfxMessageBox("项目名不能为空"); return;}
	int detectedIndex = m_productCombo.GetCurSel();
	///产品未选择状态
	if (detectedIndex < 0) {
		AfxMessageBox("请选择产品");
		return;
	}
	m_projectNameEdit.GetWindowTextA(projectName);
	m_selectedProduct = m_productVector[detectedIndex];
	CDialogEx::OnOK();
}


void BaseProjectInfoView::OnBnClickedButtonCancel()
{
	CDialogEx::OnCancel();
}
void BaseProjectInfoView::GetProjectBaseInfo(TbProject &project){
	project.SetProjectName(m_projectName);
	project.SetProduct(m_selectedProduct);
}