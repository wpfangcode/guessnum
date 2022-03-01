#include <iostream>

using namespace std;

class Guess {
public:
	Guess() {
		int i = 0;
		int first = 1234;
		int num[4];
		while (first <= 9876) {
			Spilt(first, num);
			if (noZero(num) && noRepeat(num)) {
				data[i] = first;
				i++;
			}
			first++;
		}
		size = i;
	}
	void Think(int a, int b) {
		int _ans[4];
		int _data[4];
		int count = 0;
		int diff = 0;
		int same = 0;
		int check = 0;
		temp = new int[size];
		Spilt(ans, _ans);
		for (int i = 0; i < size; i++) {
			Spilt(data[i], _data);
			if (a == 0 && b == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							same++;
							break;
						}
					}
					if (same)	break;
				}
				if (!same) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 1 && b == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
								check++;
							}
							else {
								same++;
							}
							break;
						}
					}
					if (same > 1)break;
				}
				if (same == 1 && check == 1) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 0 && b == 1) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
								check++;
								break;
							}
							else {
								same++;
							}
							break;
						}
					}
					if (same > 1 || check)break;
				}
				if (same == 1 && !check) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 2 && b == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
								check++;
								break;
							}
							else {
								same++;
							}
							if (same > 1) break;
						}
					}
					if (same > 2)break;
				}
				if (same == 2 && check == 2) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 0 && b == 2) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 0) break;
						}
					}
					if (same > 0 || check > 2)break;
				}
				if (same == 0 && check == 2) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 1 && b == 1) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 1 || check > 1) break;
						}
					}
					if (same > 1 || check > 1)break;
				}
				if (same == 1 && check == 1) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 3 && b == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
								check++;
								break;
							}
							else {
								same++;
							}
							if (same > 3) break;
						}
					}
					if (same > 3)break;
				}
				if (same == 3 && check == 3) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 0 && b == 3) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 0) break;
						}
					}
					if (same > 0 || check > 3)break;
				}
				if (same == 0 && check == 3) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 2 && b == 1) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 2 || check > 1) break;
						}
					}
					if (same > 2 || check > 1)break;
				}
				if (same == 2 && check == 1) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 1 && b == 2) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 1 || check > 2) break;
						}
					}
					if (same > 1 || check > 2)break;
				}
				if (same == 1 && check == 2) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 4 && b == 0) {
				isOver = true;
				cout << "Bingo 答對囉" << endl;
				return;
			}
			else if (a == 0 && b == 4) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 0) break;
						}
					}
					if (same > 0)break;
				}
				if (same == 0 && check == 4) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 1 && b == 3) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 1 || check > 3) break;
						}
					}
					if (same > 1 || check > 3)break;
				}
				if (same == 1 && check == 3) {
					temp[count] = data[i];
					count++;
				}
			}
			else if (a == 2 && b == 2) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (_data[i] == _ans[j]) {
							if (i == j) {
								same++;
							}
							else {
								check++;
							}
							if (same > 2 || check > 2) break;
						}
					}
					if (same > 2 || check > 2)break;
				}
				if (same == 2 && check == 2) {
					temp[count] = data[i];
					count++;
				}
			}
			else {
				cout << "輸入錯誤，請重新輸入" << endl;
				return;
			}
			same = 0;
			check = 0;
		}
		size = count;
		delete[] data;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = temp[i];
		}
		delete[] temp;
		round++;
	}
	void Answer() {
		if (size == 0) {
			cout << "你作弊！" << endl;
			isOver = true;
			return;
		}
		cout << "還有" << size << endl;
		ans = data[Random(size)];
		cout << "round " << round << " : " << "答案是 " << ans << endl;
	}
	bool Playing() {
		return !isOver;
	}
private:
	bool isOver = false;
	int size;
	int ans = 0;
	int round = 1;
	int* data = new int[3024];
	int* temp;
	bool noZero(int num[]) {
		return num[0] && num[1] && num[2] && num[3];
	}
	bool noRepeat(int num[]) {
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (num[i] == num[j]) {
					return false;
				}
			}
		}
		return true;
	}
	int Random(int num) {
		if (num == 1) {
			return 0;
		}
		srand(time(NULL));
		int n = rand() % num;
		return n;
	}
	void Spilt(int n, int* num) {
		num[0] = n / 1000;
		num[1] = (n / 100) % 10;
		num[2] = (n / 10) % 10;
		num[3] = n % 10;
	}
};
int main()
{
	cout << 1072011 << endl;
	cout << "楊哲其" << endl;
Restart:
	Guess* guess = new Guess();
	while (guess->Playing()) {
		int a, b;
		guess->Answer();
		if (!guess->Playing()) {
			return 0;
		}
		cin >> a >> b;
		cout << a << "A" << b << "B" << endl;
		cout << "---------------------" << endl;
		guess->Think(a, b);
	}
	cout << "遊戲結束" << endl;
	cout << "繼續新的一局?(y/n)" << endl;
	char c;
	while (cin >> c) {
		if (c == 'y' || c == 'Y') {
			delete guess;
			cout << "---------------------" << endl;
			goto Restart;
		}
		else if (c == 'n' || c == 'N') {
			return 0;
		}
	}
	return 0;
}
