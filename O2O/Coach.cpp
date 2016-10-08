#include "StdAfx.h"
#include "Coach.h"
#include "Appointment.h"


Coach::Coach(void)
{
}


Coach::~Coach(void)
{
}

void Coach::selectItem()
{
	int choice;
	while (true)
	{
		showMenu();
		cin >> choice;
		switch(choice)
		{
		case 1: addAppointment();break;
		case 2: getAppointment();break;
		case 3: return ;
		default: cout << "��Ч������������ѡ��\n";
		}
		PC;
	}
}

void Coach::showMenu()
{
	CLS;
	cout << "��ӭ������" << name << "\n";
	cout << "1.����ԤԼʱ��\n";
	cout << "2.�鿴ԤԼ�б�\n";
	cout << "3.�˳�" << endl;
}

void Coach::addAppointment()
{
	string id;
	string duration;
	string startTime;
	string endTime;
	double price;
	cout << "��ţ�";
	cin >> id;
	cout << "ʱ����";
	cin >> duration;
	cout << "��ʼʱ�䣺";
	cin >> startTime;
	cout << "����ʱ�䣺";
	cin >> endTime;
	cout << "�۸�";
	cin >> price;
	while (cin.fail())
	{
		cout << "�۸����벻����,����������" << endl;
		cin.clear();
		cin.sync();
		cin >> price;
	}
	Appointment* app = new Appointment(id, duration, startTime, endTime, price);
	if(dp->AddAppointment(this, app))
	{
		cout << "���ԤԼ�ɹ���" << endl;
	}
	else
	{
		cout << "���ԤԼʧ��" << endl;
	}
}

void Coach::getAppointment() const
{
	cout << "���\tʱ��\t��ʼʱ��\t����ʱ��\t�۸�\n";
	dp->getAppointment(this);
}
