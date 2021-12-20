class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        auto it = spaces.cbegin();
        for (int i = 0; i < (int)s.length(); ++i) {
            if (it != spaces.cend() && *it == i) {
                ret.push_back(' ');
                ++it;
            }
            ret.push_back(s[i]);
        }
        return ret;
    }
};
