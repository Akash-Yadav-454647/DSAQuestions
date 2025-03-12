class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0;
        int positive = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==0){
                positive = mid+1;
                l = mid+1;
            }
            else if(nums[mid]>0){
                positive = mid;
                r = mid - 1;
            }
            else{
                l = mid+1;
            }
        }
        int l1 = 0;
        int r1 = nums.size()-1;
        int negative = 0;
        while(l1<=r1){
            int mid = (l1+r1)/2;
            if(nums[mid]==0){
                negative = mid-1;
                r1 = mid-1;
            }
            else if(nums[mid]>0){
                r1 = mid - 1;
            }
            else{
                negative = mid;
                l1 = mid+1;
            }
        }
        cout<<positive<<" "<<negative<<endl;
        int n = nums.size();
        int p = n-positive;
        int n1 = negative+1;
        if(p>n1){
            return p;
        }
        return n1;
    }
};