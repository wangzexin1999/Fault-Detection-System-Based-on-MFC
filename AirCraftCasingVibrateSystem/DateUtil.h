#pragma once
class DateUtil
{
public:
	/**********************************************************************
	���������� ����ָ����ʽ�õ���ǰ��ʱ��
	��������� ʱ��ĸ�ʽ
	���������
	�� �� ֵ��
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	static CString GetCurrentCStringTime(CString format = "%Y-%m-%d %H:%M:%S");
	static CString GetCStringTimeFormCTime(CTime time);
	static CTime & GetAWeekAgoDate();

};

