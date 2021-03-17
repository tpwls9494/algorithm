#include<iostream>

using namespace std;

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
		int N, P, A[5001] = { 0, }, start, end, count[5001], Pi;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> start >> end;
			for (int j = start; j <= end; j++) {
				A[j]++;
			}
		}
		cin >> P;
		for (int i = 1; i <= P; i++) {
			cin >> Pi;
			count[i] = A[Pi];
		}
		cout << '#' << test_case;
		for (int i = 1; i <= P; i++)
			cout << ' ' << count[i];
		cout << '\n';
	}
	return 0;
}