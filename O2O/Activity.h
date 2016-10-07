#pragma once
#include "UserList.h"
class Activity
{
public:
	Activity(void);
	//活动名称，地点，开始时间，结束时间，经费，介绍
	Activity(string, string, string, string, double, string);
	~Activity(void);

	//获取群活动名
	string getActivityName() const;
	//展示活动信息
	void showActivityInfo() const;
	//添加用户到指定活动
	void addUserToActivity(User*);

private:
	string activityName;
	string activityPlace;
	string activityStarttime;
	string activityEndtime;
	double activityPrice;
	string activityIntroduction;
	UserList* userList;
};

