#include "registeredUser.h"

void registeredUser::login()
{
	if (loggedIn == false)
	{
		cout << "Please enter your username and password\n";
		cout << "Username: ";
		cin >> userName_Attempted;
		cout << "Password: ";
		cin >> password_Attempted;

		int userNameID = parseFile(userName_Attempted, "../userNameDatabase.txt");

		if (userNameID != 0)
		{
			int passwordID = parseFile(password_Attempted, "../passwordDatabase.txt");
			if (userNameID == passwordID)
			{
				cout << "\nYou have successfully logged in. \n\nWelcome " << userName_Attempted << "\n\n";
				loggedIn = true;
			}
			else
			{																											
				while (exitLogin != 'Y' || exitLogin != 'N' || exitLogin != 'n' || exitLogin != 'y')								// Invalid password
				{	
					cout << "Loin failed, Would you like to try again? Y / N \n";
					cin >> exitLogin;

					if (exitLogin == 'Y' || exitLogin == 'y')
					{
						login();
					}
					else if (exitLogin == 'N' || exitLogin == 'n')
					{
						break;
					}
					else
					{
						cout << "Please make a valid selection\n. ";
						cin.clear();
						cin.ignore(9999, '\n');
					}
				}
			}
		}
		else
		{
			
			while (exitLogin != 'Y' || exitLogin != 'N' || exitLogin != 'n' || exitLogin != 'y')									//Invalid username
			{
				cout << "Invalid username, Would you like to try again? Y / N \n";
				cin >> exitLogin;

				if (exitLogin == 'Y' || exitLogin == 'y')
				{
					login();
				}
				else if (exitLogin == 'N' || exitLogin == 'n')
				{
					break;
				}
				else
				{
					cout << "Please make a valid selection\n. ";
					cin.clear();
					cin.ignore(9999, '\n');
				}
			}
					   		
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
