#pragma once
class User;
class UserList;
class GroupList;
class Activity;
class DataProvider
{
public:
	DataProvider(void);
	~DataProvider(void);
	//注册时，判断用户名是否存在
	bool isUserExist(string);
	// 添加用户
	void addUser(User*);
	//登录
	User* login(string, string);

	bool addGroup(User* user, string name) const;
	bool joinGrop(User* user, string name) const;
	void showAllGroup() const;
	bool showMyGroup(User*) const;
	bool addActivity(User*, string, Activity*);
	bool joinActivity(User*, string, string);

private:
	UserList* userList;		//用户列表数据
	GroupList* groupList;	//群组列表数据	
};

