class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zp = 0;
        int n = nums.size();
        for(int j = 0 ; j<n; j++){
            if(nums[j]==0){
                swap(nums[zp],nums[j]);
                zp++;
            }
        }
        int tp = n-1;
        for(int k = n-1; k>=0;k--){
            if(nums[k]==2){
                swap(nums[tp],nums[k]);
                tp--;
            }
        }
    }
};