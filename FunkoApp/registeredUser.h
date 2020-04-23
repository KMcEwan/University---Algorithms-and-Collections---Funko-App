#pragma once
#include <iostream>
#include "user.h"
#include "encryptionParse.h"
#include <conio.h>
#include <string>

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
	char exitLogin;
	string userName_Attempted;
	string password_Attempted;
};