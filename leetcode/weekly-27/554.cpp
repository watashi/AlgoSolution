class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> m;
        for (auto& i: wall) {
            int s = 0;
            for (int j: i) {
                s += j;
                ++m[s];
            }
        }
        m.erase(m.rbegin()->first);
        int ans = 0;
        for (auto i: m) {
            ans = max(ans, i.second);
        }
        return (int)wall.size() - ans;
    }
};
