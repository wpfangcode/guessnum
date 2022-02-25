#include <iostream>
using namespace std;
void split(int n, int num[])
{
    num[0] = n / 1000;
    num[1] = (n / 100) % 10;
    num[2] = (n / 10) % 10;
    num[3] = n % 10;
}
bool noZero(int n)
{
	int num[4];
	split(n, num);
	if (num[0] != 0 && num[1] != 0 && num[2] != 0 && num[3] != 0)
		return true;
	else
		return false;
}
bool noRepeat(int n)
{
	int arr[4];
	split(n, arr);
	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
	{
		if (compare[arr[i]] == 100)
			return false;
		else
			compare[arr[i]] = 100;
	}
	return true;
}
void check(int goal, int test, int* cA, int* cB)
{
	int goalArr[4];
	int testArr[4];
	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	*cA = 0;
	*cB = 0;
	split(goal, goalArr);
	split(test, testArr);

	for (int i = 0; i < 4; i++)
		compare[goalArr[i]] = 100;
	for (int i = 0; i < 4; i++)
	{
		if (compare[testArr[i]] == 100)
		{
			if (testArr[i] == goalArr[i])
				*cA += 1;
			else
				*cB += 1;
		}
	}
}

int main()
{
	cout << "1102062" << endl;
	cout << "羅健毅" << endl;
	//----------------------------
    int a = 0, b = 0;
	int all[3024] = { 0 };
    int num = 1234;

	for (int i = 0; num <= 9876; num++)
	{
		if (noZero(num) && noRepeat(num))
		{
			all[i] = num;
			i++;
		}
	}

	int g;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)
		{
			if (all[i] != 100)
			{
				g = all[i];
				cout << "神奇海螺猜：" << g << endl;
				all[i] = 100;
				break;
			}
		}
		cout << "請輸入 A 和 B " << endl;
		cout << "A：";
		cin >> a;
		cout << "B：";
		cin >> b;

		int cA, cB;
		for (int i = 0; i < 3024; i++)
		{
			if (all[i] != 100)
			{
				check(g, all[i], &cA, &cB);
				if (cA != a || cB != b)
					all[i] = 100;
			}
		}
	}
	cout << "神奇海螺終於猜到了：" << g <<"!" << endl;
	return 1;
}
