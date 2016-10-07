#pragma once
#include "Groups.h"
class GroupList
{
public:
	GroupList(void);
	GroupList(int);
	~GroupList(void);

	// ��ȡ���鳤��
	inline int size(){return length;}
	// ��ȡָ��λ��Ԫ��
	Groups* at(int) const;
	// �Ƿ����ָ������Ԫ�أ���������λ��[0,length]
	const int contain(string) const;
	// �����Ⱥ��
	void addGroup(Groups*);
	// ����û���ָ������Ⱥ��
	void addUserToGroup(User*, string);
private:
	int length;
	int capacity;
	Groups* groups;
	void resize();
};

