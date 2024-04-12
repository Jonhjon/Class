#include<iostream>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int num;
	Node* next = NULL;
} Node;
int count_A = 0, count_B = 0;
using namespace std;
Node* Add(Node* ptr, int num) {
	Node* Add_temp = new Node();
	Node* pre = NULL;
	Add_temp->num = num;
	Add_temp->next = NULL;
	Node* temp = ptr;
	if (ptr == NULL)
	{
		ptr = Add_temp;
		return ptr;
	}
	else
	{
		pre = NULL;
		while (temp != NULL)
		{
			if (temp->num <= num)
			{
				if (pre == NULL)
				{
					Add_temp->next = temp;
					//ptr = Add_temp;
					return Add_temp;
				}
				else
				{
					Add_temp->next = pre->next;
					pre->next = Add_temp;
					return ptr;
				}
			}
			else if (temp->next == NULL)
			{
				temp->next = Add_temp;
				return ptr;
			}
			pre = temp;
			temp = temp->next;
		}
	}
	return ptr;
}
void Print(Node* current) {
	if (current == NULL)
		return;
	printf("%d", current->num);
	current = current->next;
	while (current != NULL) {
		printf("-> %d", current->num);
		current = current->next;
	}
}
void Free(Node* ptr) {
	Node* current;
	Node* temp;
	current = ptr;
	while (current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}
Node* InsertB_A(Node* head_A, Node* ptr_B) {
	Node* temp = NULL;
	Node* pre = NULL;
	temp = head_A;
	while (temp != NULL)
	{
		if (temp->num < ptr_B->num)
		{
			if (pre == NULL)
			{
				Node* new_node = new Node();
				new_node->num = ptr_B->num;
				new_node->next = temp;
				return new_node;
			}
			else
			{
				Node* new_node = new Node();
				new_node->num = ptr_B->num;
				new_node->next = pre->next;
				pre->next = new_node;
				return head_A;
			}
		}
		else if (temp->next == NULL)
		{
			Node* new_node = new Node();
			new_node->num = ptr_B->num;
			temp->next = new_node;
			return head_A;
			//count_A++;
		}
		pre = temp;
		temp = temp->next;
	}
	return head_A;
}
Node* DeleteB_A(Node* head_A, Node* ptr_B) {
	Node* temp = head_A;
	Node* pre = NULL;
	Node* Delte_temp = NULL;
	while (temp != NULL) {
		if (temp->num==ptr_B->num)
		{
			if (pre == NULL) {
				Delte_temp = temp;
				temp = temp->next;
				head_A = temp;
				free(Delte_temp);	
			}
			else
			{
				Delte_temp = temp;
				temp = temp->next;
				pre->next = temp;
				free(Delte_temp);
			}
			count_A--;
		}
		else
		{
			pre = temp;
			temp = temp->next;
		}
	}
	return head_A;
}
int main() {
	int choice = 0, num = 0;
	Node* Headptr_A = NULL;
	Node* Headptr_B = NULL;
	Node* temp = NULL;
	while (choice != -1)
	{
		cout << "(1) 建A (2)建B  (3) 把B丟到A (4) 把A中有B的刪掉 (-1) 離開 :";
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> num;
			count_A++;
			Headptr_A = Add(Headptr_A, num);
			break;
		case 2:
			cin >> num;
			count_B++;
			Headptr_B = Add(Headptr_B, num);
			break;
		case 3:
			while (Headptr_B != NULL)
			{
				Headptr_A = InsertB_A(Headptr_A, Headptr_B);
				temp = Headptr_B;
				Headptr_B = Headptr_B->next;
				free(temp);
				count_B--;
				count_A++;
			}
			break;
		case 4:
			while (Headptr_B != NULL) {
				Headptr_A = DeleteB_A(Headptr_A, Headptr_B);
				temp = Headptr_B;
				Headptr_B = Headptr_B->next;
				free(temp);
				count_B--;
			}
			break;
		case -1:
			Free(Headptr_A);
			Free(Headptr_B);
			return 0;
			break;
		}
		cout << "A有" << count_A << "個值 : ";
		Print(Headptr_A);
		cout << "\nB有" << count_B << "個值 : ";
		Print(Headptr_B);
		cout << endl;
	}
	return 00;
}
