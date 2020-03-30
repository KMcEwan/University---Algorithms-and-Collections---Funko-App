#include <iostream>
#include "hash.h"
#include "user.h"
#include "loginManager.h"



using namespace std;


void menuSelection(user user1, hashTable hash);

int main()
{
	/*hashTable hash;
	user user1;
	
	menuSelection(user1, hash);
	system("pause");*/

	loginManager login;

	login.createUser();
	login.login();
	system("pause");
}
void menuSelection(user user1, hashTable hash)
{
	
	int i;
	cout << "1: View all pops\n";
	cout << "2: Search for pops by name\n";
	cout << "3: Search for pops by tags\n";
	cin >> i;
	switch (i)
	{
	case 1:
		user1.printAllTable(hash);
		menuSelection(user1, hash);
		break;
	case 2:
		user1.searchPopByName(hash);
		menuSelection(user1, hash);;
		break;
	case 3:
		user1.searchPopByTag(hash);
		menuSelection(user1, hash);
		break;
	default:
		cout << "Invalid selection\n";
		menuSelection(user1, hash);
		break;
	}
};