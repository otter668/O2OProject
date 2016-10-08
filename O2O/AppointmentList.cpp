#include "StdAfx.h"
#include "AppointmentList.h"


AppointmentList::AppointmentList(void)
{
	appointments = nullptr;
}


AppointmentList::AppointmentList(int cap):length(0),capacity(cap)
{
	appointments = new Appointment[cap];
}

AppointmentList::~AppointmentList(void)
{
	if (appointments!=nullptr)
	{
		delete[] appointments;
		appointments = nullptr;
	}
}

const int AppointmentList::contain(string id) const
{
	for (int i=0;i!=length;i++)
	{
		if (appointments[i].getId() == id)
		{
			return i+1;
		}
	}
	return 0;
}

void AppointmentList::addAppointment(Appointment* app)
{
	if (!contain(app->getId()))
	{
		int index = length==capacity?resize(),length++:length++;
		appointments[index] = *app;
	}
}

void AppointmentList::addUserToAppointment(User* user, string appName)
{
	appointments[contain(appName)-1].addUserToAppointment(user);
}

void AppointmentList::showAll() const
{
	for (int i=0;i!=length;i++)
	{
		cout << appointments[i].getId() << "\t";
	}
	cout << endl;
}

void AppointmentList::resize()
{
	capacity *= 2;
	Appointment* temp = new Appointment[capacity];
	memcpy(temp,appointments,length);
	delete[] appointments;
	appointments = temp;
}
