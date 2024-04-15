#include<stdio.h>
#include<iostream>
using namespace std;
long long fu(int n ) {
	if (n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return n*fu(n-1);
	}
}

int main() {
	long long f[30] = { 0 }, g[30] = {0};
	int n = 0;
	long long sum = 1;
	f[0] = 0, f[1] = 1;
	g[0] = 0, g[1] = 1;
	cout << "input n : ";
	cin >> n;
	cout << "°j°é : \n";
	for (int i = 0; i <= n; i++)
	{
		if (i == 0 || i == 1)
		{
			cout << 1 << " ";
		}
		else {
			sum *= i;
			//f[i] = f[i - 1]*f[i - 2];
			cout << sum << " ";
		}
	}
	cout << endl;
	
	cout << "»¼°j : \n" ;
	//fu(n,g);
	for (int i = 0; i <= n; i++)
	{
		g[i]=fu(i);
		cout << g[i] << " ";
	}
}