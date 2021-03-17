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
		long long N, A = 2, B = 3;
		bool odd = true;
		cin >> N;
		while (true) {
			if (odd == 1) {
				if (N < A) {
					cout << '#' << test_case << " Bob\n";
					break;
				}
				B *= 2;
				A = 2 * A + 1;
			}
			else {
				if (N < B) {
					cout << '#' << test_case << " Alice\n";
					break;
				}
				A *= 2;
				B = 2 * B + 1;
			}
			if (odd == 1) odd = 0;
			else odd = 1;
		}
	}
	return 0;
}