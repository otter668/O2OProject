#pragma once
#include "Activity.h"
class ActivityList
{
public:
	ActivityList(void);
	ActivityList(int);
	~ActivityList(void);

	// 获取数组长度
	inline int size(){return length;}
	// 获取指定位置元素
	inline Activity* at(int index) const {return &activitys[index-1];}
	// 是否包含指定名称元素，并返回其位置[0,length]
	const int contain(string) const;
	// 添加新活动
	void addActivity(Activity*);
	// 添加用户到指定名称活动
	void addUserToActivity(User*, string);
	void ShowAll() const;
private:
	int length;
	int capacity;
	Activity* activitys;

	void resize();
};

