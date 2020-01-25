#pragma once
#include <list>
#include <string>
#include <fstream>

using namespace std;

class hashNode
{
	public:
		string name;
		string tag;
		hashNode *next;
	
		hashNode(string name, string tag)
		{
			this->name = name;
			this->tag = tag;
			next = NULL;
		}

		
};

class hashTable
{
	private:
		hashNode **table;

	public:
		const int TABLE_SIZE = 10;
		hashTable();
		~hashTable();

		int hash(string name);
		void addPop(string name, string tag);
		void printTable();


};