
#include <iostream>
using namespace std;

//先呼叫個函式，但函式寫在主程式下方排版比較好看//
bool nozero(int i); //判斷沒有0的數字組合
bool norepeat(int i); //判斷沒有重複數字在內的數字組合
void split(int i, int arr[]); //將一組4位數字拆開分別存入陣列中
void check(int target, int test, int*checkA, int*checkB); //猜測AB數的判斷式

int main()
{
	cout << "1102055黃薔" << endl;
	int a = 0, b = 0;
	int numbers[3024] = { 0 }; //所有非0且沒重複數字的4位數字組合

	//最開始電腦先從1234算起(前面數字都已知不符合條件)
	int num = 1234;
	for (int i = 0; num <= 9876; num++)
	{
		if (nozero(num) && norepeat(num)) //如果同時符合才把數字存入numbers陣列中
		{
			numbers[i]=num;
			i++;
		}
	}

	//電腦猜數字
	int guess;
	while (a != 4) //當a(A不為4時會持續重複跑迴圈)
	{
		//電腦拋出猜測的數字
		for (int i = 0; i < 3024; i++) //從numbers列內存的第一個數字開始猜起，且猜測次數肯定不超過3024次
		{
			if (numbers[i] != -1) //如果numbers陣列裡面的數字不為-1就猜
			{
				guess = numbers[i];
				cout << "guess: " << guess << endl;
				numbers[i] = -1; //將以猜過數字變成-1，就不會重複猜測了
				break;
			}
		}

		//輸入電腦猜測的數字符合幾A幾B
		cout << "A: ";
		cin >> a; //輸入A
		cout<<"B: ";
		cin >> b; //輸入B

		//檢查符合條件數字
		int checkA, checkB;
		for (int i = 0; i < 3024; i++)
		{
			if (numbers[i] != -1) //如果numbers陣列裡面的數字不為-1就執行
			{
				check(guess, numbers[i], &checkA, &checkB); //檢查數字有沒有符合幾A幾B
				if (checkA != a || checkB != b) //只要checkA跟B有一個跟人輸入的AB數值不一樣那那個數字就不會是答案，並換成-1(不看此數字)
				{
					numbers[i] = -1;
				}
			}
		}
	}
	cout << "ANS: " << guess << endl; //當跳出while迴圈即等於電腦猜出了符合4A的數字，答案得出
	return 0;
}

bool nozero(int i) //判斷沒有0的數字組合
{
	int arr[4];
	split(i, arr); //把數字拆開
	return arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0; //如果有任意1陣列位置為1則return false
}

bool norepeat(int i) //判斷沒有重複數字在內的數字組合
{
	int arr[4];
	split(i, arr); //把數字拆開

	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };

	//將4個數字分別轉成-1，如果已有-1則if條件成立且代表4個數字裡 有 重複的數字，所以norepeat 不成立，回傳上去就不會存入numbers陣列中，反之成立
	for (int j = 0; j < 4; j++)
	{
		if (compare[arr[j]] == -1)
		{
			return false;
		}
		else
		{
			compare[arr[j]] = -1;
		}
	}
	return true;
}

void split(int i, int arr[]) //將一組4位數字拆開分別存入陣列中，寫成函式可多處利用
{
	arr[0] = i / 1000;
	arr[1] = i / 100 % 10;
	arr[2] = i / 10 % 10;
	arr[3] = i % 10;
}

void check(int target, int test, int*checkA, int*checkB) //target為guess，test為numbers陣列
{
	*checkA = 0;
	*checkB = 0;

	//開兩陣列分割儲存guess,numbers值
	int targetarr[4];
	int testarr[4];
	split(target, targetarr);
	split(test, testarr);

	//相同手法，
	int compare[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 4; i++)
	{
		compare[targetarr[i]] = -1; //先把guess的數字都換成-1
	}

	for (int i = 0; i < 4; i++)
	{
		if (compare[testarr[i]] == -1) //如果numbers有數字跟guess對上(有猜到答案的數字)
		{
			if (testarr[i] == targetarr[i]) //數字對且位置也對 => 是A
			{
				*checkA += 1; //A加1
			}
			else //數字對但是位置不對 =>是B
			{
				*checkB += 1; //B加1
			}
		}
	}
}
