class Solution {
public:
    static int string2mask(const string& s) {
        int m = 0;
        for (char c: s) {
            m |= 1 << (c - 'a');
        }
        return m;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        vector<int> s, t;
        unordered_set<int> st;
        for (const auto& i: startWords) {
            st.emplace(string2mask(i));
        }
        int ans = 0;
        for (const auto& i: targetWords) {
            auto m = string2mask(i);
            for (int j = 0; j < 26; ++j) {
                if ((m & (1 << j)) != 0 && st.count(m ^ (1 << j)) > 0) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
