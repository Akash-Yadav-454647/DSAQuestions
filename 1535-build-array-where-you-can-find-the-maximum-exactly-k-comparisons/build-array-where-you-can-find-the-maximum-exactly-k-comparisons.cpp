#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int N, M, K;
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

    int solve(int idx, int cmax, int cost) {
        // Base case: all elements placed
        if (idx == N) return cost == K ? 1 : 0;
        if (cost > K) return 0; // Can't exceed target cost

        // Map cmax from [-1..M] to [0..M+1] for indexing
        int& memo = dp[idx][cmax + 1][cost];
        if (memo != -1) return memo;

        long long res = 0;
        for (int i = 1; i <= M; i++) {
            if (i > cmax) {
                // New max, increases cost
                res = (res + solve(idx + 1, i, cost + 1)) % MOD;
            } else {
                // No change in max
                res = (res + solve(idx + 1, cmax, cost)) % MOD;
            }
        }

        return memo = (int)res;
    }

public:
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        dp = vector<vector<vector<int>>>(
            N,                      // idx: 0 to N-1
            vector<vector<int>>(M + 2,  // cmax + 1: from -1 to M → 0 to M+1
                vector<int>(N + 1, -1))  // cost: 0 to K
        );
        return solve(0, -1, 0);
    }
};
