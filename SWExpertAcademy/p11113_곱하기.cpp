#include<iostream>
#include<algorithm>

// 실행속도 줄이기
#define MOD 1000000007

// 문제 내에서 정렬해서 원상태 그대로 돌려놓으란 말이 없으므로 pair필요 없음

using namespace std;
long long int map[100];

// init 어차피 n개 덮어쓰기 때문에 필요 없음

// 배열 내에 저장안해도 값 한곳에 넣어주면 됨
long long expr(long long int x, long long int y) {
	int ans = 1;
	for (int k = 0; y != 0; k++) {
		if ((y & 1) == 1) ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ans;
}

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
		int N, remind, max = 0;
		long long B, A;
		cin >> N >> A >> B;

		// max구할 때 for문 하나 더 안만들어도 입력할 때 구할 수 있음
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			max = map[i] > max ? map[i] : max;
		}

		if (A == 1) {
			sort(map, map + N);
			cout << '#' << test_case;
			for (int i = 0; i < N; i++)
				cout << ' ' << map[i];
			cout << '\n';
			continue;
		}

		// 가장 큰 값보다 작은 값중에 나누어 지지 않는 값으로 정렬
		// count 안만들어도 B 그대로 빼주면 됨
		for (int i = 0; i < N; i++) {
			while (map[i] * A < max) {
				map[i] *= A;
				B--;
			}
		}
		sort(map, map + N);

		// N으로 나누었을 때 나머지와 몫 구하기
		remind = B % N;
		int idx;
		for (idx = 0; idx < remind; idx++) {
			map[idx] = (A * map[idx]) % MOD;
		}

		// 어차피 안밀어줘도 싸이클이므로 더한 상태로 나타내면 됨

		// B가 A의 n승이므로 A에 B제곱을 해서 %div를 해준다.
		long long r = expr(A, B / N);
		cout << '#' << test_case;

		// idx를 계속 더해주면서 나타낸 것이므로 % N이 필요함
		for (; map[idx] != -1; ++idx %= N) {
			map[idx] = (map[idx] * r) % MOD;
			cout << ' ' << map[idx];
			map[idx] = -1;
		}
		cout << '\n';
	}
	return 0;
}