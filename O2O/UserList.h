#pragma once
#include "User.h"
struct Node
{
	User *user;
	Node *next;
};
class UserList
{
public:
	UserList(void);
	~UserList(void);
	
	void showAll() const;
	bool contain(string) const;
	void addUser(User*);
	User* getUser(string);
private:
	Node *head;
	int length;
};

