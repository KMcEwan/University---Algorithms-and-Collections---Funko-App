#pragma once
#include <iostream>
#include "user.h"
#include "registeredUser.h"
#include "encryptionParse.h"
#include <conio.h>
#include <string>

using namespace std;

class guestUser : public user
{
public:
	void createAccount();
	void saveFile(string line, const char* fileName, const int& id);
	int getID();
private:
	string userName = "userName";
	string password = "password";
	string passwordConfirmation = "passwordConfirmation";

};