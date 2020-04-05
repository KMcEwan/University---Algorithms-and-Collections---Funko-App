#include <iostream>
#include "hash.h"
#include "user.h"
#include "loginManager.h"
#include "guestUser.h"

using namespace std;

void menuSelection(user userSystem, hashTable hash, guestUser guestSystem, registeredUser regUser);
void guestMenu(user userSystem, hashTable hash);

int main()
{
	hashTable hash;
	user userSystem;
	guestUser guestSystem;
	registeredUser regUser;
	menuSelection(userSystem, hash, guestSystem, regUser);
	system("pause");
}

void menuSelection(user userSystem, hashTable hash, guestUser guestSystem, registeredUser regUser)
{
	cout << "Welcome\n\n";

	int menuSelect;
	cout << "1: Use as guest\n";
	cout << "2: Create an account\n";
	cout << "3: Login\n";

	cin >> menuSelect;
	cout << "\n";
	switch (menuSelect)
	{
	case 1:
		cin.clear();
		cin.ignore(9999, '\n');
		guestMenu(userSystem, hash);
		break;

	case 2:
		cin.clear();
		cin.ignore(9999, '\n');
		guestSystem.createAccount();
		regUser.login();
		guestMenu(userSystem, hash);
		break;

	case 3:
		cin.clear();
		cin.ignore(9999, '\n');
		regUser.login();
		guestMenu(userSystem, hash);
		break;

	default:				
		cout << "Invalid selection\n";
		cin.clear();
		cin.ignore(9999, '\n');
		menuSelection(userSystem, hash, guestSystem, regUser);
		break;
	}
};

void guestMenu(user userSystem, hashTable hash)
{
	int guestInput;

	cout << "1: Search pops by name\n";
	cout << "2: Seach pops by tags\n";
	cout << "3: View all pops\n";

	cin >> guestInput;

	switch (guestInput) 
	{
	case 1:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.searchPopByName(hash);
		guestMenu(userSystem, hash);
		break;

	case 2:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.searchPopByTag(hash);
		guestMenu(userSystem, hash);
		break;

	case 3:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.printAllTable(hash);
		guestMenu(userSystem, hash);
		break;
	default:
		cout << "Invalid selection\n";
		cin.clear();
		cin.ignore(9999, '\n');
		guestMenu(userSystem, hash);
		break;
	}
}

