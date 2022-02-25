#include <iostream>

using namespace std;

void split(int n, int N[]);
bool noZero(int n);
bool noReapeat(int n);
void check(int target, int test, int* checkA, int* checkB);

int main()
{
  cout << "1102038 陳璋慶" << endl;
	int a = 0, b = 0;
	int allNumbers[3024] = { 0 };

	int num = 1234;
	for (int i = 0; num <= 9876; num++) {
		if (noZero(num) && noReapeat(num)) {
			allNumbers[i] = num;
			i++;
		}
	}

	int guess;
	while (a != 4) {
		for (int i = 0; i < 3024; i++) {
			if (allNumbers[i] != -1) {
				guess = allNumbers[i];
				cout << "電腦猜:" << guess << endl;
				allNumbers[i] = -1;
				break;
			}
		}
		
		cout << "請輸入與數字對應的AB" << endl;
		cout << "A: ";
		cin >> a;
		cout << "B: ";
		cin >> b;
		

		
		int checkA, checkB;
		for (int i = 0; i < 3024; i++) {
			if (allNumbers[i] != -1) {
				check(guess, allNumbers[i], &checkA, &checkB);
				if (checkA != a || checkB != b)
					allNumbers[i] = -1;
			}
		}
	}

	cout << "答案就是" << guess << endl;
	return 0;
}

void split(int n, int N[]) {
	N[0] = n / 1000;
	N[1] = (n / 100) % 10;
	N[2] = (n / 10) % 10;
	N[3] = n % 10;
}
bool noZero(int n) {
	int N[4];
	split(n, N);
	if (N[0] && N[1] && N[2] && N[3])
		return true;
	else
		return false;
}
bool noReapeat(int n) {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int N[4];
	split(n, N);
	for (int i = 0; i < 4; i++) {
		if (arr[N[i]] == -1)
			return false;
		else
			arr[N[i]] = -1;
	}
	return true;
}

void check(int target, int test, int* checkA, int* checkB)
{
	*checkA = 0;
	*checkB = 0;

	int targetArr[4];
	int testArr[4];

	split(target, targetArr);
	split(test, testArr);

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
		compare[targetArr[i]] = -1;

	for (int i = 0; i < 4; i++){
		if (compare[testArr[i]] == -1){
			if (testArr[i] == targetArr[i])
				*checkA += 1;
			else
				*checkB += 1;
		}
	}
}
