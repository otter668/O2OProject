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
		default: cout << "��Ч������������ѡ��\n";
		}
		PC;
	}
}

void Manager::showMenu()
{
	CLS;
	cout << "��ӭȺ����" << name << "\n";
	cout << "1.����Ⱥ��\n";
	cout << "2.����Ⱥ�\n";
	cout << "3.�鿴�Ѿ�������Ⱥ��Ϣ\n";
	cout << "4.�˳�\n";	
	cout << "��ѡ��" << endl;	
}

void Manager::addGroup()
{
	string groupName;
	cout << "������";
	cin >> groupName;
	if (dp->addGroup(this, groupName))
	{
		cout << "Ⱥ�鴴���ɹ�!" << endl;
	}
	else
	{
		cout << "���ʧ�ܣ�����ӵ�����������Ⱥ����ӵ�������ͬ!" << endl;
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
	cout << "����ƣ�";
	cin >> name;
	cout << "��ص㣺";
	cin >> place;
	cout << "��ʼʱ�䣨��ʽ��2016��1��1�գ���";
	cin >> starttime;
	cout << "����ʱ�䣨��ʽ��2016��1��1�գ���";
	cin >> endtime;
	cout << "����ѣ�";
	cin >> price;
	while (cin.fail())
	{
		cout << "��������벻����,����������" << endl;
		cin.clear();
		cin.sync();
		cin >> price;
	}

	cout << "����ܣ�";
	cin >> introduction;
	cout << "������Ҫ��������Ⱥ�����ƣ�(���ǵ�Ⱥ��������1)";
	cin >> groupName;
	if (groupName == "1")
	{
		if (!dp->showMyGroup(user))
		{
			cout << "�㻹δ����Ⱥ��" << endl;
			return;
		}
		cout << "������Ҫ��������Ⱥ�����ƣ�";
		cin >> groupName;
	}
	Activity* activity = new Activity(name, place, starttime, endtime, price, introduction);
	if(dp->addActivity(user, groupName, activity))
	{
		cout << "������ɹ���" << endl;
	}
	else
	{
		cout << "�����ʧ�ܣ�" << endl;
	}
}

void Manager::showMyGroup(User* user) const
{
	dp->showMyGroup(user);
}
