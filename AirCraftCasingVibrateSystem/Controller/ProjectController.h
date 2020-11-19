
#pragma once
#include"TbCollectionparasDao.h"
#include "ProductService.h"
#include "CollectionparasService.h"
#include "TbProject.h"
#include "ChannelService.h"
#include "ProjectService.h"
#include "UserService.h"
//#include "Colle"
#include"Result.h"
class ProjectController
{

private:
	CollectionparasService m_collectionparasService;
	ProductService m_productService;
	ProjectService m_projectService;
	CChannelService m_channelService;
	UserService m_userService;
public:
	ProjectController();
	~ProjectController();

	/**********************************************************************
	功能描述：加载所有的测试设备
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllCollectionparas(vector<TbCollectionparasDao> & tbCollectionparasVec);

	/**********************************************************************
	功能描述：新建项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result AddProject(TbProject & project);

	/**********************************************************************
	功能描述：根据查询条件加载所有的项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindAllProjectBySearchCondition(TbProject project, CString startTime, CString endTime,vector<TbProject> &projectVector);
	/**********************************************************************
	功能描述：找到最后打开的项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result FindLastOpenProjectByUser(TbProject &project);

	/**********************************************************************
	功能描述：更新项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
	Result Update(TbProject project);
	/**********************************************************************
	功能描述：根据加载所有的项目
	输入参数：
	输出参数：
	返 回 值：
	其它说明：
	修改日期 版本号 修改人 修改内容
	----------------------------------------------------------------------
	***********************************************************************/
//	Result FindAllProjectBySearchCondition(int testerId, CString projectName, CString startTime, CString endTime, vector<TbProject> &projectVector);

};

