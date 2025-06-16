class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int diff = -1;
        int premin = nums[0];
        for(int i= 1; i<n; i++){
            if(premin<nums[i]){
                diff = max(diff,nums[i]-premin);
            }
            else{
                premin = nums[i];
            }
        }
        return diff;
    }
};