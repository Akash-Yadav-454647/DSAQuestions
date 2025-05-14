class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = getRotation(tops, bottoms, tops[0]);
        if (tops[0] != bottoms[0]) {
            res = min(res, getRotation(tops, bottoms, bottoms[0]));
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    int getRotation(vector<int>& tops, vector<int>& bottoms, int target) {
        int rotateTop = 0;
        int rotateBottom = 0;

        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != target && bottoms[i] != target) {
                return INT_MAX;
            }
            if (tops[i] != target) rotateTop++;
            if (bottoms[i] != target) rotateBottom++;
        }
        return min(rotateTop, rotateBottom);
    }
};