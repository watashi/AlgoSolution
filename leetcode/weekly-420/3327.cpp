class Solution {
  struct Manacher {
    vector<int> p;

    template<typename T>
    void init(int n, const T s[]) {
      p.resize(max(0, 2 * n - 1));
      for (int i = 0, j = 0, k = 0; i <= 2 * (n - 1); ++i) {
        int d = i < k ? min(p[j + j - i], (k - i) / 2) : 0;
        int a = i / 2 - d, b = (i + 1) / 2 + d;
        while (0 <= a && b < n && s[a] == s[b]) {
          --a;
          ++b;
          ++d;
        }
        p[i] = d;
        if (k < 2 * b - 1) {
          j = i;
          k = 2 * b - 1;
        }
      }
    }

    // [l, r)
    bool isPalindrome(int l, int r) {
      int m = l + r - 1;
      return m / 2 - p[m] < l;
    }
  };

  vector<vector<int>> e;
  vector<pair<int, int>> ranges;
  string orig, str;

  void dfs(int v) {
    ranges[v].first = str.length();
    for (int w : e[v]) {
      dfs(w);
    }
    str += orig[v];
    ranges[v].second = str.length();
  }

public:
  vector<bool> findAnswer(vector<int>& parent, string s) {
    const int n = parent.size();
    e = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
      e[parent[i]].push_back(i);
    }
    ranges = vector<pair<int, int>>(n);
    orig = s;
    str = "";
    dfs(0);
    
    Manacher m;
    m.init(n, str.data());
    vector<bool> ret;
    ret.reserve(n);
    for (const auto& i : ranges) {
      ret.push_back(m.isPalindrome(i.first, i.second));
    }
    return ret;
  }
};
