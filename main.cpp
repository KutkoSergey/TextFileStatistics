#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string readTextFromFile();

string readTextFromFile()
{
	ifstream  file("Data.txt");
	string tempString, textString;
	while (getline(file, tempString))
	{
		textString += tempString;
	}
	return textString;
}

int main()
{
	string textString;
	textString = readTextFromFile();
	cout << textString << endl;
	system("pause");
	return 0;
}