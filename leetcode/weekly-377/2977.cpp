class Solution {
public:
  static constexpr int CHARSET = 26;
  static constexpr int64_t INF = 1000000007LL << 10;

  struct Trie {
    int value = -1;
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

    Trie& insert(const string& s) {
      auto ret = this;
      for (char ch : s) {
        ret = &ret->insert(ch);
      }
      return *ret;
    }
  };

  pair<vector<int64_t>, vector<int>> minDist(int n, const vector<vector<pair<int, int64_t>>>& e, int s) {
    vector<int64_t> d(n, INF);
    vector<int> pre(n, -1);
    priority_queue<pair<int64_t, int>> pq;
    d[s] = 0;
    pq.emplace(-d[s], s);
    while (!pq.empty()) {
      int a = pq.top().second;
      int da = -pq.top().first;
      pq.pop();
      if (da > d[a]) {
        continue;
      }
      for (auto i : e[a]) {
        int b = i.first;
        int db = da + i.second;
        if (db < d[b]) {
          d[b] = db;
          pre[b] = a;
          pq.emplace(-d[b], b);
        }
      }
    }
    return make_pair(d, pre);
  }

  long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    Trie trie;
    vector<vector<pair<int, int64_t>>> e;
    for (int i = 0; i < (int)cost.size(); ++i) {
      auto& from = trie.insert(original[i]);
      if (from.value < 0) {
        from.value = e.size();
        e.push_back({});
      }
      auto& to = trie.insert(changed[i]);
      if (to.value < 0) {
        to.value = e.size();
        e.push_back({});
      }
      e[from.value].emplace_back(to.value, cost[i]);
    }

    const int n = e.size();
    vector<vector<int64_t>> d(n);
    for (int i = 0; i < n; ++i) {
      d[i] = minDist(n, e, i).first;
    }

    vector<int64_t> dp(source.size() + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < (int)source.size(); ++i) {
      if (source[i] == target[i]) {
        dp[i + 1] = min(dp[i + 1], dp[i]);
      }
      const Trie* from = &trie;
      const Trie* to = &trie;
      for (int j = i; j < (int)source.size(); ++j) {
        from = from->find(source[j]);
        to = to->find(target[j]);
        if (from == nullptr || to == nullptr) {
          break;
        }
        if (from->value >= 0 && to->value >= 0) {
          dp[j + 1] = min(dp[j + 1], dp[i] + d[from->value][to->value]);
        }
      }
    }
    if (dp.back() < INF) {
      return dp.back();
    }
    else {
      return -1;
    }
  }
};
