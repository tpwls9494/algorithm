#include<iostream>

using namespace std;

class BC
{
public:
	int x, y, n, p;

};

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };
int a[100], b[100];
int map[11][11][2];

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
		BC bc[9];

		int M, A, cnt = 0, ax = 1, ay = 1, bx = 10, by = 10, ans = 0;
		cin >> M >> A;

		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
				for (int k = 0; k < 2; k++)
					map[i][j][k] = 0;

		for (int i = 0; i < M; i++)
			cin >> a[i];

		for (int i = 0; i < M; i++)
			cin >> b[i];

		bc[0] = { 0, 0, 0, 0 };
		for (int i = 1; i <= A; i++)
			cin >> bc[i].x >> bc[i].y >> bc[i].n >> bc[i].p;

		for (int i = 1; i <= A; i++)
			for (int j = i + 1; j <= A; j++)
				if (bc[i].p < bc[j].p)
					swap(bc[i], bc[j]);

		for (int i = 1; i <= A; i++) {
			for (int j = bc[i].y - bc[i].n; j <= bc[i].y + bc[i].n; j++) {
				if (j < 1 || j > 10) continue;
				int rhom = bc[i].y - j;
				if (rhom < 0) rhom = j - bc[i].y;
				for (int k = bc[i].x - bc[i].n + rhom; k <= bc[i].x + bc[i].n - rhom; k++) {
					if (k < 1 || k > 10) continue;
					if (map[k][j][cnt] == 0) {
						map[k][j][cnt] = i;
						cnt = 0;
					}
					else {
						if (cnt == 1) {
							cnt = 0;
							continue;
						}
						cnt++;
						k--;
					}
				}
			}
		}

		ans = bc[map[ax][ay][0]].p + bc[map[bx][by][0]].p;
		for (int i = 0; i < M; i++) {
			ax += dx[a[i]];
			ay += dy[a[i]];
			bx += dx[b[i]];
			by += dy[b[i]];
			if (map[ax][ay][0] == map[bx][by][0]) {
				
				if(map[ax][ay][1] == 0 && map[bx][by][1] == 0)
					ans = ans + bc[map[ax][ay][0]].p;
				else if (bc[map[ax][ay][1]].p < bc[map[bx][by][1]].p) {
					ans = ans + bc[map[ax][ay][0]].p + bc[map[bx][by][1]].p;
				}
				else {
					ans = ans + bc[map[ax][ay][1]].p + bc[map[bx][by][0]].p;
				}
			}
			else
				ans = ans + bc[map[ax][ay][0]].p + bc[map[bx][by][0]].p;
			cout << i+1 << ". " << map[ax][ay][0] << ' ' << map[bx][by][0] << " (" << ax << ", " << ay << ") (" << bx << ", " << by << ")" ;
			cout << endl;
		}

		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				cout << map[j][i][0] << '\t';
			}
			cout << endl;
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}