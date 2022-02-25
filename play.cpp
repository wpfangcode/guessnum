#include <iostream>
using namespace std;
int main()
{
  cout<<"1092041"<<endl;
  cout<<"張倫榕"<<endl;
void Split(int number, int N[]) {
	N[0] = number / 1000;
	N[1] = (number / 100) % 10;
	N[2] = (number / 10) % 10;
	N[3] = number % 10;
}
void zero(int n, int number[]) {
	int iszero[4];
	Split(n, iszero);
	if (iszero[0] * iszero[1] * iszero[2] * iszero[3] == 0) {
		number[n] = 0;
		//cout << "is0" << endl;
	}
}
bool isrepeat(int n, int number[]) {
	int repeat[4];
	Split(n, repeat);
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (repeat[i] == repeat[j]) {
				number[n] = 0;
				return true;
			}
		}
	}
}

int getA(int n,int n2) {
	int A[4];
	int A2[4];
	int total=0;
	Split(n, A);//現在猜的
	Split(n2, A2);//候選數字
	for (int i = 0; i < 4; i++) {
		if (A[i] == A2[i]) total++;
	}
	return total;
}

int getB(int n, int n2) {
	int A[4];
	int A2[4];
	int total=0;
	Split(n, A);//現在猜的
	Split(n2, A2);//候選數字

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			else {
				if (A[i] == A2[j]) total++;
			}
		}
	}
	return total;
}
int main()
{

	int number[10000];
	for (int i = 1234; i < 10000; i++) {
		number[i] = i;

		zero(i, number);
		if(number[i]!=0)  isrepeat(i, number);
	}
	//-------------------------------
	int count = 0;
	

	//cout << "count=" << count;
	int index = 1234;
	int nowindex[4];
	

	int A = 0, B = 0;
	cout << number[index] << endl;
	cout << "幾A幾B?" << endl;
	cin >> A >> B;
	//cout <<"A:"<< getA(1628, 1234) <<"B:"<<getB(1628, 1234)<< endl;

	
	while (A < 4) {
		for (int i = index; i < 10000; i++) {
			if (number[i] != 0) {
				int nowA = getA(i, index);
				int	nowB = getB(i, index);
				if ( nowA== A && nowB== B) {
					//cout << "A " << nowA << "B " << nowB << endl;
					//cout <<"i** "<<i<<"index** "<<index<<"  "<<number[i]<< "留下" << endl;
				}
				else {
					number[i] = 0;
					//cout << "i** " << i << "index** " << index << "  " << number[i] << "淘汰" << endl;
				}
				
			}
		}
		//----------------------------------

		count = 0;
		for (int i = 1234; i < 10000; i++) {
			if (number[i] != 0) count++;
		}
		cout << "count=" << count << endl;
		//----------------------------------

		for (int i = 1234; i < 10000; i++) {
			if (number[i] != 0) {
				index = number[i];
				cout << "##########index########" << index<<endl;
				break;
			}
		}
		cout << index << endl;
		cin >> A >> B;
	}
}
  cout<<"demo"<<endl;
  return 1;
}
