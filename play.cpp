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

void check(int guessnum,int randnum,int *finda, int *findb)//一個是猜的數字 一個是數字表中符合條件的數字 如果數字表中的數字跟猜的數字符合幾A幾B(找出數字表跟猜的數之間的AB關係)
{
    * finda = 0;
    * findb = 0;
    int k = 0;
    int guenumarr[4];
    int randnumarr[4];
    split(guessnum, guenumarr);
    split(randnum, randnumarr);
    for (k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++)
        {
            if (guenumarr[i] == randnumarr[k])
            {
                *findb+=1;
            }

        }
    }
    k = 0;
    for (int i = 0; i < 4; i++)
    {
        if (guenumarr[i] == randnumarr[k])
        {
            *findb-=1;
                k++;
                *finda+=1;
        }
        else
        {
            k++;
        }
    }
}

int main()
{
    int a = 0;
    int b = 0;
	cout<<"s1102013"<<endl;
	cout<<"蕭家證"<<endl;
    int allnumber[3024] = { 0 };
    int i;
    int guess, guess2;
    int finda, findb;
    int k = 0;

    int number = 1234;
    for (i = 0; number <= 9876; number++)
    {
        if (noZero(number) && noRepeat(number))//如果數字不重複也沒有0 把數字存到數字表裡面 i++ i預計會到3024個數
        {
            allnumber[i] = number;
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
                guess2 = guess;
                break;
            }
        }
        cout << "請輸入數字與AB" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;

        for (i = 0; i < 3024; i++)
        {
            if (allnumber[i] != -1)
            {
                check(guess, allnumber[i], &finda, &findb);
                if (finda != a || findb != b)
                {
                    allnumber[i] = -1;
                }
            }
        }
            for (i = 0; i < 3024; i++)
            {
                if (allnumber[i] != -1)
                {
                    break;
                }
                else {
                    k++;
                }
                if (k == 3024&&a<4) {
                    cout << "你484給錯題示 蛤! ˋ口ˊ!" << endl;
                    cout << "系統提示:過程中可能給錯提示 請檢查過程。" << endl;
                    return 0;
                }
            }
        

    }
    cout << "答案是" << guess << endl;
    return 0;
}
