#include<iostream>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m, map[20][20], ans = 1, max, serv; 
		pair<int, int> house[400];
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			max = 1;

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					serv = 0;

					// ¸¶¸§¸ð
					for (int x = j - i; x <= j + i; x++) {
						int t = x > j ? i - (x - j) : i - (j - x);
						for (int y = k - t; y <= k + t; y++) {
							if (x < 0 || y < 0 || x >= n || y >= n) continue;
							if (map[x][y])
								serv++;
						}
					}
					if (serv > max) max = serv;
				}
			}
			if (max * m - (i + 1) * (i + 1) - i * i >= 0)
				ans = max;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}