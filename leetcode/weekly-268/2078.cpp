class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ret = -1;
        int n = (int)colors.size();
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[0]) {
                ret = max(ret, i);
            }
            if (colors[i] != colors[n - 1]) {
                ret = max(ret, n - 1 - i);
            }
        }
        return ret;
    }
};
