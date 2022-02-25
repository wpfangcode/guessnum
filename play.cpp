#include <iostream>
using namespace std;

bool havesame(int *A)       //判斷是否有相同數字
{
	if (A[0] == A[1] || A[0] == A[2] || A[0] == A[3] || A[1] == A[2] || A[1] == A[3] || A[2] == A[3])
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool havezero(int *A)      //判斷數字中是否有0
{
	if (A[0] * A[1] * A[2] * A[3] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	int A[4] = { 1,2,3,4 };
	int C[9] = { 1,2,3,4,5,6,7,8,9 };
	int x;
	int y;
	int lastsum=0;
	cout << "1102001" << endl;
	cout << "沈羿伶" << endl;
	
	for (int n = 0;n <= 8000;n++)
	{
		for (int n = 0;n <= 3;n++)
		{
			cout << A[n];
			if (n == 3)
			{
				cout << endl;
			}
		}
		cin >> x >> y;
		if (x == 4 && y==0)                                 //4A,遊戲結束
		{
			cout << "Game over!" << endl;
			break;
		}
		else
		{
			if (x + y == 0)                                //四個數字皆為錯誤
			{
				for (int n = 0;n <= 3;n++)
				{
					for (int i = 0;i <= 8;i++)
					{
						if (C[i] == A[n])
						{
							C[i] = 0;
						}
					}
				}
			}
			else if (x + y < 4)                           //數字有誤
			{
				if (lastsum > (x + y))        //x+y總數減少
				{
					continue;
					lastsum = (x + y);
				}
				else if(lastsum == (x + y))  //x+y總數不變
				{

				}
				else                         //x+y總數增加
				{
					lastsum = (x + y);
				}
			}
			else if (x + y == 4)                        //數字皆正確,但位置有誤
			{

			}
			else                                        //玩家輸入錯誤的x,y
			{
				cout << "Error" << endl;
				break;
			}
		}
	}
}
