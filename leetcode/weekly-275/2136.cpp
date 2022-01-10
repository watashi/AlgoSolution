class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n = (int)pt.size();
        vector<pair<int, int>> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.emplace_back(gt[i], pt[i]);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (const auto& i: v) {
            ans = max(ans, i.first) + i.second;
        }
        return ans;
    }
};
