#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, count[5];
		char c = ' ', frC = '*';
		bool isUpper = false;
		cin >> n;
		for (int i = 0; i < n; i++) {
			count[i] = 0;
			while (!(c == '.' || c == '?' || c == '!')) {
				scanf("%1c", &c);
				if (isUpper && (c == ' ' || c == '.' || c == '?' || c == '!')) {
					count[i]++;
					isUpper = false;
				}
				// �� ���ڰ� ������ ���� ���ڰ� �빮���� ��
				if ((frC == '!' || frC == '?' || frC == '.' || frC == ' ' || frC == '\n') && c >= 'A' && c <= 'Z')
					isUpper = true;
				// ���ڰ� �ҹ��ڰ� �ƴ� �� (�����ڰ� �ҹ����̸�, �������� �ҹ��� �̿� ����)
				else if (((frC >= 'a' && frC <= 'z')||(frC >= 'A' && frC <= 'Z')) && !(c >= 'a' && c <= 'z'))
					isUpper = false;
				frC = c;
			}
			scanf("%1c", &c);
		}
		cout << '#' << test_case;
		for (int i = 0; i < n; i++)
			cout << ' ' << count[i];
		cout << '\n';
	}
	return 0;
}