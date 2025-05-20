class Solution {
    vector<int> dp;
    bool ispred(string &shorter, string &longer) {
        if (shorter.size() + 1 != longer.size()) return false;

        int i = 0, j = 0;
        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++;
            }
            j++;
        }
        return i == shorter.size();
    }
    int solve(vector<string> & words){
        int n = words.size();
        int maxl = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i;j++ ){
                if(ispred(words[j],words[i])){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            maxl = max(maxl,dp[i]);
        }
        return maxl;
    }
public:
    static bool myFunc(string & word1, string & word2){
        return word1.size() < word2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),myFunc);
        dp.assign(words.size(),1);
        return solve(words);

    }
};