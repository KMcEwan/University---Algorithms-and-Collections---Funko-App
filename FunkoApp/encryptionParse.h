#pragma once
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>


using namespace std;

long long encrypted(int letter);
int decrypted(long long letter);
int parseFile(string userNameEntry, const char* fileName);