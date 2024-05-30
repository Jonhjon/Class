#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define Max 20
typedef struct edge {
	int from;
	int to;
	int weight;
}edge;

bool weight_compare(edge e1, edge e2) {
	return e1.weight < e2.weight;
}

int find(int parent[], int i) {
	if (parent[i] != i)
		parent[i] = find(parent, parent[i]);
	return parent[i];
}

void Union(int parent[], int rank[], int x, int y) {
	int rootx = find(parent, x);
	int rooty = find(parent, y);

	if (rank[rootx] < rank[rooty])
		parent[rootx] = rooty;
	else if (rank[rootx] > rank[rooty])
		parent[rooty] = rootx;
	else {
		parent[rooty] = rootx;
		rank[rootx]++;
	}
}


void KruskalMST(edge edges[], int edge_count, int vector) {
	int parent[20] = { 0 };
	int rank[20] = { 0 };
	//bool *vist=new bool[vector];
	
	for (int i = 0; i < vector; i++)
	{
		parent[i] = i;
		rank[i] = 0;
		//vist[i] = false;
	}

	edge result[Max];
	int e = 0;
	int i = 0;

	while (e < vector - 1 && i < edge_count)
	{
		edge edge_next = edges[i++];

		int x = find(parent, edge_next.from);
		int y = find(parent, edge_next.to);

		if (x!=y)
		{
			result[e++] = edge_next;
			cout << edge_next.from << "\t" << edge_next.to << "\t" << edge_next.weight << endl;
			parent[y] = x;

			//Union(parent,rank,x,y);
		}
	}
	int total_weight = 0;
	cout << "point1	point2	cost\n";

	for (int i = 0; i < e; i++)
	{
		//cout << result[i].from << "\t" << result[i].to << "\t" << result[i].weight << endl;
		total_weight += result[i].weight;
	}

	cout << "\ntotal weight : " << total_weight;

	
}

int main()
{
	fstream file;
	int num = 0;
	int count = 0;
	file.open("Graph1.txt");
	if (!file.is_open())
	{
		cout << "file erro!!\n";
		file.close();
		return 0;
	}
	edge edge[50] = { 0 };
	int len_num = 0;
	file >> len_num;
	for (int i = 0; i < len_num; i++)
	{
		for (int j = 0; j < len_num; j++)
		{
			file >> num;
			if (num!=0&&j>=i)
			{
				edge[count].from = i;
				edge[count].to = j;
				edge[count].weight=num;
				count++;
			}
		}
	}
	sort(edge, edge + count, weight_compare);
	cout << "point1	point2	cost\n";
	for (int i = 0; i < count; i++)
	{
		cout << edge[i].from << "\t" << edge[i].to << "\t" << edge[i].weight<<endl;
	}
	cout << endl << endl;
	KruskalMST(edge, count, len_num);

	return 0;
}