class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positiveCount = 0, negativeCount = 0;

        for (int num : nums) {
            positiveCount += num > 0;
            negativeCount += num < 0;
        }

        return max(positiveCount, negativeCount);
    }
};