class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for (const auto& i: bank) {
            int c = (int)count(i.begin(), i.end(), '1');
            if (c > 0) {
                v.push_back(c);
            }
        }
        int ans = 0;
        for (int i = 1; i < (int)v.size(); ++i) {
            ans += v[i - 1] * v[i];
        }
        return ans;
    }
};
