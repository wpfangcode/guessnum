
#include <iostream>
using namespace std;

bool noZero(int i);
bool noRepeat(int i);
void split(int i, int arr[]);
void check(int target, int test, int *checkA, int *checkB);

bool noZero(int i)
{
    int arr[4];
    split(i, arr);
    return arr[0]!=0 && arr[1]!=0 && arr[2]!=0 && arr[3]!=0;
}
bool noRepeat(int i) {
    int arr[4];
    split(i, arr);
    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int j = 0; j < 4; j++) { //走訪arr 走訪我們剛才分割的數字
        if (compare[arr[j]] == -1)
            return false;
        else
            compare[arr[j]] = -1;
    }
    return true;
}
void split(int i, int arr[]) {
    arr[0] = i / 1000;
    arr[1] = i / 100 % 10;
    arr[2] = i / 10 % 10;
    arr[3] = i % 10;
}
void check(int target, int test, int* checkA, int* checkB) {
    *checkA = 0;
    *checkB = 0;
    int targetArray[4];
    int testArray[4];
    split(target, targetArray);
    split(test, testArray);
    int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++) {
        compare[targetArray[i]] = -1;
    }
    for (int i = 0; i < 4; i++) {
        if (compare[testArray[i]] == -1) {
            if (testArray[i] == targetArray[i]) {


                *checkA += 1;
            }
            else {
                *checkB += 1;
            }
            
        }
    }
}

int main()
{
    int a = 0, b = 0;
    int allNumber[3024] = { 0 };

    int num = 1234;
    for (int i = 0; num <= 9876; num++) {
        if (noZero(num) && noRepeat(num)) {
            allNumber[i]=num;
            i++;
        }
    }
    int guess;
    while (a != 4) {
        for (int i = 0; i < 3024; i++) {
            if (allNumber[i] != -1) {
                guess = allNumber[i];
                cout << "電腦猜:" << guess << endl;
                allNumber[i] = -1;
                break;
            }
        }


        cout << "請輸入數字與對應的AB" << endl;
        cout << "A:" << endl;
        cin >> a;
        cout << "B:" << endl;
        cin >> b;
        int checkA, checkB;
        for (int i = 0; i < 3024; i++) {
            if (allNumber[i] != -1) {
                check(guess, allNumber[i], &checkA, &checkB);
                if (checkA != a || checkB != b) {
                    allNumber[i] = -1;
                }
            }
            
        }
    }
        cout << "答案就是" << guess << endl;
        return 0;
}
  cout<<"1092050"<<endl;
  cout<<"孫睦桓"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  return 1;
}
