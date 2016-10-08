#pragma once
#include "UserList.h"
class Appointment
{
public:
	Appointment(void);
	//ԤԼ��ţ�ʱ������ʼʱ�䣬����ʱ�䣬�۸�
	Appointment(string, string, string, string, double);
	~Appointment(void);

	//��ȡԤԼ���
	inline string getId() {return id;}
	//���û���ӵ�ԤԼ�б���
	void addUserToAppointment(User* user);
	//��ȡĳ��ԤԼ�µ��û�����
	inline UserList* getUserList() {return userList;}
	//�����û����Ͳ�ͬչʾ��ͬ���
	void showAppointmentInfo(const User* user);

private:
	string id;
	string duration;
	string startTime;
	string endTime;
	double price;	
	UserList* userList;
};

