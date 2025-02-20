class Solution {
public:
    void solve(string& res, string& temp, vector<string>& vec, int& n,bool & found){
        if(temp.size()==n){
            if(!found && find(vec.begin(), vec.end(), temp)==vec.end()){
                res = temp;
                found = true;
            }
            return;
        }
        for(int ch = '0' ; ch<='1'; ch++){
            temp.push_back(ch);
            solve(res,temp,vec,n,found);
            temp.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        string temp = "";
        bool found = false;
        solve(res,temp,nums,n,found);
        return res;
    }
};