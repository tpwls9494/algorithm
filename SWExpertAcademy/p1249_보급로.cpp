#include<iostream>
#include<queue>
#include<tuple>

using namespace std;
int map[100][100];
int cnt[100][100];
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { -1, 0, 0, 1 };
typedef tuple<int, int, int> P;
priority_queue<P, vector<P>, greater<P>> q;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;

        // map생성
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                scanf("%1d", &map[x][y]);
                cnt[x][y] = 10000;
            }
        }

        //우선순위 큐에 0저장
        q.push(make_tuple(0, 0, 0));
        while (!q.empty()) {
            int d, x, y;
            tie(d, x, y) = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < N && ny < N && nx >= 0 && ny >= 0) {
                    int nd = map[nx][ny] + d;
                    if (cnt[nx][ny] > nd) {
                        cnt[nx][ny] = nd;
                        q.push(tie(nd, nx, ny));
                    }
                }
            }
        }
        cout << "#" << test_case << ' ' << cnt[N - 1][N - 1] << '\n';
    }
    return 0;
}