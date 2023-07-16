static constexpr int CHARSET = 26;

struct Trie {
  bool mark = false;
  std::unique_ptr<Trie> children[CHARSET];

  const Trie* operator[](char ch) const {
    return children[ch - 'a'].get();
  }

  Trie* operator()(char ch) {
    auto& p = children[ch - 'a'];
    if (!p) {
      p = std::make_unique<Trie>();
    }
    return p.get();
  }
};

class Solution {
public:
  int longestValidSubstring(string word, vector<string>& forbidden) {
    Trie trie;
    for (const string& s : forbidden) {
      auto p = &trie;
      for (char c : s) {
        p = (*p)(c);
      }
      p->mark = true;
    }
    int ret = 0, pre = -1;
    int n = word.size();
    vector<int> ok(n, -1);
    for (int i = 0; i < n; ++i) {
      const Trie* p = &trie;
      for (int j = i; j < n; ++j) {
        p = (*p)[word[j]];
        if (p == nullptr) {
          break;
        }
        else if (p->mark) {
          ok[j] = max(ok[j], i);
        }
      }
      pre = max(pre, ok[i]);
      ret = max(ret, i - pre);
    }
    return ret;
  }
};
