class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> num;
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }
        for (int numi : nums) {
            if (numi != 0) {
                num.push_back(numi);
            }
        }
        while (num.size() < n) {
            num.push_back(0);
        }

        return num;
    }
};