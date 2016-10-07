#pragma once
#include "User.h"
#include "DataProvider.h"
class SystemUI
{
public:
	SystemUI(void);
	~SystemUI(void);

	//登录菜单
	void mainMenu();
	//主界面菜单
	void homeMenu();
	//登录
	void login();
	//注册
	void registration();

private:
	User* pUser;
	DataProvider* pDataProvider;
};

