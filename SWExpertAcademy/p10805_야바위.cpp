#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, Q, ballCnt = 0, max = 0, a, b, num = 0;
		int ball[100001] = { 0 };
		cin >> N >> Q;

		// 처음 변경
		ball[1] = 1;
		ball[2] = 2;
		while (Q != 0) {
			cin >> a >> b;
			
			// 공위치의 최대값
			if (max < a + 1) max = a + 1;
			if (max < b + 1) max = b + 1;

			// a나 b에 1이 있다면
			if (ball[a] == 1 || ball[b] == 1) {
				if (ball[a] == 1) {
					swap(ball[a], ball[b]);
					if (b+1 != N+1) ball[b + 1] = 2;
					if (b-1 != 0) ball[b - 1] = 2;
				}
				else {
					swap(ball[a], ball[b]);
					if (a + 1 != N+1) ball[a + 1] = 2;
					if (a - 1 != 0) ball[a - 1] = 2;
				}
			}

			// a나 b에 2가 있다면
			else if (ball[a] == 2 && ball[b] == 2) {
				Q--;
				continue;
			}
			else if (ball[a] == 2) {
				ball[a] = 0;
				if (ball[a - 1] == 1 || ball[a + 1] == 1) ball[a] = 2;
				ball[b] = 2;
			}
			else if (ball[b] == 2) {
				ball[b] = 0;
				if (ball[b - 1] == 1 || ball[b + 1] == 1) ball[b] = 2;
				ball[a] = 2;
			}
			Q--;
		}

		for (int i = 1; i < max+1; i++) {
			if (ball[i] == 2) num++;
		}

		cout << '#' << test_case << ' ' << num << '\n';
	}
	return 0;
}