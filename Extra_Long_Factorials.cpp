#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    vector<int> v;
    v.push_back(1);
    for(int i = 1; i<=n; i++){
        int carry = 0;
        for(int j = 0; j<v.size();j++){
            int val = v[j]*i+carry;
            v[j] = val%10;
            carry = val/10;
        }
        while(carry){
            v.push_back(carry%10);
            carry /= 10;
        }
    }
    for(int j = v.size()-1; j>=0;j--){
        cout<<v[j];
    }
    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
