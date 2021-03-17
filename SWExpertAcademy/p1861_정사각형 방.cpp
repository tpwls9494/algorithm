#include<iostream>

using namespace std;

int map[1000][1000];
int dMax;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int depth, int size) {
	dMax = depth;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < size && ny < size) {
			if (map[nx][ny] - map[x][y] == 1)
				dfs(nx, ny, depth + 1, size);
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
		int N, max = 0, loMin = 1000001;
		bool subtract, add;
		cin >> N;
		dMax = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				subtract = 0, add = 0, dMax = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
						if (map[i][j] - map[nx][ny] == 1) subtract = 1;
						if (map[i][j] - map[nx][ny] == -1) add = 1;
					}
				}
				if (add && !subtract) dfs(i, j, 1, N);
				if (max == dMax) {
					if (loMin > map[i][j]) loMin = map[i][j];
				}
				else if (max < dMax) {
					loMin = map[i][j];
					max = dMax;
				}
			}
		}
		cout << '#' << test_case << ' ' << loMin << ' ' << max << '\n';
	}
	
	return 0;
}