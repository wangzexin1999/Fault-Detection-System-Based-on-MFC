// BaseProjectInfoView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "BaseProjectInfoView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"
// BaseProjectInfoView 对话框
IMPLEMENT_DYNAMIC(BaseProjectInfoView, CDialogEx)

BaseProjectInfoView::BaseProjectInfoView(CWnd* pParent /*=NULL*/)
	: CDialogEx(BaseProjectInfoView::IDD, pParent)
{
	///1.默认不回显项目的数据
	m_isEchoProjectData = false;
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
	m_projectPlanGridCtrl.SetEditable(false);
	m_projectPlanGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_projectPlanGridCtrl.SetRowCount(m_vcollectionPlan.size()+1); //初始为n行
	m_projectPlanGridCtrl.SetColumnCount(3); //初始化为5列
	m_projectPlanGridCtrl.SetFixedRowCount(1); //表头为一行
	m_projectPlanGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_projectPlanGridCtrl.SetColumnResize(TRUE);
	m_projectPlanGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_projectPlanGridCtrl.ExpandColumnsToFit(true);
	m_projectPlanGridCtrl.SetSingleRowSelection(true);

	Document echoCollectionPlanDoc;
	Document::AllocatorType & echoCollectionPlanAllocator = echoCollectionPlanDoc.GetAllocator();
	if (m_isEchoProjectData){
		///如果要回显项目的采集计划
		echoCollectionPlanDoc.Parse(theApp.m_currentProject.GetCollectionPlans());
	}
	
	for (int row = 0; row < m_projectPlanGridCtrl.GetRowCount(); row++){
		CString planName;
		CString planIntro;
		if (row > 0){
			// 1.解析doc
			Document doc;
			doc.Parse(m_vcollectionPlan[row-1].GetDictValue());
			////1.1 如果解析的doc树存在解析错误或者没有成员planName和planIntro,则不解析改
			if (doc.HasParseError() || !doc.HasMember("planName") || !doc.HasMember("planIntro")){ continue; }
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
					Item.strText = "计划名称";
				}
				if (col == 2){
					Item.strText = "介绍";
				}
				m_projectPlanGridCtrl.SetItem(&Item);
				continue;
			}
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;

			CString strText;
			if (col == 0){ 
				m_projectPlanGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
				///如果需要回显数据,并且解析的json数据不存在解析错误
				if (m_isEchoProjectData&&!echoCollectionPlanDoc.HasParseError()
							&&echoCollectionPlanDoc.HasMember("collectionPlans")){
					bool isExist = false;
					Value  collectionPlan(kObjectType);
					///遍历集合,判断当前需要显示的采集计划是否被项目选了
					for (int i = 0; i < echoCollectionPlanDoc["collectionPlans"].Size();i++){
						///因为Value元素的赋值是转移语意，所以不能直接赋值
						collectionPlan.CopyFrom(echoCollectionPlanDoc["collectionPlans"][i], echoCollectionPlanAllocator);
						if (collectionPlan.HasMember("planId") &&
							collectionPlan["planId"].GetInt() == m_vcollectionPlan[row - 1].GetDictId()){
							isExist = true;
						}
					}
					///设置当前行的第一列的复选框的属性
					SetGridCellCheck(row, 0, isExist);
				}
			}
			if (col == 1) strText = planName;
			if (col == 2) strText = planIntro;

			Item.strText=strText;
			m_projectPlanGridCtrl.SetItem(&Item);
		}
	}
	///如果当前状态为不显示，或者前面的项目的采集计划json数据存在解析错误
	if (!m_isEchoProjectData || echoCollectionPlanDoc.HasParseError()){
		///设置默认第一行为选中状态
		SetGridCellCheck(1,0,true);
	}
}

BOOL BaseProjectInfoView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (m_isEchoProjectData){
		/// 回显项目名
		m_projectNameEdit.SetWindowTextA(theApp.m_currentProject.GetProjectName());
	}
	m_dictionaryController.FindAllBySearchCondition(m_vcollectionPlan, 0, "collectionplan");
	Result res = m_productController.FindAllProduct(m_productVector);
	if (res.GetIsSuccess()){
		///将查询到的产品初始化到下拉框
		for (int i = 0; i < m_productVector.size(); i++){
			m_productCombo.InsertString(i, m_productVector[i].GetProductName());
			if (m_isEchoProjectData &&
				m_productVector[i] == theApp.m_currentProject.GetProduct()){
				///回显产品，并将产品下拉框置为不可选
				m_productCombo.SetCurSel(i);
				CEdit *pEdit = (CEdit*)m_productCombo.GetWindow(GW_CHILD);
				pEdit->EnableWindow(FALSE);
				///找到的回显的产品，即可跳出循环
				break;
			}
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
	else
	{
		if (isChecked)
		{
			SetGridCellCheck(0, 0, !isChecked);
		}
		else
		{
			int count = 0;
			for (int row = 1; row < m_projectPlanGridCtrl.GetRowCount(); row++){
				if (GetGridCellCheck(row, 0))
				{
					count = count + 1;
				}
			}
			if (count == m_projectPlanGridCtrl.GetRowCount() - 1)
			{
				SetGridCellCheck(0, 0, !isChecked);
			}
		}
	}
}
void BaseProjectInfoView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_projectPlanGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked); 
}

bool BaseProjectInfoView::GetGridCellCheck(int row, int col){
	if (!m_projectPlanGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_projectPlanGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, col);
	bool isChecked = pCell->GetCheck();
	return isChecked;
}


void BaseProjectInfoView::GetSelectedCollectionPlan(vector<TbDictionary> &selectedPlan){
	for (int row = 1; row < m_projectPlanGridCtrl.GetRowCount(); row++){
		if (!m_projectPlanGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_projectPlanGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_projectPlanGridCtrl.GetCell(row, 0);
		if (pCell->GetCheck()){
			selectedPlan.push_back(m_vcollectionPlan[row - 1]);
		}
	}
}

void BaseProjectInfoView::OnBnClickedButtonOk()
{
	m_projectNameEdit.GetWindowTextA(m_projectName);
	if (m_projectName == ""){ AfxMessageBox("项目名不能为空"); return; }
	int detectedIndex = m_productCombo.GetCurSel();
	///产品未选择状态
	if (detectedIndex < 0) {
		AfxMessageBox("请选择产品");
		return;
	}
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
void BaseProjectInfoView::SetProjectEchoStatus(bool isEcho){
	m_isEchoProjectData = isEcho;
}