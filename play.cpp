// 1a1b.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
//策略:
/*人類出題
*電腦猜數字
*
* 電腦猜-->人類提示-->電腦猜
* 
* 電腦建立一張列表 表內有從1234~98762的數字
* 把重複&有包含0的數字去除
* 電腦隨機猜數字->人類給提示
* 
* 例:
* 題目:4578
* 電腦猜:1234
* 人類提示:0A1B
* 電腦接受提示-> 4567 6578 4768
*/
#include <iostream>
using namespace std;
void sprate(int n, int N[])
{
    N[0] = n / 1000;
    N[1] = (n / 100) % 10;
    N[2] = (n / 10) % 10;
    N[3] = n % 10;
}
void check(int target, int test, int* checkA, int* checkB)
{
    *checkA = 0;
    *checkB = 0;

        int targetarray[4];
        int testarray[4];
        sprate(target, targetarray);
        sprate(test, testarray);
        int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
        for (int i = 0; i < 4;i++)
        {
            compare[targetarray[i]] = -1;
        }
        for (int i = 0; i < 4; i++)
        {
            if (compare[testarray[i]] == -1)//如果出現在裡面
            {
                if (testarray[i] == targetarray[i])//如果位置一樣
                *checkA += 1;//A+1
                else//位置不一樣 但是有出現在裡面
                *checkB += 1;//B+1
            }
        }
}
bool noZero(int n)
{
    int N[4];
    sprate(n, N);
    if (N[0] * N[1] * N[2] * N[3] != 0)
        return true;
    else
        return false;
}
bool noRepet(int i)
{
    // 設 i = 1234
    // arr[0] = 5
    // arr[1] = 7
    // arr[2] = 4
    // arr[3] = 6

    int arr[4];
    sprate(i, arr);

    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 }; //檢差數字
    for (int j = 0; j < 4; j++) //走訪arr 走訪剛剛分割的數字
    {
        if (compare[arr[j]] == -1)

            return false;
        else
            compare[arr[j]] = -1;
    }
    return true;//這個數字沒有重複
}
int main()
{
  cout<<"1102043"<<endl;
  cout<<"林益綺"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  return 1;
    int a = 0, b = 0;
    int all[3024] = { 0 };
    //列表內宗共有3024種組合

    int num = 1234;
    for (int i = 0; num < 9876; num++)
    {
        if (noZero(num) && noRepet(num))//監察完沒有0 且沒有重複
        {
            all[i] = num;//把數字放進列表
            i++;
        }
    }

    int guess;
    while (a != 4)
    {
        for (int i = 0; i < 3024; i++)//走訪列表
        {
            if (all[i] != -1) 
            {
                guess = all[i];//找到列表符合和條件的數字
                cout << "電腦提出猜測:" << guess << endl;
                all[i] = -1;
                break;
            }
        }
        //人類提示電腦
        cout << "請輸入數字與對應AB" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;

        int checkA, checkB;
        for (int i = 0; i < 3024; i++)
        {
            if (all[i] != -1)
            {
                //電腦猜1234
                // 人類提示
                //1234和1235比較
                //1234和1236比較
                //1234和1237比較
                //.....
                check(guess, all[i], &checkA, &checkB);
                if (checkA != a || checkB != b)
                    all[i] = -1;
            }
        }
        
    }
    cout << "答案是:" << guess << endl;
    return 0;

}
