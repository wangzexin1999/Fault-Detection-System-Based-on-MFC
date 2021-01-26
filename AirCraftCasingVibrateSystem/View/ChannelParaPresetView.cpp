// ChannelParaPresetView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AirCraftCasingVibrateSystem.h"
#include "ChannelParaPresetView.h"
#include "afxdialogex.h"
#include "CommonUtil.h"
#include "Result.h"


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
	DDX_Control(pDX, IDC_COMBO_START_CHANNEL, m_startChannelCombo);
	DDX_Control(pDX, IDC_COMBO_END_CHANNEL, m_endChannelCombo);
}


BEGIN_MESSAGE_MAP(ChannelParaPresetView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_GRIDCTRL_CHANNELPARA, OnGridClick)
	ON_NOTIFY(NM_DBLCLK, IDC_GRIDCTRL_CHANNELPARA, OnGridDblClick)
	
	ON_CBN_SELCHANGE(IDC_COMBO_START_CHANNEL, &ChannelParaPresetView::OnCbnSelchangeComboStartChannel)
	ON_CBN_SELCHANGE(IDC_COMBO_END_CHANNEL, &ChannelParaPresetView::OnCbnSelchangeComboEndChannel)
END_MESSAGE_MAP()


// ChannelParaPresetView ��Ϣ�������


