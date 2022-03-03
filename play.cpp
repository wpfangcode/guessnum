#include <iostream>
using namespace std;

void split(int n, int N[]) //spilt number
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}



bool noZero(int n)
{
	int N[4];
	split(n, N);
	if (N[0] && N[1] && N[2] && N[3])
		return true;
	else
		return false;
}



bool noReapeat(int n)
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int N[4];
	split(n, N);
	 if ((N[0]==N[1]) || (N[0]==N[2]) || (N[0]==N[3]) || (N[1]==N[2]) || (N[1]==N[3]) || (N[2]==N[3]))
        return false;
    else
        return true;
}


int main()
{
	cout << "1072015黃翰強" << endl;
	int a = 0, b = 0;
	int allanswers[3024] = { 0 };

	int num = 1234;
	for (int i = 0; num <= 9876; num++) 
  {
		if (noZero(num) && noReapeat(num)) 
    {
			allanswers[i] = num;
			i++;
		}
	}

	int guess;
	while (a != 4)
  {
		for (int i = 0; i < 3024; i++)
    {
			if (allanswers[i] != -1) 
      {
				guess = allanswers[i];
				cout << "電腦猜:" << guess << endl;
				allanswers[i] = -1;
				break;
			}
		}

		cout << "請依序輸入與數字對應的A和B的數量" << endl;
		cout << "A: ";
		cin >> a;
		cout << "B: ";
		cin >> b;

	}

	cout << "答案為" << guess << endl;
	return 0;
}






  
  
