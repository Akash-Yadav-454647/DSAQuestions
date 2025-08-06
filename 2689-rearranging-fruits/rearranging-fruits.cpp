class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        int globalMin = INT_MAX;

        for (int i = 0; i < basket1.size(); ++i) {
            count[basket1[i]]++;
            count[basket2[i]]--;
            globalMin = min(globalMin, min(basket1[i], basket2[i]));
        }

        vector<int> excess;
        for (auto& [key, val] : count) {
            if (val % 2 != 0) return -1;
            for (int i = 0; i < abs(val) / 2; ++i) {
                excess.push_back(key);
            }
        }

        sort(excess.begin(), excess.end());
        long long cost = 0;
        for (int i = 0; i < excess.size() / 2; ++i) {
            cost += min(excess[i], 2 * globalMin);
        }
        return cost;
    }
};