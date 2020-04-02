#include "guestUser.h"

void guestUser::createAccount()
{
	string userName, password;
	cout << "Create a username and password\n";
	cin >> userName >> password;


	if (checkFile(userName, "../userNameDatabase.txt") != 0)
	{
		cout << "That username is not available, please try again\n";
		return;
	}

	int id = 1 + getID();
	saveFile(userName, "../userNameDatabase.txt", id);
	saveFile(password, "../passwordDatabase.txt", id);

	cout << "Account created\n.";
}

void guestUser::saveFile(string line, const char * fileName, const int & id)
{
	fstream file;
	file.open(fileName, ios::app);
	file.seekg(0, ios::end);

	if (file.tellg() != 0)
		file << "\n";

	file.seekg(0, ios::beg);

	for (int i = 0; i < line.length(); i++)
	{
		file << encrypted(line[i]);
		file << "\n";
	}

	file << "#ID:" << id;
	file.close();
}

int guestUser::getID()
{
	fstream file;
	file.open("../userNameDatabase.txt", ios::in);
	file.seekg(0, ios::end);

	if (file.tellg() == -1)
		return 0;

	string IDstring;

	for (int i = -1; IDstring.find("#") == string::npos; i--)
	{
		file.seekg(i, ios::end);
		file >> IDstring;
	}

	file.close();
	IDstring.erase(0, 4);

	int id;
	istringstream(IDstring) >> id;

	return id;
}
