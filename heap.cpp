/*
 * Title: heap.cpp
 * Abstract: This program ask a user to input a heap.  It checks if its valid, if not it constructs a max heap.
 * The user can insert a number into the heap or delete the Max value.
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 07/25/2017
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//Print out selection menu
void menu()
{
    cout << "Select an operation\n";
    cout <<"\t 1:  Insert a number\n";
    cout <<"\t 2:  Delete the max\n";
    cout <<"\t 3:  Heapsort & Quit\n";
}

//Checks if vector is a heap
bool isHeap(vector<int> heap, int inputSize)
{
    int left, right;

    for (int i = inputSize/2; i >= 1 ; i--)
    {
        left = 2 * i;
        right = 2 * i + 1;
        if (left == inputSize)
        {
            right = 0;
        }
        else if (right > inputSize)
        {
            left = 0;
            right = 0;
        }

        if (heap[left] > heap[i] || heap[right] > heap[i])
        {
            return false;
        }
    }
    return true;
}

//Constructs a max heap
void makeHeap(vector<int>& heap, int inputSize)
{
    int left, right, largest, temp;
    while(!isHeap(heap, inputSize))
    {
        for (int i = inputSize/2; i >= 1 ; i--)
        {
            left = 2 * i;
            right = 2 * i + 1;
            if (left == inputSize)
            {
                right = 0;
            }
            else if (right > inputSize)
            {
                left = 0;
                right = 0;
            }

            if (heap[left] > heap[right])
            {
                largest = left;
            }
            else
            {
                largest = right;
            }

            if (heap[largest] > heap[i])
            {
                temp = heap[largest];
                heap[largest] = heap[i];
                heap[i] = temp;
            }
        }
    }
}

//Inserts a number into the heap
void insertHeap(vector<int>& heap, int insertNum, int& inputSize)
{
    inputSize++;
    heap.push_back(insertNum);
    makeHeap(heap, inputSize);
}

//Deletes the max number in the heap
void deleteheap(vector<int>& heap, int& inputSize)
{
    heap[1] = heap[inputSize];
    heap.resize(inputSize);
    inputSize--;
    makeHeap(heap, inputSize);

}

//Prints out the heap
void print(vector<int> heap)
{
    for(int i = 1; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << "\n\n";
}

int main()
{
    bool loop = true;
    int inputSize, selection, temp, insertNum;

    cout << "Input size: ";
    cin >> inputSize;

    vector<int> heap(inputSize+1, 0);
    cout << "Enter numbers: ";
    for (int i = 1; i <= inputSize; i++)
    {
        cin >> temp;
        heap[i] = temp;
    }

    if(isHeap(heap, inputSize))
    {
        cout << "This is a heap.\n";
    }
    else
    {
        cout << "This is NOT a heap.\n";
        cout << "Constructed heap: ";
        makeHeap(heap, inputSize);
        print(heap);
    }

    while(loop)
    {
        menu();
        while (!(cin >> selection))
        {
            cout << "Selection Invalid!\n";
            cin.clear();
            cin.ignore(80, '\n');
            menu();
        }

        switch(selection)
        {
        case 1:
            cout << "Enter a number: ";
            cin >> insertNum;
            insertHeap(heap, insertNum, inputSize);
            cout << "Updated heap: ";
            print(heap);
            break;
        case 2:
            deleteheap(heap, inputSize);
            cout << "Updated heap: ";
            print(heap);
            break;
        case 3:
        	cout<< "Heapsort: ";
        	print(heap);
            cout << "Bye!";
            loop = false;
            break;
        default:
            cout <<"Selection Invalid!\n";
            break;
        }


    }
    return 0;
}
