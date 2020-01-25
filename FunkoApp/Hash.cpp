#include <iostream>
#include "Hash.h"


//Create the hash table, populate with hashnodes all set to null
hashTable::hashTable()
{
	table = new hashNode * [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i] = NULL;
	}
		
	ifstream popData;
	string name;
	string tag;
	popData.open("../popData.txt");
	if (popData.fail())
	{
		cout << "File failed" << endl;
		exit(1);
	}	
	while (!popData.eof())
	{		
		/*popData >> name >> tag;
		addPop(name, tag);*/
		getline(popData, name);
		cout << "name :" << name << endl;
		getline(popData, tag);
		cout << "tag : " << tag << endl;
		addPop(name, tag);
	}
	popData.close();

}

hashTable::~hashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)

		if (table[i] != NULL)

			delete table[i];

	delete[] table;
}



int hashTable::hash(string name)
{
	int hash = 0;
	int bucket;

	for (int i = 0; i < name.length(); i++)
	{
		hash = hash + (int)name[i];
		cout << "hash =	" << hash << endl;
	}

	bucket = hash % TABLE_SIZE;

	return bucket;
}

void hashTable::addPop(string name, string tag)
{	
	hashNode *temp = new hashNode(name, tag);
	int location = hash(name);
	temp->next = table[location];
	table[location] = temp;

}

void hashTable::printTable()
{	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (hashNode *p = table[i]; p; p = p->next) {
			cout << "bucket " << i << " name = " << p->name
				<< ". tag = " << p->tag << endl;
		}
	}

}

