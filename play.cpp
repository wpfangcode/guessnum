#include <pch.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout<<1102007<<endl;
  cout<<林芸<<endl;
	string ans;
	string gus;
	int A = 0;
	int B = 0;//A,B的共通點是數字一樣
	while (cin >> ans >> gus)
	{
		if (gus != "0000")//如果輸入是0000就結束
		{
			for (int i = 0; i < 4; i++)//i,j代表位置
			{
				for (int j = 0; j < 4; j++)
				{
					if (i == j && ans[i] == gus[j])//位置一樣,數字一樣就表示A
					{
						A++;
					}
					else if (i != j && ans[i] == gus[j])//位置不一樣,數字一樣就表示B
					{
						B++;
					}
				}
			}
			cout << A << "A" << B << "B" << endl;//輸出AB總和
			A = 0;
			B = 0;
		}
		else {
			break;
		}
	}
	return 0;
}
