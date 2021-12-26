class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ret;
        for (size_t i = 0; i < s.length(); ++i) {
            int x = startPos[0], y = startPos[1];
            int j = i;
            do {
                switch (s[j]) {
                    case 'L': --y; break;
                    case 'R': ++y; break;
                    case 'U': --x; break;
                    case 'D': ++x; break;
                }
                if (0 <= x && x < n && 0 <= y && y < n) {
                    ++j;
                } else {
                    break;
                }
            } while (j < s.length());
            ret.push_back(j - i);
        }
        return ret;
    }
};
