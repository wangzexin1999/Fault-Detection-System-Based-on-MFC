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
	//m_dictionController.FindAllBySearchCondition(m_vwindowTypes, 0, "windowtype");
	//m_dictionController.FindAllBySearchCondition(m_vinputMethods, 0, "inputmethod");
	GetParamSelectValue(theApp.m_vecHardChannel[0].m_strMachineIP);
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
		if (col == 1) theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetChannelDesc(m_generalParaGridCtrl.GetItemText(pItem->iRow, col));
		if (col == 2){
			// ��������
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetFullValue(std::make_pair(index, pCellCombo->GetText()));
		}
		if (col == 3){
			// ����Ƶ��
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetUpFreq(std::make_pair(index, pCellCombo->GetText()));
		}
		if (col == 4){
			///�õ�ѡ������뷽ʽ
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetInputMode(std::make_pair(index, pCellCombo->GetText()));
		}
		if (col == 5){
			// �õ������������
			theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetSensitivity(atoi(m_generalParaGridCtrl.GetItemText(pItem->iRow, col)));
		}
		if (col == 6){
			///�õ�ѡ��ĵ�ѹ������Χ
			CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(pItem->iRow, col);
			index = pCellCombo->GetCurSel();
			if (index < 0) continue;
			theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1].SetElcPressure(std::make_pair(index, pCellCombo->GetText()));
		}
			
	}
	///����ѡ������̷�Χ��ȡ���̵����ֵ����Сֵ
	//theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetChartXYCoordinateLen(0,-1,0, yInterval.Max);
	///ˢ�´�����ʾ�Ĵ�����
	theApp.m_vsignalCaptureView[pItem->iRow - 1]->SetChannel(theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1]);
	///�������ݿ⣬�������麽��
	ChannelController m_ChannelController;
	Result res = m_ChannelController.UpdateChannel(theApp.m_currentProject.GetChannelVector()[pItem->iRow - 1]);
	if (!res.GetIsSuccess()){
		AfxMessageBox(res.GetMessages());
	}
	///���������Ϊ���ɱ༭
	m_generalParaGridCtrl.SetEditable(FALSE);
}
void CGeneralParaView::GetParamSelectValue(string strMachineIP)
{
	BSTR *strSelectValue = new BSTR();
	char *pTempData;
	//��ȡ������ѡ���б�
	theApp.m_pHardWare->GetParamSelectValue(theApp.m_vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), theApp.m_vecHardChannel[0].m_nChannelStyle, theApp.m_vecHardChannel[0].m_nChannelID, theApp.m_vecHardChannel[0].m_nCellID, theApp.SHOW_CHANNEL_FULLVALUE, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strFullValueSelect = pTempData;
		int nFullValueCount = BreakString(strFullValueSelect, m_listFullValue, string("|"));
		delete pTempData;
	}
	//��ȡ����ֵ
	theApp.m_pHardWare->GetParamValue(theApp.m_vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), theApp.m_vecHardChannel[0].m_nChannelStyle, theApp.m_vecHardChannel[0].m_nChannelID, theApp.m_vecHardChannel[0].m_nCellID, theApp.SHOW_CHANNEL_SENSECOEF, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		m_strSenseCoef = pTempData;
		delete pTempData;
	}
	//��ȡ��ѹ������Χ
	theApp.m_pHardWare->GetParamSelectValue(theApp.m_vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), theApp.m_vecHardChannel[0].m_nChannelStyle, theApp.m_vecHardChannel[0].m_nChannelID, theApp.m_vecHardChannel[0].m_nCellID, theApp.SHOW_ELC_PRESSURE, strSelectValue);
	if (*strSelectValue){
		char *pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strEXCHANGEAB = pTempData;
		int nBridgeTypeCount = BreakString(strEXCHANGEAB, m_elcpressure, string("|"));
		delete pTempData;
	}
	//��ȡ������ѡ���б�
	theApp.m_pHardWare->GetParamSelectValue(theApp.m_vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), theApp.m_vecHardChannel[0].m_nChannelStyle, theApp.m_vecHardChannel[0].m_nChannelID, theApp.m_vecHardChannel[0].m_nCellID, theApp.SHOW_CHANNEL_UPFREQ, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strUpFreq = pTempData;
		int nUpFreqCount = BreakString(strUpFreq, m_listUpFreq, string("|"));
		delete pTempData;
	}

	//��ȡ������ѡ���б�
	theApp.m_pHardWare->GetParamSelectValue(theApp.m_vecHardChannel[0].m_nChannelGroupID, strMachineIP.data(), theApp.m_vecHardChannel[0].m_nChannelStyle, theApp.m_vecHardChannel[0].m_nChannelID, theApp.m_vecHardChannel[0].m_nCellID, theApp.SHOW_CHANNEL_ACQ_INPUTMODE, strSelectValue);
	if (*strSelectValue){
		pTempData = _com_util::ConvertBSTRToString(*strSelectValue);
		string strInputMode = pTempData;
		int nInputModeCount = BreakString(strInputMode, m_listInputMode, string("|"));
		delete pTempData;
	}
	delete strSelectValue;
}
int CGeneralParaView::BreakString(const string& strSrc, list<string>& lstDest, const string& strSeprator)
{
	//����б�
	lstDest.clear();
	//����
	int iCount = 0;

	if (strSeprator.length() == 0)
	{
		lstDest.push_back(strSrc);
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
			lstDest.push_back(strSrc.substr(iPos, strSrc.length() - iPos));
			iCount++;
			iPos = strSrc.length();
		}
		//����
		else
		{
			lstDest.push_back(strSrc.substr(iPos, iNewPos - iPos));
			iCount++;
			iPos = iNewPos;
			iPos++;
		}
	}

	return iCount;
}

