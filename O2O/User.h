#pragma once
#include "DataProvider.h"
class User
{
public:
	User(void);
	User(string name, string pwd, DataProvider* pdp):name(name),pwd(pwd),dp(pdp){}
	virtual ~User(void);

	string getName() const;
	virtual void selectItem() =0;
	bool verification(string) const;
	inline User* logout() const {return nullptr;}

protected:
	string name;
	string pwd;
	DataProvider* dp;

	virtual void showMenu() =0;
};

