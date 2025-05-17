class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zp = 0;
        int n = nums.size();
        int tp = n-1;
        int j = 0;
        while(j<=tp){
            if(nums[j]==0){
                swap(nums[zp],nums[j]);
                zp++;
                j++;
            }
            else if(nums[j]==2){
                swap(nums[tp],nums[j]);
                tp--;
            }
            else{
                j++;
            }
        }

    }
};