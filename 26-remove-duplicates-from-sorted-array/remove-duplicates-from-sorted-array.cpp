class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int prev = nums[0];
        int curr = 1;
        for(int i = 0; i < n; i++){
            if(prev != nums[i]){
                if(curr<n) nums[curr++] = nums[i];
                count++;
                prev = nums[i];
            } 
        }
        return count+1;
    }
};