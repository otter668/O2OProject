#include "StdAfx.h"
#include "Appointment.h"
#include "Coach.h"


Appointment::Appointment(void)
{
	userList = nullptr;
}


Appointment::Appointment(string id, string duration, string startTime, string endTime, double price)
{
	this->id = id;
	this->duration =duration;
	this->startTime = startTime;
	this->endTime = endTime;
	this->price = price;
	userList = new UserList();
}

Appointment::~Appointment(void)
{
	if (userList!=nullptr)
	{
		delete userList;
		userList = nullptr;
	}
}

void Appointment::addUserToAppointment(User* user)
{
	if (userList->contain(user->getName()))
	{
		cout << "你已经预约了该私教！" << endl;
		return;
	}
	userList->addUser(user);
	return;
}

void Appointment::showAppointmentInfo(const User* user)
{
	cout << id << "\t";
	cout << duration << "\t";
	cout << startTime << "\t";
	cout << endTime << "\t";
	cout << price << endl;
	// RTTI
	if (typeid(*user)==typeid(Coach))
	{
		cout << "预约成员：\n";
		userList->showAll();
	}
}
