#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class loginManager
{
public:
	loginManager()
	{
		accessGranted = 0;
	}

	void login();
	void createUser();	
	void saveFile(string line, const char* fileName, const int& id);
	int getID();
	int checkFile(string userNameEntry, const char* fileName);
	long long encrypted(int letter);
	int decrypted(long long letter);

private:
	string userName_Attempted;
	string password_Attempted;
	bool accessGranted;
};
