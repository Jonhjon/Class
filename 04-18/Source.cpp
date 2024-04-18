#include<iostream>
#include<fstream>
#include<string>

using namespace std;
typedef struct node {
	int num;
	int pow;
	struct node* Next;
}node;
node* Add(node* ptr, int num, int pow) {
	node *Add = new node();
	node* temp = ptr;
	Add->num = num;
	Add->pow = pow;
	if (temp==NULL)
	{
		ptr = Add;
		return ptr;
	}
	while (temp->Next!=NULL)
	{
		temp = temp->Next;
	}
	temp->Next = Add;
	return ptr;
}
void Free(node * cur) {
	node* temp;
	while (cur!=NULL)
	{
		temp = cur;
		cur = cur->Next;
		free(temp);
	}
}
int main() {
	node* head_A = NULL;
	node* head_b = NULL;
	node* head_c = NULL;
	node* current = NULL;
	string pre = " ", temp = " ";
	string sym = " ";
	int check = 0;
	int check2 = 0;
	int num = 0, pow = 0;
	string str;
	ifstream file;
	file.open("1.txt");
	if (!file.is_open())
	{
		cout << "ÀÉ®×¶}±Ò¿ù»~!\n"; return 0;
	}
	getline(file, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) && check==0)
		{
			pre = str[i];
			check = 1;
		}
		else if (isdigit(str[i]) && check == 1)
		{
			temp = str[i];
			check++;
		}
		else if (str[i] == 'x' && str[i + 1] == '^')
		{
			if (check == 2)
			{
				num = stoi(pre) * 10 + stoi(temp);
				sym = " ";
			}
			else 	num = stoi(pre);
			check = 0;
		}
		else if (str[i] == ' ' && (str[i + 1] == '+'|| str[i+1]=='-'))
		{
			if (check == 2)
			{
				pow = stoi(pre) * 10 + stoi(temp);
			}
			else {
				pow = stoi(pre);
			}
			check = 0;
			head_A = Add(head_A, num, pow);
			num = 0;
			pow = 0;
		}
		if (i==(str.length()-1))
		{
			if (check == 2)
			{
				num = stoi(pre) * 10 + stoi(temp);
			}
			else 	num = stoi(pre);
			check = 0;
			head_A = Add(head_A, num, pow); num = 0;
			pow = 0;
		}
	}
	current = head_A;
	while (current !=NULL)
	{
		if (current->pow==0)
		{
			cout << " + " << current->num << " ";
			//cout << " - " << current->num << " ";
		}
		else {
			cout << " " << current->num << "x^" << current->pow;
			//cout << " " << current->num << "x^" << current->pow;
		}
		current = current->Next;
	}
	Free(head_A);
	return 0;
}