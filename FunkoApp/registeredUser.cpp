#include "registeredUser.h"

void registeredUser::login()
{
	if (loggedIn == true)																													// Checks if user is already logged in
	{
		cout << "You are already logged in as " << userNameAttempted << "\n\n";
	}
	else																								
	{
		int userNameID = 0;
		while (userNameID == 0)
		{
			cout << "Please enter your username and password to login\n";
			cout << "Username: ";
			cin >> userNameAttempted;
			int userNameID = parseFile(userNameAttempted, "../userNameDatabase.txt");
			while (userNameID != 0)
			{
				passwordAttempted = "";
				char astSymbol;																												// astSymbol = * symbol for password entry
				cout << "Password: ";
				astSymbol = _getch();
				while (astSymbol != 13)
				{
					passwordAttempted.push_back(astSymbol);
					cout << '*';
					astSymbol = _getch();
				}
				cout << "\n";
				int passwordID = parseFile(passwordAttempted, "../passwordDatabase.txt");
				if (userNameID == passwordID)
				{
					cout << "\nYou have successfully logged in. \n\nWelcome " << userNameAttempted << "\n\n";
					loggedIn = true;	
					goto exit;
				}
				else
				{
					cout << "Invalid password\n\n";
					goto tryAgain;
				}

				if (loggedIn == false)
				{
				tryAgain:
					cout << "Would you like to try to login again? Please enter Y to try again, or any other key to exit \n\n";
					cin.clear();																												// Clear stream
					cin.ignore(9999, '\n');
					cin >> exitAttempt;
					cout << "\n";
					exitAttempt = toupper(exitAttempt);
					if (exitAttempt != 'Y')
					{					
						goto exit;
					}
				}
			}	cout << "Invalid username, would you like to try to login again? Please enter Y to try again, or any other key to exit \n\n";
			cin.clear();																														// Clear stream
			cin.ignore(9999, '\n');
			cin >> exitAttempt;
			cout << "\n";
			exitAttempt = toupper(exitAttempt);
			if (exitAttempt != 'Y')
			{
				goto exit;
			}
			
		}

	}
	while (false)																																// While loop only used for the goto exit statement, while loop not actually reached
	{
	exit:
		cin.clear();
		cin.ignore(9999, '\n');
		break;
	}
}


