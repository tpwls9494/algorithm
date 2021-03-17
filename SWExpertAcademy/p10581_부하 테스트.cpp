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
		int P, ans = 0;
		long long L, C;
		cin >> L >> P >> C;
		while (true) {
			if (L * C >= P) break;
			ans++;
			if (C * C > 1000000000)
				break;
			else
				C *= C;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}