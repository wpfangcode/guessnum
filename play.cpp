#include <iostream>
using namespace std;

void split(int n, int N[])
{
    N[0] = n / 1000;
    N[1] = n / 100 % 10;
    N[2] = n / 10 % 10;
    N[3] = n % 10;
}
bool has0(int N[])
{
    return !(N[0] * N[1] * N[2] * N[3]);
}
bool isrepeat(int N[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (N[i] == N[j])
                return true;
        }
    }
    return false;
}
bool check(int a, int b)
{
    return (a == 4);
}
int main()
{
  cout<<"student id"<<endl;
  cout<<"name"<<endl;
  //-----------------------
  int N[4];
    int a = 0, b = 0;
    for (int n = 1234; n <= 9876; n++)
    {
        split(n, N);
        if (has0(N) || isrepeat(N))
            ;
        else
        {
            cout << n << endl;
            cin >> a >> b;
            if (check(a, b))
                break;
        }
    }
  return 1;
}
