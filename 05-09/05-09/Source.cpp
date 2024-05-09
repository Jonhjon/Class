#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;

typedef struct Node {
	char value;
	Node* left;
	Node* right;
}Node;

int search(char arr[],int start,int end,char val) {
	for (int i = start; i <= end; i++) {
		if (arr[i]==val)
		{
			return i;
		}
	}
	return -1;
}

Node* build(char* pre, int pre_start, int pre_end, char* Inorder, int Inorder_start, int Inorder_end) {
	if (pre_start > pre_end || Inorder_start > Inorder_end) return NULL;
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = pre[pre_start];
	root->left = NULL;
	root->right = NULL;

	int root_index = search(Inorder, Inorder_start, Inorder_end, pre[pre_start]);
	if (root_index == -1) 
		return NULL;
	root->left = build(pre, pre_start + 1, pre_start + root_index - Inorder_start, Inorder, Inorder_start, root_index - 1);
	root->right = build(pre, pre_start + root_index - Inorder_start + 1, pre_end, Inorder, root_index + 1, Inorder_end);
	return root;
}


struct Node* buildTree(char* preorder, int preorderSize, char* inorder, int inorderSize) {
	return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
void Post(Node* root)
{
	if (root==NULL)
	{
		return;
	}
	Post(root->left);
	Post(root->right);
	cout <<" "<<root->value;
}
int main() {
	fstream file;
	Node *root = NULL;
	char preorder[20] = { 0 };
	char Inorder[20] = { 0 };
	char postorer[20] = { 0 };
	file.open("«e¤¤02.txt");
	if (!file.is_open())
	{
		cout << "erro!!\n";
		file.close();
		return 0;
	}
	for (int i = 0; i <15; i++) {
		file >> preorder[i];
	}
	for (int i = 0; i < 15; i++)
	{
		file >> Inorder[i];
	}
	file.close();
	cout << "Q1\nPreorder : ";
	for (int i = 0; i < 15; i++)
	{
		cout << " " << preorder[i];
	}
	cout << endl;
	cout << "Inorder :  ";
	for (int i = 0; i < 15; i++)
	{
		cout << " " << Inorder[i];
	}
	cout << endl;
	root = buildTree(preorder, sizeof(preorder) / sizeof(char), Inorder, sizeof(Inorder) / sizeof(char));
	cout << "Postoder : ";
	Post(root);




	return 0;
}