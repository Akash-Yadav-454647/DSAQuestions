class Solution {
    vector<int> dp;
    int solve(vector<int>& nums,int i , int n){
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<=n; i++){
            int take = nums[i-1]+dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(skip,take);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1,-1);
        return solve(nums,0,n);
    }
};