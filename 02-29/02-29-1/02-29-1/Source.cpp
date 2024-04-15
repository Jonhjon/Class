#include<iostream>
#include<stdio.h>
using namespace std;
int func(int m, int n) {
	if (m == 0)
	{
		return n+1;
	}
	else if (n==0) {
		return func(m-1, 1);
	}
	else
	{
		return func(m - 1, func(m, n - 1));
	}
}



int main() {
	int m = 0, n = 0;
	cout << "input m n:";
	cin >> m;
	cin >> n;
	cout <<func(m, n);
	return 0;
}