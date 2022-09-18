class Solution {
public:
  static constexpr int CHARSET = 26;
  struct Trie {
    vector<unique_ptr<Trie>> children{ CHARSET };
    int count = 0;

    Trie* next(char ch) {
      auto& child = children[ch - 'a'];
      if (!child) {
        child = make_unique<Trie>();
      }
      return child.get();
    }
  };

  vector<int> sumPrefixScores(vector<string>& words) {
    Trie root;
    for (const auto& s : words) {
      Trie* p = &root;
      for (const char c : s) {
        p = p->next(c);
        ++p->count;
      }
    }
    vector<int> ret;
    for (const auto& s : words) {
      Trie* p = &root;
      int sum = 0;
      for (const char c : s) {
        p = p->next(c);
        sum += p->count;
      }
      ret.push_back(sum);
    }
    return ret;
  }
};
