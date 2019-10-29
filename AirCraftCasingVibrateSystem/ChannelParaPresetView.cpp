// ChannelParaPresetView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"
// ChannelParaPresetView 对话框

IMPLEMENT_DYNAMIC(ChannelParaPresetView, CDialogEx)

ChannelParaPresetView::ChannelParaPresetView(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChannelParaPresetView::IDD, pParent)
{

}

ChannelParaPresetView::~ChannelParaPresetView()
{
}

void ChannelParaPresetView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GRIDCTRL_CHANNELPARA, m_channelParaGridCtrl);
	DDX_Control(pDX, IDC_COMBO_START_CHANNEL, m_startChannelCombo);
	DDX_Control(pDX, IDC_COMBO_END_CHANNEL, m_endChannelCombo);
}


BEGIN_MESSAGE_MAP(ChannelParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_CHANNELPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_CHANNELPARA, OnGridDblClick)
	
	ON_CBN_SELCHANGE(IDC_COMBO_START_CHANNEL, &ChannelParaPresetView::OnCbnSelchangeComboStartChannel)
	ON_CBN_SELCHANGE(IDC_COMBO_END_CHANNEL, &ChannelParaPresetView::OnCbnSelchangeComboEndChannel)
END_MESSAGE_MAP()


// ChannelParaPresetView 消息处理程序


BOOL ChannelParaPresetView::OnInitDialog()
{
	///查询所有的窗类型
	Result res = m_dictionController.FindAllBySearchCondition(m_vwindowTypes, 0, "windowtype");
	if (!res.GetIsSuccess()){
		AfxMessageBox("床类型查询失败");
	}
	res = m_dictionController.FindAllBySearchCondition(m_vinputMethods, 0, "inputmethod");
	if (!res.GetIsSuccess()){
		AfxMessageBox("输入类型查询失败");
	}

	//把下面这行注释掉
	m_advantechDaqController.GetChannels(m_vchannelId);

	CDialogEx::OnInitDialog();
	ChannelComboInit();
	GridCtrlInit();
	return TRUE; 
}
void ChannelParaPresetView::GridCtrlInit()
{
	int startChannelIndex = m_startChannelCombo.GetCurSel();
	int endChannelIndex = m_endChannelCombo.GetCurSel();
	m_channelParaGridCtrl.DeleteAllItems();
	if (endChannelIndex < startChannelIndex){ return; }
	m_channelParaGridCtrl.SetEditable(false);
	m_channelParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	if (startChannelIndex == -1 && endChannelIndex == -1){
		///如果两个下拉框都没有数据，则默认显示一行
		m_channelParaGridCtrl.SetRowCount(1);
	}
	else m_channelParaGridCtrl.SetRowCount(endChannelIndex-startChannelIndex+2); //初始为n行
	m_channelParaGridCtrl.SetColumnCount(7); //初始化为8列
	m_channelParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_channelParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_channelParaGridCtrl.SetColumnResize(TRUE);
	m_channelParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_channelParaGridCtrl.ExpandColumnsToFit(true);
	
	m_channelParaGridCtrl.SetSingleRowSelection(true);
	//m_channelParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_channelParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_channelParaGridCtrl.GetColumnCount(); col++)
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
				m_channelParaGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText = "通道号";
			}
			if (col == 2){
				Item.strText = "通道描述";
			}
			if (col == 3){
				Item.strText = "窗类型";
			}
			if (col == 4){
				Item.strText = "灵敏度";
			}
			if (col == 5){
				Item.strText = "输入方式";
			}
			if (col == 6){
				Item.strText = "量程";
			}
			m_channelParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) Item.strText = m_vchannelId[startChannelIndex ++];
		if (col == 2) Item.strText = "通道" + CommonUtil::Int2CString(row);
		if (col == 3) {
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto windowType : m_vwindowTypes){
				OptionsType.Add(_T(windowType.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		if (col == 4) Item.strText = "";
		if (col == 5) {
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto inputMethod : m_vinputMethods){
				OptionsType.Add(_T(inputMethod.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		if (col == 6) Item.strText = "";
		m_channelParaGridCtrl.SetItem(&Item);
	}
	///默认选中所有通道
	for (int row = 0; row < m_channelParaGridCtrl.GetRowCount(); row++){
		SetGridCellCheck(row, 0,TRUE);
	}
}

void ChannelParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///获得选中的单选框的状态
	if (!m_channelParaGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///全选按钮
		for (int row = 1; row < m_channelParaGridCtrl.GetRowCount(); row++){
			SetGridCellCheck(row, 0, !isChecked);
		}
	}
}


void ChannelParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_channelParaGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}

void ChannelParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_channelParaGridCtrl.SetEditable(TRUE);
}



void ChannelParaPresetView::GetSelectedChannels(vector<TbSensor> & vsensors){
	for (int row = 1; row < m_channelParaGridCtrl.GetRowCount(); row++){
		if (!m_channelParaGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, 0);
		TbSensor currentSensor;
		if (pCell->GetCheck()){
			for (int col = 0; col < m_channelParaGridCtrl.GetColumnCount();col++){
				if (col == 1) currentSensor.SetChannelId(m_channelParaGridCtrl.GetItemText(row, col));
				if (col == 2) currentSensor.SetSensorDesc(m_channelParaGridCtrl.GetItemText(row,col));
				if (col == 3){
					///拿到选择的窗类型
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					currentSensor.SetWindowType(m_vwindowTypes[index]);
				}
				if (col == 4) currentSensor.SetSensitivity(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
				if (col == 5){
					///拿到选择的窗类型
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					currentSensor.SetInputMethod(m_vinputMethods[index]); 
				}
				if (col == 6) currentSensor.SetMileageRange(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
			}
			vsensors.push_back(currentSensor);
		}
	}
}

void ChannelParaPresetView::OnCbnSelchangeComboStartChannel()
{
	GridCtrlInit();
}


void ChannelParaPresetView::OnCbnSelchangeComboEndChannel()
{
	GridCtrlInit();
}
void ChannelParaPresetView::ChannelComboInit(){
	m_startChannelCombo.ResetContent();
	m_endChannelCombo.ResetContent();
	for (int i = 0; i < m_vchannelId.size();i++){
		m_startChannelCombo.InsertString(i, m_vchannelId[i]);
		m_endChannelCombo.InsertString(i, m_vchannelId[i]);
	}
	m_startChannelCombo.SetCurSel(0);
	m_endChannelCombo.SetCurSel(m_vchannelId.size() - 1);
}