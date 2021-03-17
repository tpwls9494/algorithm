#include<iostream>
#include<algorithm>

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
		int N, w[100], max = 0, ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> w[i];
		}
		sort(w, w + N);
		for (int i = 0; i < N; i++) {
			if (50 % w[i]) w[i] = 50 / w[i] + 1;
			else w[i] = 50 / w[i];
		}

		int cnt = 0;
		for (int i = N - 1; i >= 0; i--) {
			cnt = cnt + w[i] - 1;
			ans++;
			if (cnt >= i) {
				cnt = cnt - w[i] + 1;
				cnt = i - cnt + 1;
				if (cnt / w[i] < 1) ans--;
				break;

			}
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}