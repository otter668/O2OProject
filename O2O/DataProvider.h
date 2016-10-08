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
	// ע��ʱ���ж��û����Ƿ����
	bool isUserExist(string);
	// ����û�
	void addUser(User*);
	// ��¼
	User* login(string, string);
	// ����Ⱥ��
	bool addGroup(User* user, string name) const;
	// ����Ⱥ��
	bool joinGrop(User* user, string name) const;
	// ��ʾ����Ⱥ��
	void showAllGroup() const;
	// ��ʾ�û�����Ⱥ��
	bool showMyGroup(const User*) const;
	// �����
	bool addActivity(User*, string, Activity*);
	// ����
	bool joinActivity(User*, string, string);
	// ����ԤԼ
	bool AddAppointment(User*, Appointment*);
	// ����ԤԼ
	bool joinAppointment(User*, string);
	// ��ȡ˽��ԤԼ
	void getAppointment(const User*);
	// ��ʾ�û��Ѷ�ԤԼ
	int showAllAppointment(const User*) const;
private:
	UserList* userList;					//�û��б�
	GroupList* groupList;				//Ⱥ���б�
	AppointmentList* appointmentList;	// ԤԼ�б�
};

