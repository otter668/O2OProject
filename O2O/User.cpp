#include "StdAfx.h"
#include "User.h"


User::User(void)
{
}


User::~User(void)
{
}

string User::getName() const
{
	return name;
}

bool User::verification(string pwd) const
{
	return this->pwd == pwd;
}
