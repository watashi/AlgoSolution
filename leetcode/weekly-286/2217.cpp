class Solution {
public:    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int d = (intLength + 1) / 2;
        int r = intLength / 2;
        long long d10 = 1, r10 = 1;
        for (int i = 1; i < d; ++i) {
            d10 *= 10;
        }
        for (int i = 0; i < r; ++i) {
            r10 *= 10;
        }
        vector<long long> ans;
        for (long long i: queries) {
            if (i > 9 * d10) {
                ans.push_back(-1);
            } else {
                long long x = d10 + i - 1;
                long long y = x;
                long long z = 0;
                for (int i = 0; i < d; ++i) {
                    z = z * 10 + y % 10;
                    y /= 10;
                }
                ans.push_back(x * r10 + z % r10);
            }
        }
        return ans;
    }
};
