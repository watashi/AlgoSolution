class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> m;
        for (char c: s) {
            ++m[c];
        }
        vector<pair<char, int>> v(m.begin(), m.end());
        string ret;
        while (!v.empty()) {
            auto x = v.back();
            v.pop_back();
            int y = min(repeatLimit, x.second);
            x.second -= y;
            for (int i = 0; i < y; ++i) {
                ret.push_back(x.first);
            }
            if (x.second > 0) {
                if (v.empty()) {
                    break;
                } else {
                    ret.push_back(v.back().first);
                    v.back().second -= 1;
                    if (v.back().second == 0) {
                        v.pop_back();
                    }
                }
                v.push_back(x);
            }
        }
        return ret;
    }
};
