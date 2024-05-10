#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

typedef struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

int search(char* inorder, int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}


Node* build(char* post, int post_start, int post_end, char* inorder, int inorder_start, int inorder_end) {
    if (post_start > post_end || inorder_start > inorder_end)
        return NULL;

    Node* root = (Node*)malloc(sizeof(Node));
    root->value = post[post_end];
    root->left = NULL;
    root->right = NULL;


    int root_index = search(inorder, inorder_start, inorder_end, root->value);
    if (root_index == -1)
        return NULL;

    root->left = build(post, post_start, post_start + root_index - inorder_start - 1, inorder, inorder_start, root_index - 1);
    root->right = build(post, post_start + root_index - inorder_start, post_end - 1, inorder, root_index + 1, inorder_end);

	//root->left = build(pre, pre_start + 1, pre_start + root_index - Inorder_start, Inorder, Inorder_start, root_index - 1);
	//root->right = build(pre, pre_start + root_index - Inorder_start + 1, pre_end, Inorder, root_index + 1, Inorder_end);
    return root;
}

Node* buildTree(char* post, int post_size, char* inorder, int inorder_size) {
	return build(post,0,post_size-1,inorder,0,inorder_size-1); 
}

void preorder(Node* root) {
    if (root == NULL)
        return;
	printf("%c ", root->value);
	preorder(root->left);
	preorder(root->right);
}

int main() {
	fstream file;
	Node* root = NULL;
	int line = 9;

	char Inorder[20] = { 0 };
	char postorer[20] = { 0 };
	file.open("中後01.txt");
	if (!file.is_open())
	{
		cout << "erro!!\n";
		file.close();
		return 0;
	}
	for (int i = 0; i < line; i++) {
		file >> Inorder[i];
	}
	for (int i = 0; i < line; i++)
	{
		file >> postorer[i];
	}
	file.close();
	cout << "Q2\nInorder : ";
	for (int i = 0; i < line; i++)
	{
		cout << " " << Inorder[i];
	}
	cout << endl;
	cout << "postorer :  ";
	for (int i = 0; i < line; i++)
	{
		cout << " " << postorer[i];
	}
	cout << endl;
	root = buildTree(postorer, sizeof(postorer) / sizeof(char), Inorder, sizeof(Inorder) / sizeof(char));
	cout << "Postoder : ";
	preorder(root);
	return 0;
}

