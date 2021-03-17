#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start, end;
        int a[10000];
        for (int i = 0; i < n; i++) {
            if (i == 0)
                a[i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (i == 0)
                    a[j] = nums[j];
                if (a[i] > a[j]) swap(a[i], a[j]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != a[i]) {
                start = i;
                break;
            }
            else if (i == n - 1)
                return 0;
        }
        for (int i = n - 1; i >= 0; i--)
            if (nums[i] != a[i]) {
                end = i;
                break;
            }
        return end - start + 1;
    }
};