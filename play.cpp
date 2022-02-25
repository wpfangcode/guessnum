#include <iostream>
using namespace std;

class guest1A2B {
public:
	int Ans[4] = { 0 }, PossibleNum[9] = { 1,2,3,4,5,6,7,8,9 };
	int a = 0, b = 0;
	int p = 9;
	int respond[2] = { 0 };
	

	void firstStep()
	{
		cout << "1234" << endl;
	}
	void secondStep()
	{
		cout << "5678" << endl;
	}
	void thirdStep()
	{
		cout << "3456" << endl;
	}
	void possible(int n)
	{
		for (int i = 0; i < p; i++)
		{
			if (PossibleNum[i] == n)
			{
				int j = i;
				while (PossibleNum[j] != 0)
				{
					PossibleNum[j] = PossibleNum[j + 1];
					j++;
				}
				break;
			}
		}
	}
	void guest()
	{

	}
	void input()
	{
		cin >> respond[0] >> respond[1];
		a = respond[0]; b = respond[1];
	}
};

int main()
{
  cout<<"1092027"<<endl;
  cout<<"羅尹晴"<<endl;
  //-----------------------
  cout<<endl;
  
  int a1, b1, a2, b2, a3, b3, ap = 0;
	bool has9 = false;
	guest1A2B n;

	n.firstStep();
	n.input();
	a1 = n.a; b1 = n.b;
	if ((a1 + b1) == 4) 
	{
		for (int i = 1; i <= 4; i++)
		{
			n.Ans[i] = i;
		}
		//
		
	}
	else if ((a1 + b1) == 0)
	{
		for (int i = 1; i <= 4; i++)
		{
			n.possible(i);
		}
	}

	n.secondStep();
	n.input();
	a2 = n.a; b2 = n.b;
	if ((a2 + b2) == 4)
	{
		for (int i = 5; i <= 8; i++)
		{
			n.Ans[i] = i;
		}
		//

	}
	else if ((a2 + b2) == 0)
	{
		for (int i = 5; i <= 8; i++)
		{
			n.possible(i);
		}
	}

	if ((a1 + b1 + a2 + b2) == 3)
	{
		n.Ans[ap] = 9;
		ap++;
		has9 = true;
	}
	else if ((a1 + b1 + a2 + b2) == 4)
	{
		n.possible(9);
	}

	//n.guest();
  
  return 1;
}
