class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int c = 0;
        int r = 1;
        for(int i = 1; i<n; i++){
            if(word[i-1]==word[i]) {
                c++;
            }
            else{
                r += c;
                c = 0;
            }
        }
        return r+c;
    }   
};