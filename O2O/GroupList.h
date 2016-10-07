#pragma once
#include "Groups.h"
class GroupList
{
public:
	GroupList(void);
	GroupList(int);
	~GroupList(void);

	// 获取数组长度
	inline int size(){return length;}
	// 获取指定位置元素
	Groups* at(int) const;
	// 是否包含指定名称元素，并返回其位置[0,length]
	const int contain(string) const;
	// 添加新群组
	void addGroup(Groups*);
	// 添加用户到指定名称群组
	void addUserToGroup(User*, string);
private:
	int length;
	int capacity;
	Groups* groups;
	void resize();
};

