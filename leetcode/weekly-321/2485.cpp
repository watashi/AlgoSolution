class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; ++i) {
            if (i * (i + 1) == (n - i + 1) * (i + n)) {
                return i;
            }
        }
        return -1;
    }
};
