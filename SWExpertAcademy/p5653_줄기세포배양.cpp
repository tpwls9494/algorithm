#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int check[351][351];
int N, M, K, cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<tuple<int, int, int, int>> q;
tuple<int, int, int> t[2500];

void bfs() {
	int x, y, n, max = 0;
	while (!q.empty()) {
		tie(n, x, y, cnt) = q.front();
		if (cnt >= max) max++;
		if (K+1 == max) return;
		q.pop();

		if (n < check[x][y]) {
			if (check[x][y] % n == n - 1) {
				check[x][y] = -2;
				continue;
			}
			q.push(tie(n, x, y, max));
			check[x][y]++;
		}
		else if (n == check[x][y]) {
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (check[nx][ny] != -1) continue;
				check[nx][ny] = 0;
				q.push(tie(n, nx, ny, max));
			}
			if (n > 1) {
				q.push(tie(n, x, y, max));
				check[x][y]++;
				continue;
			}
			check[x][y] = -2;
		}
		else {
			check[x][y]++;
			q.push(tie(n, x, y, max));
		}

		// 시점이 끝나는 상태에서 cnt++;를 해줘야한다.
	}
}

void init() {
	cnt = 0;
	for (int i = 0; i < 351; i++) {
		for (int j = 0; j < 351; j++) {
			check[i][j] = -1;
		}
	}
	queue<tuple<int, int, int, int>> newQ;
	swap(q, newQ);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin.tie(nullptr);
		cout.tie(nullptr);
		ios::sync_with_stdio(false);
		int n, cellNum = 0;
		cin >> N >> M >> K;
		init();
		for (int i = 150; i < N+150; i++) {
			for (int j = 150; j < M+150; j++) {
				cin >> n;
				if (n != 0) {
					t[cellNum] = make_tuple(n, i, j);
					check[i][j] = 0;
					cellNum++;
				}
			}
		}
		for (int i = 0; i < cellNum; i++) {
			for (int j = i + 1; j < cellNum; j++) {
				if (get<0>(t[i]) < get<0>(t[j]))
					swap(t[i], t[j]);
			}
		}
		for (int i = 0; i < cellNum; i++) {
			q.push(tie(get<0>(t[i]), get<1>(t[i]), get<2>(t[i]), cnt));
		}
		bfs();
		cout << '#' << test_case << ' ' << q.size() << '\n';
	}
	return 0;
}