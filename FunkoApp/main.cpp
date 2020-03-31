#include <iostream>
#include "hash.h"
#include "user.h"
#include "loginManager.h"



using namespace std;


void menuSelection(user userSystem, hashTable hash, loginManager loginSystem);

int main()
{
	hashTable hash;
	user userSystem;
	loginManager loginSystem;
	menuSelection(userSystem, hash, loginSystem);
	system("pause");


	system("pause");
}
void menuSelection(user userSystem, hashTable hash, loginManager loginSystem)
{
	
	int i;
	cout << "1: Create an account\n";
	cout << "2: Login\n";
	cout << "3: Show all pops\n";
	cout << "4: Search for pops by name\n";
	cout << "5: Search for pops by tags\n";
	cout << "6: Logout\n";
	cin >> i;
	switch (i)
	{
	case 1:
		cin.clear();
		cin.ignore(9999, '\n');
		loginSystem.createUser();
		menuSelection(userSystem, hash, loginSystem);
		break;
	case 2:
		cin.clear();
		cin.ignore(9999, '\n');
		loginSystem.login();
		menuSelection(userSystem, hash, loginSystem);
		break;
	case 3:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.printAllTable(hash);
		menuSelection(userSystem, hash, loginSystem);
		break;
	case 4:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.searchPopByName(hash);
		menuSelection(userSystem, hash, loginSystem);;
		break;
	case 5:
		cin.clear();
		cin.ignore(9999, '\n');
		userSystem.searchPopByTag(hash);
		menuSelection(userSystem, hash, loginSystem);
		break;
	case 6:
		loginSystem.logout();
		menuSelection(userSystem, hash, loginSystem);
		break;
	default:		
		//if (cin.eof())
			//return;
		cout << "Invalid selection\n";
		cin.clear();
		cin.ignore(9999, '\n');
		menuSelection(userSystem, hash, loginSystem);
		break;
	}
};

