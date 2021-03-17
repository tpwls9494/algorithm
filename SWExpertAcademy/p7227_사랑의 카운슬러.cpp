#include<iostream>

using namespace std;
long long mi, x[20], y[20], allX, allY;

long long bfs(int depth, int maxDepth, int sumX, int sumY, int index) {
	if (depth == maxDepth) {
		long long x = allX - sumX *2;
		long long y = allY - sumY *2;
		return x * x + y * y;
	}
	
	for (int i = index; i < maxDepth * 2; i++) {
		long long result = bfs(depth + 1, maxDepth, sumX + x[index],
			sumY + y[index], i + 1);
		if (result < mi) mi = result;
	}
	return mi;
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
		int N;
		cin >> N;
		mi = 100000000000;
		allX = 0;
		allY = 0;
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
			allX += x[i];
			allY += y[i];
		}


		cout << '#' << test_case << ' ' << bfs(0, N / 2, 0, 0, 0) << '\n';
	}
	return 0;
}