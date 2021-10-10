class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (const auto& i: grid) {
            v.insert(v.end(), i.begin(), i.end());
        }
        sort(v.begin(), v.end());

        int m = v[0];
        for (int& i: v) {
            i -= m;
            if (i % x != 0) {
                return -1;
            }
            i /= x;
        }

        int t = v[v.size() / 2];
        int ans = 0;
        for (int i: v) {
            ans += abs(t - i);
        }
        return ans;
    }
};
