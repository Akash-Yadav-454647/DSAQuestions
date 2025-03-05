class Solution {
public:
    long long coloredCells(long long n) {
        return (long long)1+4*(n)*(n-1)/2;
    }
};