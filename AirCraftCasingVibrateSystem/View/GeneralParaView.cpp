// GeneralParaView.cpp : 实现文件
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
// CGeneralParaView 对话框

IMPLEMENT_DYNAMIC(CGeneralParaView, CDialogEx)

CGeneralParaView::CGeneralParaView(CWnd* pParent /*=NULL*/)
: CDialogEx(CGeneralParaView::IDD, pParent)
{
	
}

CGeneralParaView::~CGeneralParaView()
{
}

void CGeneralParaView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_GridControl(pDX, IDC_GENERAPARA_GRIDCTRL, m_generalParaGridCtrl);
}

BEGIN_MESSAGE_MAP(CGeneralParaView, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_GENERAPARA_GRIDCTRL, OnGridDblClick)
	ON_NOTIFY(GVN_ENDLABELEDIT, IDC_GENERAPARA_GRIDCTRL, OnGridEndEdit)
END_MESSAGE_MAP()

// CGeneralParaView 消息处理程序
BOOL CGeneralParaView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_dictionController.FindAllBySearchCondition(m_vwindowTypes, 0, "windowtype");
	m_dictionController.FindAllBySearchCondition(m_vinputMethods, 0, "inputmethod");
	GridCtrlInit();
	return TRUE;
}

void CGeneralParaView::OnGridEndEdit(NMHDR *pNotifyStruct, LRESULT* pResult)
{
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	int index;
	TRACE("\n保存第%d行\n", pItem->iRow);
	
	///获取指定行的数据，同步到全局项目对象
	for (int col = 1; col < m_generalParaGridCtrl.GetColumnCount(); col++){
		if (col == 2) theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetSensorDesc(m_generalParaGridCtrl.GetItemText(pItem->iRow, col));
		if (col == 3){
			///拿到选择的窗类型
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetWindowType(m_vwindowTypes[index]);
		}
		if (col == 4) 
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetSensitivity(atoi(m_generalParaGridCtrl.GetItemText(pItem->iRow, col)));
		if (col == 5){
			///拿到选择的窗类型
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetInputMethod(m_vinputMethods[index]);
		}
		if (col == 6){
			///拿到选择的量程范围
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetMileageRange(m_measuringRange[pItem->iRow - 1][index]);
		}
			
	}
	///根据选择的量程范围获取量程的最大值和最小值
	MathInterval yInterval;
	yInterval.Type = theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].GetMileageRange();
	m_advantechDaqController.GetValueRangeInformationByVrgType(yInterval);
	theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetChartXYCoordinateLen(0,-1,yInterval.Min, yInterval.Max);
	///刷新窗口显示的传感器
	theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetSensor(theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1]);
	///更新数据库，交给周书航了

	SensorController m_SensorController;
	Result res = m_SensorController.UpdateSensor(theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1]);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}


	///将表格设置为不可编辑
	m_generalParaGridCtrl.SetEditable(FALSE);
}

void CGeneralParaView::GridCtrlInit()
{
	//初始化足够数量的采集卡对象数据
	m_measuringRange.resize(theApp.m_currentProject.GetSensorVector().size());
	m_generalParaGridCtrl.SetEditable(false);
	m_generalParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//黄色背景
	m_generalParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //初始为n行
	m_generalParaGridCtrl.SetColumnCount(7); //初始化为7列
	m_generalParaGridCtrl.SetFixedRowCount(1); //表头为一行
	m_generalParaGridCtrl.SetRowResize(TRUE); ///自动设置行和列的大小
	m_generalParaGridCtrl.SetColumnResize(TRUE);
	m_generalParaGridCtrl.SetListMode(true); ////在选定一个单元格时，选择整行
	m_generalParaGridCtrl.ExpandColumnsToFit(true);
	m_generalParaGridCtrl.SetSingleRowSelection(true);
	//m_generalParaGridCtrl.OnGridClick();
	int deviceNum;
	WCHAR	vrgDescription[128];
	MathInterval	ranges;
	ValueUnit    u = Volt;
	Array<ValueRange>* g_valueRanges = nullptr;
	int valueRangeIndex;
	CStringArray OptionsType;
	for (int row = 0; row < m_generalParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_generalParaGridCtrl.GetColumnCount(); col++)
	{
		//设置表格显示属性
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///设置表头内容
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("通道号"), 0); }
			if (col == 1){ Item.strText.Format(_T("通道状态"), 1); }
			if (col == 2){ Item.strText.Format(_T("通道描述"), 2); }
			if (col == 3){ Item.strText.Format(_T("窗类型"), 3); }
			if (col == 4){ Item.strText.Format(_T("灵敏度"), 4); }
			if (col == 5){ Item.strText.Format(_T("输入方式"), 5); }
			if (col == 6){ Item.strText.Format(_T("量程"), 6); }
			m_generalParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0)
		{
			Item.strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetChannelId();
			m_generalParaGridCtrl.SetItemState(row, col, GVIS_READONLY);
		}
		if (col == 1) Item.strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetSensorStatus().GetDictValue();
		if (col == 2) 
			Item.strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetSensorDesc();
		if (col == 3) {
			m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto windowType : m_vwindowTypes){
				OptionsType.Add(_T(windowType.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetWindowType().GetDictValue();
		}
		if (col == 4) Item.strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetSensorVector()[row - 1].GetSensitivity());
		if (col == 5) {
			m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto inputMethod : m_vinputMethods){
				OptionsType.Add(_T(inputMethod.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = theApp.m_currentProject.GetSensorVector()[row - 1].GetInputMethod().GetDictValue();
		}
		if (col == 6){
			m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			OptionsType.RemoveAll();
			valueRangeIndex = 0;
			deviceNum = CommonUtil::CString2Int(CommonUtil::GetCStringVectorFromSplitCString(theApp.m_currentProject.GetSensorVector()[row - 1].GetChannelId(),"-")[0]);
			m_advantechDaqController.GetValueRangeInformationByDeviceNum(deviceNum, g_valueRanges);
			for (int i = 0; i < g_valueRanges->getCount(); i++){
				ErrorCode error = AdxGetValueRangeInformation((g_valueRanges->getItem(i)), sizeof(vrgDescription), vrgDescription, &ranges, &u);
				m_advantechDaqController.CheckError(error);
				if (u == CelsiusUnit)
				{
					continue;
				}
				CString str(vrgDescription);
				OptionsType.Add(str);
				if (g_valueRanges->getItem(i) == theApp.m_currentProject.GetSensorVector()[row - 1].GetMileageRange()){
					///记录上次选中的量程的索引
					valueRangeIndex = i;
				}
				m_measuringRange[row - 1].push_back((int)g_valueRanges->getItem(i));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			///如果未选择量程，则默认量程是第一个
			Item.strText = OptionsType[valueRangeIndex];
			/*///设置对应采集窗口的量程
			MathInterval yInterval;
			yInterval.Type = m_measuringRange[row - 1][valueRangeIndex];
			m_advantechDaqController.GetValueRangeInformationByVrgType(yInterval);
			theApp.m_vsignalCaptureView[row - 1]->ConfigurateChart(yInterval.Min, yInterval.Max);*/
		}
		m_generalParaGridCtrl.SetItem(&Item);
	}
}

void CGeneralParaView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_generalParaGridCtrl.SetEditable(TRUE);
}

