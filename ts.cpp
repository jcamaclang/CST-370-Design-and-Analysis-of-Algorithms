/*
 * Title: ts.cpp
 * Abstract: This program reads a file and implements the topological sorting algorithm
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 07/03/2017
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

//Finds the vector with the zero degree and puts it into the queue.  Excludes those already visited
void zeroDegree(vector<int> inEdges, queue<int> & myQueue)
{
    queue<int> emptyQueue;
    myQueue.swap(emptyQueue);
    for (int i = 0; i < inEdges.size(); i++)
    {
        if (inEdges[i]== 0)
        {
            myQueue.push(i);
        }
    }
}

int main() {

	string filename;
	int vertices, edge, currVertex;
	queue<int> myQueue;

	//Get file name from user
	cout << "Enter input file name: ";
	cin >> filename;

	//Open file for reading
	ifstream file_ {filename};

	//Get first 2 integers and assign them as the vertices and number of edges
	file_ >> vertices;
	vector <vector<int>> matrix(vertices, vector<int>(vertices, 0));
	vector <int> inEdges(vertices, 0);
	vector <int> order;

	for (int i = 0; i < vertices; i ++)
	{
		for (int j = 0; j < vertices; j++)
		{
			// Creates matrix and calculates edges for each vertex
			file_ >> edge;
			matrix[i][j] = edge;
			if (matrix[i][j]==1)
            {
                inEdges[j] += 1;
            }
		}
	}

    zeroDegree(inEdges, myQueue);

    //Implements topological sorting
    while (!myQueue.empty())
    {
        currVertex = myQueue.front();
        for (int i = 0; i < vertices; i++)
        {
            if(matrix[currVertex][i] == 1)
            {
                inEdges[i] -= 1;
            }
        }
        //Mark Vertex as visited
        inEdges[currVertex] = -1;
        order.push_back(currVertex);
        myQueue.pop();
        zeroDegree(inEdges, myQueue);
    }

    //Prints out results
    cout << "Topological sort: ";
    for (int i = 0; i < order.size()-1; i++)
    {
        cout << order[i] << " -> ";
    }
    cout << order[order.size()-1];

	return 0;
}
