class Solution {
public:
    long long countVowels(string word) {
        long long s = 0, n = (long long)word.size();
        for (long long i = 0; i < n; ++i) {
            if ("aeiou"s.find(word[i]) != string::npos) {
                s += (i + 1) * (n - i);
            }
        }
        return s;
    }
};
