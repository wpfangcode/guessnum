#include <iostream>
using namespace std;
void value(int n,int N[])
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}
bool nozero(int n)
{
	int N[4];
	value(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0)
		return false;
	else
		return true;
}
bool nosame(int n)
{
	int N[4];
	value(n,N);
	if (N[0] == N[1] || N[0] == N[2] || N[0] == N[3] || N[1] == N[2] || N[1] == N[3] || N[2] == N[3])
		return false;
	else
		return true;
}
void check(int target, int test, int* checkA, int* checkB)
{
	*checkA = 0;
	*checkB = 0;
	int targetArray[4];
	int testArray[4];
	value(target, targetArray);
	value(test, testArray);
	int compare[10] = {0,1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < 4; i++)
	{
		compare[i] = -1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (compare[i] == -1)
		{
			if (targetArray[i] == testArray[i])
				*checkA+=1;
			else
				*checkB+=1;
		}
	}
}
int main()
{
  cout<<"s1102050"<<endl;
  cout<<"洪碩亨"<<endl;
  
  cout<<"demo"<<endl;
  return 1;
	int a = 0, b = 0;
	int all[3024] = { 0 };
	int num = 1234;
	for (int i = 0; num <= 9876; num++)
	{
		if (nozero(num) && nosame(num))
		{
			all[i] = num;
			i++;
		}
	}
	int guess;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)
		{
			if (all[i] != -1)
			{
				guess = all[i];
				cout << "電腦猜測:" << guess << endl;
				all[i] = -1;
				break;
			}
		}
		cout << "請輸入數字對應的幾A幾B:" << endl;
		cout << "A:";
		cin >> a;
		cout << "B:";
		cin >> b;
		int checkA;
		int checkB;
		for (int i = 0; i < 3024; i++)
		{
			if (all[i] != -1)
			{
				check(guess, all[i], &checkA, &checkB);
				if (checkA != a || checkB != b)
					all[i] = -1;
			}
		}
	}
	 cout << "答案就是:" << guess << endl;
		return 0;
}
