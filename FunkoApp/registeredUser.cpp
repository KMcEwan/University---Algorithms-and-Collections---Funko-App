#include "registeredUser.h"
#include "loginManager.h"

void registeredUser::login()
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

void registeredUser::logout()
{
	
}
//
//int registeredUser::checkFile(string userNameEntry, const char* fileName)
//{
//	string line;
//	fstream file;
//
//	string currentChar;
//	long long encryptedChar;
//
//	file.open(fileName, ios::in);
//
//	while (true)
//	{
//		file >> currentChar;
//		if (currentChar.find("#ID:") != string::npos)
//		{
//			if (userNameEntry == line)
//			{
//				file.close();
//				currentChar.erase(0, 4);
//				int id;
//				istringstream(currentChar) >> id;
//				return id;
//			}
//			else
//			{
//				line.erase(line.begin(), line.end());
//			}
//		}
//		else
//		{
//			istringstream(currentChar) >> encryptedChar;
//			line += (char)decrypted(encryptedChar);
//			currentChar = "";
//
//		}
//		if (file.peek() == EOF)
//		{
//			file.close();
//			return 0;
//		}
//	}
//}
//
//long long registeredUser::encrypted(int letter)
//{
//	return powf(letter, 5) * 4 - 14;
//}
//
//int registeredUser::decrypted(long long letter)
//{
//	return powf((letter + 14) / 4, 1 / 5.0f);
//}
//
