#pragma once
#include "User.h"
#include "DataProvider.h"
class SystemUI
{
public:
	SystemUI(void);
	~SystemUI(void);

	//��¼�˵�
	void mainMenu();
	//������˵�
	void homeMenu();
	//��¼
	void login();
	//ע��
	void registration();

private:
	User* pUser;
	DataProvider* pDataProvider;
};

