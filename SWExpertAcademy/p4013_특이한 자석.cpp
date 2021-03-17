#include<iostream>

using namespace std;

int magnet[5][8];

void rotation(int n, int d) {
	if (d < 0) {
		for (int i = 0; i < 7; i++) {
			swap(magnet[n][i], magnet[n][i + 1]);
		}
	}
	else {
		for (int i = 6; i >= 0; i--) {
			swap(magnet[n][i], magnet[n][i + 1]);
		}
	}
}

int main(int argc, char** argv)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K, n, dir, dirN, ans = 0, lo;
		int dn[5] = { 0, 1, 2, 4, 8 };
		bool swapNum[4];
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> n >> dir;
			dirN = 2;
			if (dir == 1) dirN = -2;
			for (int j = 1; j <= 3; j++) {
				swapNum[j] = 0;
				if (magnet[j][2] != magnet[j + 1][6])
					swapNum[j] = 1;
			}
			rotation(n, dir);
			lo = n - 1;
			while (lo > 0) {
				if (!swapNum[lo]) break;
				if ((n - lo) % 2 == 0) {
					rotation(lo, dir);
				}
				else {
					rotation(lo, dir + dirN);
				}
				lo--;
			}
			lo = n + 1;
			while (lo < 5) {
				if (!swapNum[lo - 1]) break;
				if ((n - lo) % 2 == 0) {
					rotation(lo, dir);
				}
				else {
					rotation(lo, dir + dirN);
				}
				lo++;
			}
		}
		for (int j = 1; j <= 4; j++) {
			ans = ans + magnet[j][0] * dn[j];
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}