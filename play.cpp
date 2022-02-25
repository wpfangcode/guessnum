
//
//  main.cpp
//  1A2B
//
//  Created by TaKo on 2022/2/18.
//

#include <iostream>
using namespace std;

bool no0(int i);
bool noRepeat(int i);
void split(int i, int arr[]);
void check(int target, int test,int* guessC);

bool no0(int i) //檢查有沒有零
{
    int arr[4];
    split(i, arr);
    return arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0;
}

bool noRepeat(int i) //檢查有沒有重複
{
    int arr[4];
    split(i, arr);

    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int j = 0; j < 4; j++)
    {
        if (compare[arr[j]] == -1)
            return false;
        else
            compare[arr[j]] = -1;
    }
    return true;
}

void split(int i, int arr[])  //拆數字
{
    arr[0] = i / 1000;
    arr[1] = i / 100 % 10;
    arr[2] = i / 10 % 10;
    arr[3] = i % 10;
}

void check(int target, int test, int*guessC)  //檢查測試數字成立與否
{
    *guessC = 0;
    int targetArray[4];
    int testArray[4];
    split(target, targetArray);
    split(test, testArray);

    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)
        compare[targetArray[i]] = -1;

    for (int i = 0; i < 4; i++)
    {
        if (compare[testArray[i]] == -1)
        {
            *guessC +=1;
        }
    }
}


int main()
{
    cout<<"student id:1102042"<<endl;
    cout<<"name:周沅樟"<<endl;
    //-----------------------
    cout<<"demo"<<endl;
    int a = 0, b = 0;
    int allNum[3024] = { 0 };

    int num = 1234;
    for (int i = 0; num <= 9876; num++) //
    {
        if (no0(num) && noRepeat(num))
        {
            allNum[i] = num;
            i++;
        }
    }

    int guess;
    while (a != 4)
    {
        for (int i = 0; i < 3024; i++)  //沒有重複和零的組合共有3024組
        {
            if (allNum[i] != -1)
            {
                guess = allNum[i];
                cout << "電腦猜:" << guess << endl;
                allNum[i] = -1;
                break;
            }
        }

        cout << "請輸入數字和AB" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;

        int guessC; //電腦猜的A.B
        for (int i = 0; i < 3024; i++)
        {
            if (allNum[i] != -1)
            {
                check(guess, allNum[i], &guessC);
                if (a+b!=guessC) //效能會偏差 但不會出錯
                    allNum[i] = -1;
            }
        }
    }

    cout << "答案就是" << guess << endl;
    return 0;
}


