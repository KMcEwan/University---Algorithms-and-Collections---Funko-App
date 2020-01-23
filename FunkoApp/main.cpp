#include <iostream>
#include "hash.h"


using namespace std;

int main()
{
	hashTable hash;
	//hash.printTable();

	hash.addPop("IronMan", "Marvel");
	hash.addPop("IronaMn", "Marvel");
	hash.addPop("Han Solo", "Star Wars");
	hash.addPop("Dogmeat", "Fallout");

	hash.printTable();

	system("pause");

}
