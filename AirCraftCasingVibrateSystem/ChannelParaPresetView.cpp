// ChannelParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"

// ChannelParaPresetView �Ի���

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
}


BEGIN_MESSAGE_MAP(ChannelParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_CHANNELPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_CHANNELPARA, OnGridDblClick)
END_MESSAGE_MAP()


// ChannelParaPresetView ��Ϣ�������


BOOL ChannelParaPresetView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	///��ѯ���еĴ�����
	m_dictionController.FindAllBySearchCondition(m_vwindowTypes, 0, "windowtype");
	m_dictionController.FindAllBySearchCondition(m_vinputMethods, 0, "inputmethod");
	GridCtrlInit();
	return TRUE; 
}
void ChannelParaPresetView::GridCtrlInit()
{
	m_channelParaGridCtrl.SetEditable(false);
	m_channelParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_channelParaGridCtrl.SetRowCount(5); //��ʼΪn��
	m_channelParaGridCtrl.SetColumnCount(7); //��ʼ��Ϊ8��
	m_channelParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_channelParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_channelParaGridCtrl.SetColumnResize(TRUE);
	m_channelParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_channelParaGridCtrl.ExpandColumnsToFit(true);
	
	m_channelParaGridCtrl.SetSingleRowSelection(true);
	//m_channelParaGridCtrl.OnGridClick();
	for (int row = 0; row < m_channelParaGridCtrl.GetRowCount(); row++)
	for (int col = 0; col < m_channelParaGridCtrl.GetColumnCount(); col++)
	{
		//���ñ����ʾ����
		GV_ITEM Item;
		Item.mask = GVIF_TEXT | GVIF_FORMAT;
		Item.row = row;
		Item.col = col;
		///���ñ�ͷ����
		if (row == 0){
			Item.nFormat = DT_CENTER | DT_WORDBREAK;
			if (col == 0){
				m_channelParaGridCtrl.SetCellType(0, 0, RUNTIME_CLASS(CGridCellCheck));
			}
			if (col == 1){
				Item.strText = "���";
			}
			if (col == 2){
				Item.strText = "ͨ������";
			}
			if (col == 3){
				Item.strText = "������";
			}
			if (col == 4){
				Item.strText = "������";
			}
			if (col == 5){
				Item.strText = "���뷽ʽ";
			}
			if (col == 6){
				Item.strText = "����";
			}
			m_channelParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0){ m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck)); }
		if (col == 1) Item.strText = CommonUtil::Int2CString(row);
		if (col == 2) Item.strText = "ͨ��" + CommonUtil::Int2CString(row);
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
	///Ĭ��ѡ������ͨ��
	for (int row = 0; row < m_channelParaGridCtrl.GetRowCount(); row++){
		SetGridCellCheck(row, 0,TRUE);
	}
}

void ChannelParaPresetView::OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*)pNotifyStruct;
	if (pItem->iRow < 0) return;
	///���ѡ�еĵ�ѡ���״̬
	if (!m_channelParaGridCtrl.GetCell(pItem->iRow, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(pItem->iRow, 0, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(pItem->iRow, 0);
	bool isChecked = pCell->GetCheck();
	pCell->SetCheck(!isChecked);

	if (pItem->iRow == 0){
		///ȫѡ��ť
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
			for (int col = 1; col < m_channelParaGridCtrl.GetColumnCount();col++){
				if (col == 2) currentSensor.SetSensorDesc(m_channelParaGridCtrl.GetItemText(row,col));
				if (col == 3){
					///�õ�ѡ��Ĵ�����
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					currentSensor.SetWindowType(m_vwindowTypes[index]);
				}
				if (col == 4) currentSensor.SetSensitivity(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
				if (col == 5){
					///�õ�ѡ��Ĵ�����
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					currentSensor.SetInputMethod(m_vinputMethods[index]); 
				}
				if (col == 6) currentSensor.SetMileageRange(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
			}
			currentSensor.SetChannels("#012s-"+CommonUtil::Int2CString(row));
			vsensors.push_back(currentSensor);
		}
	}
}