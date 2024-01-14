class Solution {
public:
  template<typename T = char>
  struct Z {
    vector<T> pat;
    vector<int> z;

    void init(int n, const T s[]) {
      vector<T>(s, s + n).swap(pat);
      z.resize(n);
      if (n > 0) {
        z[0] = n;
      }
      if (n > 1) {
        z[1] = 0;
        for (int& w = z[1]; w + 1 < n && pat[w + 1] == pat[w]; ++w) {
        }
      }
      for (int i = 2, k = 1; i < n; ++i) {
        int x = k + z[k] - i, y = z[i - k];
        if (y < x) {
          z[i] = y;
        }
        else {
          z[i] = max(0, x);
          for (int& w = z[i]; w + i < n && pat[w + i] == pat[w]; ++w) {
          }
          k = i;
        }
      }
    }

    vector<int> gao(int m, const T t[]) {
      int n = (int)pat.size();
      vector<int> ret(m);
      if (m > 0) {
        for (int& w = ret[0]; w < n && w < m && t[w] == pat[w]; ++w) {
        }
      }
      for (int i = 1, k = 0; i < m; ++i) {
        int x = k + ret[k] - i, y = i - k < n ? z[i - k] : 0;
        if (y < x) {
          ret[i] = y;
        }
        else {
          ret[i] = max(0, x);
          for (int& w = ret[i]; w < n && w + i < m && t[w + i] == pat[w]; ++w) {
          }
          k = i;
        }
      }
      return ret;
    }
  };

  vector<int> gao(const string& pat, const string& s) {
    int n = pat.size();
    Z z;
    z.init(pat.size(), pat.data());
    auto m = z.gao(s.size(), s.data());
    vector<int> v;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (m[i] == n) {
        v.push_back(i);
      }
    }
    return v;
  }

  vector<int> beautifulIndices(string s, string a, string b, int k) {
    auto oka = gao(a, s);
    auto okb = gao(b, s);
    reverse(okb.begin(), okb.end());
    vector<int> ret;
    for (auto i: oka) {
      while (!okb.empty() && okb.back() < i - k) {
        okb.pop_back();
      }
      if (!okb.empty() && okb.back() <= i + k) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
