#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;	
#define len 16
void complete(int matrx[][len]) {
	int V = 0;
	for (int i = 0; i < len ; i++)
	{
		for (int j = i; j < len; j++) {
			if(i!=j && matrx[i][j]==1)
				V++;
		}
	}
	if (V != (len * (len - 1) / 2))
		cout << "Not a complete graph\n";
	else
		cout << "a complete graph\n";
	return;
}

void DFS(int matrx[][len], int V, bool vist[]) {
	vist[V] = true;
	for (int i = 0; i < len; i++) {
		if (matrx[V][i] && !vist[i])
		{
			DFS(matrx, i, vist);
		}
	}
}
void is_connected(int matrix[][len]) {
	bool vist[len] = { false };
	DFS(matrix, 0, vist);
	for (int i = 0; i < len; i++)
	{
		if (!vist[i]) {
			cout << "Not a connected graph\n";
			return;
		}
	}
	cout << "a connected graph\n";
	return;
}

int count_connected(int matrix[][len]) {
	bool vist[len] = { false };
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (!vist[i]) {
			DFS(matrix, i, vist);
			count++;
		}
	}
	return count;
}
int main() {
	ifstream file;
	int temp;
	int matrix[len][len] = { 0 };
	file.open("01.txt");
	if (!file.is_open())
	{
		cout << "erro!!!!"; 
		file.close();
		return 0;
	}
	file >> temp;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
		{
			file >> matrix[i][j];
		}
	}		
	file.close();

	cout << "matrix: \n";
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++)
		{
			cout<< matrix[i][j]<<" ";
		}
		cout << endl;
	}
	complete(matrix);
	is_connected(matrix);
	cout << count_connected(matrix) << " connected component\n";
	return 0;
}