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
	}
	cout << "The Final Answer is:" << guess << endl;
	return 0;
}
