#pragma once
#include "Appointment.h"
class AppointmentList
{
public:
	AppointmentList(void);
	AppointmentList(int);
	~AppointmentList(void);

	// ��ȡ���鳤��
	inline int size(){return length;}
	// ��ȡָ��λ��Ԫ��
	inline Appointment* at(int index) const {return &appointments[index-1];}
	// �Ƿ����ָ������Ԫ�أ���������λ��[0,length]
	const int contain(string) const;
	// �����ԤԼ
	void addAppointment(Appointment*);
	// ����û���ָ������ԤԼ
	void addUserToAppointment(User*, string);
	void showAll() const;
private:
	int length;
	int capacity;
	Appointment* appointments;

	void resize();
};

