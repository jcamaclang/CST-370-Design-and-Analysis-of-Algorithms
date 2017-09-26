/*
 * Title: BFS.cpp
 * Abstract: This program reads a file containing an adjacency matrix
 * and implements the Breadth-First Search (BFS) algorithm
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 06/17/2017
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	string filename;
	int vertices, num, start;
	queue<int> mark;
	vector<int> finalOrder;

	//Get file name from user
	cout << "Enter input file name: ";
	cin >> filename;

	//Open file for reading
	ifstream file_ {filename};

	//Read file and save number of vertices.  Create vector matrix
	file_ >> vertices;
	vector <vector<int>> matrix(vertices, vector<int>(vertices));
	vector<bool> visited(vertices);

	//Copy matrix in file into two-dimensional vector
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			file_ >> num;
			matrix[i][j] = num;
		}
	}

	//Prompt where to start
	cout << "Enter a start vertex: ";
	cin >> start;

	//Initiate queue
	mark.push(start);
	visited[start] = true;
	finalOrder.push_back(start);

	//BFS algorithm
	while(!mark.empty())
	{
		for (int i = 0; i < vertices; i++)
		{
			if (matrix[mark.front()][i] == 1 && visited[i] == false)
			{
				finalOrder.push_back(i);
				visited[i] = true;
				mark.push(i);
			}
		}
		mark.pop();
	}

	//print out order
	cout << "BFS order: ";

	for (int i = 0; i < vertices; i++)
	{
		if (i != (vertices - 1))
		{
			cout << finalOrder[i] << " -> ";
		}
		else
		{
			cout <<finalOrder[i];
		}
	}

	return 0;
}
