class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i][0]<nums2[j][0])ans.push_back(nums1[i++]);
            else if(nums1[i][0]>nums2[j][0])ans.push_back(nums2[j++]);
            else if(nums1[i][0]==nums2[j][0]){
                vector<int>temp;
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]+nums2[j][1]);
                ans.push_back(temp);
                i++;
                j++;
            }
        }
        while(i<nums1.size())ans.push_back(nums1[i++]);
        while(j<nums2.size())ans.push_back(nums2[j++]);
        return ans;
    }
};