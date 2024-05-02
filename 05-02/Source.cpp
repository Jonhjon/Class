#include<iostream>
#include<fstream>
using namespace std;
typedef struct node {
	int num;
	node* left,*right;
}node;
node* insert(node* ptr, int num) {
	if (ptr == NULL) {
		node* add = new node();
		add->num = num;
		add->left = add->right = NULL;
		return add;
	}
	if (num > ptr->num)
	{
		ptr->right = insert(ptr->right, num);
	}
	else if (num < ptr->num) {
		ptr->left = insert(ptr->left, num);
	}
	return ptr;
}

int search(node* ptr, int num) {
	if (ptr==NULL)
	{
		return 0;
	}
	if (ptr->num==num)
	{
		return 1;
	}
	if (num < ptr->num)
	{
		search(ptr->left, num);
	}
	else if(num > ptr->num)
	{
		search(ptr->right, num);
	}
}

void In_order(node* ptr) {
	if (ptr!=NULL)
	{
		In_order(ptr->left);
		cout << ptr->num<<" ";
		In_order(ptr->right);
	}
}

void Pre_order(node* ptr) {
	if (ptr!=NULL)
	{
		cout << ptr->num << " ";
		Pre_order(ptr->left);
		Pre_order(ptr->right);
	}
}

void Post_order(node* ptr) {
	if (ptr!=NULL)
	{
		Post_order(ptr->left);
		Post_order(ptr->right);
		cout << ptr->num << " ";
	}
}

int main() {
	node* root = NULL;
	int num = 0;
	ifstream file;
	file.open("1.txt");
	if (!file.is_open())
	{
		cout << "erro!!\n"; return 0;
	}
	cout << "Insert node : ";
	for (int  i = 0; i < 15; i++)
	{
		file >> num;
		root = insert(root, int(num));
		cout << num << " ";
	}
	file.close();
	cout << endl<<"Inorder : ";
	In_order(root);
	cout << endl << "Preorder : ";
	Pre_order(root);
	cout << endl << "Postorder : ";
	Post_order(root);
	while (true)
	{
		cout << "\n(1)Search (-1)µ²§ô: ";
		cin >> num;
		if (num==-1)
		{
			break;
		}
		cout << "Search : ";
		cin >> num;
		cout<<(search(root, num) ? "Sucess!!\n" : "Fail!!\n");
	}
	return 0;
}