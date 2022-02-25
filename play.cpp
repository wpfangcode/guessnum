#include <iostream>
using namespace std;
int main()
{
    cout<<"1102034"<<endl;
    cout<<"陳語翎"<<endl;
    int a;
    cin>>a;
    int b;

    while(cin>>b)
    {
        int c=0;
        int d=0;
        if(b==0000)
            break;
        if(a/1000==b/1000)
            c=c+1;
        if((a%1000)/100==(b%1000)/100)
            c=c+1;
        if((a%100)/10==(b%100)/10)
            c=c+1;
        if(a%10==b%10)
            c=c+1;
        if(a/1000==(b%1000)/100)
            d=d+1;
        if(a/1000==(b%100)/10)
            d=d+1;
        if(a/1000==b%10)
            d=d+1;
        if((a%1000)/100==b/1000)
            d=d+1;
        if((a%1000)/100==(b%100)/10)
            d=d+1;
        if((a%1000)/100==b%10)
            d=d+1;
        if((a%100)/10==b/1000)
            d=d+1;
        if((a%100)/10==(b%1000)/100)
            d=d+1;
        if((a%100)/10==b%10)
            d=d+1;
        if(a%10==b/1000)
            d=d+1;
        if(a%10==(b%1000)/100)
            d=d+1;
        if(a%10==(b%100)/10)
            d=d+1;
        cout<<c<<"A"<<d<<"B"<<endl;
    }
    return 0;
}
