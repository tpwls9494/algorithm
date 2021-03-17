#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
char map[20][20];
queue<tuple<int, int, int, int>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char now;
int lo, memo;
bool path[20][20][16][4];

bool cha(int ny, int nx) {
    switch (now) {
    case '<':
        lo = 2;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '^':
        lo = 3;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '>':
        lo = 0;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case 'v':
        lo = 1;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '_':
        if (memo == 0) lo = 0;
        else lo = 2;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '|':
        if (memo == 0) lo = 1;
        else lo = 3;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '+':
        memo++;
        if (memo > 15)
            memo = 0;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '-':
        memo--;
        if (memo < 0)
            memo = 15;
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '.':
        if (!path[ny][nx][memo][lo]) {
            q.push(tie(ny, nx, memo, lo));
            path[ny][nx][memo][lo] = true;
        }
        break;
    case '@':
        return true;
        break;
    case '?':
        for (int i = 0; i < 4; i++) {
            lo = i;
            if (!path[ny][nx][memo][lo]) {
                q.push(tie(ny, nx, memo, lo));
                path[ny][nx][memo][lo] = true;
            }
        }
        break;
    default:
        if (now >= '0' && now <= '9') {
            memo = now - '0';
            if (!path[ny][nx][memo][lo]) {
                q.push(tie(ny, nx, memo, lo));
                path[ny][nx][memo][lo] = true;
            }
        }
        break;
    }
    return false;
}

string answer(int R, int C) {
    int nx = 0, ny = 0;
    queue<tuple<int, int, int, int>> emptyque;
    swap(q, emptyque);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            for (int k = 0; k < 16; k++)
                for (int l = 0; l < 4; l++)
                    path[i][j][k][l] = false;

    lo = 0, memo = 0;
    now = map[0][0];
    if (cha(ny, nx)) return "YES";

    while (!q.empty()) {
        tie(ny, nx, memo, lo) = q.front();
        q.pop();

        nx += dx[lo];
        ny += dy[lo];
        if (nx == -1) nx = C - 1;
        else if (ny == -1) ny = R - 1;
        else if (nx == C) nx = 0;
        else if (ny == R) ny = 0;
        now = map[ny][nx];
        if(cha(ny, nx)) return "YES";
        cout << '\n' << now;
    }
    return "NO";
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
        int R, C;
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }
        cout << '#' << test_case << ' ' << answer(R, C) << '\n';
    }
    return 0;
}