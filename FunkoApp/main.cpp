#include <iostream>
#include "hash.h"
#include <algorithm>


using namespace std;

int main()
{
	hashTable hash;
	//hash.printTable();
	string name ="";
	//hash.addPop("IronMan", "Marvel");
	//hash.addPop("IronaMn", "Marvel");
	//hash.addPop("Han Solo", "Star Wars");
	//hash.addPop("Dogmeat", "Fallout");

	//hash.printTable();

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

	system("pause");

}
