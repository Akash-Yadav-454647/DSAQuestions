class Solution {
public:
    string gen(string& s){
        int n = s.size();
        for(int i = 0; i<n; i++){
            char c = s[i];
            char nc = incr(s[i]);
            s+= nc;
        }
        return s; 
    }
    char incr(char c){
        int pos = c-'a';
        int npos = (pos+1)%26;
        char res = 'a'+npos;
        return res;
    }
    char kthCharacter(int k) {
        string s = "a";
        while(s.size()<k){
            gen(s);
        }
        return s[k-1];
        
    }
};