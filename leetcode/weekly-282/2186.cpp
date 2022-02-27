class Solution {
public:    
    int minSteps(string s, string t) {
        vector<int> x(26), y(26);
        for (char i: s) {
            ++x[i - 'a'];
        }
        for (char i: t) {
            ++y[i - 'a'];
        }
        int z = 0;
        for (int i = 0; i < 26; ++i) {
            z += max(x[i], y[i]);
        }
        return z * 2 - s.size() - t.size();
    }
};
