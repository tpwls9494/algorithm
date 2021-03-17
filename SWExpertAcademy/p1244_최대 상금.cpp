#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        bool is_max = true, is_break = false;
        int num, t_count, n_count = 0, cnt = 0, arr[6], max[6], n;
        int mi, ma;
        cin >> num >> t_count;

        // 자리수 구해주기 배열 거꾸로
        for (int i = num; i != 0; i /= 10) {
            arr[n_count] = num % 10;
            max[n_count] = arr[n_count];
            num /= 10;
            n_count++;
        }

        // 최대값 구하기
        for (int i = 0; i < n_count; i++) {
            for (int j = i + 1; j < n_count; j++) {
                if (max[i] > max[j]) swap(max[i], max[j]);
            }
        }
        cnt = n_count - 1;

        // 변환횟수가 남아있을 때
        while (t_count != 0) {
            is_break = false;
            n = 0;
            for (int i = 0; i < n_count; i++) {
                if (max[i] != arr[i]) is_max = false;
            }
            if (is_max) {
                if (t_count > 1 && t_count % 2 == 0) {
                    break;
                }
                else {
                    if (arr[0] == arr[1] || arr[1] == arr[2]) break;
                    for (int i = 0; i < n_count; i++) {
                        if (arr[0] != arr[i]) {
                            swap(arr[i], arr[i - 1]);
                            is_break = true;
                            break;
                        }
                    }
                    if (is_break) break;
                }
            }

            // 고치기
            for (int i = 0; i <= cnt; i++)
                if (max[cnt] == max[cnt - i])  n++;
            if (n > 2) swap(arr[cnt], arr[cnt - 1]);
            for (int i = 0; i <= cnt; i++) {
                if (max[cnt - i] == arr[cnt - i]) continue;
                else {
                    for (int j = 0; j <= cnt; j++) {
                        if (max[cnt - i] == arr[j]) {
                            swap(arr[cnt - i], arr[j]);
                            break;
                        }
                    }
                    break;
                }
            }
            t_count--;
            is_max = true;
        }
        cout << '#' << test_case << ' ';
        for (int i = n_count - 1; i >= 0; i--) cout << arr[i];
        cout << '\n';
    }
    return 0;
}