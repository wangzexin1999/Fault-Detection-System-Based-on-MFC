// GeneralParaView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "GeneralParaView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
// CGeneralParaView �Ի���

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

// CGeneralParaView ��Ϣ�������
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
	TRACE("\n�����%d��\n", pItem->iRow);
	
	///��ȡָ���е����ݣ�ͬ����ȫ����Ŀ����
	for (int col = 1; col < m_generalParaGridCtrl.GetColumnCount(); col++){
		if (col == 2) theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetSensorDesc(m_generalParaGridCtrl.GetItemText(pItem->iRow, col));
		if (col == 3){
			///�õ�ѡ��Ĵ�����
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetWindowType(m_vwindowTypes[index]);
		}
		if (col == 4) 
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetSensitivity(atoi(m_generalParaGridCtrl.GetItemText(pItem->iRow, col)));
		if (col == 5){
			///�õ�ѡ��Ĵ�����
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetInputMethod(m_vinputMethods[index]);
		}
		if (col == 6){
			///�õ�ѡ������̷�Χ
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].SetMileageRange(m_measuringRange[pItem->iRow - 1][index]);
		}
			
	}
	///����ѡ������̷�Χ��ȡ���̵����ֵ����Сֵ
	MathInterval yInterval;
	yInterval.Type = theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1].GetMileageRange();
	m_advantechDaqController.GetValueRangeInformationByVrgType(yInterval);
	theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetChartXYCoordinateLen(0,-1,yInterval.Min, yInterval.Max);
	///ˢ�´�����ʾ�Ĵ�����
	theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetSensor(theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1]);
	///�������ݿ⣬�������麽��

	SensorController m_SensorController;
	Result res = m_SensorController.UpdateSensor(theApp.m_currentProject.GetSensorVector()[pItem->iRow - 1]);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}


	///���������Ϊ���ɱ༭
	m_generalParaGridCtrl.SetEditable(FALSE);
}

void CGeneralParaView::GridCtrlInit()
{
	//��ʼ���㹻�����Ĳɼ�����������
	m_measuringRange.resize(theApp.m_currentProject.GetSensorVector().size());
	m_generalParaGridCtrl.SetEditable(false);
	m_generalParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_generalParaGridCtrl.SetRowCount(theApp.m_currentProject.GetSensorVector().size() + 1); //��ʼΪn��
	m_generalParaGridCtrl.SetColumnCount(7); //��ʼ��Ϊ7��
	m_generalParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_generalParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_generalParaGridCtrl.SetColumnResize(TRUE);
	m_generalParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
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
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;

			if (col == 0){ Item.strText.Format(_T("ͨ����"), 0); }
			if (col == 1){ Item.strText.Format(_T("ͨ��״̬"), 1); }
			if (col == 2){ Item.strText.Format(_T("ͨ������"), 2); }
			if (col == 3){ Item.strText.Format(_T("������"), 3); }
			if (col == 4){ Item.strText.Format(_T("������"), 4); }
			if (col == 5){ Item.strText.Format(_T("���뷽ʽ"), 5); }
			if (col == 6){ Item.strText.Format(_T("����"), 6); }
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
					///��¼�ϴ�ѡ�е����̵�����
					valueRangeIndex = i;
				}
				m_measuringRange[row - 1].push_back((int)g_valueRanges->getItem(i));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			///���δѡ�����̣���Ĭ�������ǵ�һ��
			Item.strText = OptionsType[valueRangeIndex];
			/*///���ö�Ӧ�ɼ����ڵ�����
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

