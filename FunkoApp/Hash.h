#pragma once
#include <list>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

class  hashNode
{
	public:
		string name;
		string nameDesc;
		string number;
		string tag;
		string status;
		string price;
		hashNode *next;
	
		hashNode(string name, string nameDesc, string number, string tag, string status, string price)
		{
			this->name = name;
			this->nameDesc = nameDesc;
			this->number = number;
			this->tag = tag;
			this->status = status;
			this->price = price;

			next = NULL;
		}		
		
}; 

class hashTable
{
	private:
		hashNode **table;

	public:
		const int TABLE_SIZE = 30;
		hashTable();
		~hashTable();

		int hash(string name);
		void addPop(string name, string nameDesc, string number, string tag, string status, string price);
		void printTable();
		void searchForPop(string name);
		void searchByTag(string tag);
		void showBuckets();				
};