#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long sum = 0, n, num[6], max = 0;
	cin >> n;
	if (n == 1) {
		for (int i = 0; i < 6; i++) {
			cin >> num[i];
			sum += num[i];
			if (max < num[i]) max = num[i];
		}
		sum -= max;
	}
	else {
		for (int i = 0; i < 6; i++)
			cin >> num[i];

		for (int i = 0; i < 3; i++)
				if (num[i] > num[5-i]) swap(num[i], num[5 - i]);

		sort(num, num + 3);

		for (int i = 0; i < 2; i++)
			num[i + 1] += num[i];

		if (n == 2) sum = num[1] * 4 + num[2] * 4;
		else sum = num[2] * 4 + num[1] * ((n - 1) * 8 - 4) + 
			num[0] * ((n - 2) * ((n - 2) + (n - 1) * 4));
	}
	cout << sum << '\n';
	return 0;
}