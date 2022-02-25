
#include <iostream>
using namespace std;
bool Nozero(int i); //沒有0
bool Norepeat(int i); //沒有重複的
void split(int i, int arr[]);
void check(int target, int test, int* checkA, int* checkB);

int main()
{
    int a = 0, b = 0;
    int all[3024] = { 0 };

    int num = 1234;
    for (int i = 0; num <= 9876; num++) {
        if (Nozero(num) && Norepeat(num)) { //檢查完沒有0且沒有重複的
            all[i] = num; //把這個數字放進列表
            i++;
        }
    }

    int guess;
    while (a != 4) {
        for (int i = 0; i < 3024; i++) { //走訪列表
            if (all[i] != -1) {
                guess = all[i]; //找到列表當中第一個符合條件的數字
                cout << "猜測:" << guess << endl;
                all[i] = -1;
                break;
            }
        }
        //人類提示電腦
        cout << "A:"; //輸入A
        cin >> a;
        cout << "B:"; //輸入B
        cin >> b;
        cout << "傅昱瑄" << endl;
        cout << "1102046" << endl;

        int checkA, checkB;
        for (int i = 0; i < 3024; i++) {
            if (all[i] != -1) { //猜的和下一個比較
                check(guess, all[i], &checkA, &checkB);
                if (checkA != a || checkB != b)
                    all[i] = -1;
            }
        }
    }

    cout << "答案" << guess << endl;
    return 0;
}

bool Nozero(int i)
{
    int arr[4];
    split(i, arr);
    return arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0;
}

bool Norepeat(int i)
{
    int arr[4];
    split(i, arr);

    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 }; //檢查數字
    for (int j = 0; j < 4; j++) { //走訪arr 走訪我們剛才分割的數字
        if (compare[arr[j]] == -1) //已經變-1 代表重複
            return false; //這個數字有重複
        else
            compare[arr[j]] = -1;
    }
    return true; //這個數字沒有重複
}

void split(int i, int arr[])
{
    arr[0] = i / 1000; //千位數
    arr[1] = i / 100 % 10; //百位數
    arr[2] = i / 10 % 10; //十位數
    arr[3] = i % 10; //個位數
}

void check(int target, int test, int* checkA, int* checkB)
{
    *checkA = 0;
    *checkB = 0;

    int targetArray[4];
    int testArray[4];
    split(target, targetArray);
    split(test, testArray);

    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)
        compare[targetArray[i]] = -1;

    for (int i = 0; i < 4; i++) {
        if (compare[testArray[i]] == -1) { //如果有出現在裡面
            if (testArray[i] == targetArray[i]) //如果位置一樣
                *checkA += 1; //A + 1
            else //位置不一樣
                *checkB += 1; //B + 1
        }
    }
}

