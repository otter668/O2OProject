#pragma once
#include "Activity.h"
class ActivityList
{
public:
	ActivityList(void);
	ActivityList(int);
	~ActivityList(void);

	// ��ȡ���鳤��
	inline int size(){return length;}
	// ��ȡָ��λ��Ԫ��
	Activity* at(int) const;
	// �Ƿ����ָ������Ԫ�أ���������λ��[0,length]
	const int contain(string) const;
	// ����»
	void addActivity(Activity*);
	// ����û���ָ�����ƻ
	void addUserToActivity(User*, string);
	void ShowAll() const;
private:
	int length;
	int capacity;
	Activity* activitys;

	void resize();
};

