class Solution {
public:
    string rev(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        vector<string> s = strs;
        string ret = "A";
        for (int i = 0; i < n; ++i) {
            string mid = "";
            for (int j = 1; j < n; ++j) {
                mid += max(s[j], rev(s[j]));
            }
            for (int j = 0; j < (int)s[0].size(); ++j) {
                string prefix = s[0].substr(0, j), suffix = s[0].substr(j);
                string tmp = max(suffix + mid + prefix, rev(prefix) + mid + rev(suffix));
                ret = max(ret, tmp);
            }
            rotate(s.begin(), s.begin() + 1, s.end());
        }
        return ret;
    }
};
