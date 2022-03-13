class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<pair<int, int>, int> mp;
        vector<int> d(artifacts.size());
        for (int i = 0; i < (int)d.size(); ++i) {
            int r1 = artifacts[i][0];
            int c1 = artifacts[i][1];
            int r2 = artifacts[i][2];
            int c2 = artifacts[i][3];
            for (int x = r1; x <= r2; ++x) {
                for (int y = c1; y <= c2; ++y) {
                    mp[make_pair(x, y)] = i;
                    ++d[i];
                }
            }
        }
        for (const auto& i: dig) {
            int x = i[0];
            int y = i[1];
            auto it = mp.find(make_pair(x, y));
            if (it != mp.end()) {
                --d[it->second];
            }
        }
        return count(d.begin(), d.end(), 0);
    }
};
