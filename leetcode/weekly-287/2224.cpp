class Solution {
public:
    static int c2i(char c) {
        return c - '0';
    }
    
    static int t2i(const string& s) {
        return (c2i(s[0]) * 10 + c2i(s[1])) * 60 + c2i(s[3]) * 10 + c2i(s[4]);
    }
    
    int convertTime(string current, string correct) {
        int diff = t2i(correct) - t2i(current);
        if (diff < 0) {
            diff += 24 * 60;
        }
        int ret = 0;
        const int GAP[] = {60, 15, 5, 1};
        for (int i: GAP) {
            ret += diff / i;
            diff %= i;
        }
        return ret;
    }
};
