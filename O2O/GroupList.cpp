#include "StdAfx.h"
#include "GroupList.h"


GroupList::GroupList(void)
{
	groups = nullptr;
}


GroupList::GroupList(int cap):length(0),capacity(cap)
{
	groups = new Groups[cap];
}

GroupList::~GroupList(void)
{
	if (groups!=nullptr)
	{
		delete[] groups;
		groups = nullptr;
	}
}

Groups* GroupList::at(int index) const
{
	return &groups[index-1];
}

const int GroupList::contain(string name) const
{
	for (int i=0;i!=length;i++)
	{
		if (groups[i].getName() == name)
		{
			return i+1;
		}
	}
	return 0;
}

void GroupList::addGroup(Groups *group)
{
	if (!contain(group->getName()))
	{
		int index = length == capacity ? resize(),length++ : length++; 
		groups[index] = *group;
	}
}

void GroupList::addUserToGroup(User* user, string name)
{
	groups[contain(name)-1].addUserToGroup(user);
}

void GroupList::resize()
{
	capacity *= 2;
	Groups* temp = new Groups[capacity];
	memcpy(temp,groups,length);
	delete[] groups;
	groups = temp;
}
