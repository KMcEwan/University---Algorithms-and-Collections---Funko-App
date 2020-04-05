#include "user.h"

void user::searchPopByName(hashTable& hash)
{	
	string name = "";
	bool searchAgainName = true;
	while (searchAgainName == true)
	{		
		//cin.clear();
		cin.ignore();
		cout << "Enter a pops name to search for ";
		
		getline(cin, name);

		for_each(name.begin(), name.end(), [](char & c) {
			c = ::toupper(c);
		});


		if (name != "")
		{
			hash.searchForPop(name);
		}

		cout << "Search again? Y / N \n";
		char searchInputName;
		cin >> searchInputName;
		cout << "\n";
		searchInputName = toupper(searchInputName);

		if (searchInputName == 'Y')
		{
			searchAgainName == true;
		}
		else if (searchInputName == 'N')
		{			
			searchAgainName == false;
			break;
		}
		else 
		{			
			cout << "invalid input try again ";
			cin >> searchInputName;
		}

	}
}

void user::searchPopByTag(hashTable& hash)
{
	string tag = "";
	bool searchAgainTag = true;
	
	while (searchAgainTag == true)
	{
		
		cout << "Enter a tag to search for ";
		cin.ignore(9999, '/n');
		getline(cin, tag);
		
		for_each(tag.begin(), tag.end(), [](char & c) {
			c = ::toupper(c);
		});


		if (tag != "")
		{
			hash.searchByTag(tag);
		}

		cout << "Search again? Y / N \n";
		char searchInputTag;
		cin >> searchInputTag;
		cout << "\n";
		searchInputTag = toupper(searchInputTag);

		if (searchInputTag == 'Y')
		{
			searchAgainTag == true;
		}
		else if (searchInputTag == 'N')
		{
			searchAgainTag == false;
			break;
		}
		else
		{
			cout << "invalid input try again ";
			cin >> searchInputTag;
		}
	}
}

void user::printAllTable(hashTable & hash)
{
	cout << "\n";
	hash.printTable();
}
