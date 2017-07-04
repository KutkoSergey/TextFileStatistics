#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string readTextFromFile(string nameOfFile);
void  getNumbSentencesAndWords(string textString, int &numbOfSentences, int &numbOfWords);
bool checkSymbol(char symbol, string checkingString);

extern "C"
__declspec(dllexport)
void getStatistic(char * nameOfFile,  int &numbOfWords, int &numbOfSentences)
{
	string nameOfFileString = (string) nameOfFile;
	string textString = readTextFromFile(nameOfFileString);
	getNumbSentencesAndWords(textString, numbOfSentences, numbOfWords);
	textString.clear();
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
	for (int i = 0; i < textString.size(); i++)
	{
		if (checkSymbol(textString.at(i), checkingStringForSentences))
			if (!checkSymbol(textString.at(i - 1), checkingStringForSentences))
				numbOfSentences++;
		if (checkSymbol(textString.at(i), checkingStringForWords))
			if (!checkSymbol(textString.at(i - 1), checkingStringForWords))
				numbOfWords++;
	}
	if (numbOfWords == 0)
		numbOfWords = 55;
	checkingStringForSentences.clear();
	checkingStringForWords.clear();
}

string readTextFromFile(string nameOfFile)
{
	ifstream  file(nameOfFile);
	string tempString, textString;
	while (getline(file, tempString))
	{
		textString += tempString;
	}
	file.close();
	tempString.clear();
	return textString;
}