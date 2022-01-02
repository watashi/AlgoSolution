class Solution {
public:
    bool checkString(string s) {
        string t = s;
        sort(t.begin(), t.end());
        return s == t;
    }
};
