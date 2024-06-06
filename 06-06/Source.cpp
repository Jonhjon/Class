#include<iostream>
#include<stdio.h>
#include<fstream>
#include <limits.h>
using namespace std;
#define len 10

void Print_matrix(int matrix[][len],int line) {
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			if (matrix[i][j] > 0)
			{
				printf("(%c - %c : %d)\t", i + 'A', j + 'A', matrix[i][j]);
			}
		}
		cout << endl;
	}
}

int MinDistance(int distance[], bool vist[],int line) {
	int min = INT_MAX, min_index = 0;

	for (int i = 0; i < line; i++)
	{
		if (!vist[i] && distance[i] <= min)
			min = distance[i], min_index = i;
	}

	return min_index;
}
void dijkstra(int matrix[len][len], int start,int line) {
	int distance[len] = { 0 };
	bool vist[len] = { false };
	int parent[len] = { 0 };

	for (int i = 0; i < len; i++) {
		distance[i] = INT_MAX;
		parent[i] = i;
	}

	distance[start]=0;

	for (int i = 0; i < line; i++)
	{
		int u = MinDistance(distance, vist,line);

		vist[u] = true;

		for (int j = 0; j < line; j++)
		{
			if (!vist[j] && matrix[u][j]!=-1  && distance[u]!= INT_MAX && (distance[u] + matrix[u][j] < distance[j]))
			{
				distance[j] = distance[u] + matrix[u][j];
				parent[j] = u;
			}
		}

		for (int i = 0; i < line; i++)
		{
			if (distance[i] == INT_MAX)
			{
				printf("(-1,%c) ", parent[i] + 'A');
			}
			/*else if (parent[i]==-1)
			{
				printf("(-1,A) ", distance[i]);
			}*/
			else
			{
				printf("(%d,%c) ", distance[i], parent[i] + 'A');
			}
		}
		cout << endl;
	}


}





int main() {
	fstream file;
	int matrix[len][len] = { 0 };
	file.open("Data-1.txt");
	if (!file.is_open())
	{
		cout << "file erro!!\n";
		return 0;
	}
	int line = 0,num=0;
	file >> line;
	for (int i = 0; i < line; i++)
	{
		for (size_t j = 0; j < line; j++)
		{
			file >> num;
			matrix[i][j] = num;
		}
	}
	file.close();
	Print_matrix(matrix, line);
	int start = 0;

	dijkstra(matrix, start,line);
	return 0;
}