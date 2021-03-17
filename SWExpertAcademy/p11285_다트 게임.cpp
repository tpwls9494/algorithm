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

		int N, ans = 0;
		short x, y;
		unsigned short score;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			score = 40001;
			if(x * x + y * y <= 40000) score = x * x + y * y;
			if (score >= 0 && score <= 400) ans += 10;
			else if (score <= 1600) ans += 9;
			else if (score <= 3600) ans += 8;
			else if (score <= 6400) ans += 7;
			else if (score <= 10000) ans += 6;
			else if (score <= 14400) ans += 5;
			else if (score <= 19600) ans += 4;
			else if (score <= 25600) ans += 3;
			else if (score <= 32400) ans += 2;
			else if (score <= 40000) ans += 1;
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}