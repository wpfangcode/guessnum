#include "pch.h"
#include <iostream>
using namespace std;

void split(int n, int N[]);
bool nozero(int n);
void filter(int test1, int test2, int* answera, int* answerb);
bool norepeat(int n);

int main()
{
	int a = 0, b = 0;
	int allpossibilities[3024] = { 0 };

	int num = 1234;
	for (int n = 0; num <= 9876; num++)
	{
		if (nozero(num) && norepeat(num))
		{
			allpossibilities[n] = num;
			n++;
		}
	}

	int enter;
	while (a != 4)
	{
		for (int n = 0; n < 3024; n++)
		{
			if (allpossibilities[n] != -1)
			{
				enter = allpossibilities[n];
				cout << "computer guess:" << enter << endl;
				allpossibilities[n] = -1;
				break;
			}
		}
		cout << "Input number" << endl;
		cout << "Input A: ";
		cin >> a;
		cout << "Input B: ";
		cin >> b;

		int answera;
		int answerb;
		for (int n = 0; n < 3024; n++)
		{
			if (allpossibilities[n] != -1)
			{
				filter(enter, allpossibilities[n], &answera, &answerb);
				if (answera != a || answerb != b)
					allpossibilities[n] = -1;
			}
		}
	}
	cout << "The answer is:" << enter << endl;
	return 0;
}

void split(int n, int N[])
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}

bool nozero(int n)
{
	int N[4];
	split(n, N);
	return N[0] != 0 && N[1] != 0 && N[2] != 0 && N[3] != 0;
}

void filter(int test1, int test2, int* answera, int* answerb)
{
	*answera = 0;
	*answerb = 0;

	int test1Arr[4];
	int test2Arr[4];
	split(test1, test1Arr);
	split(test2, test2Arr);

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int n = 0; n < 4; n++)
		compare[test1Arr[n]] = -1;

	for (int n = 0; n < 4; n++)
	{
		if (compare[test2Arr[n]] == -1)
		{
			if (test2Arr[n] == test1Arr[n])
				*answera += 1;
			else
				*answerb += 1;
		}
	}
}

bool norepeat(int n)
{
	int N[4];
	split(n, N);

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int k = 0; k < 4; k++)
	{
		if (compare[N[k]] == -1)
			return false;
		else
			compare[N[k]] = -1;
	}
	return true;
}
