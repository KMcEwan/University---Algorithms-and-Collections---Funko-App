#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Hash.h"

using namespace std;

class user
{

private:

public:

	user();
	//~user();

	void searchPopByName(hashTable& hash);
	void searchPopByTag(hashTable& hash);
};
#endif // !USER_H
