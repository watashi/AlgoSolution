class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> c;
        for (const auto& i: matches) {
            c[i[0]];
            ++c[i[1]];
        }
        vector<vector<int>> ret(2);
        for (const auto& i: c) {
            if (i.second < 2) {
                ret[i.second].push_back(i.first);
            }
        }
        return ret;
    }
};
