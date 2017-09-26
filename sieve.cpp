/*
 * Title: sieve.cpp
 * Abstract: This program implements the sieve of Eratosthenes algorithm,
 * which finds all prime numbers between a given number
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 05/03/2017
 */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int * ptr;

    int inputNum;

    cout << "Enter a number: ";
    cin >> inputNum;

    ptr = new (nothrow) int[inputNum];

    if(ptr == nullptr)
    {
    	cout << "Error: memory could not be allocated";
    }
    else
    {
        for (int i = 2; i <= inputNum; i++)
        {
            ptr[i] = i;
        }
        for (int i = 2; i <= floor (sqrt (inputNum)); i++)
        {
            if (ptr[i] != 0)
            {
                int j = i * i;
                while (j <= inputNum)
                {
                    ptr[j] = 0;
                    j += i;
                }
            }
        }

        cout << "Prime numbers: ";

        for (int i = 2; i < inputNum; i++)
        {
            if (ptr[i] != 0)
            {
                cout << ptr[i] << ", ";
            }
        }
        delete[] ptr;
    }

    return 0;
}

