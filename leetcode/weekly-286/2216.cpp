class Solution {
public:
    int minDeletion(vector<int>& a) {
        int n = (int)a.size();
        int c = 0;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && a[j] == a[i]) {
                ++j;
            }
            if (j < n) {
                ++c;
                ++j;
            }
            i = j;
        }
        return n - 2 * c;
    }
};
