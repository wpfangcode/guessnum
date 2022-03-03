#include <iostream>
using namespace std;

void number(int x, int num[])
{
    num[0] = x / 1000;
    num[1] = (x / 100) % 10;
    num[2] = (x / 10) % 10;
    num[3] = x % 10;
}
bool zero(int x)
{
    int num[4];
    number(x, num);
    if (num[0] * num[1] * num[2] * num[3] != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool repeat(int x)
{
    int num[4];
    number(x, num);
    int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)
    {
        if (A[num[i]] == -1)
            return false;
        else
        {
            A[num[i]] = -1;
        }
    }
    return true;
}
void check(int purpose, int test, int* check1, int* check2)
{
    *check1 = 0;
    *check2 = 0;
    int Purpose[4];
    int Test[4];
    number(purpose, Purpose);
    number(test, Test);
    int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int x = 0; x < 4; x++)
    {
        A[Purpose[x]] = -1;
    }
    for(int x=0;x<4;x++)
    {
        if (A[Test[x]] == -1)
        {
            if (Test[x] == Purpose[x])
            {
                *check1 += 1;
            }
            else
            {
                *check2 = 1;
            }
        }
    }
}
int main()
{
    cout << "1102016" << endl;
    cout << "陳宥瑜" << endl;
    int a = 0, b = 0;
    int num = 1234;
    int all[3024] = { 0 };
    for (int x = 0; num <= 9876; num++)
    {
        if (zero(num) && repeat(num))
        {
            all[x] = num;
            x++;
        }
    }
    int ans;
    while (a != 4)
    {
        for (int x = 0; x < 3024; x++)
        {
            if (all[x] != -1)
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
        int check1, check2;
        for (int x = 0; x < 3024; x++)
        {
            if (all[x] != -1)
            {
                check(ans, all[x], &check1, &check2);
                if (check1 != a || check2 != b)
                {
                    all[x] = -1;
                }
            }
        }
    }
    cout << "the answer is:" << ans << endl;
}
