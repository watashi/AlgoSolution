class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
        int n = (int)a.size();
        vector<unordered_set<int>> byr(n), byc(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                byr[i].insert(a[i][j]);
                byc[j].insert(a[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (byr[i].size() != n || byc[i].size() != n) {
                return false;
            }
        }
        return true;
    }
};
