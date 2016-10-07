#include "StdAfx.h"
#include "SystemUI.h"
#include "Member.h"
#include "Coach.h"
#include "Manager.h"


SystemUI::SystemUI(void)
{
	pUser = nullptr;
	pDataProvider = new DataProvider();
}


SystemUI::~SystemUI(void)
{
	if (pUser!=nullptr)
	{
		delete pUser;
		pUser = nullptr;
	}
	if (pDataProvider!=nullptr)
	{
		delete pDataProvider;
		pDataProvider = nullptr;
	}
}

void SystemUI::mainMenu()
{
	int choice;
	while (true)
	{
		CLS;
		cout << "1.��¼  2.ע��  3.�˳�\n";
		cin >> choice;
		switch(choice)
		{
		case 1: login();break;
		case 2: registration();break;
		case 3: exit(0);
		default: cout << "��Ч������������ѡ��" << endl;PAUSE;
		}
	}
}

void SystemUI::homeMenu()
{
	CLS;
	pUser->selectItem();
	pUser = pUser->logout();
}

void SystemUI::login()
{
	CLS;
	string name;
	string pwd;
	cout << "�˺ţ�";
	cin >> name;
	cout << "���룺";
	cin >> pwd;
	if ((pUser=pDataProvider->login(name, pwd))!=nullptr)
	{
		cout << "��¼�ɹ�..." << endl;
		PC;
		homeMenu();
	}
	else
	{
		cout << "�û������������" << endl;
		PC;
		return ;
	}
}

void SystemUI::registration()
{
	CLS;
	string name;
	string pwd;
	int role;
	while (true)
	{
		cout << "�˺ţ�";
		cin >> name;
		if (pDataProvider->isUserExist(name))
		{
			cout << "���û����ѱ�ռ�ã����������룡\n";PC;
		}
		else
		{
			break;
		}
	}
	cout << "���룺";
	cin >> pwd;
	while (pUser == nullptr)
	{
		cout << "��ѡ���ɫ��\n1.��ͨ��Ա��2.˽�˽�����3.Ⱥ��\n";
		cin >> role;
		switch(role)
		{
		case 1: pUser = new Member(name, pwd, pDataProvider);break;
		case 2: pUser = new Coach(name, pwd, pDataProvider);break;
		case 3: pUser = new Manager(name, pwd, pDataProvider);break;
		default: cout << "��Ч������������ѡ��\n";PAUSE;
		}
	}
	pDataProvider->addUser(pUser);
	cout << "ע��ɹ���" << endl;
	PC;
	homeMenu();
}
