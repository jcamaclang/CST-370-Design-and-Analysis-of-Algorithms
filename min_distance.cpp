/*
 * Title: min_distance.cpp
 * Abstract: This program reads integers from a user and displays the closest distance
 * between two numbers among the numbers
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 04/24/2017
 */

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int numSize = 10; //initialize size of set of numbers
    int numArray[numSize];  //array that holds numbers
    int minDistance;
    int tempDistance;
    vector<int> xPair;  //vector to store x ordered pair
    vector<int> yPair;  //vector to store y ordered pair

    //Prompt user for numbers
    cout << "Enter " << numSize << " numbers: ";

    //loop user input to store in numArray
    for (int i = 0; i < numSize; i++)
    {
    	cin >> numArray[i];
    }

    //sorts array
    sort(numArray, numArray+numSize);

    //loops through each pair in the array and find minDistance
    for (int i = 0; i < numSize; i++)
    {
    	for (int k = i + 1; k < numSize; k++)
    	{
    		if (i == 0 && k == 1)
    		{
    			//initializes the first pair difference as minDistance
    			minDistance = abs (numArray[i]-numArray[k]);
    		}
    		else
    		{
    			//compares new pair of numbers' distance to minDistance
    			tempDistance = abs (numArray[i]-numArray[k]);
    			if (tempDistance < minDistance)
    			{
    				//sets new minDistance if tempDistance is lower
    				minDistance = tempDistance;
    			}
    		}
    	}
    }

    //loops through each pair and find those who have a difference of minDistance
    for (int i = 0; i < numSize; i++)
    {
    	for (int k = i + 1; k < numSize; k++)
    	{
    		if (abs (numArray[i]-numArray[k]) == minDistance)
    		{
    			//push back ordered pair into vector
    			xPair.push_back(numArray[i]);
    			yPair.push_back(numArray[k]);
    		}
    	}
    }

    //displays minimum distance
    cout << "Minimum distance: " << minDistance << endl;

    //displays number pairs with minimum distance
    for (unsigned int i = 0; i < xPair.size(); i++)
    {
       	cout << "Two numbers with minimum distance: " << xPair[i] << " and " << yPair[i] << endl;
    }

    return 0;
}




