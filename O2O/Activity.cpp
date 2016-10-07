#include "StdAfx.h"
#include "Activity.h"


Activity::Activity(void)
{
	userList = nullptr;
}

Activity::Activity(string name, string place, string startTime, string endTime, double price, string intro)
{
	activityName = name;
	activityPlace = place;
	activityStarttime = startTime;
	activityEndtime = endTime;
	activityPrice = price;
	activityIntroduction = intro;
	userList = new UserList();
}

Activity::~Activity(void)
{
	if (userList!=nullptr)
	{
		delete userList;
		userList = nullptr;
	}
}

string Activity::getActivityName() const
{
	return activityName;
}

void Activity::showActivityInfo() const
{
	cout << "活动：" << activityName << endl;
	cout << "组员：" << endl;
	userList->showAll();
	cout << "====================" << endl;
}

void Activity::addUserToActivity(User* user)
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
