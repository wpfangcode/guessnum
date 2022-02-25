#include <iostream>
using namespace std;
int main()
{
  int num[4],a=0,b=0;
	int allnumber[3024];
	int t=0;
	for(int i=1234;i<9877;i++){
		num[0]=i/1000;
		num[1]=(i/100)%10;
		num[2]=(i/10)%10;
		num[3]=i%10;
		if(	num[0]==0||	num[1]==0||	num[2]==0||	num[3]==0){
			continue;
		}
		else if(num[0]==num[1]||num[0]==num[2]||num[0]==num[3]||num[1]==num[2]||num[1]==num[3]||num[2]==num[3]){
			continue;
		}
		allnumber[t]=i;
		t++;
	}
	int ans;
	while(a!=4){
		for(int i=0;i<3024;i++){
		if(allnumber[i]!=-1){
			ans=allnumber[i];
			num[0]=allnumber[i]/1000;
			num[1]=(allnumber[i]/100)%10;
			num[2]=(allnumber[i]/10)%10;
			num[3]=allnumber[i]%10;			
			cout<<allnumber[i]<<endl;
			allnumber[i]=-1;
			break;
			}
		}
		cin>>a>>b;
		if(a==4){
			break;
		}
		int m[4];
		for(int i=0;i<3024;i++){
			int cora=0,corb=0;
			if(allnumber[i]!=-1){
				m[0]=allnumber[i]/1000;
				m[1]=(allnumber[i]/100)%10;
				m[2]=(allnumber[i]/10)%10;
				m[3]=allnumber[i]%10;
				for(int j=0;j<4;j++){
					for(int s=0;s<4;s++){
						if(m[j]==num[s]&&j==s){
							cora++;
							m[j]=0;
						}
						else if(m[j]==num[s]&&j!=s){
							corb++;
							m[j]=0;
						}
					}
				}	
			}
			if(cora!=a||corb!=b){
			allnumber[i]=-1;
			}
		}
	}
	cout<<"答案為:"<<ans<<endl; 
  cout<<"1102030"<<endl;
  cout<<"陳東科"<<endl;
  return 1;
}
