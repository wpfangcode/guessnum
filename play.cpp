#include <iostream>
using namespace std;
//數字分成四塊
void split(int i, int arr[]) 
{
	arr[0] = i / 1000;  //假設i=1234 arr[0]=1234/1000 -> 1
	arr[1] = (i / 100) % 10; //arr[1]=(1234/100)%10=12%10 -> 2
	arr[2] = (i / 10) % 10;  //arr[2]=(1234/10)%10=123%10 -> 3
	arr[3] = i % 10;  //arr[3]=1234%10 -> 4
}

//判斷列表內的數字有沒有零
bool noZero(int i)
{
	int arr[4]; 
	split(i, arr); 
	return arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0;
}

//判斷列表內的數字中有沒有重複的
bool noRepeat(int i)
{
	int arr[4];
	split(i, arr);

	int check[10] = { 0,1,2,3,4,5,6,7,8,9 }; //用來檢查的數字列
	for (int j = 0; j < 4; j++)
	{
		if (check[arr[j]] == -1)
			return false;
		else
			check[arr[j]] == -1;
	}
	return true;
}

int main()
{
	cout<<"1102031"<<endl;
	cout<<"黃舒榆"<<endl;
	cout << "Ans:4896";
	int allnumbers[3100] = { 0 }; //建立一個全部數字的列表
	int n= 1234; //數字從1234開始
	for (int i = 0; n <= 9876; n++)
	{
		if (noZero(n) && noRepeat(n)) //檢查沒有零且沒有重複
		{
			allnumbers[i] = n;
			i++;
		}
	}

	int a = 0;
	int guess;
	while (a != 4)
	{
		for (int i = 0; i < 3100; i++)
		{
			if (allnumbers[i] != 0)
			{
				guess = allnumbers[i];  //找出列表中第一個符合的數字
				cout << "猜:" << guess << endl;
				allnumbers[i] = -1; //猜完之後把這個數字從列表中刪除
				break;
			}
		}
	}
}