BOOL ChannelParaPresetView::OnInitDialog()
{
	///��ѯ���еĴ�����
	/*Result res = m_dictionController.FindAllBySearchCondition(m_vwindowTypes, 0, "windowtype");
	if (!res.GetIsSuccess()){
	AfxMessageBox("�����Ͳ�ѯʧ��");
	}*/
	/*res = m_dictionController.FindAllBySearchCondition(m_vinputMethods, 0, "inputmethod");
	if (!res.GetIsSuccess()){
		AfxMessageBox("�������Ͳ�ѯʧ��");
	}*/

		for (int i = 0; i < theApp.m_vecHardChannel.size(); i++)
		{
			// ����������ͨ��
			if (!theApp.m_vecHardChannel[i].m_bOnlineFlag)
				continue;
			CString strGroupID;
			int nGroupID = theApp.m_vecHardChannel[i].m_nChannelGroupID;
			strGroupID.Format("%d", nGroupID);

			CString strChannelID;
			strChannelID.Format("%d", theApp.m_vecHardChannel[i].m_nChannelID);

			CString strText = strGroupID + "-" + strChannelID;

			m_vchannelCode.push_back(strText);
		}
		GetParamSelectValue(theApp.m_vecHardChannel[0].m_strMachineIP);
	////����������ע�͵�
	//m_advantechDaqController.GetChannels(m_vchannelCode);
	CDialogEx::OnInitDialog();
	ChannelComboInit();
	GridCtrlInit();
	return TRUE; 
}
//��ȡ������ѡ���б�
void ChannelParaPresetView::GetParamSelectValue(string strMachineIP)
{
	m_dhTestHardWareController.GetAllGroupChannel(theApp.m_pHardWare, theApp.m_vecGroupChannel, theApp.m_vecHardChannel);
	m_dhTestHardWareController.GetAllInputMode(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listInputMode);
	m_dhTestHardWareController.GetAllElcPressure(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_elcpressure);
	m_dhTestHardWareController.GetAllFullValue(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listFullValue);
	m_dhTestHardWareController.GetAllUpFreq(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listUpFreq);
	m_dhTestHardWareController.GetAllMessaueType(theApp.m_pHardWare, theApp.m_vecHardChannel, theApp.m_vecHardChannel[0].m_strMachineIP, theApp.m_listMessaueType);
}
int ChannelParaPresetView::BreakString(const string& strSrc, vector<string>& vecDest, const string& strSeprator)
{
	//����б�
	vecDest.clear();
	//����
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		vecDest.push_back(strSrc);
		iCount = 1;
		return iCount;
	}

	//���ҵ�λ��
	std::string::size_type iPos = 0;
	while (iPos < strSrc.length())
	{
		std::string::size_type iNewPos = strSrc.find_first_of(strSeprator, iPos);
		//��ǰ�ַ����ָ���
		if (iNewPos == iPos)
		{
			iPos++;
		}
		//û�ҵ��ָ���
		else if (iNewPos == std::string::npos)
		{
			vecDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//����
		else
		{
			vecDest.push_back(strSrc.substr(iPos, iNewPos - iPos));
			iCount++;
			iPos = iNewPos;
			iPos++;
		}
	}

	return iCount;
}
void ChannelParaPresetView::GridCtrlInit()
{
	//m_vmeasuringRange.resize(m_channelParaGridCtrl.GetRowCount());
	int startChannelIndex = m_startChannelCombo.GetCurSel();
	
	int endChannelIndex = m_endChannelCombo.GetCurSel();
	m_channelParaGridCtrl.DeleteAllItems();
	if (endChannelIndex < startChannelIndex){ return; }
	m_channelParaGridCtrl.SetEditable(false);
	m_channelParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	if (startChannelIndex == -1 && endChannelIndex == -1){
		///�������������û�����ݣ���Ĭ����ʾһ��
		m_channelParaGridCtrl.SetRowCount(1);
	}
	else m_channelParaGridCtrl.SetRowCount(endChannelIndex-startChannelIndex+2); //��ʼΪn��
	m_channelParaGridCtrl.SetColumnCount(8); //��ʼ��Ϊ8��
	m_channelParaGridCtrl.SetFixedRowCount(1); //��ͷΪһ��
	m_channelParaGridCtrl.SetRowResize(TRUE); ///�Զ������к��еĴ�С
	m_channelParaGridCtrl.SetColumnResize(TRUE);
	m_channelParaGridCtrl.SetListMode(true); ////��ѡ��һ����Ԫ��ʱ��ѡ������
	m_channelParaGridCtrl.ExpandColumnsToFit(true);
	
	m_channelParaGridCtrl.SetSingleRowSelection(true);
	//m_channelParaGridCtrl.OnGridClick();
	m_vmeasuringRange.clear();
	m_vmeasuringRange.resize(m_channelParaGridCtrl.GetRowCount()-1);
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
				Item.strText = "ͨ����";
			}
			if (col == 2){
				Item.strText = "ͨ������";
			}
			if (col == 3){
				Item.strText = "����Ƶ��";
			}
			if (col == 4){
				Item.strText = "������������";
			}
			if (col == 5){
				Item.strText = "���뷽ʽ";
			}

			if (col == 6){
				Item.strText = "��������";
			}
			if (col == 7){
				Item.strText = "��������";
			}
			if (col == 8){
				Item.strText = "������Χ";
			}
			m_channelParaGridCtrl.SetItem(&Item);
			continue;
		}

		Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
		CString strText;
		if (col == 0)
		{
			m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
			m_channelParaGridCtrl.SetItemState(row, col, GVIS_READONLY);
		}
		if (col == 1)
		{
			Item.strText = m_vchannelCode[startChannelIndex++];
			m_channelParaGridCtrl.SetItemState(row, col, GVIS_READONLY);
		}
		if (col == 2) Item.strText = "ͨ��" + CommonUtil::Int2CString(row);
		if (col == 3) {
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto windowType : theApp.m_listUpFreq){
				OptionsType.Add(_T(windowType.data()));
					//.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		if (col == 4) Item.strText = m_strSenseCoef;
		if (col == 5) {
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto inputMethod : theApp.m_listInputMode){
				OptionsType.Add(_T(inputMethod.data()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		if (col == 6)
		{
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto FullValue : theApp.m_listFullValue){
				OptionsType.Add(_T(FullValue.data()));
					//GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
			
		}
		if (col == 7) {
			//��������
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto messaueType : theApp.m_listMessaueType){
				OptionsType.Add(_T(messaueType.data()));
				//.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		if (col == 8) {
			//������Χ
			m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
			pCellCombo->SetStyle(CBS_DROPDOWN);
			CStringArray OptionsType;
			for (auto inputMethod : theApp.m_elcpressure){
				OptionsType.Add(_T(inputMethod.data()));
				//.GetDictValue()));
			}
			pCellCombo->SetOptions(OptionsType);
			pCellCombo->SetCurSel(0);
			Item.strText = OptionsType[0];
		}
		
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
	else
	{
		if (isChecked)
		{
			SetGridCellCheck(0, 0, !isChecked);
		}
		else
		{
			int count = 0;
			for (int row = 1; row < m_channelParaGridCtrl.GetRowCount(); row++){
				if (GetGridCellCheck(row, 0))
				{
					count = count + 1;
				}
			}
			if (count == m_channelParaGridCtrl.GetRowCount() - 1)
			{
				SetGridCellCheck(0, 0, !isChecked);
			}
		}
	}
}


void ChannelParaPresetView::SetGridCellCheck(int row, int col, bool isChecked){
	if (!m_channelParaGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, col);
	pCell->SetCheck(isChecked);
}

bool ChannelParaPresetView::GetGridCellCheck(int row, int col){
	if (!m_channelParaGridCtrl.GetCell(row, col)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
		m_channelParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCheck));
	CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, col);
	bool isChecked = pCell->GetCheck();
	return isChecked;
}

void ChannelParaPresetView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_channelParaGridCtrl.SetEditable(TRUE);
}

