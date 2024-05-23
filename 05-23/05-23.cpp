#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
#define len 50
#define node_len 20
typedef struct edg {
	int side;
	edg* next;
}edg;

typedef struct Graph {
	edg* edg_start;
}Graph;

edg* add(edg* n, int num) {
	edg* new_edg = new edg();
	new_edg->side = num;
	edg *pre = NULL, *cur = n;
	while (cur!=NULL)
	{
		if (cur->side > num)
		{
			break;
		}	
		pre = cur;
		cur = cur->next;
	}
	if (pre==NULL)
	{
		new_edg->next = cur;
		return new_edg;
	}
	else if (cur==NULL)
	{
		pre->next = new_edg;
	}
	else
	{
		pre->next = new_edg;
		new_edg->next = cur;
	}
	return n;
}
void Free(edg* n) {
	edg* temp = n;
	while (n!=NULL)
	{
		n = n->next;
		free(temp);
		temp = n;
	}
}
void DFS_Print(Graph graph[],int side ,bool vist[])
{
	edg* list = graph[side].edg_start;
	edg* temp = list;

	vist[side] = true;
	cout << "V" << side<<" ";
	while (temp)
	{
		if (!vist[temp->side])
		{
			DFS_Print(graph, temp->side, vist);
		}
		temp = temp->next;
	}
}
void BFS_Print(Graph graph[], int start) {
	bool vist[len] = { false };
	int queue[len] = { 0 };
	int front = 0, rear = 0;
	vist[0] = true;
	queue[rear] = start;
	rear++;
	while (front < rear)
	{
		int num = queue[front];
		cout << "V" << num << " ";
		front++;

		edg* temp = graph[num].edg_start;

		while (temp)
		{
			if (!vist[temp->side])
			{
				vist[temp->side] = true;
				queue[rear] = temp->side;
				rear++;
			}
			temp = temp->next;
		}
	}
}

int main() {
	Graph graph[node_len] = { 0 };
	fstream file;
	bool vist[20] = { false };
	file.open("InputData1.txt");
	if (!file.is_open())
	{
		cout << "file errro!!\n";
		file.close();
		return 0;
	}
	int num = 0,side=0;
	file >> num;
	for (int i = 0; i < num; i++)
	{
		for (size_t j = 0; j < num; j++)
		{
			file >> side;
			if (side)
			{
				graph[i].edg_start=add(graph[i].edg_start, j);
			}
		}
	}
	cout << "matrix : \n";
	for (int i = 0; i < num; i++)
	{
		edg* start = graph[i].edg_start;
		for (int j= 0; j < num ; j++)
		{
			if (start)
			{
				if (start->side == j)
				{
					cout << "1 ";
					start = start->next;
				}
				else
				{
					cout << "0 ";
				}
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
	cout << "\n\nadjacency lists :\n";
	for (int i = 0; i < num; i++)
	{
		edg* start = graph[i].edg_start;
		cout << "V" << i << ": ";
		while (start)
		{
			cout << "-> V" << start->side;
			start = start->next;
		}
		cout << endl;
	}
	cout << "\nDepth-First Search : \n";
	//DFS
	for (int i = 0; i < num; i++)
	{
		if (!vist[i])
		{
			DFS_Print(graph, i, vist);
		}
	}
	cout << endl;
	//BFS
	cout << "\nBreadth first search: \n";
	BFS_Print(graph, 0);

	//free
	for (size_t i = 0; i < num; i++)
	{
		Free(graph[i].edg_start);
	}

	return 0;
}