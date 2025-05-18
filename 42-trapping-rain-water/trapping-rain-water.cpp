class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); 
        int water = 0;     
        vector<int> l_max(n), r_max(n);
        l_max[0] = height[0]; 
        for (int i = 1; i < n; i++)
            l_max[i] = max(height[i], l_max[i - 1]);
        r_max[n - 1] = height[n - 1]; 
        for (int i = n - 2; i >= 0; i--)
            r_max[i] = max(height[i], r_max[i + 1]);
        for (int i = 1; i < n - 1; i++)
        {
            water += min(r_max[i], l_max[i]) - height[i];
        }
        return water; 
    }
};