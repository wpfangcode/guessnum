#include <iostream>
using namespace std;

class ComputerGuessProgrem {
public:
    /// <summary>
    /// 初始化ComputerGuessProgrem
    /// 初始化所有可能性的四位數
    /// 1. 分割成四個一位數 split
    /// 2. 不為零 noZero && 不重複 noRepeat
    /// </summary>
    ComputerGuessProgrem() {
        int number = 1234;
        for (int i = 0; number <= 9876; number++)
        {
            split(number);
            if (noZero(four) && noRepeat(four))
            {
                allnumber[i] = number;
                i++;
            }
        }
    }
    /// <summary>
    /// 電腦猜數字
    /// 根據幾a幾b調配答案
    /// </summary>
    void Guess(int a,int b) {
        for (int i = 0; i < 3024; i++)
        {
            if (allnumber[i] != -1)
            {
                int guess = allnumber[i];
                cout << "電腦猜:" << guess << endl;
                allnumber[i] = -1;
                break;
            }
        }
    }
    /// <summary>
    /// 把一個四位數切成四個一位數(陣列儲存)
    /// </summary>
    /// <param name="n">一個四位數</param>
    void split(int n)
    {
        four[0] = n / 1000;
        four[1] = (n / 100) % 10;
        four[2] = (n / 10) % 10;
        four[3] = n % 10;
    }
    /// <summary>
    /// 四個一位數裡皆不等於0
    /// </summary>
    /// <param name="n[]">四個一位數</param>
    bool noZero(int n[])
    {
        if ((n[0]) && (n[1]) && (n[2]) && (n[3]) != 0)
            return true;
        else
            return false;
    }
    /// <summary>
    //四個一位數裡皆不重複
    /// </summary>
    /// <param name="n[]">四個一位數</param>
    bool noRepeat(int n[])
    {
        if ((n[0] != n[1]) && (n[0] != n[2]) && (n[0] != n[3]) && (n[1] != n[2]) && (n[1] != n[3]) && (n[2] != n[3]))
            return true;
        else
            return false;
    }
private:
    //四個一位數
    int four[4];
    //全部可能性的四位數
    int allnumber[3024];
};
int main()
{
    //輸出 我
    cout << "s1072012" << endl;
    cout << "姜義鴻" << endl;
    //幾a幾b 參數使用
    int a = 0, b = 0;

    //new ComputerGuessProgrem
    ComputerGuessProgrem* computer = new ComputerGuessProgrem();

    //A4正解
    while (a != 4)
    {
        //電腦猜
        computer->Guess(a,b);
        //玩家輸入
        cout << "請輸入數字與AB" << endl;
        cout << "A:";
        cin >> a;
        cout << "B:";
        cin >> b;
    }

}
