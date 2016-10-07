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
		cout << "1.登录  2.注册  3.退出\n";
		cin >> choice;
		switch(choice)
		{
		case 1: login();break;
		case 2: registration();break;
		case 3: exit(0);
		default: cout << "无效操作！请重新选择。" << endl;PAUSE;
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
	cout << "账号：";
	cin >> name;
	cout << "密码：";
	cin >> pwd;
	if ((pUser=pDataProvider->login(name, pwd))!=nullptr)
	{
		cout << "登录成功..." << endl;
		PC;
		homeMenu();
	}
	else
	{
		cout << "用户名或密码错误" << endl;
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
		cout << "账号：";
		cin >> name;
		if (pDataProvider->isUserExist(name))
		{
			cout << "该用户名已被占用，请重新输入！\n";PC;
		}
		else
		{
			break;
		}
	}
	cout << "密码：";
	cin >> pwd;
	while (pUser == nullptr)
	{
		cout << "请选择角色：\n1.普通会员；2.私人教练；3.群主\n";
		cin >> role;
		switch(role)
		{
		case 1: pUser = new Member(name, pwd, pDataProvider);break;
		case 2: pUser = new Coach(name, pwd, pDataProvider);break;
		case 3: pUser = new Manager(name, pwd, pDataProvider);break;
		default: cout << "无效操作！请重新选择。\n";PAUSE;
		}
	}
	pDataProvider->addUser(pUser);
	cout << "注册成功！" << endl;
	PC;
	homeMenu();
}
