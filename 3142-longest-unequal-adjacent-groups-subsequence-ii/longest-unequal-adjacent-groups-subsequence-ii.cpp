class Solution {
public:
    int dp[1001][1002];
    vector<string> ans;
    bool fun(const string &x, const string &y) {
        if (x.size() != y.size()) return false;
        int cnt = 0;
        for (int i = 0; i < (int)x.size(); i++) {
            if (x[i] != y[i] && ++cnt > 1)
                return false;
        }
        return cnt == 1;
    }
    int solve(int ind, int prev,
              const vector<string>& w,
              const vector<int>& g) {
        int pi = prev + 1, n = w.size();
        if (ind == n) 
            return 0;
        if (dp[ind][pi] != -1) 
            return dp[ind][pi];
        int best = solve(ind + 1, prev, w, g);

        if (prev == -1 ||
            (g[prev] != g[ind] && fun(w[prev], w[ind]))) {
            best = max(best,
                       1 + solve(ind + 1, ind, w, g));
        }

        return dp[ind][pi] = best;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& w,
                                                vector<int>& g) {
        int n = w.size();
        // initialize memo to -1
        memset(dp, -1, sizeof(dp));

        // fill dp table
        solve(0, -1, w, g);

        // Phase 2: iterative reconstruction
        ans.clear();
        int ind = 0, prev = -1;
        while (ind < n) {
            int pi = prev + 1;
            int skip = dp[ind + 1][pi];
            int take = -1;

            // check if we can take w[ind]
            if (prev == -1 ||
                (g[prev] != g[ind] && fun(w[prev], w[ind]))) {
                take = 1 + dp[ind + 1][ind + 1];
            }

            if (take > skip) {
                // choose to take it
                ans.push_back(w[ind]);
                prev = ind;
            }
            // otherwise skip
            ind++;
        }

        return ans;
    }
};