#include<iostream>
#include<stdio.h>
using namespace std;
int hanoi(int n, char A, char B, char C) 
{	static int sum = 0;
	if (n ==1 )
	{
		printf("%d 從 %c 移至 %c \n", n, A, C);
		sum++;
	}
	else
	{
		hanoi(n - 1, A, C, B);
		printf("%d 從 %c 移至 %c \n", n, A, C);
		hanoi(n - 1, B, A, C);
		sum++;
	}
	return sum;}

int main() {
	int n = 0;
	cout << "請輸入任一數 : ";
	cin >> n;
	cout<<hanoi(n, 'A', 'B', 'C');

	return 0;
}