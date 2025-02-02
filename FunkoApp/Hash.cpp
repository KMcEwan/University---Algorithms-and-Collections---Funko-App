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
	string nameDesc;
	string number;
	string tag;
	string status;
	string price;
	popData.open("../popData.txt");
	if (popData.fail())
	{
		cout << "File failed" << endl;
		exit(1);
	}	

	while (!popData.eof())
	{		
		getline(popData, name);		
		getline(popData, nameDesc);
		getline(popData, number);
		getline(popData, tag);
		getline(popData, status);
		getline(popData, price);
		addPop(name, nameDesc, number, tag, status, price);
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

// Hashing function to determine the bucket for each of the pops
int hashTable::hashfunction(string name)
{
	int hashfunction = 0;
	int bucket;

	for (int i = 0; i < name.length(); i++)
	{
		hashfunction = hashfunction + (int)name[i] + hashfunction /2;																
	}
	
	bucket = hashfunction % TABLE_SIZE;

	return bucket;

}


void hashTable::addPop(string name, string nameDesc, string number, string tag, string status, string price)
{	
	hashNode *temp = new hashNode(name, nameDesc, number, tag, status, price);
	int location = hashfunction(name);
	temp->next = table[location];
	table[location] = temp;	

}

void hashTable::printTable()
{	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (hashNode *p = table[i]; p; p = p->next) {
			cout << "Name = " << p->name  << " " << p->nameDesc <<"\n" << "Number = " << p->number << "\n" << "Tag = " << p->tag << "\n" << "Status = " << p->status << "\n" << "Price = " << p->price << "\n\n";
		}
	}

}

// Search for pop by name function, takes in users input of pops name and output pops data that matches user input. 
void hashTable::searchForPop(string passedName)
{	
	int bucket = hashfunction(passedName);																							// De-hashing to find bucket number
	
	for (hashNode *p = table[bucket]; p; p = p->next)
	{
		if (passedName == p->name)
		{
			cout << "Name = " << p->name << " " << p->nameDesc <<"\n"<< "Number = " << p->number <<"\n"<< "Tag = " << p->tag << "\n" << "Status = " << p->status << "\n" << "Price = " << p->price <<"\n\n";
		}
	}
}

void hashTable::searchByTag(string tag)
{	

	for (int i = 0; i < TABLE_SIZE; i++)
	{  
		for (hashNode *p = table[i]; p; p = p->next)
		{
			size_t found = p->tag.find(tag);
			if (found != string::npos)
			{
				cout << "Name = " << p->name << " " << p->nameDesc <<"\n"<< "Number = " << p->number << "\n" << "Tag = " << p->tag << "\n" << "Status = " << p->status << "\n" << "Price = " << p->price << "\n\n";
			}
		}
	}
}

// Only for debugging purposes. Prints the pops details and their corresponding buckets
void hashTable::showBuckets()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		for (hashNode *p = table[i]; p; p = p->next) {
			cout << "bucket " << i << " name = " << p->name << " " << p->nameDesc << "Number " << p->number
				<< ". tag = " << p->tag << " status = " << p->status << ". price = " << p->price << endl;
		}
	}
}




