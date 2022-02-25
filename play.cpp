#include <iostream>
using namespace std;

void split(int n, int N[]);
bool hasZero(int n);
void filter(int test1,int test2, int* answera, int* answerb);
bool Same(int n);

void split(int n, int N[])
{
	//切割成四份
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}

bool hasZero(int n)
{
	//將零踢出
	int N[4];
	split(n, N);
	return N[0] != 0 && N[1] != 0 && N[2] != 0 && N[3] != 0;
}

void filter(int test1,int test2, int* answera, int* answerb)
{
	//檢查AB
	*answera = 0;//指標answera，用作回傳值
	*answerb = 0;//指標answerb，用作回傳值

	int test1Arr[4];
	int test2Arr[4];
	split(test1, test1Arr);
	split(test2, test2Arr);

	//幾A的部分
	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int n = 0; n < 4; n++)
		compare[ test1Arr[n]] = -1;

	//幾B的部分
	for (int n = 0; n< 4; n++)
	{
		if (compare[test2Arr[n]] == -1)
		{
			if (test2Arr[n] == test1Arr[n])
				*answera+=1;
			else
				*answerb+=1;
		}
	}
}

bool Same(int n)
{
	//判斷幾A幾B
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

int main()
{
  cout<<"1092047"<<endl;
  cout<<"汪士翔"<<endl;
  return 1;
  cout<<"demo"<<endl;
  
  int a = 0, b = 0;
	int allpossibilities[3024] = { 0 };

	int num = 1234;
	for (int n = 0; num <= 9876; num++)
	{
		if (hasZero(num) && Same(num))
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
				cout << "電腦猜測數字為" << enter << endl;
				allpossibilities[n] = -1;
				break;
			}
		}
		cout << "請輸入數字以及得到的結果" << endl;
		cout << "請輸入A: ";
		cin >> a;
		cout << "請輸入B: ";
		cin >> b;

		int answera;
		int answerb;
		for (int n = 0; n < 3024; n++)
		{
			if (allpossibilities[n] != -1)
			{
				filter(enter, allpossibilities[n], &answera, &answerb);//取回answera,answerb的地址
				if (answera != a || answerb != b)
					allpossibilities[n] = -1;
			}
		}
	}
	cout << "猜對啦!答案是" << enter <<endl;
	return 0;
}
