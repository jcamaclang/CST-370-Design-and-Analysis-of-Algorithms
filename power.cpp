/*
 * Title: adj_matrix.cpp
 * Abstract: This program reads a file and creates an adjacency matrix with given values
 * between two numbers among the numbers
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 05/01/2017
 */

#include <iostream>
using namespace std;

int power(int power);

int main() {

	int input;

	cout << "Enter a number: " << endl;

	cin >> input;

	cout << "Result: " << power(input);

	return 0;
}

int power(int input)
{
	if (input == 0)
	{
		return 1;
	}
	else
	{
	return (2*power(input-1));
	}
}
