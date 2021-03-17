#include<iostream>

using namespace std;

pair<int, int> cross[1000];

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
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> cross[i].first >> cross[i].second;
			for (int j = 0; j < i; j++) {
				if ((cross[i].first > cross[j].first && cross[i].second < cross[j].second) ||
					(cross[i].first < cross[j].first && cross[i].second > cross[j].second))
					ans++;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}