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

void Coach::addActivity()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Coach::getActivity() const
{
	throw std::logic_error("The method or operation is not implemented.");
}