void ChannelParaPresetView::GetSelectedChannels(vector<TbChannel> & vchannels){
	int a = m_channelParaGridCtrl.GetRowCount();
	for (int row = 1; row < m_channelParaGridCtrl.GetRowCount(); row++){
		if (!m_channelParaGridCtrl.GetCell(row, 0)->IsKindOf(RUNTIME_CLASS(CGridCellCheck)))
			m_channelParaGridCtrl.SetCellType(row, 0, RUNTIME_CLASS(CGridCellCheck));
		CGridCellCheck* pCell = (CGridCellCheck*)m_channelParaGridCtrl.GetCell(row, 0);
		TbChannel currentChannel;
		if (pCell->GetCheck()){
			int b = m_channelParaGridCtrl.GetColumnCount();
			for (int col = 0; col < m_channelParaGridCtrl.GetColumnCount();col++){
				if (col == 1)currentChannel.SetChannelCode(m_channelParaGridCtrl.GetItemText(row, col));
				if (col == 2) currentChannel.SetChannelDesc(m_channelParaGridCtrl.GetItemText(row, col));
				if (col == 3){
					///�õ�ѡ�������Ƶ��
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					CString strText = pCellCombo->GetText();
					currentChannel.SetUpFreq(std::make_pair(index, strText));// .SetUpFreq(a);
						//.SetUpFreq(iter);
						//SetWindowType(m_vwindowTypes[index]);
				}
				//������
				if (col == 4) currentChannel.SetSensitivity(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
				if (col == 5){
					///�õ�ѡ������뷽ʽ
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					CString strText = pCellCombo->GetText();
					currentChannel.SetInputMode(std::make_pair(index, strText));
				}
				if (col == 6)
					//currentSensor.SetFullValue(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
				{
					///�õ�ѡ�����������
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					CString strText = pCellCombo->GetText();
					currentChannel.SetFullValue(std::make_pair(index, strText));
				}
				if (col == 7){
					///�õ�ѡ��ĵ�ѹ��Χ
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					CString strText = pCellCombo->GetText();
					currentChannel.SetMessureType(std::make_pair(index, strText));
				}
				if (col == 8)
					//currentSensor.SetFullValue(atoi(m_channelParaGridCtrl.GetItemText(row, col)));
				{
					///�õ�ѡ��ĵ�ѹ��Χ
					CGridCellCombo* pCellCombo = (CGridCellCombo*)m_channelParaGridCtrl.GetCell(row, col);
					int index = pCellCombo->GetCurSel();
					CString strText = pCellCombo->GetText();
					currentChannel.SetElcPressure(std::make_pair(index, strText));
				}
			}
			vchannels.push_back(currentChannel);
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
	for (int i = 0; i < m_vchannelCode.size(); i++){
		m_startChannelCombo.InsertString(i, m_vchannelCode[i]);
		m_endChannelCombo.InsertString(i, m_vchannelCode[i]);
	}
	m_startChannelCombo.SetCurSel(0);
	m_endChannelCombo.SetCurSel(m_vchannelCode.size() - 1);
}