#include<iostream>

using namespace std;

int map[100][100];

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
		int N, M;
		cin >> N >> M;
		bool rowSmall, colSmall, ans = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				rowSmall = 1; colSmall = 1;
				for (int k = 0; k < N; k++) {
					if (map[i][j] < map[k][j]) rowSmall = 0;
				}
				for (int k = 0; k < M; k++) {
					if (map[i][j] < map[i][k]) colSmall = 0;
				}
				if (!rowSmall && !colSmall) {
					ans = 0;
					break;
				}
			}
			if (!ans) break;
		}
		if (ans) cout << '#' << test_case << " YES\n";
		else cout << '#' << test_case << " NO\n";
	}
	return 0;
}