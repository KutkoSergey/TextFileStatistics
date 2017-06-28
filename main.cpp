#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string readTextFromFile();
bool checkSymbol(char symbol, string checkingString);
void getNumbSentencesAndWords(string textString, int &numbOfSentences, int &numbOfWords);
bool comparisonForSorting(pair< string, int > &a, pair< string, int > &b);
vector< pair < string, int > > getWords(string textString);

string readTextFromFile()
{
	ifstream  file("Data.txt");
	string tempString, textString;
	while (getline(file, tempString))
	{
		textString += tempString;
	}
	file.close();
	tempString.clear();
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
	checkingStringForSentences.clear();
	checkingStringForWords.clear();
}

bool comparisonForSorting (pair< string, int > &a, pair< string, int > &b )
{
	return a.second > b.second;
}
vector< pair < string, int > > getWords(string textString)
{
	string tempString;
	string checkingStringForWords = "!.?;:,^&*=+- ";
	map <string, int>  containerOfWords;
	for (int i = 0;i < textString.size(); i++)
	{
		if (!checkSymbol(textString.at(i), checkingStringForWords)) {
			tempString.push_back(textString.at(i));
		}
		else if (tempString.size() > 0)
		{
			if (containerOfWords.count(tempString) > 0)
				++containerOfWords[tempString];
			else
				containerOfWords.insert(std::pair<std::string, int>(tempString, 1));
			tempString.clear();
		}	
	}
	vector< pair < string, int > > vectorOfWords(containerOfWords.begin(), containerOfWords.end());
	sort(vectorOfWords.begin(), vectorOfWords.end(), comparisonForSorting);
	tempString.clear();
	checkingStringForWords.clear();
	containerOfWords.clear();
	return vectorOfWords;
}

int main()
{
	string textString;
	int numbOfSentences = 0, numbOfWords = 0;
	int i = 0;
	vector< pair < string, int > > vectorOfWords;
	textString = readTextFromFile();
	cout << textString << endl;
	getNumbSentencesAndWords(textString, numbOfSentences, numbOfWords);
	cout << "Numb of sentences are " << numbOfSentences << endl;
	cout << "Numb of words are " << numbOfWords << endl;
	vectorOfWords = getWords(textString);
	cout << setw(10)<< "Unique word" << setw(50) <<"Numb of this word in the text" << endl;
	for (auto it = vectorOfWords.begin(); it != vectorOfWords.end(), i<25; it++, i++)
		cout << setw(10) <<   it->first << setw(50) << it->second << endl;
	textString.clear();
	vectorOfWords.clear();
	system("pause");
	return 0;
}