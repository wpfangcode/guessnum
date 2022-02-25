#include <iostream>
using namespace std;

class Game {
public:
	int guess_list[3024];
	int count;
	int myguess;
	Game() {
		count = 0;
		for (int i = 1234; i <= 9876; i++) {
			if (check(i)) {
				guess_list[count] = i;
				count++;
			}
		}
	}
	bool noZero(int N[]) {//沒有零
		if (N[0] * N[1] * N[2] * N[3]) {
			return true;
		}
		else {
			return false;
		}
	}
	bool noRepeat(int N[]) {//沒有重複
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (N[i] == N[j]) {
					return false;
				}
			}
		}
		return true;
	}
	void split(int n, int N[]) {//分割
		N[0] = n / 1000;
		N[1] = (n / 100) % 10;
		N[2] = (n / 10) % 10;
		N[3] = n % 10;
	}
	bool check(int n) {//分割並檢查
		int N[4];
		split(n, N);
		return noZero(N) && noRepeat(N);
	}
	int guess_count() {//剩幾個答案
		int guess_count = 0;
		for (int i = 0; i < 3024; i++) {
			if (guess_list[i] != 0) {
				guess_count++;
			}
		}
		return guess_count;
	}
	int guess() {
		for (int i = 0; i < 3024; i++) {
			if (guess_list[i] != 0) {
				myguess = guess_list[i];
				return myguess;
			}
		}
	}
	int ab(int n, int m) {
		int AB = 0;

		int n_split[4];
		split(n, n_split);
		int m_split[4];
		split(m, m_split);

		for (int i = 0; i < 4; i++) {
			if (n_split[i] == m_split[i]) {
				AB += 10;
			}
			for (int j = 0; j < 4; j++) {
				if (i != j && n_split[i] == m_split[j]) {
					AB++;
				}
			}
		}
		return AB;
	}
	void delete_guess(int a, int b) {
		int temp = myguess;
		for (int i = 0; i < 3024; i++) {
			int aa = a, bb = b;
			if (guess_list[i] != 0) {
				aa = aa - ab(temp, guess_list[i]) / 10;
				bb = bb - ab(temp, guess_list[i]) % 10;
			}
			if (aa != 0 || bb != 0) {
				guess_list[i] = 0;
			}
		}
	}
};
int main() {
  cout<<"1072041"<<endl;
  cout<<"陳泳志"<<endl;
  //-----------------------
  cout<<"demo"<<endl;
  
	Game game;
	
	while (game.guess_count() > 1) {
		cout << "電腦猜:" << game.guess() << endl;
		cout << "? A ? B" << endl;
		int a, b;
		cin >> a >> b;
		game.delete_guess(a, b);
	}
	if (game.guess_count() == 1) {
		cout << "答案是:" << game.guess() << endl;
	}
	if (game.guess_count() == 0) {
		cout << "你說謊" << endl;
	}
}
