#include<stdlib.h>
#include <iostream>
using namespace std;
void spilit(int n, int N[])
{

	N[0] = n / 1000;
	N[1] = n / 100 % 10;
	N[2] = n / 10 % 10;
	N[3] = n % 10;
}
bool haszero(int n)
{
	int N[4];
	spilit(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0) { return true; }
	else return false;
}
bool hassame(int n)
{
	int N[4];
	spilit(n, N);
	if (N[0] == N[1] || N[0] == N[2] || N[0] == N[3])
	{
		return true;
	}
	else if (N[1] == N[2] || N[1] == N[3])
	{
		return true;
	}
	else if (N[2] == N[3])
	{
		return true;
	}
	else return false;
}
int countA(int n,int m)
{
	int index[4];
	spilit(n, index);
	int index2[4];
	spilit(m, index2);
	int count=0;
	for(int x=0;x<4;x++)
	{
		if(index[x]==index2[x])
		{
			count++;
		}
	}
	return count;
}
int countB(int n,int m)
{
	int index[4];
	spilit(n, index);
	int index2[4];
	spilit(m, index2);
	int count=0;
	for(int y=0;y<4;y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (index[y] == index2[y])
			{
			}else if(index[y]==index2[x])
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
  cout<<"1092045"<<endl;
  cout<<"周鉅峰"<<endl;
	int A = 0;
	int B;
	int num= 2;//猜測次數
	int all[8643];//用於儲存所有可能數字排列的陣列(8643=9876-1234)
	all[0] = 1234;
	int index = 1234;
	for(int j=1;j<8643;j++)
	{
		all[j] =1234+j;
		if((haszero(all[j]) == true || hassame(all[j]) == true))
		{
			all[j] = 0;
		}
	}
	cout << "第 1 次猜數" << index << " ";
	cin >> A >> B;
	while(A<4)
	{
		for(int i=0;i<8643;i++)
		{
			if (all[i] != 0)
			{
				int nowa = countA(all[i],index);//nowa為目前對比結果A的數量
				int nowb = countB(all[i], index);//nowb為目前對比結果B的數量
				if (A == nowa && B == nowb)
				{
					continue;
				}
				else
				{
					all[i] = 0;
				}
			}
		}
		for(int k=0;k<8643;k++)
		{
			if(all[k]!=0)
			{
				index = all[k];
				break;
			}
		}
		cout << "第 " << num << " 次猜數" << index << " ";
		cin >> A >> B;
		num++;
	}
	cout << "great";
}
