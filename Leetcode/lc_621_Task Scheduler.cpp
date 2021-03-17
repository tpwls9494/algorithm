#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> alpha(26, 0);
        int ans = 0, reminder = 0, changedN, cnt = 0;
        for (int i = 0; i < tasks.size(); i++) {
            alpha[tasks[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                if (alpha[i] < alpha[j])
                    swap(alpha[i], alpha[j]);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i]) cnt++;
            else break;
        }
        if (n > 25) {
            reminder = n - 25;
            n = 25;
        }
        while (!alpha[0]) {
            for (int i = 0; i <= n; i++) {
                alpha[i]--;
                ans++;
            }
            if (reminder) ans += reminder;
            for (int i = 0; i < cnt; i++) {
                for (int j = i + 1; j < cnt; j++) {
                    if (alpha[i] < alpha[j])
                        swap(alpha[i], alpha[j]);
                }
            }
            if (!alpha[0]) {
                for (int i = 0; i <= 26; i++) {
                    if (alpha[i] < 0) ans--;
                }
                continue;
            }
            for (int i = 0; i < cnt; i++) {
                if (alpha[i] < 0) alpha[i]++;
            }
        }
        if (reminder) ans -= reminder;
        return ans;
    }
};