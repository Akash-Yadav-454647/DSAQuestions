class Solution {
public:
    int gcd(int a, int b){
        while(a!=0)
        {
            int t = a;
            a = b%a;
            b = t;
        }
        return b;
    }
    int findGCD(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        for(int i = 0; i <nums.size(); i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        return gcd(maxi,mini);
    }
};