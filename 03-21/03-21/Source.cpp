#include<stdio.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int op_compare(char op) {
	switch (op)
	{
	case '+':case '-':return 1;
	case '*':case '/':return 2;
	default:
		return 0;
	break;
	}
}
void MidToPost(char* str,char *post) {//������e��
	char stack[100] = { 0 };
	int top = 0,j=0;
	for (int i = 0; i <str[i]!='\0'; i++)
	{
		switch (str[i])
		{
		case '(':
			top++;
			stack[top] = str[i];
			break;
		case ')':
			while (stack[top]!='(')
			{
				post[j] = stack[top];
				j++;
				top--;
			}
			top--;
			break;
		case '+': case '-':case '*': case '/':
			while (op_compare(stack[top]) >= op_compare(str[i]))
			{
				post[j] = stack[top];
				j++;
				top--;
			}
			stack[++top] = str[i];
			break;
		default:
			post[j] = str[i];
			j++;
			break;
		}
	}
	if (top!=0)
	{
		for (int i = top; i > 0; i--) {
			post[j] = stack[top];
			j++;
		}
	}
}

void PostToMid(char * post, char * infix) {//�����e��
	char stack[100][100] = {0};
	int top = -1, j = 0,x=0;
	char temp[100] = { 0 };
	for (int i = 0; post[i]!='\0'; i++)
	{
		switch (post[i])
		{
		case '+':case '-':case '*':case '/':
			sprintf(temp, "(%s%c%s)", stack[top--], post[i], stack[top--]);//��̤W����Ӧr�ꮳ�X�Ӹ�B�⤸�@�X��
			top++;
			strcpy(stack[top], temp);
			break;
		default:
			top++;
			strcpy(stack[top], " ");
			stack[top][0] = post[i];
			break;
		}
	}
	strcpy(infix, temp);
}
int main() {
	char str[100] = { '\0' }, ch_post[100] = { '\0' }, post[100] = { '\0' }, ch_infix[100] = { '\0'};
	int x = 0;
	//cout << "��ƾǦ�(����) : \n";
	//cin >> str;
	////cout << str;
	//MidToPost(str, ch_post);
	//cout << "�ƾǦ�(���) :\n" << ch_post;
	cout << "\n��ƾǦ�(���) :\n";
	cin >> post;
	PostToMid(post, ch_infix);
	cout << "�ƾǦ�(����) : \n";
	cout << ch_infix;
	return 0;
}