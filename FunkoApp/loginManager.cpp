#include "loginManager.h"

void loginManager::login()
{
	if (loggedIn == false)
	{
		cout << "Please enter your username and password\n";
		cout << "Username: ";
		cin >> userName_Attempted;
		cout << "Password: ";
		cin >> password_Attempted;

		int userNameID = checkFile(userName_Attempted, "../userNameDatabase.txt");

		if (userNameID != 0)
		{
			int passwordID = checkFile(password_Attempted, "../passwordDatabase.txt");
			if (userNameID == passwordID)
			{
				cout << "Welcome " << userName_Attempted << "\n";
				loggedIn = true;
			}
			else
			{
				cout << "Invalid login, please try again\n";
				login();
			}
		}
		else
		{
			cout << "Invalid username, please try again\n";
			login();
		}
	}
	else
	{
		cout << "You are already logged in " << userName_Attempted << "\n\n";
	}
	
}

void loginManager::createUser()
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
}

void loginManager::saveFile(string line, const char * fileName, const int & id)
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

int loginManager::getID()
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

int loginManager::checkFile(string userNameEntry, const char* fileName)
{
	string line;
	fstream file;

	string currentChar;
	long long encryptedChar;

	file.open(fileName, ios::in);
	
	while (true)
	{
		file >> currentChar;
		if (currentChar.find("#ID:") != string::npos)
		{
			if (userNameEntry == line)
			{
				file.close();
				currentChar.erase(0, 4);
				int id;
				istringstream(currentChar) >> id;
				return id;
			}
			else
			{
				line.erase(line.begin(), line.end());
			}
		}
		else
		{
			istringstream(currentChar) >> encryptedChar;
			line += (char)decrypted(encryptedChar);
			currentChar = "";
				
		}
		if (file.peek() == EOF)
		{
			file.close();
			return 0;
		}
	}
}

long long loginManager::encrypted(int letter)
{
	return powf(letter, 5) * 4 - 14;
}

int loginManager::decrypted(long long letter)
{
	return powf((letter + 14) / 4, 1 / 5.0f);
}

void loginManager::logout()
{
	loggedIn = false;
	userName_Attempted == "";
}


