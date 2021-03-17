#include<iostream>

using namespace std;

class Microbe {
public:
	int x;
	int y;
	int n;
	int lo;
	int prev = 0;
};

Microbe mi[1000];

void remove(int k, int r) {
	for (int i = r; i < k-1; i++)
		mi[i] = mi[i + 1];
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
		int n, m, k, ans = 0;
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++)
			cin >> mi[i].y >> mi[i].x >> mi[i].n >> mi[i].lo;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < k; j++) {
				if (mi[j].prev)
					mi[j].prev = 0;

				// microbe를 움직일 때
				if (mi[j].lo == 1) mi[j].y -= 1;
				else if (mi[j].lo == 2) mi[j].y += 1;
				else if (mi[j].lo == 3) mi[j].x -= 1;
				else mi[j].x += 1;

				// 가장자리에 닿을 때
				if (mi[j].y == 0) {
					mi[j].lo += 1;
					mi[j].n /= 2;
				}
				else if (mi[j].y == n - 1) {
					mi[j].lo -= 1;
					mi[j].n /= 2;
				}
				else if (mi[j].x == 0) {
					mi[j].lo += 1;
					mi[j].n /= 2;
				}
				else if (mi[j].x == n - 1) {
					mi[j].lo -= 1;
					mi[j].n /= 2;
				}
			}

			// 미생물이 서로 겹치거나 0일 때
			for (int j = 0; j < k; j++) {
				if (mi[j].n == 0) {
					remove(k, j);
					k--;
				}
				for (int l = j + 1; l < k; l++) {
					if (mi[j].x == mi[l].x && mi[j].y == mi[l].y) {

						// 미생물이 2개만 겹칠 때
						if (!mi[j].prev) {
							if (mi[j].n > mi[l].n) {
								mi[j].prev = mi[j].n;
								mi[j].n += mi[l].n;
								remove(k, l);
							}
							else {
								mi[l].prev = mi[l].n;
								mi[l].n += mi[j].n;
								remove(k, j);
								j--; k--;  break;
							}
						}

						// 다중으로 겹칠 때
						else {
							if (mi[j].prev > mi[l].n) {
								mi[j].n += mi[l].n;
								remove(k, l);
							}
							else {
								mi[l].prev = mi[l].n;
								mi[l].n += mi[j].n;
								remove(k, j);
								j--; k--;  break;
							}
						}
						k--;
						l--;
					}
				}
			}
		}

		for (int i = 0; i < k; i++)
			ans += mi[i].n;

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}