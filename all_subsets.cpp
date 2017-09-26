/*
 * Title: all_subsets.cpp
 * Abstract: This program displays all subsets of a set.
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 05/21/2017
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

string binary(int);

int main() {

	int input;
	string binString;
	string temp;
	vector<char> charVector;
	vector<string> subSets;
	char tempChar;

	cout << "Number of input characters: ";
	cin >> input;

	cout << "Enter " << input << " characters: ";

	for (int i = 0; i < input; i++)
	{
		cin >> tempChar;
    	charVector.push_back(tempChar);
	}

	for (int i = 0; i < pow(2, charVector.size()); i++)
	{
		binString = binary(i);
		if(binString.length() == 0)
		{
			subSets.push_back("");
		}
		else
		{
			temp = "";
			for (int j = 0; j < binString.length(); j++)
			{
				if (binString[j] == '1')
				{
					temp += charVector[j];
				}
			}
			subSets.push_back(temp);
		}
	}

	cout << "===== All Subsets =====" << endl;

	for (int i = 0; i < subSets.size(); i++)
	{
		if(subSets[i] == "")
		{
			cout << "{empty}\n";
		}
		else
		{
			cout << "{";
			for (int j = 0; j < subSets[i].length()-1; j++)
			{
				cout << subSets[i].at(j) << ",";
			}
			cout << subSets[i].at(subSets[i].length()-1) << "}\n";

		}
	}

	return 0;
}

string binary(int number)
{
	string binary;
	int remainder;

	while (number > 0)
	{
		remainder = number % 2;
		number /= 2;
		if (remainder == 0)
		{
			binary += "0";
		}
		else
		{
			binary += "1";
		}
	}
	return binary;
}




