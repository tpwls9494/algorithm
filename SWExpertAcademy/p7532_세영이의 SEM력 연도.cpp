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
		int S, E, M, cnt = 0;
		cin >> S >> E >> M;
		if (S != 1) {
			cnt = S - 1;
			S = 1;
		}
		E -= cnt;
		M -= cnt;
		for (int i = 0; i < 16; i++) {
			if (E < 0) E += 24;
			if (M < 0) M += 29;
		}

		while (!(S == 1 && E == 1 && M == 1)) {
			E -= 5; M -= 17;
			if (E < 1) E += 24;
			if (M < 1) M += 29;
			cnt += 365;
		}

		cout << '#' << test_case << ' ' << cnt + 1 << '\n';
	}
	return 0;
}