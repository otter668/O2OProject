#include "StdAfx.h"
#include "DataProvider.h"
#include "UserList.h"
#include "GroupList.h"
#include "Activity.h"

DataProvider::DataProvider(void)
{
	userList = new UserList();
	groupList = new GroupList(10);
}


DataProvider::~DataProvider(void)
{
	if (userList!=nullptr)
	{
		delete userList;
		userList = nullptr;
	}
}

bool DataProvider::isUserExist(string name)
{
	return userList->contain(name);
}

void DataProvider::addUser(User* user)
{
	userList->addUser(user);
}

User* DataProvider::login(string name, string pwd)
{
	if (!isUserExist(name))
	{
		return false;
	}
	User *user = userList->getUser(name);
	if(user->verification(pwd))
	{
		return user;
	}
	else
	{
		return nullptr;
	}
}

bool DataProvider::addGroup(User* user, string name) const
{
	if (groupList->contain(name))
	{
		return false;
	}
	else
	{
		Groups *group = new Groups(name);
		group->addUserToGroup(user);
		groupList->addGroup(group);
		return true;
	}
}

bool DataProvider::joinGrop(User* user, string name) const
{
	int index = groupList->contain(name);
	if (groupList->contain(name))
	{
		groupList->addUserToGroup(user, name);
		return true;
	}
	else
	{
		return false;
	}
}

void DataProvider::showAllGroup() const
{
		if (groupList->size() == 0)
		{
			cout << "暂无数据\n";
			return ;
		}
		for (int i=0;i!=groupList->size();i++)
		{
			groupList->at(i+1)->showGroupInfo();
		}
}

bool DataProvider::showMyGroup(User* user) const
{
		bool flag = false;
		for (int i=0; i!=groupList->size(); i++)
		{
			Groups* group = groupList->at(i+1);
			UserList* userList = group->getGroupUsers();
			if (userList->contain(user->getName()))
			{
				flag = true;
				group->showGroupInfo();
			}
		}
		return flag;
}

bool DataProvider::joinActivity(User* user, string groupName, string activityName)
{
	int gIndex = groupList->contain(groupName);
	if (!gIndex)
	{
		cout << "未找到群组：" << groupName << endl;
		return false;
		
	}
	Groups* group = groupList->at(gIndex);
	if (!group->getGroupUsers()->contain(user->getName()))
	{
		cout << "你还未加入组名为：" << groupName << "的小组，不能加入此活动！"<< endl;
		return false;
	}
	int aIndex = group->getGroupActivitys()->contain(activityName);
	if (!aIndex)
	{
		cout << "未找到活动：" << activityName << endl;
		return false;
	}
	Activity* activity = group->getGroupActivitys()->at(aIndex);
	activity->addUserToActivity(user);
	return true;
}

bool DataProvider::addActivity(User* user, string groupName, Activity* activity)
{
	int gIndex = groupList->contain(groupName);
	if (!gIndex)
	{
		cout << "未找到群组：" << groupName << endl;
		return false;
	}
	Groups* group = groupList->at(gIndex);
	if (!group->getGroupUsers()->contain(user->getName()))
	{
		cout << "你不是该群:" << groupName << "的群主，不能添加群活动"<< endl;
		return false;
	}
	int aIndex = group->getGroupActivitys()->contain(activity->getActivityName());
	if (aIndex)
	{
		cout << "已存在：" << activity->getActivityName() << "活动，不能重复发布！" << endl;
		return false;
	}
	group->addActivity(activity);
	return true;
}
