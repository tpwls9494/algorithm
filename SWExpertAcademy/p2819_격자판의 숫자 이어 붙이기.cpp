#include<iostream>

using namespace std;

bool check[10000000];
int map[4][4];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int n, int depth) {
	if (depth == 7) {
		check[n] = 1;
		return;
	}

	n = n * 10 + map[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
			dfs(nx, ny, n, depth + 1);
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
		int ans = 0;
		for (int i = 0; i < 10000000; i++)
			check[i] = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				dfs(x, y, 0, 0);
			}
		}
		for (int i = 0; i < 10000000; i++) {
			if (check[i] != 0)
				ans++;
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}