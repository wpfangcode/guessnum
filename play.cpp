#include "pch.h"
#include <iostream>
using namespace std;

void split(int i, int N[])
{
	N[0] = i / 1000;
	N[1] = (i / 100) % 10;
	N[2] = (i / 10) % 10;
	N[3] = i % 10;
}

bool iszero(int i)
{
	int N[4];
	split(i, N);
	if ((N[0] * N[1] * N[2] * N[3]) == 0)
		return true;
	else
		return false;
}
bool isrepeat(int i)
{
	int N[4];
	split(i, N);
	if (N[0] == N[1] || N[0] == N[2] || N[0] == N[3] || N[1] == N[2] || N[1] == N[3] || N[2] == N[3])
		return true;
	else
		return false;
}

void check(int target, int test, int* checkA, int* checkB)
{
	*checkA = 0;
	*checkB = 0;

	int targetarr[4];
	int testarr[4];
	split(target, targetarr);
	split(test, testarr);

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
		compare[targetarr[i]] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (compare[testarr[i]] == -1)
		{
			if (testarr[i] == targetarr[i])
				*checkA++;
			else
				*checkB++;
		}
	}

}

int main()
{
	int alldata[3024] = { 0 };
	int num = 1234;
	for (int i = 0; num <= 9876; num++)
	{
		if (!(iszero(num) )&& !(isrepeat(num)))
		{
			alldata[i] = num;
			i = i + 1;
		}
	}
	int a = 0, b = 0;
	int guess;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)
		{
			if (alldata[i] != -1)
			{
				guess = alldata[i];
				cout << "電腦猜:" << guess << endl;
				alldata[i] = -1;
				break;
			}
		}

		cout << "輸入AB:" << endl;
		cin >> a >> b;

		int checkA, checkB;
		for (int i = 0; i < 3024; i++)
		{
			if (alldata[i] != -1)
			{
				check(guess, alldata[i], &checkA, &checkB);
				if (checkA != a || checkB != b)
					alldata[i] = -1;
			}
		}
	}
	cout << "答案:" << guess<<endl;
  cout<<"1102003"<<endl;
  cout<<"林雅棋";
	/*
	int N[4];
	split(1234, N);
	cout << N[0] << " " << N[1] << " " << N[2] << " " << N[3] << endl;
	if (!(iszero(1230)))
		cout << "NOTZERO";
	else
		cout << "ISZERO";
	cout << endl;
	if (isrepeat(6536))
		cout << "REPEAT";
	else
		cout << "NOTREPEAT";
	*/
}
