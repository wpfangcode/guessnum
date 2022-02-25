#include <iostream>
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
	/*
	if (N[0] * N[1] * N[2] * N[3] = 0)
		return true;
	else
		return false;
	*/
	return!(N[0] && N[1] && N[2] && N[3]);
}

void testcase1()
{
	int N[4];
	split(3456, N);
	cout << N[0] << " " << N[1] << " " << N[2] << " " << N[3] << endl;
}

void testcase2()
{
	if (hasZero(1023) == true)cout << "1023 has zero" << endl;
	if (hasZero(1523) == false)cout << "1523 no zero" << endl;
}

int main()
{
  cout<<"1102004"<<endl;
  cout<<"江芸安"<<endl;
	testcase1();
	testcase2();
}
