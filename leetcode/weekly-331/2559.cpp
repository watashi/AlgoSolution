class Solution {
public:
  bool isVowel(char c) {
    static const string s = "aeiou";
    return s.find(c) != string::npos;
  }

  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    const string v = "aeiou";
    vector<int> c(words.size() + 1, 0);
    for (int i = 0; i < (int)words.size(); ++i) {
      if (isVowel(words[i].front()) && isVowel(words[i].back())) {
        c[i + 1] = 1;
      }
    }
    partial_sum(c.begin(), c.end(), c.begin());
    vector<int> ret;
    for (const auto& q : queries) {
      ret.push_back(c[q[1] + 1] - c[q[0]]);
    }
    return ret;
  }
};
