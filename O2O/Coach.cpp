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
		default: cout << "无效操作！请重新选择。\n";
		}
		PC;
	}
}

void Coach::showMenu()
{
	CLS;
	cout << "欢迎教练：" << name << "\n";
	cout << "1.发布预约时间\n";
	cout << "2.查看预约列表\n";
	cout << "3.退出" << endl;
}

void Coach::addAppointment()
{
	string id;
	string duration;
	string startTime;
	string endTime;
	double price;
	cout << "编号：";
	cin >> id;
	cout << "时长：";
	cin >> duration;
	cout << "开始时间：";
	cin >> startTime;
	cout << "结束时间：";
	cin >> endTime;
	cout << "价格：";
	cin >> price;
	while (cin.fail())
	{
		cout << "价格输入不合理,请重新输入" << endl;
		cin.clear();
		cin.sync();
		cin >> price;
	}
	Appointment* app = new Appointment(id, duration, startTime, endTime, price);
	if(dp->AddAppointment(this, app))
	{
		cout << "添加预约成功！" << endl;
	}
	else
	{
		cout << "添加预约失败" << endl;
	}
}

void Coach::getAppointment() const
{
	cout << "编号\t时长\t开始时间\t结束时间\t价格\n";
	dp->getAppointment(this);
}
