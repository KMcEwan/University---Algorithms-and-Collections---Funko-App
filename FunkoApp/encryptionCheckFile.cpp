#pragma once
#include "encryptionCheckFile.h"

long long encrypted(int letter)
{
	return powf(letter, 5) * 4 - 14;
}

int decrypted(long long letter)
{
	return powf((letter + 14) / 4, 1 / 5.0f);
}

int checkFile(string userNameEntry, const char* fileName)
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