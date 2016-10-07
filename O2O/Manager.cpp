#include "StdAfx.h"
#include "Manager.h"
#include "Activity.h"


Manager::Manager(void)
{
}


Manager::~Manager(void)
{
}

void Manager::selectItem()
{
	int choice;
	while (true)
	{
		showMenu();
		cin >> choice;
		switch(choice)
		{
		case 1: addGroup();break;
		case 2: publishActivity(this);break;
		case 3: showMyGroup(this);break;
		case 4: return ;
		default: cout << "无效操作！请重新选择。\n";
		}
		PC;
	}
}

void Manager::showMenu()
{
	CLS;
	cout << "欢迎群主：" << name << "\n";
	cout << "1.创建群组\n";
	cout << "2.发布群活动\n";
	cout << "3.查看已经创建的群信息\n";
	cout << "4.退出\n";	
	cout << "请选择：" << endl;	
}

void Manager::addGroup()
{
	string groupName;
	cout << "组名：";
	cin >> groupName;
	if (dp->addGroup(this, groupName))
	{
		cout << "群组创建成功!" << endl;
	}
	else
	{
		cout << "添加失败！你添加的组名与其他群主添加的组名相同!" << endl;
	}
}

void Manager::publishActivity(User* user)
{
	string name;
	string place;
	string starttime;
	string endtime;
	double price;
	string introduction;
	string groupName;
	cout << "活动名称：";
	cin >> name;
	cout << "活动地点：";
	cin >> place;
	cout << "开始时间（格式：2016年1月1日）：";
	cin >> starttime;
	cout << "结束时间（格式：2016年1月1日）：";
	cin >> endtime;
	cout << "活动经费：";
	cin >> price;
	while (cin.fail())
	{
		cout << "活动经费输入不合理,请重新输入" << endl;
		cin.clear();
		cin.sync();
		cin >> price;
	}

	cout << "活动介绍：";
	cin >> introduction;
	cout << "请输入要发布到的群组名称：(不记得群名？输入1)";
	cin >> groupName;
	if (groupName == "1")
	{
		if (!dp->showMyGroup(user))
		{
			cout << "你还未创建群组" << endl;
			return;
		}
		cout << "请输入要发布到的群组名称：";
		cin >> groupName;
	}
	Activity* activity = new Activity(name, place, starttime, endtime, price, introduction);
	if(dp->addActivity(user, groupName, activity))
	{
		cout << "活动发布成功！" << endl;
	}
	else
	{
		cout << "活动发布失败！" << endl;
	}
}

void Manager::showMyGroup(User* user) const
{
	dp->showMyGroup(user);
}
