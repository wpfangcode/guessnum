
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
unsigned const int DataA = 3024;
int N1[4] = { 0,0,0,0 }, ComNum[4] = { 0,0,0,0 };
int ANSDATA[DataA];
void split(int N)
{
	N1[0] = N / 1000;
	N1[1] = (N / 100) % 10;
	N1[2] = (N / 10) % 10;
	N1[3] = N % 10;
}
void Comsplit(int N)
{
	ComNum[0] = N / 1000;
	ComNum[1] = (N / 100) % 10;
	ComNum[2] = (N / 10) % 10;
	ComNum[3] = N % 10;
}
bool Haszero(int N)
{
	split(N);
	if (N1[0] * N1[1] * N1[2] * N1[3] == 0)
		return true;
	else
		return false;
}
bool Isrepeat(int N)
{

	bool ANS = false;
	split(N);
	for (unsigned int y = 0; y < 3; ++y)
	{
		for (unsigned int x = y + 1; x < 4; ++x)
		{
			/* -----------Inner loop  indicate y+1 mean no check onitself

				 this is test case cout << N1[y] << N1[x] << endl;

			*/
			if (N1[y] == N1[x])
			{
				//cout << N1[y];
				return true;
			}
		}
	}
	if (ANS)
		return true;
	else
		return false;
}
void ABCount(unsigned int COMANS, unsigned a, unsigned b)
{
	/*------------this is debug code
	*
		for (auto i : ComNum)
		cout << i;

		for (auto i : ANSDATA)
			cout << i << " ";
		cout << endl;

		cout << count <<" ";
	*/
	unsigned int count = 0;
	Comsplit(ANSDATA[COMANS]);
	for (unsigned int data1 = 0; data1 < DataA && ANSDATA[data1]!=0; ++data1)
	{
		split(ANSDATA[data1]);
		for (unsigned int i = 0; i < 4; ++i)
		{
			if (b == 4)
			{
				for (unsigned int i = 0; i < 4; ++i)
				{
					if (ComNum[i] == N1[i])
						ANSDATA[data1] = 0;
				}
			}
			for (unsigned int j = 0; j < 4; ++j)
			{
				if (ComNum[i] == N1[j])
					++count;
				if (b == 0 && ComNum[i] == N1[j])
					ANSDATA[data1] = 0;
			}
		}
		if (count < a + b)
			ANSDATA[data1] = 0;
		
		count = 0;
	}


}
int main()
{
	int count = 0;
	unsigned int ComANS = 0, inputA = 0, inputB = 0;
	ComANS = 0;
	// ----------- INITIALIZE DATA

	for (unsigned int input = 1234, i = 0; input <= 9876 && i < 3024; ++input)
	{
		if (!Isrepeat(input) && !Haszero(input))
		{
			ANSDATA[i] = input;
			++i;

			//     ++count;
		}

	}
	/*----------------- this is test case
	*
	for (auto i : ANSDATA)
		cout << i <<" ";
	cout << endl;
	cout << "\n" << count << endl;


	*/

	// ----------- GAME START

	while (inputA != 4 && ComANS < DataA)
	{
		if (ANSDATA[ComANS] != 0)
		{
			cout << ComANS << " " << ANSDATA[ComANS] << endl;
			cout << 'A';
			cin >> inputA;
			cout << "B";
			cin >> inputB;
			cout << endl;
			ABCount(ComANS, inputA, inputB);
		}

		/*
		* while(ANSDATA[ComANS] == 0)
		{
			++ComANS;
		}
		cout << ComANS<< " " << ANSDATA[ComANS] << endl;

		for (auto i : ANSDATA)
			cout << i << " ";
		*/
		++ComANS;
	}
	cout<<"student id: 1091806"<<endl;
  cout<<"name Chen Yen Yi"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  return 1;
}



