class Solution {
public:
  map<char, int> counts(string s) {
    map<char, int> m;
    for (char c : s) {
      ++m[c];
    }
    return m;
  }

  bool isItPossible(string word1, string word2) {
    const auto m1 = counts(word1);
    const auto m2 = counts(word2);
    for (const auto& i : m1) {
      for (const auto& j : m2) {
        int c1 = m1.size(), c2 = m2.size();
        if (i.first != j.first) {
          if (i.second == 1) {
            --c1;
          }
          if (j.second == 1) {
            --c2;
          }
          if (m1.count(j.first) == 0) {
            ++c1;
          }
          if (m2.count(i.first) == 0) {
            ++c2;
          }
        }
        if (c1 == c2) {
          return true;
        }
      }
    }
    return false;
  }
};
