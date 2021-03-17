#include<iostream>
#include<algorithm>

// ����ӵ� ���̱�
#define MOD 1000000007

// ���� ������ �����ؼ� ������ �״�� ���������� ���� �����Ƿ� pair�ʿ� ����

using namespace std;
long long int map[100];

// init ������ n�� ����� ������ �ʿ� ����

// �迭 ���� ������ص� �� �Ѱ��� �־��ָ� ��
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

		// max���� �� for�� �ϳ� �� �ȸ��� �Է��� �� ���� �� ����
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

		// ���� ū ������ ���� ���߿� ������ ���� �ʴ� ������ ����
		// count �ȸ��� B �״�� ���ָ� ��
		for (int i = 0; i < N; i++) {
			while (map[i] * A < max) {
				map[i] *= A;
				B--;
			}
		}
		sort(map, map + N);

		// N���� �������� �� �������� �� ���ϱ�
		remind = B % N;
		int idx;
		for (idx = 0; idx < remind; idx++) {
			map[idx] = (A * map[idx]) % MOD;
		}

		// ������ �ȹо��൵ ����Ŭ�̹Ƿ� ���� ���·� ��Ÿ���� ��

		// B�� A�� n���̹Ƿ� A�� B������ �ؼ� %div�� ���ش�.
		long long r = expr(A, B / N);
		cout << '#' << test_case;

		// idx�� ��� �����ָ鼭 ��Ÿ�� ���̹Ƿ� % N�� �ʿ���
		for (; map[idx] != -1; ++idx %= N) {
			map[idx] = (map[idx] * r) % MOD;
			cout << ' ' << map[idx];
			map[idx] = -1;
		}
		cout << '\n';
	}
	return 0;
}