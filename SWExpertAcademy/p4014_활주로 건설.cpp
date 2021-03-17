#include<iostream>

using namespace std;

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
		int N, X, map[20][20], ans = 0, cnt;
		bool front;
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int j;
		for (int i = 0; i < N; i++) {
			front = 0;
			cnt = 1;
			for (j = 0; j < N - 1; j++) {
				if (map[i][j] == map[i][j + 1]) {
					cnt++;
				}
				else if (map[i][j] == map[i][j + 1] + 1) {
					if (front)
						if (cnt < X) break;
					cnt = 1;
					front = 1;
				}
				else if (map[i][j] == map[i][j + 1] - 1) {
					if (front) {
						if (cnt < X * 2) break;
					}
					else
						if (cnt < X) break;
					cnt = 1;
					front = 0;
				}
				else break;
			}
			cout << '#' << test_case << ' ' << ans << '\n';
			if (j != N - 1) continue;
			if (cnt >= X) ans++;
			else
				if (!front) ans++;
		}

		int i;
		for (int j = 0; j < N; j++) {
			front = 0;
			cnt = 1;
			for (i = 0; i < N - 1; i++) {
				if (map[i][j] == map[i + 1][j]) {
					cnt++;
				}
				else if (map[i][j] == map[i + 1][j] + 1) {
					if (front)
						if (cnt < X) break;
					cnt = 1;
					front = 1;
				}
				else if (map[i][j] == map[i + 1][j] - 1) {
					if (front) {
						if (cnt < X * 2) break;
					}
					else
						if (cnt < X) break;
					cnt = 1;
					front = 0;
				}
				else break;
			}
			cout << '#' << test_case << ' ' << ans << '\n';
			if (i != N - 1) continue;
			if (cnt >= X) ans++;
			else
				if (!front) ans++;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}