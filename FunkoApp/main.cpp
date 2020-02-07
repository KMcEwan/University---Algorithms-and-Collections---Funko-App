#include <iostream>
#include "hash.h"
#include "user.h"



using namespace std;

int main()
{
	
	hashTable hash;
	user user1;
	user1.searchPopByName(hash);
	user1.searchPopByTag(hash);
	

	//hash.printTable();







	system("pause");

}
