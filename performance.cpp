/*
 * Title: performance.cpp
 * Abstract: This program creates a file of random numbers and runs a selection sort and
 * quicksort on the list.  It then shows the execution times of the basic operation.
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 05/25/2017
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Make a file containing all the numbers in a vector
void makeFile(vector<int> numbers, string filename)
{
    ofstream myfile;
    myfile.open (filename + ".txt");
    for (int i = 0; i < numbers.size(); i++)
    {
        myfile << numbers[i];
		myfile << ", ";
    }

    myfile.close();
}
//Selection Sort Algorithm
void selectionSort(vector<int> numbers)
{
    int min, temp;
    int count = 0;
    string fileName = "selectionSort";

    for (int i = 0; i < numbers.size()-1; i++)
    {
        min = i;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            count ++;
            if (numbers[j] < numbers[min])
            {
                min = j;
            }
        }
        temp = numbers[min];
        numbers[min] = numbers[i];
        numbers[i] = temp;
    }

    //Create a file showing sorted vector using selection sort
    makeFile(numbers, fileName);
    cout << "Selection sort performance\nNumber of executions: " << count << " times";
}

//Partition step for quick sort algorithm
int hoarePartition(vector<int> & numbers, int l, int r)
{
    int p = numbers[l];
    int i = l - 1;
    int j = r + 1;
    int temp;

    while (true)
    {
        do
        {
            i++;
        } while(numbers[i] < p);

        do
        {
            j--;
        } while(numbers[j] > p);

        if (i >= j)
        {
            return j;
        }

        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

}

//Quick Sort Algorithm
void quickSort(vector<int> & numbers, int l, int r, int& counter)
{
    int s;

    counter++;
    if (l < r)
    {
        s = hoarePartition(numbers, l, r);
        quickSort(numbers, l, s, counter);
        quickSort(numbers, s+1, r, counter);
    }
}

int main() {

	int size, max, random, range;
	int counter = 0;
	int lowest = 0;
	vector<int> numbers;
	srand((int)time(0));
	string temp, inputFile = "input", qSortFile = "quickSort";

    //Get user input for size and max value for random numbers
	cout << "Enter input size: ";
	cin >> size;
	cout << "Enter max value of input: ";
	cin >> max;

    //Used to get range for random generator
	range = (max-lowest)+1;

	//Create vector of random numbers
	for (int i = 0; i < size; i++)
	{
		random = lowest+int(range*rand()/(RAND_MAX + 1.0));
		numbers.push_back(random);
	}

    //Make file to show random numbers
    makeFile(numbers, inputFile);

    cout << "================================================\n";
    cout << "Generating input data . . .\nDone.";
    cout << "\n================================================\n";
    selectionSort(numbers);
    cout << "\n================================================\n";
    quickSort(numbers, 0, numbers.size()-1, counter);
    cout << "Quick sort performance\nNumber of executions: " << counter << " times";
    //Create file to show sorted vector by quick sort
    makeFile(numbers, qSortFile);
    cout << "\n================================================\n";

	return 0;
}
