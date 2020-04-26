#pragma once

#include "dog.h"
#include <vector>


class UserList
{
protected:
	std::vector<dog> userList;

public:
	UserList() {}

	std::vector<dog> getUserList() { return userList; }
	void add(dog &d) { userList.push_back(d); }
};