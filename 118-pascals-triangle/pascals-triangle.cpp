class Solution {
public:
     vector<vector<int>> fun(int n, vector<vector<int>>  & vec) {
        if(n==1){
            vec.push_back({1});
            return vec;
        }
        fun(n-1,vec);
        int r = vec.size();
        int m = vec[r-1].size();
        vector<int> a;
        a.push_back(1);
        for(int i = 1; i<m; i++){
            a.push_back(vec[r-1][i]+vec[r-1][i-1]);
        }
        a.push_back(1);
        vec.push_back(a);
        return vec;
     }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> vec ;
        fun(n,vec);
        return vec;
        
    }
};