class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nums(n1 + n2);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());

        int n = nums.size();
        if (n % 2 == 0) {
            int mid1 = n / 2 - 1;
            int mid2 = n / 2;
            return (nums[mid1] + nums[mid2]) / 2.0; 
        } else {
            int mid = n / 2;
            return nums[mid];
        }
    }
};