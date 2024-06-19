#include<iostream>
#include<fstream>
using namespace std;
#define len 6
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
	edg* pre = NULL, * cur = n;
	if (!cur)
	{
		n = new_edg;
		return n;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new_edg;
	return n;
}
void Free(edg* n) {
	edg* temp = n;
	while (n != NULL)
	{
		n = n->next;
		free(temp);
		temp = n;
	}
}
void Print_graph(Graph graph[], int num) {
	cout << "matrix : \n";
	for (int i = 0; i < num; i++)
	{
		edg* start = graph[i].edg_start;
		cout << "V" << i << ": ";
		for (int j = 0; j < num; j++)
		{
			if (start)
			{
				if (start->side == j) {
					cout << start->side << " ";
					start = start->next;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}
bool any_way_forward(Graph graph[], int side) {
	for (int i = 0; i < len; i++)
	{
		edg* start = graph[i].edg_start;
		while (start)
		{
			if (start->side == side)
			{
				return true;
			}
			start = start->next;
		}
	}
	return false;
}

edg* Delete_vect(Graph graph[], int side) {

	edg* start = graph[side].edg_start;
	while (start)
	{
		edg* n = start;
		start = start->next;
		free(n);
	}
	return start;
}


void Topological(Graph graph[], int side) {
	bool vist[len] = { false };
	int queue[len] = { 0 };
	int front = 0, rear = 0;

	for (int i = 0; i < len; i++)
	{
		if (!vist[i] && !any_way_forward(graph, i))
		{
			vist[i] = true;
			queue[rear] = i;
			rear++;
		}
	}
	while (front < rear)
	{
		int num = queue[front];
		cout << num << " ";
		front++;

		edg* temp = graph[num].edg_start;
		graph[num].edg_start = Delete_vect(graph, num);
		for (int i = 0; i < len; i++)
		{
			if (!vist[i] && !any_way_forward(graph, i))
			{
				vist[i] = true;
				queue[rear] = i;
				rear++;
				break;
			}
		}
	}
}

int main() {
	fstream file;
	file.open("Data.txt");
	if (!file.is_open())
	{
		cout << "erro !!\n";
		file.close();
		return 0;
	}
	int line = 0, side = 0;
	Graph graph[len] = { 0 };
	file >> line;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line; j++)
		{
			file >> side;
			if (side == 1)
			{
				graph[i].edg_start = add(graph[i].edg_start, j);
			}
		}
	}
	Print_graph(graph, line);
	cout << endl << endl;
	side = 0;
	cout << "topological sort :";
	Topological(graph, side);
	for (size_t i = 0; i < line; i++)
	{
		Free(graph[i].edg_start);
	}
	return 0;
}
