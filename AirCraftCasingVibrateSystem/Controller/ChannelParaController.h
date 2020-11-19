
#pragma once
#include "TbProject.h"
#include "Result.h"
#include "ChannelParaService.h"
#include "vector"
using namespace std;
class ChannelParaController
{

private:
	ChannelParaService channelParaService;

public:
	ChannelParaController();
	~ChannelParaController();

	/**********************************************************************
	������������ѯָ����Ŀ�Ĵ���������
	���������
	���������
	�� �� ֵ��Result ����
	����˵����
	�޸����� �汾�� �޸��� �޸�����
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindALLChannelParaByProjectId(TbProject &project);
};

