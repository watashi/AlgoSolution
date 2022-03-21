class Solution {
public:
    int countHillValley(vector<int>& a) {
        int ret = 0;
        for (int i = 1; i < (int)a.size() - 1; ++i) {
            if (a[i] == a[i - 1]) {
                continue;
            }
            int j = i + 1;
            while (j < (int)a.size() && a[j] == a[i]) {
                ++j;
            }
            if (j < (int)a.size() && (a[i - 1] < a[i]) == (a[j] < a[i])) {
                ++ret;
            }
        }
        return ret;
    }
};
