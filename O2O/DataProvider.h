#pragma once
class User;
class Activity;
class Appointment;
class UserList;
class GroupList;
class AppointmentList;
class DataProvider
{
public:
	DataProvider(void);
	~DataProvider(void);
	// 注册时，判断用户名是否存在
	bool isUserExist(string);
	// 添加用户
	void addUser(User*);
	// 登录
	User* login(string, string);
	// 新增群组
	bool addGroup(User* user, string name) const;
	// 加入群组
	bool joinGrop(User* user, string name) const;
	// 显示所有群组
	void showAllGroup() const;
	// 显示用户所有群组
	bool showMyGroup(const User*) const;
	// 新增活动
	bool addActivity(User*, string, Activity*);
	// 加入活动
	bool joinActivity(User*, string, string);
	// 新增预约
	bool AddAppointment(User*, Appointment*);
	// 加入预约
	bool joinAppointment(User*, string);
	// 获取私教预约
	void getAppointment(const User*);
	// 显示用户已定预约
	int showAllAppointment(const User*) const;
private:
	UserList* userList;					//用户列表
	GroupList* groupList;				//群组列表
	AppointmentList* appointmentList;	// 预约列表
};