void CGeneralParaView::GridCtrlInit()
{
	//��ʼ���㹻�����Ĳɼ�����������
	//m_measuringRange.resize(theApp.m_currentProject.GetChannelVector().size());
	m_generalParaGridCtrl.SetEditable(false);
	m_generalParaGridCtrl.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));//��ɫ����
	m_generalParaGridCtrl.SetRowCount(theApp.m_currentProject.GetChannelVector().size() + 1); //��ʼΪn��
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
	int valueRangeIndex;
	CStringArray OptionsType;
	for (int row = 0; row < m_generalParaGridCtrl.GetRowCount(); row++){
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
				if (col == 1){ Item.strText.Format(_T("ͨ������"), 1); }
				if (col == 2){ Item.strText.Format(_T("��������"), 2); }
				if (col == 3){ Item.strText.Format(_T("����Ƶ��"), 3); }
				if (col == 4){ Item.strText.Format(_T("���뷽ʽ"), 4); }
				if (col == 5){ Item.strText.Format(_T("������"), 5); }
				if (col == 6){ Item.strText.Format(_T("��ѹ������Χ"), 6); }
				m_generalParaGridCtrl.SetItem(&Item);
				continue;
			}
			Item.nFormat = DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS;
			CString strText;
			if (col == 0)
			{
				Item.strText = theApp.m_currentProject.GetChannelVector()[row - 1].GetChannelCode();
				m_generalParaGridCtrl.SetItemState(row, col, GVIS_READONLY);
			}
			if (col == 1)
				Item.strText = theApp.m_currentProject.GetChannelVector()[row - 1].GetChannelDesc();
			if (col == 2) {
				//��������
				m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
				CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
				pCellCombo->SetStyle(CBS_DROPDOWN);
				CStringArray OptionsType;
				for (auto FullValue : m_listFullValue){
					OptionsType.Add(_T(FullValue.data()));
				}
				pCellCombo->SetOptions(OptionsType);
				pCellCombo->SetCurSel(0);
				list<string>::iterator iter = m_listFullValue.begin();
				advance(iter, theApp.m_currentProject.GetChannelVector()[row - 1].GetFullValue().first);//ȡ���е�����Ԫ��
				string ddds = *iter;
				Item.strText = CString(ddds.c_str());;
			}
			if (col == 3) {
				//����Ƶ��
				m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
				CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
				pCellCombo->SetStyle(CBS_DROPDOWN);
				CStringArray OptionsType;
				for (auto UpFreq : m_listUpFreq){
					OptionsType.Add(_T(UpFreq.data()));
				}
				pCellCombo->SetOptions(OptionsType);
				pCellCombo->SetCurSel(0);
				list<string>::iterator iter = m_listUpFreq.begin();
				advance(iter, theApp.m_currentProject.GetChannelVector()[row - 1].GetUpFreq().first);//ȡ���е�����Ԫ��
				string ddds = *iter;
				Item.strText = CString(ddds.c_str());;
			}
			if (col == 4) {
				//���뷽ʽ
				m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
				CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
				pCellCombo->SetStyle(CBS_DROPDOWN);
				CStringArray OptionsType;
				for (auto inputMethod : m_listInputMode){
					OptionsType.Add(_T(inputMethod.data()));
				}
				pCellCombo->SetOptions(OptionsType);
				pCellCombo->SetCurSel(0);
				list<string>::iterator iter = m_listInputMode.begin();
				advance(iter, theApp.m_currentProject.GetChannelVector()[row - 1].GetInputMode().first);//ȡ���е�����Ԫ��
				string ddds = *iter;
				Item.strText = CString(ddds.c_str());//theApp.m_currentProject.GetChannelVector()[row - 1].GetInputMode().GetDictValue();
			}
			// ������
			if (col == 5)
				Item.strText = CommonUtil::DoubleOrFloat2CString(theApp.m_currentProject.GetChannelVector()[row - 1].GetSensitivity());

			if (col == 6) {
				//��ѹ������Χ
				m_generalParaGridCtrl.SetCellType(row, col, RUNTIME_CLASS(CGridCellCombo));
				CGridCellCombo* pCellCombo = (CGridCellCombo*)m_generalParaGridCtrl.GetCell(row, col);
				pCellCombo->SetStyle(CBS_DROPDOWN);
				CStringArray OptionsType;
				for (auto elcpressure : m_elcpressure){
					OptionsType.Add(_T(elcpressure.data()));
				}
				pCellCombo->SetOptions(OptionsType);
				pCellCombo->SetCurSel(0);
				list<string>::iterator iter = m_elcpressure.begin();
				advance(iter, theApp.m_currentProject.GetChannelVector()[row - 1].GetElcPressure().first);//ȡ���е�����Ԫ��
				string ddds = *iter;
				Item.strText = CString(ddds.c_str());//theApp.m_currentProject.GetChannelVector()[row - 1].GetInputMode().GetDictValue();
			}
			m_generalParaGridCtrl.SetItem(&Item);
		}
	}
}

void CGeneralParaView::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult){
	m_generalParaGridCtrl.SetEditable(TRUE);
}

