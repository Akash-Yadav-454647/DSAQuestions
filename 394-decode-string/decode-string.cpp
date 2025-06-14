class Solution {
public:
    bool isDigit(string ch) {
        if(ch == "0" || ch == "1" || ch == "2" || ch == "3" || ch == "4" || ch == "5"
          || ch == "6" || ch == "7" || ch == "8" || ch == "9")
            return true;
        return false;
    }
    string decodeString(string s) {
        stack<string> st;
        
        for(char ch:s) {
            if(ch != ']') {
                st.push(string(1, ch));
                continue;
            }
            
            string temp = "";
            while(!st.empty() && st.top() != "[") {
                temp = st.top() + temp;
                st.pop();
            }
            
            if(!st.empty()) {
                st.pop();
            }
            
            string num = "";
            while(!st.empty() && isDigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            
            string add = "";
            int times = stoi(num);
            while(times--) {
                add += temp;
            }
            
            st.push(add);
        }
        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};