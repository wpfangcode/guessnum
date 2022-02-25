#include <iostream>
using namespace std;

void split(int n,int N[])//將四位數分割
{
	N[0] = n / 1000;//千位
	N[1] = (n / 100) % 10;//百位
	N[2] = (n / 10) % 10;//十位
	N[3] = n % 10;//個位
}
bool noZero(int n)//沒有0
{
	int N[4];
	split(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0)
		return false;
	else
		return true;
}
bool noRepeat(int n)//沒有重複的數字(ex:5566)
{
	int N[4];
	split(n, N);
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
void check(int target, int test, int* checkA, int* checkB)//從電腦猜的數與人給的提示，檢查哪些數可以從列表中移除
{
	*checkA = 0;
	*checkB = 0;

	int targetArray[4];//答案
	int testArray[4];//猜測
	split(target, targetArray);
	split(test, testArray);

	int C[10] = { 0,1,2,3,4,5,6,7,8,9 };//檢查數字
	for (int i = 0; i < 4; i++)
		C[targetArray[i]] = -1;//若猜測1278,C={0,-1,-1,3,4,5,6,-1,-1,9}

	for (int i = 0; i < 4; i++)
	{
		if (C[testArray[i]] == -1)//如果有出現在裡面
		{
			if (testArray[i] == targetArray[i])//位置一樣
				*checkA += 1;// A+1
			else
				*checkB += 1;//位置不一樣 B+1
		}
	}
}

int main()
{
  cout<<"1102053"<<endl;
  cout<<"蕭渝樺"<<endl;
	int a = 0, b = 0;
	int A[3024] = { 0 };//列表:1234~9876減去有零的四位數和重複的數字總共有3024個數字

	int num = 1234;
	for (int i = 0; num <= 9876; num++)
	{
		if (noZero(num) && noRepeat(num))//檢查完沒有0 而且沒有重複
		{
			A[i] = num;//把整個數字放進列表
			i++;
		}
	}

	int guess;
	while (a != 4)
	{
		for (int i = 0; i < 3024; i++)
		{
			if (A[i] != -1)
			{
				guess = A[i];
				cout << "電腦猜測:" << guess << endl;
				A[i] = -1;
				break;
			}
		}
    
		//玩家提示電腦
		cout << "提示" << endl;
		cout << "A:";
		cin >> a;//輸入A
		cout << "B:";
		cin >> b;//輸入B

		int checkA, checkB;
		for (int i = 0; i < 3024; i++)//從電腦猜的數與人給的提示，檢查哪些數可以從列表中移除
		{
			if (A[i] != -1)//數字符合留下來 稍後繼續判斷
			{
				check(guess, A[i], &checkA, &checkB);
				if (checkA != a || checkB != b)//若不符合就移除該數字
					A[i] = -1;
			}
		}
	}
	cout << "答案就是" << guess << endl;
	return 0;
}

