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
		/*popData >> name >> tag;
		addPop(name, tag);*/
		getline(popData, name);
		//cout << "name :" << name << endl;
		getline(popData, tag);
		//cout << "tag : " << tag << endl;
		getline(popData, status);
		//cout << "name :" << name << endl;
		getline(popData, price);
		//cout << "tag : " << tag << endl;
		addPop(name, tag, status, price);
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
		//cout << "hash =	" << hash << endl;
	}

	bucket = hash % TABLE_SIZE;

	return bucket;
}

void hashTable::addPop(string name, string tag, string status, string price)
{	
	hashNode *temp = new hashNode(name, tag, status, price);
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
				<< ". tag = " << p->tag << " status = " << p->status << ". price = " << p->price <<	endl;
		}
	}

}

void hashTable::searchForPop(string passedName)
{
	int bucket = hash(passedName);

	//for (int i = 0; i < TABLE_SIZE; i++)
	//{
		for (hashNode *p = table[bucket]; p; p = p->next)
		{
			if (passedName == p->name)
			{
				cout << "name : " << p->name << " Tag : " << p->tag << " Status : " << p->status << " Price : " << p->price << "\n";
			}
		}
//	}








	/*bool foundPop = false;
	string popName;
	string popTags;
	string popStatus;
	string popPrice;

	hashNode *Ptr = table[bucket]; 
	while (Ptr != NULL)
	{
		if (Ptr->name == passedName)
		{
			foundPop = true;
			popName = Ptr->name;
			popTags = Ptr->tag;
			popStatus = Ptr->status;
			popPrice = Ptr->price;
		}
		Ptr = Ptr->next;
	}
	if (foundPop == true)
	{
		cout << " pop found" << endl; 
		cout << "Name : " << popName << " Tags : " << popTags << " Status : " << popStatus << " Price : " << popPrice << endl;
	}
	else
	{
		cout << passedName << " not found	" << endl;
	}*/
}
//
//void hashTable::searchByTag(string tag)
//{
//	//int bucket = hash(tag);
//
//	for (int i = 0; i < TABLE_SIZE; i++)
//	{
//		for (hashNode *p = table[i]; p; p = p->next)
//		{
//			if (tag == p->tag)
//			{
//				cout << "name : " << p->name << " Tag : " << p->tag << " Status : " << p->status << " Price : " << p->price << "\n";
//			}
//		}
//	}
//}


