vector<vector<long long>> dp(100001, vector<long long>(2, -1));


class Solution {
    long long solve(vector<int>& nums, int i, int n, bool flag) {
        if (i >= n) return 0;
        if (dp[i][flag] != -1) return dp[i][flag];

        long long val = flag ? nums[i] : -nums[i];
        long long take = val + solve(nums, i + 1, n, !flag);
        long long skip = solve(nums, i + 1, n, flag);

        return dp[i][flag] = max(take, skip);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        
        for (int i = 0; i <= n; ++i)
            dp[i][0] = dp[i][1] = -1;

        return solve(nums, 0, n, true);
    }
};