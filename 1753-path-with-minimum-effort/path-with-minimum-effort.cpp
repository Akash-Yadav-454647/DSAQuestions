class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[m-1].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        auto cmp = [&](pair<pair<int,int>,pair<int,int>> & a, pair<pair<int,int>,pair<int,int>> & b) {
            return 
            abs(h[a.first.first][a.first.second] - h[a.second.first][a.second.second]) >  
            abs(h[b.first.first][b.first.second] - h[b.second.first][b.second.second]);
        };
        priority_queue< pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, decltype(cmp)> pq(cmp);
        if(1>=0 && 1<n) pq.push({{0,0}, {0,1}});
        if(1>=0 && 1<m)pq.push({{0,0}, {1,0}});
        vis[0][0] = 1;

        int effort = 0;
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            effort = max(effort, abs(h[t.first.first][t.first.second] - h[t.second.first][t.second.second]));
            if (t.second.first == m - 1 && t.second.second == n - 1) {
                return effort;
            }
            int tp = t.second.first - 1;
            int bt = t.second.first + 1;
            int lf = t.second.second + 1;
            int rt = t.second.second - 1;
            vis[t.first.first][t.first.second] = 1;
            if ((tp >= 0 && tp < m) && !vis[tp][t.second.second]) {
                pq.push({{t.second.first, t.second.second}, {tp, t.second.second}});
            }
            if ((bt >= 0 && bt < m) && !vis[bt][t.second.second]) {
                pq.push({{t.second.first, t.second.second}, {bt, t.second.second}});
            }
            if ((lf >= 0 && lf < n) && !vis[t.second.first][lf]) {
                pq.push({{t.second.first, t.second.second}, {t.second.first, lf}});
            }
            if ((rt >= 0 && rt < n) && !vis[t.second.first][rt]) {
                pq.push({{t.second.first, t.second.second}, {t.second.first, rt}});
            }
        }
        return effort;
    }
};

