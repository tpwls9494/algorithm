#include<iostream>

using namespace std;

int arr[1000];

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
		int N, min = 1000001, sum = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (arr[i] < min) min = arr[i];
			sum += arr[i];
		}
		for (int i = 1; i < N-1; i++) {
			arr[i] ^= arr[i-1];
		}
		if (arr[N - 2] == arr[N - 1])
			cout << '#' << test_case << ' ' << sum - min << '\n';
		else
			cout << '#' << test_case << " NO\n";
	}
	return 0;
}