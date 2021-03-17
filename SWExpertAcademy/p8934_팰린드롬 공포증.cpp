#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int test_case;
	int T;
	cin >> T;
	string spell;
		for (test_case = 1; test_case <= T; ++test_case)
		{
			bool isPallin = 0;
			int arr[3] = { 0, }, max = 0;
			cin >> spell;
			int num = spell.size();
			for (int i = 0; i < num; i++) {
				if (spell[i] == 'a') arr[0]++;
				else if (spell[i] == 'b') arr[1]++;
				else arr[2]++;
			}
			for (int i = 0; i < 3; i++)
				if (max < arr[i])
					max = arr[i];
			for (int i = 0; i < 3; i++)
				if (max - arr[i] > 1)
					isPallin = 0;
			if (isPallin)
				cout << '#' << test_case << " YES" << '\n';
			else
				cout << '#' << test_case << " NO" << '\n';
		}
	return 0;
}