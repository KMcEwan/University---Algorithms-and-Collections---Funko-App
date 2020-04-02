#pragma once
#include <iostream>
#include "user.h"
#include "encryptionCheckFile.h"

using namespace std;

class registeredUser : public user
{
public:
	registeredUser()
	{
		loggedIn = 0;
	}
	void login();
	void logout();

private:
	bool loggedIn;
	string userName_Attempted;
	string password_Attempted;
};