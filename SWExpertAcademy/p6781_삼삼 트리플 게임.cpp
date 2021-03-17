#include<iostream>
#include<string>

using namespace std;

bool isContinue(int card[][10]) {
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i <= 9; i++) {
			if (card[k][i] >= 3)
				card[k][i] %= 3;
			if (i < 8) {
				if (card[k][i] > 0 && card[k][i + 1] > 0 && card[k][i + 2] > 0) {
					card[k][i]--;
					card[k][i + 1]--;
					card[k][i + 2]--;
					i--;
				}
			}
		}
		for (int i = 1; i <= 9; i++)
			if (card[k][i] != 0)
				return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int rSize = 0, gSize = 0, bSize = 0;
		char c;
		int card[3][10] = { 0, };
		string color, num;
		cin >> num >> color;
		for (int i = 0; i < 9; i++) {
			if (color[i] == 'R') {
				card[0][num[i] - '0']++;
				rSize++;
			}
			else if (color[i] == 'G') {
				card[1][num[i] - '0']++;
				gSize++;
			}
			else {
				card[2][num[i] - '0']++;
				bSize++;
			}
		}
		if (rSize % 3 == 0 && gSize % 3 == 0 &&
			bSize % 3 == 0)
		{
			if (isContinue(card))
				cout << '#' << test_case << ' ' << "Continue" << '\n';
			else
				cout << '#' << test_case << ' ' << "Win" << '\n';
		}
		else
			cout << '#' << test_case << ' ' << "Continue" << '\n';
	}
	return 0;
}