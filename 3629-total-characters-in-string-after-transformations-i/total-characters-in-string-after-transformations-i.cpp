class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod=1e9+7;
        vector<int>fre(26,0);
        for(char c:s) fre[c-'a']++;
        while(t--){
            int zee=fre[25];
            for(int i=25;i>0;i--){
                fre[i]=fre[i-1];
            }
            fre[0]=zee;
            fre[1]=(zee+fre[1])%mod;
        }
        int res=0;
        for(int x:fre) res=(res+x)%mod;
        return res;
    }
};