#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;
queue<pair<int, int>> q;
char map[1000][1000];
int check[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt;

void init(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = NULL;
			check[i][j] = 0;
		}
	}
	cnt = 0;
	queue<pair<int, int>> emptyq;
	swap(emptyq, q);
}

int bfs(int x, int y, int N, int M) {
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M &&
				check[nx][ny] == 0 && map[nx][ny] == 'C') {
				check[nx][ny] = check[x][y] + 1;
				q.push({ nx, ny });
				if (map[nx][ny] == 'L')
					cnt += check[nx][ny];
			}
		}
	}
	return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
		init(N, M);
		for (int i = 0; i < N; i++) {
			scanf("%*c");
			for (int j = 0; j < M; j++) {
				scanf("%1c", &map[i][j]);
				if (map[i][j] == 'W') {
					q.push({ i, j });
				}
			}
		}
		cout << '#' << test_case << ' ' << bfs(0, 0, N, M) << '\n';
	}
	return 0;
}