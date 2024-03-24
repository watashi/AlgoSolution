
class Solution {
public:
  static constexpr int CHARSET = 26;
  static constexpr int INF = 1000000007;

  struct Trie {
    pair<int, int> value{INF, -1};
    vector<unique_ptr<Trie>> children = vector<unique_ptr<Trie>>(CHARSET);

    const Trie* find(char ch) const {
      return children[ch - 'a'].get();
    }

    Trie& insert(char ch) {
      auto& ret = children[ch - 'a'];
      if (!ret) {
        ret = make_unique<Trie>();
      }
      return *ret;
    }
  };


  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    Trie trie;
    for (int i = 0; i < (int)wordsContainer.size(); ++i) {
      const auto& s = wordsContainer[i];
      Trie* p = &trie;
      p->value = min(p->value, pair<int, int>(s.length(), i));
      for (auto it = s.rbegin(); it != s.rend(); ++it) {
        p = &p->insert(*it);
        p->value = min(p->value, pair<int, int>(s.length(), i));
      }
    }
    vector<int> ret;
    ret.reserve(wordsQuery.size());
    for (const auto& s : wordsQuery) {
      const Trie* p = &trie;
      for (auto it = s.rbegin(); it != s.rend(); ++it) {
        const Trie* q = p->find(*it);
        if (q == nullptr) {
          break;
        }
        else {
          p = q;
        }
      }
      ret.push_back(p->value.second);
    }
    return ret;
  }
};
