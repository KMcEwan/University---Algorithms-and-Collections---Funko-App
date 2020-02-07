#include "user.h"

user::user()
{
	cout << "Welcome User" << endl;
}

void user::searchPopByName(hashTable& hash)
{
	string name = "";

	while (name != "exit")
	{
		cout << "search for ";
		getline(cin, name);

		for_each(name.begin(), name.end(), [](char & c) {
			c = ::toupper(c);
		});


		if (name != "exit")
		{
			hash.searchForPop(name);
		}
	}
}

void user::searchPopByTag(hashTable& hash)
{
	string tag = "";
	while (tag != "exit")
	{
		cout << "search for ";
		getline(cin, tag);

		for_each(tag.begin(), tag.end(), [](char & c) {
			c = ::toupper(c);
		});


		if (tag != "exit")
		{
			hash.searchByTag(tag);
		}
	}
}