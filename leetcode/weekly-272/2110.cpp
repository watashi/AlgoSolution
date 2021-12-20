class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        for (int i = 0; i < (int)prices.size(); ) {
            int c = 1;
            while (i + c < (int)prices.size() && prices[i + c] == prices[i] - c) {
                ++c;
            }
            ans += c * (c + 1LL) / 2;
            i += c;
        }
        return ans;
    }
};
