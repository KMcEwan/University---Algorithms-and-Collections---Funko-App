#pragma once
#include "encryptionParse.h"

// Encryption of username and password
long long encrypted(int letter)
{		
	return powf(letter, 6) * 204 * 190 + 118;	
}
//Decrytion of username & password
int decrypted(long long letter)
{	
	return powf((letter - 118) / 190 / 204, 1 / 6.0f);	
}

// Parse the file for username and password
int parseFile(string userNameEntry, const char* fileName)
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