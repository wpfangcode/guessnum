#include <iostream>
using namespace std;

bool noZero(int i);
bool noRepeat(int i);
void split(int i, int arr[]);
void check(int target, int test, int* checkA, int* checkB);
int main()
{
	int a = 0, b = 0;
	int allnumbers[3024] = { 0 };
	int num = 1234;
	for (int i = 0; num <= 9876; num++)
	{
		if (noZero(num) && noRepeat(num))
		{
			allnumbers[i] = num;
			i++;
		}
	}
	bool noZero(int i)
	{
		int arr[4];
		split(i, arr);
		return arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0;
	}
	bool noRepeat(int i)
	{
		int arr[4];
		split(i, arr);
		int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };//檢查數字
		for (int j = 0; j < 4; j++)
		{
			if (compare[arr[j]] == -1)
				return false;
			else
				compare[arr[j]] == -1;
		}
		return ture;
	}
	void split(int i, int arr[])
	{
		arr[0] = i / 1000;
		arr[1] = i / 100 % 10;
		arr[2] = i / 10 % 10;
		arr[3] = i % 10;
	}
	int guess;
}
