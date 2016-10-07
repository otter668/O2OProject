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
	//ע��ʱ���ж��û����Ƿ����
	bool isUserExist(string);
	// ����û�
	void addUser(User*);
	//��¼
	User* login(string, string);

	bool addGroup(User* user, string name) const;
	bool joinGrop(User* user, string name) const;
	void showAllGroup() const;
	bool showMyGroup(User*) const;
	bool addActivity(User*, string, Activity*);
	bool joinActivity(User*, string, string);

private:
	UserList* userList;		//�û��б�����
	GroupList* groupList;	//Ⱥ���б�����	
};

