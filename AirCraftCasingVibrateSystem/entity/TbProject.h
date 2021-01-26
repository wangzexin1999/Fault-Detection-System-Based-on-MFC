#pragma once
#include "TbUser.h"
#include"TbCollectionparas.h"
#include "TbProduct.h"
#include "TbChannel.h"
#include <vector>
using namespace std;
class TbProject
{
public:

	TbProject(int projectId = 0,CString  projectName = "",int projectStatus = 0);
	TbProject(int projectId, CString  projectName, CString projectCreatetime, TbUser user, TbCollectionparas  collectionparas, TbProduct  product);
	~TbProject();

protected:

	int m_projectId;
	TbUser m_user;
	CString  m_projectName;
	CString m_projectCreatetime;
	CString m_projectUpdatetime;
	TbCollectionparas  m_collectionparas;
	TbProduct m_product;
	vector<TbChannel> m_channelVector;
	int m_projectStatus;

public:
	void SetProjectId(int projectId);
	void SetProjectName(CString projectName);
	void SetUser(TbUser user);
	void SetCollectionparas(TbCollectionparas collectionparas);
	TbCollectionparas & GetCollectionparas();
	TbProduct & GetProduct();
	void SetProduct(TbProduct  product);
	void SetProjectCreateTime(CString m_projectCreatetime);
	void SetProjectUpdateTime(CString projectUpdatetime);

	TbUser & GetUser();
	CString GetProjectCreateTime();
	CString GetProjectUpdateTime();

	CString GetProjectName();

	vector<TbChannel> & GetChannelVector();
	void SetChannelVector(vector<TbChannel> channelParaVector);

	int GetProjectId();
	void SetProjectStatus(int status);
	int GetProjectStatus();

};

