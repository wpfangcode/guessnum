#include <iostream>
using namespace std;
void spilt(int n, int N[])
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}
bool nozero(int n)
{
	int N[4];
	spilt(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0)
		return false;
	else return true;
}
bool norepeat(int n)
{
	int N[4];
	spilt(n, N);
	if (N[0] == N[1])
		return false;
	else if (N[0] == N[2])
		return false;
	else if (N[0] == N[3])
		return false;
	else if (N[1] == N[2])
		return false;
	else if (N[1] == N[3])
		return false;
	else if (N[2] == N[3])
		return false;
	else
		return true;
}
void check(int first, int test, int* checkA, int* checkB)
{
	*checkA = 0;
	*checkB = 0;
	int firstN[4];
	int testN[4];
	spilt(first, firstN);
	spilt(test, testN);

	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
		A[firstN[i]] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (A[testN[i]] == -1)
		{
			if (testN[i] == firstN[i])
				*checkA = *checkA + 1;
			else
				*checkB = *checkB + 1;
		}
	}
}
int main()
{
  cout<<"1102035"<<endl;
  cout<<"袁萱芳"<<endl;
  int N[3024] = { 0 };
	int a = 0, b = 0;
	int n = 1234;
	for (int i = 0; n <= 9876; n++)
	{
		if (nozero(n) && norepeat(n))
		{
			N[i] = n;
			i++;
		}
	}
	int guess = 0;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)
		{
			if (N[i] != 0)
			{
				guess = N[i];
				cout << "Answer:" << guess << endl;
				N[i] = 0;
				break;
			}
		}
		cout << "A:";
		cin >> a;
		cout << "B:";
		cin >> b;
		cout<< endl;
		int checkA, checkB;
		for (int i = 0; i < 3024; i++)
		{
			if (N[i] != 0)
			{
				check(guess, N[i], &checkA, &checkB);
				if (checkA != a || checkB != b)
					N[i] = 0;
			}
		}
	}
	cout << "The Final Answer is:" << guess << endl;
	return 0;
}
