#pragma once
#include <list>
#include <string>

using namespace std;

class hashNode
{
	public:
		string name;
		string type;
		hashNode *next;
	
		hashNode(string name, string type)
		{
			this->name = name;
			this->type = type;
			next = NULL;
		}

		string getName() 
		{
			return name;
		}

		string getType() 
		{
			return type;
		}

		void setType(string type)
		{
			this->type = type;
		}

		hashNode *getNext()
		{
			return next;
		}
			
		void setNext(hashNode *next)
		{
			this->next = next;
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
		void addPop(string name, string type);
		void printTable();


};