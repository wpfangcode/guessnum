#include <iostream>
using namespace std;
void split(int n,int N[])
{
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}
bool hasZero(int n)
{
	int N[4];
	split(n, N);
	if (N[0] * N[1] * N[2] * N[3] == 0)
		return true;
	else
		return false;
}
bool hasRepeat(int n)
{
	// declares a array to store each digit of the number
	int N[4];
	split(n, N); // adds to assign the value into the array

	// goes through each digit in the array

	for (int i = 0; i <= 3; i++) {
		for (int j = i + 1; j <= 3; j++)
		{
			if (N[i] == N[j])
				return true;
		}
	}
	return false;
}
void set(int N2[])
{
	int n = 1234;
	N2[0] =  n/ 1000;
	N2[1] = (n / 100) % 10;
	N2[2] = (n / 10) % 10;
	N2[3] = n % 10;
}
int a = 0;
int b = 0;
int countA(int n)
{
	int N[4];
	int N2[4];
	
	split(n, N);
	set(N2);
	for (int i = 0; i <= 3; i++) {
		for (int j = n + 1; j <= 3; j++) {
			if (N[i] == N2[i]) {
				a++;
			}
			else if (N[i]==N2[j]) {
				b++;
			}
		}
	}
}
void test1()
{
	int N[4];
	split(1234, N);
	cout << N[0] << " " << N[1] << " " << N[2] << " " << N[3] << " " << endl;
}
void test2()
{
	if (hasZero(1230))
		cout << 1230 << "：has zero" << endl;
	else
		cout << 1230 << "：has no zero" << endl;

	if (hasZero(1237))
		cout << 1237 << "：has zero" << endl;
	else
		cout << 1237 << "：has no zero" << endl;
}
void test3() {
	if (hasRepeat(1233))
		cout << 1233 << "：has repeat" << endl;
	else
		cout << 1233 << "：has no repeat" << endl;

	if (hasRepeat(1234))
		cout << 1234 << "：has repeat" << endl;
	else
		cout << 1234 << "：has no repeat" << endl;
}
void test4() {
	countA(1243);
	cout << a << " A " << b <<" B "<< endl;
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	
}
