  #include <iostream>
using namespace std;
void split(int n, int N[]);
bool nozero(int n);
bool norepeat(int n);
void check(int t, int test, int* checkA, int* checkB);

int main()
{
  cout>>1102005>>endl;
  cout>>歐姿含>>endl;
    int a=0;
    int b=0;
    int allnum[3024] = { 0 };//數字列表
    
    int num = 1234;//可猜的最小數字為1234
    for (int i = 0; num < 9876; num++)//可猜的最大數字為9876
    {
        if (nozero(num) && norepeat(num))//檢查完沒有0以及無重複數字
        {
            allnum[i] = num;//把數字放入陣列形成符合規則的可猜列表
            i++;
        }
    }
    
    int guess;//開始猜題
    while (a != 4)//a=4遊戲結束
    {
        for (int i = 0; i < 3024; i++)//走訪可猜列表
        {
            if (allnum[i] != -1)
            {
                guess = allnum[i];//可猜列表中最小的數字
                cout << "電腦猜:"<<guess << endl;
                allnum[i] = -1;
                break;
            }
        }
        
        //人輸出提示（對應的ＡＢ）
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;
        
        int checkA;
        int checkB;
        for (int i = 0; i < 3024; i++)
        {
            if (allnum[i] != -1)
            {
                check(guess, allnum[i], &checkA, &checkB);
                if (checkA != a || checkB != b)
                    allnum[i] = -1;
            }
        }
}
    return 0;
    }
void split(int n, int N[])
{
    N[0] = n / 1000;
    N[1] = (n / 100) % 10;
    N[2] = (n / 10) % 10;
    N[3] = n % 10;
}
bool nozero(int n)
{
    int N[4];//將數字拆成四項
    split(n, N);
    return (N[0] != 0 && N[1] != 0 && N[2] != 0 && N[3] != 0);//四個數都不是零 return_true 否則 return_false
}
bool norepeat(int n)//檢查數字是否重複
{
    int N[4];
    split(n, N);
    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)//檢查剛剛分割的數字（在陣列中將該數標示為-1,如果已被標示為-1代表該數重複)
    {
        if (compare[N[i]] == -1)
            return false;
        else
            compare[N[i]] = -1;
    }
    return true;//代表無數字重複
}
void check(int t, int test, int* checkA, int* checkB)
{
    *checkA = 0;
    *checkB = 0;
    
    int T[4];
    int TEST[4];
    split(t, T);
    split(test, TEST);
    
    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)
        compare[T[i]] = -1;//方式同上，以標記-1的方式在列表中作標記
    
    for (int i = 0; i < 4; i++)
    {
        if (compare[TEST[i]] == -1)//如果有出現在裡面
        {
            if (TEST[i] == T[i])
                *checkA += 1;//位置一樣Ａ＋1
            else
                *checkB += 1;//數字一樣，位置不一樣Ｂ＋1
        }
    }
}

}
