class Solution {
public:
    bool isZeroArray(vector<int>& n, vector<vector<int>>& q) {
        vector<int> d(n.size(),0);
        for(int i = 0 ; i<q.size();i++){
            int  l = q[i][0];
            int r = q[i][1];
            d[l] -= 1;
            if(r+1<n.size()){
                d[r+1] += 1;
            }
        }
        for(int i = 1;i<d.size(); i++){
            d[i] += d[i-1];
        }
        for(int i = 0; i<n.size();i++){
            n[i] += d[i];
            if(n[i]> 0){
                return false;
            }

        }
        return true;
         
    }
};