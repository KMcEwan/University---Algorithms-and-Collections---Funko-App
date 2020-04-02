#pragma once
#include <iostream>
#include "user.h"
#include "registeredUser.h"
#include "encryptionCheckFile.h"

using namespace std;

class guestUser : public user
{
public:
	void createAccount();
	void saveFile(string line, const char* fileName, const int& id);
	int getID();
private:

};