/*
 * Title: adj_matrix.cpp
 * Abstract: This program reads a file and creates an adjacency matrix with given values
 * between two numbers among the numbers
 * Author: Jan Patrick Camaclang
 * ID: 3013
 * Date: 05/01/2017
 */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	string filename;
	int vertices, edges, v, e;

	//Get file name from user
	cout << "Enter input file name: ";
	cin >> filename;

	//Open file for reading
	ifstream file_ {filename};

	//Get first 2 integers and assign them as the vertices and number of edges
	file_ >> vertices >> edges;
	vector <vector<int>> matrix(vertices, vector<int>(vertices, 0));

	cout << "(v,e): ";
	while (file_ >> v >> e)
	{
		cout << "("<< v << "," << e << ") "; //Display ordered pairs from the file
		matrix[v][e] = 1; //Assign the value of 1 in (v,e)
	}

	//Display number of vertices, edges and matrix
	cout << "\nNumber of vertices: " << vertices;
	cout << "\nNumber of edges: " << edges;
	cout << "\nAdjacency matrix:\n";

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
