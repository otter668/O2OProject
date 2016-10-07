#include "StdAfx.h"
#include "Coach.h"


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
		case 1: addActivity();break;
		case 2: getActivity();break;
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

void Coach::addActivity()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Coach::getActivity() const
{
	throw std::logic_error("The method or operation is not implemented.");
}
