#pragma once
#include "UserList.h"
class Appointment
{
public:
	Appointment(void);
	//预约编号，时长，开始时间，结束时间，价格
	Appointment(string, string, string, string, double);
	~Appointment(void);

	//获取预约编号
	inline string getId() {return id;}
	//将用户添加到预约列表中
	void addUserToAppointment(User* user);
	//获取某个预约下的用户集合
	inline UserList* getUserList() {return userList;}
	//根据用户类型不同展示不同结果
	void showAppointmentInfo(const User* user);

private:
	string id;
	string duration;
	string startTime;
	string endTime;
	double price;	
	UserList* userList;
};

