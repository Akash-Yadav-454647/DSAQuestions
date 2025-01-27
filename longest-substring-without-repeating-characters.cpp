#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    vector<int> chars(256, 0);
    int n = s.size();
    int first = 0;
    int second = 0;
    int len = 0;
    while (second < n)
    {
      while (chars[s[second]])
      {
        chars[s[first]]--;
        first++;
      }
      chars[s[second]]++;
      second++;
      len = max(len, (second - first));
    }
    return len;
  }
};