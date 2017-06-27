#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string readTextFromFile();
bool checkSymbol(char symbol, string checkingString);
void getNumbSentencesAndWords(string textString, int &numbOfSentences, int &numbOfWords);

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

bool checkSymbol(char symbol, string checkingString)
{
	for (int i = 0; i < checkingString.size();i++)
		if (symbol == checkingString[i])
			return true;
	return false;
}

void getNumbSentencesAndWords(string textString, int &numbOfSentences, int &numbOfWords)
{
	string checkingStringForSentences = "!.?";
	string checkingStringForWords = "!.?;:,^&*=+- ";
	for (int i = 0; i < textString.size(); i++) {
		if (checkSymbol(textString.at(i), checkingStringForSentences))
			if (!checkSymbol(textString.at(i - 1), checkingStringForSentences))
				numbOfSentences++;
		if (checkSymbol(textString.at(i), checkingStringForWords))
			if (!checkSymbol(textString.at(i - 1), checkingStringForWords))
				numbOfWords++;
	}
}

int main()
{
	string textString;
	int numbOfSentences = 0, numbOfWords = 0;
	textString = readTextFromFile();
	cout << textString << endl;
	getNumbSentencesAndWords(textString, numbOfSentences, numbOfWords);
	cout << numbOfSentences << endl;
	cout << numbOfWords << endl;
	system("pause");
	return 0;
}