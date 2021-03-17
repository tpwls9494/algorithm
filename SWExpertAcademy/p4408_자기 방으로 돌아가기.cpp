#include<iostream>

using namespace std;
int count[200];

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
		int N, start, end;
		cin >> N;
		int count[200] = { 0, }, max = 0;
		for (int i = 0; i < N; i++) {
			cin >> start >> end;
			if (start > end) swap(start, end);

			if (start % 2 == 1) start /= 2;
			else start = start / 2 - 1;

			if (end % 2 == 1) end /= 2;
			else end = end / 2 - 1;

			for (int j = start; j < end; j++) {
				count[j]++;
			}
		}
		for (int i = 0; i < 400; i++) if (count[i] > max) max = count[i];
		cout << '#' << test_case << ' ' << max << '\n';
	}
	return 0;
}