#include "StdAfx.h"
#include "DataProvider.h"
#include "UserList.h"
#include "GroupList.h"
#include "ActivityList.h"
#include "AppointmentList.h"

DataProvider::DataProvider(void)
{
	userList = new UserList();
	groupList = new GroupList(10);
	appointmentList = new AppointmentList(10);
}


DataProvider::~DataProvider(void)
{
	if (userList!=nullptr)
	{
		delete userList;
		userList = nullptr;
	}
	if (groupList!=nullptr)
	{
		delete groupList;
		groupList = nullptr;
	}
	if (appointmentList!=nullptr)
	{
		delete appointmentList;
		appointmentList = nullptr;
	}
}

bool DataProvider::isUserExist(string name)
{
	return userList->contain(name);
}

void DataProvider::addUser(User* user)
{
	userList->addUser(user);
}

User* DataProvider::login(string name, string pwd)
{
	if (!isUserExist(name))
	{
		return false;
	}
	User *user = userList->getUser(name);
	if(user->verification(pwd))
	{
		return user;
	}
	else
	{
		return nullptr;
	}
}

bool DataProvider::addGroup(User* user, string name) const
{
	if (groupList->contain(name))
	{
		return false;
	}
	else
	{
		Groups *group = new Groups(name);
		group->addUserToGroup(user);
		groupList->addGroup(group);
		return true;
	}
}

bool DataProvider::joinGrop(User* user, string name) const
{
	int index = groupList->contain(name);
	if (groupList->contain(name))
	{
		groupList->addUserToGroup(user, name);
		return true;
	}
	else
	{
		return false;
	}
}

void DataProvider::showAllGroup() const
{
		if (groupList->size() == 0)
		{
			cout << "��������\n";
			return ;
		}
		for (int i=0;i!=groupList->size();i++)
		{
			groupList->at(i+1)->showGroupInfo();
		}
}

bool DataProvider::showMyGroup(const User* user) const
{
		bool flag = false;
		for (int i=0; i!=groupList->size(); i++)
		{
			Groups* group = groupList->at(i+1);
			UserList* userList = group->getGroupUsers();
			if (userList->contain(user->getName()))
			{
				flag = true;
				group->showGroupInfo();
			}
		}
		return flag;
}

bool DataProvider::joinActivity(User* user, string groupName, string activityName)
{
	int gIndex = groupList->contain(groupName);
	if (!gIndex)
	{
		cout << "δ�ҵ�Ⱥ�飺" << groupName << endl;
		return false;
		
	}
	Groups* group = groupList->at(gIndex);
	if (!group->getGroupUsers()->contain(user->getName()))
	{
		cout << "�㻹δ��������Ϊ��" << groupName << "��С�飬���ܼ���˻��"<< endl;
		return false;
	}
	int aIndex = group->getGroupActivitys()->contain(activityName);
	if (!aIndex)
	{
		cout << "δ�ҵ����" << activityName << endl;
		return false;
	}
	Activity* activity = group->getGroupActivitys()->at(aIndex);
	activity->addUserToActivity(user);
	return true;
}

bool DataProvider::AddAppointment(User* user, Appointment* app)
{
	if (appointmentList->contain(app->getId()))
	{
		cout << "�˱���Ѵ��ڻ�����˽��ռ�ã��뻻�����" << endl;
		return false;
	}
	app->addUserToAppointment(user);
	appointmentList->addAppointment(app);
	return true;
}

bool DataProvider::joinAppointment(User* user, string id)
{
	for (int i=0;i!=appointmentList->size();i++)
	{
		Appointment* app = appointmentList->at(i+1);
		if (app->getId() == id)
		{
			app->addUserToAppointment(user);
			return true;
		}
	}
	return false;
}

void DataProvider::getAppointment(const User* user)
{
	for (int i=0;i!=appointmentList->size();i++)
	{
		Appointment *app = appointmentList->at(i+1);
		if (app->getUserList()->contain(user->getName()))
		{
			app->showAppointmentInfo(user);
		}
	}
}

int DataProvider::showAllAppointment(const User* user) const
{
	for (int i=0;i!=appointmentList->size();i++)
	{
		appointmentList->at(i+1)->showAppointmentInfo(user);
	}
	return appointmentList->size();
}

bool DataProvider::addActivity(User* user, string groupName, Activity* activity)
{
	int gIndex = groupList->contain(groupName);
	if (!gIndex)
	{
		cout << "δ�ҵ�Ⱥ�飺" << groupName << endl;
		return false;
	}
	Groups* group = groupList->at(gIndex);
	if (!group->getGroupUsers()->contain(user->getName()))
	{
		cout << "�㲻�Ǹ�Ⱥ:" << groupName << "��Ⱥ�����������Ⱥ�"<< endl;
		return false;
	}
	int aIndex = group->getGroupActivitys()->contain(activity->getActivityName());
	if (aIndex)
	{
		cout << "�Ѵ��ڣ�" << activity->getActivityName() << "��������ظ�������" << endl;
		return false;
	}
	group->addActivity(activity);
	return true;
}
