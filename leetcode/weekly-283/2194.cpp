class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> v;
        for (char x = s[0]; x <= s[3]; ++x) {
            for (char y = s[1]; y <= s[4]; ++y) {
                string t;
                t.push_back(x);
                t.push_back(y);
                v.push_back(std::move(t));
            }
        }
        return v;
    }
};
