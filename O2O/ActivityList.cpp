#include "StdAfx.h"
#include "ActivityList.h"


ActivityList::ActivityList(void)
{
	activitys = nullptr;
}


ActivityList::ActivityList(int cap):length(0),capacity(cap)
{
	activitys = new Activity[cap];
}

ActivityList::~ActivityList(void)
{
	if (activitys!=nullptr)
	{
		delete[] activitys;
		activitys = nullptr;
	}
}

const int ActivityList::contain(string name) const
{
	for (int i=0;i!=length;i++)
	{
		if (activitys[i].getActivityName() == name)
		{
			return i+1;
		}
	}
	return 0;
}

void ActivityList::addActivity(Activity* activity)
{
	if (!contain(activity->getActivityName()))
	{
		int index = length == capacity ? resize(),length++ : length++;
		activitys[index] = *activity;
	}
}

void ActivityList::addUserToActivity(User* user, string name)
{
	activitys[contain(name)-1].addUserToActivity(user);
}

void ActivityList::ShowAll() const
{
	for (int i=0;i!=length;i++)
	{
		cout << activitys[i].getActivityName() << "\t";
	}
	cout << endl;
}

void ActivityList::resize()
{
	capacity *= 2;
	Activity* temp = new Activity[capacity];
	memcpy(temp,activitys,length);
	delete[] activitys;
	activitys = temp;
}
