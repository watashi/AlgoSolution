class Solution {
public:
    static bool isPalindromic(const string& s) {
        for (int i = 0, j = (int)s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (const auto& i: words) {
            if (isPalindromic(i)) {
                return i;
            }
        }
        return "";
    }
};
