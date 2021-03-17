#include<iostream>
#include<set>

using namespace std;

char arr[28];

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
		int n, k, size, n10;
		char n16[7];
		set<int> s;
		cin >> n >> k >> arr;
		size = n / 4;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < size; j++) {
				int l = i + j;
				if (l >= n) l %= n;
				n16[j] = arr[l];
			}
			n10 = (int)strtol(n16, NULL, 16);
			s.insert(n10);
		}

		size = 1;
		for (auto ri = s.rbegin(); ri != s.rend(); ri++) {
			if (size == k) {
				cout << '#' << test_case << ' ' << *ri << '\n';
				break;
			}
			size++;
		}
	}
	return 0;
}