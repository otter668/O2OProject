#pragma once
#include "UserList.h"
#include "ActivityList.h"
class Groups
{
public:
	Groups(void);
	Groups(string);
	~Groups(void);

	void showGroupInfo() const;
	void addUserToGroup(User*);
	void addActivity(Activity*);
	string getName() const;
	UserList* getGroupUsers() const;
	ActivityList* getGroupActivitys() const;

private:
	string groupName;
	ActivityList* activityList;
	UserList* userList;
};

