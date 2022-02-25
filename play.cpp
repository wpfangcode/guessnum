#include <iostream>
using namespace std;
int main()
{
    cout<<"1102056<<endl;
    cout<<"洪慈惠"<<endl;
    int i, n, a, b, c, d, A, B;
    cin >> n;
    i = 1;

    //把數字拆成a、b、c、d
    a = ((n / 10) / 10) / 10;   //千位數
    b = ((n / 10) / 10) % 10;   //百位數
    c = (n / 10) % 10;          //十位數
    d = n % 10;                 //個位數

    while (cin >> i)  //我們猜得值
    {
        A = 0;
        B = 0;
        
        

        if (i == 0)
        {
            cout << A << "A" << B << "B" << endl;
        }
        else if (i != 0)
        {
            for (int j = 0; j < 4; j++)    //j=0個位數j=1十位數j=2百位數j=3千位數
            {
                if (i % 10 == a)  //1234%10=a=4
                {
                    if (j == 3)   //位置
                    {
                        A++;
                    }
                    else
                    {
                        B++;
                    }
                }
                else if (i % 10 == b)  //123%10=b=3
                {
                    if (j == 2)
                    {
                        A++;
                    }
                    else
                    {
                        B++;
                    }
                }
                else if (i % 10 == c)  //12%10=c=2
                {
                    if (j == 1)
                    {
                        A++;
                    }
                    else
                    {
                        B++;
                    }
                }
                else if (i % 10 == d)  //1%10=d=1
                {
                    if (j == 0)
                    {
                        A++;
                    }
                    else
                    {
                        B++;
                    }
                }
                i = i / 10;
                if (j == 3)
                {
                    cout << A << "A" << B << "B" << endl;
                }
            }
        }
    }
    return 0;
}
