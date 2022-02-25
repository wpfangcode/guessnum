#include <iostream>
using namespace std;
bool Nozero(int i);
bool Norepeat(int i);
void Split(int i, int array[]);
void cheak(int target, int test, int* cheakA, int* cheakB);

bool Nozero(int i) {
    int array[4];
    Split(i, array);
    if (array[0] != 0 && array[1] != 0 && array[2] != 0 && array[3] != 0) {
      //陣列元素對照是否有0
        return true;
    }
    else
        return false;
}
bool Norepeat(int i){
    int array[4];
    Split(i, array);
    int numbers[10] = { 0,1,2,3,4,5,6,7,8,9 };
  //將四位數字先後變為-1,若有重複的-1就過不了
    for (int j = 0; j < 4; j++) {
        if (numbers[array[j]] == -1) {
            return false;
        }
        else {
            numbers[array[j]] = -1;
        }
    }
        return true;
}
void Split(int i, int array[]) {//分割數字
    array[0] = i / 1000;
    array[1] = i / 100 % 10;
    array[2] = i / 10 % 10;
    array[3] = i % 10;
}
void cheak(int target, int test, int* cheakA, int* cheakB) {
    *cheakA = 0;
    *cheakB = 0;
    int targetarray[4];
    int testarray[4];
    Split(target, targetarray);
    Split(test, testarray);
    int numbers[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++) {
        numbers[targetarray[i]] = -1;
    }
    for (int i = 0; i < 4; i++) {
        if (numbers[targetarray[i]] == -1) {
            if (numbers[targetarray[i]] == numbers[testarray[i]]) {
                (*cheakA)++;
            }
            else {
                (*cheakB)++;
            }
        }
    }
}
int main()
{
    cout<<"郭品佑"<<endl;
    cout<<"1092002"<<endl;
    int a = 0;
    int b = 0;
    int allnumbers[4000] = { 0 };
    int number = 1234;
    for (int i = 0; number <= 9876; number++) {
        if (Nozero(number) && Norepeat(number)) {
            allnumbers[i] = number;
            i++;
        }
    }
    int guess;
    while (a != 4) {
        for (int i = 0; i < 4000; i++) {
            if (allnumbers[i] != -1) {
                guess = allnumbers[i];
                cout << "電腦猜: " << guess << endl;
            
                allnumbers[i] = -1;
                break;
            }
        }
        cout << "回答幾A幾B" << endl;
        cout << "A:" << endl;
        cin >> a;
        cout << "B:" << endl;
        cin >> b;
        int cheakA;
        int cheakB;
        for(int i=0;i<4000;i++){
            if (allnumbers[i] != -1) {
                cheak(guess, allnumbers[i], &cheakA, &cheakB);
                if (cheakA != a || cheakB != b) {
                    allnumbers[i] = -1;
                }
            }
        }
    }
    cout << "答案是: " << guess << endl;
    return 0;
}

