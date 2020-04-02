#pragma once
#include <iostream>
#include "user.h"
#include "encryptionCheckFile.h"

using namespace std;

class registeredUser : public user
{
public:
	void login();
	void logout();
//	int checkFile(string userNameEntry, const char* fileName);
//	long long encrypted(int letter);
	//int decrypted(long long letter);
private:
	bool loggedIn;
	string userName_Attempted;
	string password_Attempted;
};