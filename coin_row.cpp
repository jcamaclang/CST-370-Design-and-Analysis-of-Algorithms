/*
 * Title: coin_row.cpp
 * Abstract: This program ask a user to input a number of coins with their values.
 * The program should display the set of coins to be picked and maximum amount
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 07/30/2017
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinRow(vector<int> values)
{
	//Vector matrix holding the set of numbers for the current maximum
    vector<vector<int>> location(values.size());

    //Vector holding the maximum amount for each round
    vector<int> savedAmount(values.size(), 0);

    savedAmount[1] = values[1];
    location[1].push_back(1);

    for (int i = 2; i < values.size(); i++)
    {
        savedAmount[i] = max((values[i] + savedAmount[i-2]), savedAmount[i-1]);
        if ((values[i] + savedAmount[i-2]) > savedAmount[i-1])
        {
            if (i == 2)
            {
                location[i].push_back(2);
            }
            else
            {
                location[i] = location[i-2];
                location[i].push_back(i);
            }
        }
        else
        {
            location[i] = location[i-1];
        }
    }

    cout<< "Best set: ";

    for(int i = 0; i < location[values.size()-1].size(); i++)
    {
        cout << location[values.size()-1][i] << " ";
    }

    cout << endl;
    return savedAmount[values.size()-1];
}

int main()
{
    int numCoins, temp, maxAmount;
    vector<int> location;

    cout << "Number of coin(s): ";
    cin >> numCoins;

    vector<int> values(numCoins+1, 0);

    cout << "Value(s): ";

    for(int i = 1; i < numCoins+1; i++)
    {
        cin >> temp;
        values[i] = temp;
    }

    maxAmount = coinRow(values);

    cout << "Max Value: " << maxAmount;

    return 0;
}
