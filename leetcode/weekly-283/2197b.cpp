class Solution {
public:    
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int i: nums) {
            while (!ans.empty()) {
                int g = gcd(ans.back(), i);
                if (g > 1) {
                    i /= g;
                    i *= ans.back();
                    ans.pop_back();
                } else {
                    break;
                }
            }
            ans.push_back(i);
        }
        return ans;
    }
};
