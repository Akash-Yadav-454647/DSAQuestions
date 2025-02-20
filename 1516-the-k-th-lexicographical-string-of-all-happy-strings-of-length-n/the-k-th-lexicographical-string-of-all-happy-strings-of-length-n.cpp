class Solution {
public:
    void solve(string & res, string & temp, int & counter,int & n,int & k){
        if(temp.size()==n){
            counter++;
            if(counter==k){
                res = temp;
            }
            return;
        }
        for(char ch = 'a'; ch<='c'; ch++){
            if( temp.size()>= 1 && temp.back() == ch)
                continue;
            temp.push_back(ch);
            solve(res,temp,counter,n,k);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
         string res = "";
         string temp = "";
         int counter = 0;
         solve(res,temp,counter,n,k);
         return res;

    }
};