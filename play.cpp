#include <iostream>
using namespace std;

int all[3024] = {0};    //1234~9876 minus hasZero minus Same
int N[4] = {0};         //for the function
int guess = 0;          //the number i guess
int countA = 0;
int countB = 0;
int a = 0;              //the number of A that the player give to me
int b = 0;              //the number of A that the player give to me

void cutFour(int n, int N[4])   //to seperate each numbers
{
    N[0] = n/1000;
    N[1] = (n/100)%10;
    N[2] = (n/10)%10;
    N[3] = n%10;
}

bool noZero(int n, int N[4])    //find the numbers that don't have zero
{
    cutFour(n, N);

    if (N[0]*N[1]*N[2]*N[3] == 0)
        return false;
    else
        return true;
}

bool noSame(int n, int N[4])    //find the numbers that don't have the "same number(?)"
{
    cutFour(n, N);

    if ((N[0]==N[1]) || (N[0]==N[2]) || (N[0]==N[3]) || (N[1]==N[2]) || (N[1]==N[3]) || (N[2]==N[3]))
        return false;
    else
        return true;
}

void howManyAB(int G[4], int A[4])  //compare two numbers to find out how many A and B
{
    for (int i = 0 ; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (G[i] = A[j])
            {
                if (i = j)
                    countA++;
                else
                    countB++;
            }
        }
    }
}

void del(int a, int b)              //delete the numbers that don't match ?A?B
{
    int G[4] = {0};
    int A[4] = {0};
    for (int i = 0; i <= 3024; i++)
    {
        if (all[i] != 0)
        {
            cutFour(guess, G);
            cutFour(all[i], A);
            howManyAB(G, A);        //call the function to know many A and B does this number has
            if ((a != countA)||(b != countB))
                all[i] = 0;
        }
    }
}

int main()
{
    int number = 1234;

    for (int i = 0; number <= 9876; number++)
    {
        if (noZero(number, N)&&noSame(number, N))
        {
            all[i] = number;
            i++;
        }
    }

    cout<<"遊戲開始"<<endl;
    
    while (a != 4)
    {
        for (int i = 0; i <= 3024; i++)
        {
            if (all[i] != 0)
            {
                guess = all[i];
                cout<<"電腦猜測數字："<<guess<<endl;
                all[i] = 0;
                break;
            }
        }

        cout<<"請輸入對應的AB數"<<endl;
        cout<<"A = ";
        cin>>a;
        cout<<"B = ";
        cin>>b;

        for (int i = 0; i < 3024; i++)
        {
            if (all[i] != 0)
                del(a, b);
        }
    }
    
    cout<<"遊戲結束"<<endl;

    return 0;
}

