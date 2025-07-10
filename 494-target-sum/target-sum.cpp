class Solution {
public:
    int offset = 1000;

    int sl(vector<int> & nums,int target,int n,vector<vector<int>> &dp){
        if(n==0){
            if(target == 0){
                return 1;
            }
            else return 0;
        }
        if (target + offset < 0 || target + offset > 2000) return 0;
        if(dp[n][target+offset]!=-1){
            return dp[n][target+offset];
        }
        return dp[n][target+offset] = sl(nums,target-nums[n-1],n-1,dp)+sl(nums,target+nums[n-1],n-1,dp);
        

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, -1));
        sl(nums,target,n,dp);
        return dp[n][target+offset];

    }
};