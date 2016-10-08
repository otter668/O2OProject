#pragma once
#include "Appointment.h"
class AppointmentList
{
public:
	AppointmentList(void);
	AppointmentList(int);
	~AppointmentList(void);

	// 获取数组长度
	inline int size(){return length;}
	// 获取指定位置元素
	inline Appointment* at(int index) const {return &appointments[index-1];}
	// 是否包含指定名称元素，并返回其位置[0,length]
	const int contain(string) const;
	// 添加新预约
	void addAppointment(Appointment*);
	// 添加用户到指定名称预约
	void addUserToAppointment(User*, string);
	void showAll() const;
private:
	int length;
	int capacity;
	Appointment* appointments;

	void resize();
};

