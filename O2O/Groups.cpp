#include "StdAfx.h"
#include "Groups.h"


Groups::Groups(void)
{
	userList = nullptr;
	activityList = nullptr;
}


Groups::Groups(string name):groupName(name)
{
	userList = new UserList();
	activityList = new ActivityList(10);
}

Groups::~Groups(void)
{
	if (userList!=nullptr)
	{
		delete userList;
		userList = nullptr;
	}
	if (activityList!=nullptr)
	{
		delete activityList;
		activityList = nullptr;
	}
}

void Groups::showGroupInfo() const
{
	cout << "组名：" << groupName << endl;
	cout << "组员：" << endl;
	userList->showAll();
	cout << "活动：" << endl;
	activityList->ShowAll();
	cout << "====================" << endl;
}

string Groups::getName() const
{
	return groupName;
}

void Groups::addUserToGroup(User* user)
{
	if (!userList->contain(user->getName()))
	{
		userList->addUser(user);
	}
	else
	{
		cout << "你已经加入改群组了！" << endl;
	}
}

UserList* Groups::getGroupUsers() const
{
	return userList;
}

ActivityList* Groups::getGroupActivitys() const
{
	return activityList;
}

void Groups::addActivity(Activity* activity)
{
	activityList->addActivity(activity);
}
