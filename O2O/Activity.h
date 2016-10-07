#pragma once
#include "UserList.h"
class Activity
{
public:
	Activity(void);
	//����ƣ��ص㣬��ʼʱ�䣬����ʱ�䣬���ѣ�����
	Activity(string, string, string, string, double, string);
	~Activity(void);

	//��ȡȺ���
	string getActivityName() const;
	//չʾ���Ϣ
	void showActivityInfo() const;
	//����û���ָ���
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

