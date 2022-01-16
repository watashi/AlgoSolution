class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for (int i = 0; i < (int)s.length(); i += k) {
            v.push_back(s.substr(i, k));
        }
        while ((int)v.back().length() < k) {
            v.back().push_back(fill);
        }
        return v;
    }
};
