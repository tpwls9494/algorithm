#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void sumA(vector<int>& nums, int depth, int sum, int S, int& ans) {
    if (depth == nums.size()) {
        if (sum == S)
            ans++;
    }
    else {
        sumA(nums, depth + 1, sum + nums[depth], S, ans);
        sumA(nums, depth + 1, sum - nums[depth], S, ans);
    }
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        sumA(nums, 0, 0, S, ans);
        return ans;
    }
};