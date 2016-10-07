#pragma once
#include "User.h"
class Manager :
	public User
{
public:
	Manager(void);
	Manager(string name, string pwd, DataProvider* pdp):User(name, pwd, pdp){}
	~Manager(void);

	virtual void selectItem();

protected:
	virtual void showMenu();
private:
	void addGroup();
	void publishActivity(User*);
	void showMyGroup(User*) const;
};

