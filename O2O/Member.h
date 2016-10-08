#pragma once
#include "User.h"
class Member :
	public User
{
public:
	Member(void);
	Member(string name, string pwd, DataProvider* pdp):User(name, pwd, pdp){}
	~Member(void);

	virtual void selectItem();

protected:
	virtual void showMenu();
private:
	void showAllGroup() const;
	void joinGroup();
	void joinActivity();
	void appointmentCoache(User*);
	void getAppointment(const User*);
};

