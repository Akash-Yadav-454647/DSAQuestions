class Solution {
    vector<int> dp;
    int solve(vector<int> &nums,int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = nums[i]+solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);
        return dp[i] = max(take,skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1,-1);
        return solve(nums,0,n);
    }
};