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
		default: cout << "无效操作！请重新选择。\n";PAUSE;
		}
		PC;
	}
}

void Member::showMenu()
{
	CLS;
	cout << "欢迎会员:" << name << "\n";
	cout << "1.查看所有群\n";
	cout << "2.加入群组\n";
	cout << "3.查看群信息并加入该群的活动\n";
	cout << "4.查看可以预约的教练信息，并预约教练\n";
	cout << "5.查看已经预约的教练列表\n";
	cout << "6.退出\n";
	cout << "请选择：";
}

void Member::showAllGroup() const
{
	dp->showAllGroup();
}

void Member::joinGroup()
{
	string groupsName;
	cout << "请输入要加入的群组名称(不知道有哪些群组，输入1)：";
	cin >> groupsName;
	if (groupsName == "1")
	{
		showAllGroup();
		cout << "请输入要加入的群组名称：";
		cin >> groupsName;
	}
	if(dp->joinGrop(this, groupsName))
	{
		cout << "加入成功！" << endl;
	}
	else
	{
		cout << "加入失败！并不存在该群组，请重新加入其它群组！" << endl;
	}
}

void Member::joinActivity()
{
	string groupName;
	string activityName;
	if (!dp->showMyGroup(this))
	{
		cout << "暂无数据！" << endl;
		return;
	}
	cout << "请输入要参加的活动所在的群名称：";
	cin >> groupName;
	cout << "请输入活动名称：";
	cin >> activityName;
	if(dp->joinActivity(this, groupName, activityName))
	{
		cout << "加入成功！" << endl;
	}
	else
	{
		cout << "加入失败！并不存在该群组或者活动，请重新加入其它群组的活动！" << endl;
	}
}

void Member::appointmentCoache(User* user)
{
	cout << "编号\t时长\t开始时间\t结束时间\t价格\n";
	if (!dp->showAllAppointment(user))
	{
		cout << "暂无数据！" << endl;
		return;
	}
	string id;
	cout << "请输入预约编号：";
	cin >> id;
	if(dp->joinAppointment(user, id))
	{
		cout << "预约成功！" << endl;
	}
	else
	{
		cout << "预约失败！" << endl;
	}
}

void Member::getAppointment(const User* user)
{
	cout << "编号\t时长\t开始时间\t结束时间\t价格\n";
	dp->getAppointment(user);
}
