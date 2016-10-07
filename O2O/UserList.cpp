#include "StdAfx.h"
#include "UserList.h"


UserList::UserList(void)
{
	head = new Node;
	head->next = nullptr;
	length = 0;
}


UserList::~UserList(void)
{
	if(head!=nullptr)
	{
		Node *ptr = head->next;
		while(ptr!=nullptr)
		{
			delete head;
			head = ptr;
			ptr = ptr->next;
		}
		delete head;
		head = nullptr;
	}
}

bool UserList::contain(string name) const
{
	Node* ptr = head->next;
	while(ptr != nullptr)
	{
		if (ptr->user->getName() == name)
		{
			return true;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return false;
}

void UserList::addUser(User* user)
{
	Node* ptr = head;
	while(ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	Node* node = new Node;
	node->user = user;
	node->next = nullptr;
	ptr->next = node;
	length++;
}

User* UserList::getUser(string name)
{
	Node* ptr = head->next;
	while(ptr != nullptr)
	{
		if (ptr->user->getName() == name)
		{
			return ptr->user;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return nullptr;
}

void UserList::showAll() const
{
	Node* ptr = head->next;
	while(ptr != nullptr)
	{
		cout << ptr->user->getName() << "\t";
		ptr = ptr->next;
	}
	cout << endl;
}
