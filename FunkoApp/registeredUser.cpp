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
