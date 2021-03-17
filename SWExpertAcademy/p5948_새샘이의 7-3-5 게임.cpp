#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n[7], count = 0, sum[35], num = 0;
		for (int i = 0; i < 7; i++) {
			cin >> n[i];
		}
		set<int> s(n, n + 7);
		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); iter++) {
			n[count] = *iter;
			count++;
		}
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j < count; j++) {
				for (int k = j + 1; k < count; k++) {
					sum[num] = n[i] + n[j] + n[k];
					num++;
				}
			}
		}
		set<int> s2(sum, sum + num);
		set<int>::reverse_iterator r_iter;
		num = 0;
		for (r_iter = s2.rbegin(); r_iter != s2.rend(); r_iter++) {
			sum[num] = *r_iter;
			if (num == 4) break;
			num++;
		}
		cout << '#' << test_case << ' ' << sum[4];
	}
	return 0;
}