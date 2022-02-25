#include <iostream>
using namespace std;

int main()
{
    cout << "1102016" << endl;
    cout << "陳宥瑜" << endl;
    int a = 0, b = 0;
    int first = 1234;
    int all[3024] = { 0 };
    for (int x = 0; first < 9876; first++)
    {
        if (zero(first) && repeat(first))
        {
            all[x] = first;
            x++;
        }
    }
    int ans;
    while (a != 4)
    {
        for (int x = 0; x < 3024; x++)
        {
            if (all[x] != 0)
            {
                ans = all[x];
                cout << "醜八怪小貝貝問:" << ans << endl;
                all[x] = 0;
                break;
            }
        }
        cout << "請神奇海螺回答" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;
    }
}
void number(int n, int num[])
{
    num[0] = n / 1000;
    num[1] = (n / 100) % 10;
    num[2] = (n / 10) % 10;
    num[3] = n % 10;
}
bool zero(int n)
{
    int num[4];
    number(n, num);
    if (num[0] * num[1] * num[2] * num[3] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool repeat(int n)
{
    int num[4];
    number(n, num);
    int A[9] = { 1,2,3,4,5,6,7,8,9 };
    for (int x = 0; x <= 3; x++)
    {
        if (A[num[x]] == 0)
            return false;
        else
        {
            A[num[x]] = 0;
            return true;
        }
    }
}
