class Solution {
public:
    int countVowelSubstrings(string word) {
        int ret = 0;
        const string aeiou = "aeiou";
        for (int i = 0; i < (int)word.size(); ++i) {
            vector<int> c(5);
            int d = 5;
            for (int j = i; j < (int)word.size(); ++j) {
                auto pos = aeiou.find(word[j]);
                if (pos == string::npos) {
                    break;
                }
                if (c[pos]++ == 0) {
                    --d;
                }
                if (d == 0) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};
