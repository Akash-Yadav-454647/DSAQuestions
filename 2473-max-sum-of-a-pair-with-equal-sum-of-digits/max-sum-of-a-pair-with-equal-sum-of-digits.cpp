class Solution {
public:
    int sc(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int, priority_queue<int>> m; 
        for (int num : nums) {
            int digitSum = sc(num);
            m[digitSum].push(num);
        }

        int maxi = -1;
        for (auto& entry : m) {
            if (entry.second.size() >= 2) {  
                int first = entry.second.top();
                entry.second.pop();
                int second = entry.second.top(); 
                maxi = max(maxi, first + second);  
            }
        }

        return maxi;  
    }
};