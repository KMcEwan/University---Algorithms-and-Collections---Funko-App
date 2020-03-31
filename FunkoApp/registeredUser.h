#pragma once
#include <iostream>
#include "user.h"

using namespace std;

class registeredUser : public user
{
public:
	void login();
	void logout();
private:

};