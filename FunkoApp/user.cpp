#include "user.h"

void user::searchPopByName(hashTable& hash)
{
	string name = "";
	bool searchAgainName = true;
	char searchInputName = ' ';																							// prompted input - for if wish to search again
	bool firstCheck = false;
	while (searchAgainName == true)
	{	
		if(firstCheck == 1)																								// Needed to ignore for first run.  
		{
			cin.ignore(9999, '\n');																							
		}
		firstCheck = true;
							
		cout << "Enter a pops name to search for ";
		
		getline(cin, name);

		for_each(name.begin(), name.end(), [](char & c) {
			c = ::toupper(c);
		});


		if (name != "")
		{
			hash.searchForPop(name);
		}

		while (searchInputName != 'N' || searchInputName != 'Y')														// Search again prompt
		{			
			cout << "Search again? Y / N " << endl;
			cin >> searchInputName;
						
			cout << "\n";
			searchInputName = toupper(searchInputName);

			if (searchInputName == 'Y')
			{
				searchAgainName = true;		
				break;
			}
			else if (searchInputName == 'N')
			{
				searchAgainName = false;
				break;
			}
			else
			{
				cout << "Invalid input. ";
				cin.clear();
				cin.ignore(9999, '\n');
			}
		}
	}
}


void user::searchPopByTag(hashTable& hash)
{
	string tag = "";
	bool searchAgainTag = true;
	char searchInputTag = ' ';																								// prompted input - for if wish to search again
	bool firstCheck = false;																
	while (searchAgainTag == true)
	{
		if (firstCheck == 1)																							
		{
			cin.ignore(9999, '\n');
		}
		firstCheck = true;
		cout << "Enter a tag to search for ";
		
		getline(cin, tag);
		
		for_each(tag.begin(), tag.end(), [](char & c) {
			c = ::toupper(c);
		});

		if (tag != "")
		{
			hash.searchByTag(tag);
		}

		while (searchInputTag != 'N' || searchInputTag != 'Y')																// Search again prompt
		{
			cout << "Search again? Y / N " << endl;
			cin >> searchInputTag;

			cout << "\n";
			searchInputTag = toupper(searchInputTag);

			if (searchInputTag == 'Y')
			{
				searchAgainTag = true;
				break;
			}
			else if (searchInputTag == 'N')
			{
				searchAgainTag = false;
				break;
			}
			else
			{
				cout << "Invalid input. ";
				cin.clear();
				cin.ignore(9999, '\n');
			}
		}
	}
}

void user::printAllTable(hashTable & hash)
{
	cout << "\n";
	hash.printTable();
}


