#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        	ios::sync_with_stdio(false);
        int n, map[100][100], cnt = 0;
        bool check[100][100] = { 0, };
        pair<int, int> matrix[2000]{ {0, 0}, };
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            if (map[i][0] && !check[i][0]) {
                for (int y = i; y < n; y++) {
                    if (!map[y][0]) break;
                    matrix[cnt].first++;
                    check[y][0] = 1;
                }
                for (int x = 0; x < n; x++) {
                    if (!map[i][x]) break;
                    matrix[cnt].second++;
                    check[i][x] = 1;
                }
                for (int y = i + 1; y < i + matrix[cnt].first - 1; y++) {
                    for (int x = 1; x < n; x++) {
                        if (!map[y][x]) break;
                        check[y][x] = 1;
                    }
                }
                cnt++;
            }
            for (int j = 1; j < n - 1; j++) {
                if ((!map[i][j] && map[i][j + 1] && !check[i][j + 1])) {
                    for (int y = i; y < n; y++) {
                        if (!map[y][j + 1]) break;
                        matrix[cnt].first++;
                        check[y][j + 1] = 1;
                    }
                    for (int x = j + 1; x < n; x++) {
                        if (!map[i][x]) break;
                        matrix[cnt].second++;
                        check[i][x] = 1;
                    }
                    for (int y = i + 1; y < i + matrix[cnt].first - 1; y++) {
                        for (int x = j + 1; x < n; x++) {
                            if (!map[y][x]) break;
                            check[y][x] = 1;
                        }
                    }
                    cnt++;
                }
            }
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (matrix[i].first * matrix[i].second >= matrix[j].first * matrix[j].second)
                    swap(matrix[i], matrix[j]);
            }
        }
        cout << '#' << test_case << ' ' << cnt;
        for (int i = 0; i < cnt; i++)
            cout << ' ' << matrix[i].first << ' ' << matrix[i].second;
        cout << '\n';
    }
    return 0;
}