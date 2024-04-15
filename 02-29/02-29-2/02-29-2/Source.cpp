#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;



int main() {
	//FILE* pFile = nullptr;
	ifstream ifs;
	int A[3][3][3] = { 0 }, ans[3][3] = { 0 };
	char temp = 0;
	/*pFile = fopen("./02txt.txt", "r");
	if (pFile==NULL)
	{
		cout << "開檔失敗~~~\n";
		return 0;
	}
	else
	{
		cout << "成功!!\n";
	}*/
	ifs.open("02.txt");
	if (!ifs.is_open())
	{
		cout << "erro!!!!\n";
		return 0;
	}
	for (int x = 0; x < 3; x++)
	{
		ifs >> temp;
		cout << temp << "矩陣:\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				ifs >> A[x][i][j];
				cout << A[x][i][j]<<" ";
			}
			cout << endl;
		}
	}
	cout << "轉置後的矩陣:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			cout << A[0][j][i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			ans[i][j] = 0;
			for (size_t k = 0; k < 3; k++)//0 1
			{
				ans[i][j] += A[0][i][k] * A[1][k][j];
			}
			//cout << ans[i][j] << " ";
			//ans[i][j] = A[0][i][j] * A[1][i][j] + A[0][i + 1][j] * A[1][i][j + 1] + A[0][i + 2][j] * A[1][i][j + 2];
		}
	}
	cout << "矩陣D=A*B+C\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			ans[i][j] += A[2][i][j];
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}