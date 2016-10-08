#pragma once
#include "User.h"
class Coach :
	public User
{
public:
	Coach(void);
	Coach(string name, string pwd, DataProvider* pdp):User(name, pwd, pdp){}
	~Coach(void);

	virtual void selectItem();

protected:
	virtual void showMenu();
private:
	void addAppointment();
	void getAppointment() const;
};

