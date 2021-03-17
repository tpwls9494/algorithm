#include<iostream>
#include<queue>
using namespace std;
bool check[10001];

int answer(int max, int N, int n[]) {
	queue<int> q;
	int sum = 0;
	check[0] = true;
	q.push(0);
	for (int i = 0; i < N; i++) {
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int score = q.front();
			q.pop();

			if (!check[score + n[i]]) {
				check[score + n[i]] = true;
				q.push(score + n[i]);
			}
			q.push(score);
		}
	}
	for (int i = 0; i < max; i++) {
		if (check[i] == true) {
			sum++;
			check[i] = 0;
		}
	}
	return sum;
}

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
		int N, n[100], max = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> n[i];
			max += n[i];
		}
		cout << '#' << test_case << ' ' << answer(max, N, n) << '\n';
	}
	return 0;
}