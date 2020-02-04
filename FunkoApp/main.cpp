#include <iostream>
#include "hash.h"
#include <algorithm>


using namespace std;

int main()
{
	hashTable hash;
	//hash.printTable();
	string name ="";
	string tag = "";
	//hash.addPop("IronMan", "Marvel");
	//hash.addPop("IronaMn", "Marvel");
	//hash.addPop("Han Solo", "Star Wars");
	//hash.addPop("Dogmeat", "Fallout");

	hash.printTable();

	//while (name != "exit")
	//{
	//	cout << "search for ";
	//	getline(cin, name);

	//	for_each(name.begin(), name.end(), [](char & c) {
	//		c = ::toupper(c);
	//	});


	//	if (name != "exit")
	//	{
	//		hash.searchForPop(name);
	//	}
	//}


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

	system("pause");

}
