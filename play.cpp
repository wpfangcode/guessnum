#include <iostream>
using namespace std;

void split(int n, int four[])
{
    four[0] = n / 1000;
    four[1] = (n / 100) % 10;
    four[2] = (n / 10) % 10;
    four[3] = n % 10;
}
bool noZero(int n)
{
    int four[4];
    split(n, four);
    if ((four[0]) && (four[1]) && (four[2]) && (four[3]) != 0)
        return true;
    else
        return false;
}
bool noRepeat(int n)
{
    int four[4];
    split(n, four);
    if ((four[0] != four[1]) && (four[0] != four[2]) && (four[0] != four[3]) && (four[1] != four[2]) && (four[1] != four[3]) && (four[2] != four[3]))
        return true;
    else
        return false;

}

int main()
{
  cout<<"s1102013"<<endl;
  cout<<"蕭家證"<<endl;
	int a = 0;
	int b = 0;
    int allnumber[3024] = { 0 };
    int i;
    int guess;

    int number = 1234;
    for(i=0;number<=9876;number++)
    {
        if (noZero(number) && noRepeat(number) )
        {
            allnumber[i]=number;
                i++;
        }
    }
    while (a != 4)
    {
        for (i = 0; i < 3024; i++)
        {
            if (allnumber[i] != -1)
            {
                guess = allnumber[i];
                cout << "電腦猜:" << guess << endl;
                allnumber[i] = -1;
                break;
            }
        }
        cout << "請輸入數字與AB" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;
    }

}
