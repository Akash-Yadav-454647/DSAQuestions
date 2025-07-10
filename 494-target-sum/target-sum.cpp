struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        // Combine the hash of both integers
        // A common way: shift and xor
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, pair_hash> memo;

    int dp(const vector<int>& nums, int target, int index, int curr_sum) {
        pair<int, int> key = {index, curr_sum};
        if (memo.find(key) != memo.end())
            return memo[key];
        if (index < 0)
            return curr_sum == target ? 1 : 0;

        int positive = dp(nums, target, index - 1, curr_sum + nums[index]);
        int negative = dp(nums, target, index - 1, curr_sum - nums[index]);

        memo[key] = positive + negative;
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, target, nums.size() - 1, 0);
    }
};