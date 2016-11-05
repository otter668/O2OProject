#include "StdAfx.h"
#include "Member.h"


Member::Member(void)
{
}


Member::~Member(void)
{
}

void Member::selectItem()
{
	int choice;
	while (true)
	{
		showMenu();
		cin >> choice;
		switch(choice)
		{
		case 1: showAllGroup();break;
		case 2: joinGroup();break;
		case 3: joinActivity();break;
		case 4: appointmentCoache(this);break;
		case 5: getAppointment(this);break;
		case 6: return ;
		default: cout << "��Ч������������ѡ��\n";PAUSE;
		}
		PC;
	}
}

void Member::showMenu()
{
	CLS;
	cout << "��ӭ��Ա:" << name << "\n";
	cout << "1.�鿴����Ⱥ\n";
	cout << "2.����Ⱥ��\n";
	cout << "3.�鿴Ⱥ��Ϣ�������Ⱥ�Ļ\n";
	cout << "4.�鿴����ԤԼ�Ľ�����Ϣ����ԤԼ����\n";
	cout << "5.�鿴�Ѿ�ԤԼ�Ľ����б�\n";
	cout << "6.�˳�\n";
	cout << "��ѡ��";
}

void Member::showAllGroup() const
{
	dp->showAllGroup();
}

void Member::joinGroup()
{
	string groupsName;
	cout << "������Ҫ�����Ⱥ������(��֪������ЩȺ�飬����1)��";
	cin >> groupsName;
	if (groupsName == "1")
	{
		showAllGroup();
		cout << "������Ҫ�����Ⱥ�����ƣ�";
		cin >> groupsName;
	}
	if(dp->joinGrop(this, groupsName))
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ��������ڸ�Ⱥ�飬�����¼�������Ⱥ�飡" << endl;
	}
}

void Member::joinActivity()
{
	string groupName;
	string activityName;
	if (!dp->showMyGroup(this))
	{
		cout << "�������ݣ�" << endl;
		return;
	}
	cout << "������Ҫ�μӵĻ���ڵ�Ⱥ���ƣ�";
	cin >> groupName;
	cout << "���������ƣ�";
	cin >> activityName;
	if(dp->joinActivity(this, groupName, activityName))
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ�ܣ��������ڸ�Ⱥ����߻�������¼�������Ⱥ��Ļ��" << endl;
	}
}

void Member::appointmentCoache(User* user)
{
	cout << "���\tʱ��\t��ʼʱ��\t����ʱ��\t�۸�\n";
	if (!dp->showAllAppointment(user))
	{
		cout << "�������ݣ�" << endl;
		return;
	}
	string id;
	cout << "������ԤԼ��ţ�";
	cin >> id;
	if(dp->joinAppointment(user, id))
	{
		cout << "ԤԼ�ɹ���" << endl;
	}
	else
	{
		cout << "ԤԼʧ�ܣ�" << endl;
	}
}

void Member::getAppointment(const User* user)
{
	cout << "���\tʱ��\t��ʼʱ��\t����ʱ��\t�۸�\n";
	dp->getAppointment(user);
}
