#include<iostream>
#include<stdio.h>
using namespace std;
int hanoi(int n, char A, char B, char C) 
{	static int sum = 0;
	if (n ==1 )
	{
		printf("%d �q %c ���� %c \n", n, A, C);
		sum++;
	}
	else
	{
		hanoi(n - 1, A, C, B);
		printf("%d �q %c ���� %c \n", n, A, C);
		hanoi(n - 1, B, A, C);
		sum++;
	}
	return sum;}

int main() {
	int n = 0;
	cout << "�п�J���@�� : ";
	cin >> n;
	cout<<hanoi(n, 'A', 'B', 'C');

	return 0;
}