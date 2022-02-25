#include<iostream>
using namespace std;

void split(int n, int N[])
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}
bool hasZero(int n)
{
	int N[4];
	split(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0)
		return true;
	else
		return false;
}
bool noRepeat(int*N)
{
	if (N[0] == N[1] || N[0] == N[2] || N[0] == N[3] || N[1] == N[2] || N[1] == N[3] || N[2] == N[3])
		return true;
	else
		return false;
}
void check(int target, int test, int* checkA, int* checkB)
{
	*checkA = 0;
	*checkB = 0;
	int targetArray[4];
	int testArray[4];
	split(target, targetArray);
	split(test, testArray);
	int C[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
		C[targetArray[i]] = -1;
	for (int i = 0; i < 4; i++)
	{
		if (C[testArray[i]] == -1)
		{
			if (testArray[i] == targetArray[i])
				*checkA += 1;
			else
				*checkB += 1;
		}
	}
}
int main()
{
  cout<<"1102022"<<endl;
  cout<<"陳晰"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  return 1;
}
