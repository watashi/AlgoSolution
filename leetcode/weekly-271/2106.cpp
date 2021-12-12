class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<pair<int, int>> v;
        int s = 0;
        v.reserve(fruits.size());
        for (const auto& i: fruits) {
            v.emplace_back(i[0], s);
            s += i[1];
        }
        // (-inf, pos)
        auto query = [&v, s](int pos) {
            auto it = lower_bound(v.begin(), v.end(), make_pair(pos, 0));
            return it == v.end() ? s : it->second;
        };
        int ret = max(query(startPos + 1) - query(startPos - k), query(startPos + k + 1) - query(startPos));
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i].first < startPos - k || v[i].first > startPos + k) {
                continue;
            }
            if (v[i].first <= startPos) {
                int right = startPos + k - 2 * (startPos - v[i].first);
                ret = max(ret, query(right + 1) - v[i].second);
            } else {
                int left = startPos - k + 2 * (v[i].first - startPos);
                ret = max(ret, (i + 1 < (int)v.size() ? v[i + 1].second : s) - query(left));
            }
        }
        return ret;
    }
};
