class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        for(int i = 0; i<nums.size();i++) mp[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        for(auto e : mp){
            pq.push({e.first,e.second});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(pq.size()>0){
            auto r = pq.top();
            res.push_back(r.first);
            pq.pop();
        }
        return res;
        
    }
};