class Solution {
public:
    bool isPalindrome(string &w1){
        int end = w1.length()-1;
        int strt = 0;
        while(strt <= end){
            if(w1[strt] != w1[end]){
                return false;
            }
            strt++;
            end--;
        }
        return true;
    }

    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int res = 0;
        bool centerUsed = false;

        for (string &word : words) {
            mp[word]++;
        }

        for (auto &it : mp) {
            string curr = it.first;
            int count = it.second;
            string reversed = curr;
            reverse(reversed.begin(), reversed.end());

            if (curr == reversed) {
                // For palindromic words like "aa"
                res += (count / 2) * 4;
                if (count % 2 == 1 && !centerUsed) {
                    res += 2;
                    centerUsed = true;
                }
                mp[curr] = 0;  // mark as used
            } else if (mp.find(reversed) != mp.end()) {
                int minPair = min(count, mp[reversed]);
                res += minPair * 4;
                mp[curr] = 0;
                mp[reversed] = 0;  // mark both as used
            }
        }

        return res;
    }
};
