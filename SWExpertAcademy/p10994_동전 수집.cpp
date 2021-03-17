#include<iostream>

using namespace std;
pair<int, bool> n[500000];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K, coin, chk, sum = 0, count = 0;
		cin >> N >> K;
		cin >> coin >> chk;
		n[0] = { coin, chk };
		for (int i = 0; sum < K && i < N-1; i++) {
			cin >> coin >> chk;
			n[i+1] = { coin, chk };
			if (!n[i].second) {
				if (sum + n[i].first < n[i+1].first) {
					sum += n[i].first;
					count++;
				}
			}
		}
		if (!n[N - 1].second) {
			if (sum + n[N - 1].first < K) {
				sum += n[N - 1].first;
				count++;
			}
		}
		else {
			if (sum == 0) {
				sum = 1;
			}
		}
		cout << '#' << test_case << ' ' << count << ' ' << K - sum << '\n';
	}
	return 0;
}