#include<iostream>
#include<string>

using namespace std;
string str;

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
		int ans[7] = { 0, }, div = 1000000007LL;
		cin >> str;

		// S0 A1 M2 S3 U4 N5 G6 
		for (int i = 0; i < str.length(); ++i) {
			switch (str[i]) {
			case 'S':
				ans[0] = (ans[0] + 1) % div;
				ans[3] = (ans[3] + ans[2]) % div;
				break;
			case 'A':
				ans[1] = (ans[1] + ans[0]) % div;
				break;
			case 'M':
				ans[2] = (ans[2] + ans[1]) % div;
				break;
			case 'U':
				ans[4] = (ans[4] + ans[3]) % div;
				break;
			case 'N':
				ans[5] = (ans[5] + ans[4]) % div;
				break;
			case 'G':
				ans[6] = (ans[6] + ans[5]) % div;
				break;
			default:
				break;
			}
		}
		cout << '#' << test_case << ' ' << ans[6] << '\n';
	}
	return 0;
}