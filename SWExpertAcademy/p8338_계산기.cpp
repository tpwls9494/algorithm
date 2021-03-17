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
		int n, a, sum;
		cin >> n;
		cin >> sum;
		for (int i = 1; i < n; i++) {
			cin >> a;
			sum = (a + sum) > (a * sum) ? (a + sum) : (a * sum);
		}

		cout << '#' << test_case << ' ' << sum << '\n';
	}
	return 0;
}