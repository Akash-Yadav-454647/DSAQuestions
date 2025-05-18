class Solution {
    int solve(vector<int> &nums,int n){
        vector<int>dp(2500,1);
        int maxlis = 1;
        for(int j = 0; j<n; j++){
            for(int i = 0; i<=j;i++){
                if(nums[i]<nums[j]){
                    dp[j] = max(dp[j] , (1+dp[i]));
                    maxlis = max(maxlis,dp[j]);
                }
            }
        }
        return maxlis;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n);
        
    }
};