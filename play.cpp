#include <iostream>
using namespace std;
int main()
{
  cout<<"1102054"<<endl;
  cout<<"蘇蕙婷"<<endl;
  
  void open(int n, int N[])//把四位數拆開成四個數字
{
    N[0] = n / 1000;//1234/1000=1
    N[1] = (n / 100) % 10;//1234/100=12%10=2
    N[2] = (n / 10) % 10;//1234/10]=123%10=3
    N[3] = n % 10;//1234%10=4
}

bool haveZero(int n)//把四位數中沒有零的(符合規則的) return true
{
    int N[4];
    open(n, N);
    if (N[0]!=0 && N[1]!=0 && N[2]!=0 && N[3]!=0)
        return true;//四位數中沒有0的 return true
    else
        return false;//四位數中有0的 return false
    /*return !(N[0] && N[1] && N[2] && N[3]);//回傳不為零的*/
}

bool noRepeatFigure(int n)//四位數中沒有重複數字的值 return true (例如5994)
{
    int N[4];
    open(n, N);
    int mark[10] = { 0,1,2,3,4,5,6,7,8,9 };//用來標示已出現的數為-1,方便後面做判斷
    for (int i = 0; i < 4; i++)
    {
        if (mark[N[i]] == -1)
        {
            return false;//如果mark[]=-1就代表前面已經有出現同一個數字，所以就 return false
            break;//跳出 function 不再判斷
        }
        mark[N[i]] = -1;//假設為1234，N[0]=1，所以mark[1]=-1，後面依此類推。mark[2][3][4]皆為-1
    }
    return true;//標示完，沒有重複，就代表沒有重複數字，return true
}

void decideAB(int computer, int dataTest, int *decideA, int *decideB)//以一個電腦猜的數和人輸入的 xAyB 為提示，判斷哪些可以在列表內 哪些該刪掉
{
    *decideA = 0;
    *decideB = 0;
    int comArray[4];
    int testArray[4];
    open(computer, comArray);
    open(dataTest, testArray);
    int mark[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 4; i++)
        mark[comArray[i]] = -1;
    for (int i = 0; i < 4; i++)
    {
        mark[comArray[i]] = -1;//假設computer輸出1234，mark={0,-1,-1,-1,-1,5,6,7,8,9}
        if (mark[testArray[i]]==-1)//先判斷電腦猜的array和測試的array是否有重複數字
        {
            if (comArray[i] = testArray[i])//如果位置相同
                decideA = decideA + 1;//A就加1
            else
                decideB = decideB + 1;//位置不相同 B就加1
        }
    }
}

int main()
{//test open
    /*int N[4];
    open(1234,N);
    for (int i = 0; i < 4; i++)
    {
        cout << N[i] << endl;
    }*/
 //*********************************
    int data[4000] = {0};//列表 資料庫
    int N[4];
    int a = 0;
    int b = 0;
    int decideA;
    int decideB;
    int guess;
    int dataNumber = 1234;
    for (int i = 0; dataNumber <= 9876; dataNumber++)//把1234~9876放到data[]內
    {
        if (haveZero(dataNumber) && noRepeatFigure(dataNumber))//符合沒有0 沒有重複數字的值，存到data裡面
        {
            data[i] = dataNumber;
            i++;
        }
    }
    while (a != 4)
    {
        for (int i = 0; i < 3024; i++)
        {
            if (data[i] != -1)
            {
                guess = data[i];//從data裡面的第一個開始猜
                cout << "Computer guess figure:" << guess << endl;
                data[i] = -1;//猜測完就標為-1,以免重複猜測
                break;//標完就跳出，再來判斷幾A幾B
            }
        }
        cout << "Please input ?A?B"<<endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin>> b;
        cout<< endl;
        for (int i = 0; i < 3024; i++)//用剛剛電腦猜的和輸入的幾A幾B來判斷列表內哪些該標為-1(不符合)
        {
            if (data[i] != -1)//資料的值皆為目前符合的 再比較
            {
                decideAB(guess, data[i], &decideA, &decideB);
                if (decideA != a || decideB !=  b)
                    data[i] = -1;
            }
        }
    }
    cout << "Answer is" << guess << endl;
    return 0;
}
