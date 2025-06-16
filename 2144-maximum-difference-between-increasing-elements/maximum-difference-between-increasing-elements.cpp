class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int diff = -1;
        for(int i= 0; i<n-1; i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    diff = max(diff,(nums[j]-nums[i]));
                }
            }
        }
        return diff;
    }
};