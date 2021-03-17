#include<iostream>

using namespace std;
int index[10000001];
int memo[3164];
int count = 0;

void idx() {
    int n, cnt;
    for (int i = 1; i < 10000001; i++) {
        index[i] = i;
    }
    for (int i = 1; i * i <= 10000000; i++) {
        int status = 0;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
            {
                status = 1;
                break;
            }
        if (status == 0)
            memo[count++] = i;
    }
    for (int i = 1; i < count; i++) {
        n = memo[i] * memo[i];
        cnt = 1;
        while (n * cnt <= 10000000) {
            while (index[n * cnt] % n == 0) {
                index[n * cnt] /= n;
            }
            cnt++;
        }
    }
}

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int test_case;
    int T;

    cin >> T;
    idx();

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int A;
        cin >> A;
        cout << '#' << test_case << ' ' << index[A] << '\n';
    }

    return 0;
}