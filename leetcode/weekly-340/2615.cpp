class Solution {
public:
  vector<long long> distance(vector<int>& a) {
    int n = a.size();
    unordered_map<int, vector<long long>> mp;
    for (int i = 0; i < n; ++i) {
      mp[a[i]].push_back(i);
    }
    vector<long long> ret(n);
    for (const auto& i : mp) {
      int m = i.second.size();
      vector<long long> s = i.second;
      partial_sum(s.begin(), s.end(), s.begin());
      for (int j = 0; j < m; ++j) {
        long long k = i.second[j];
        ret[k] = (k * (j + 1) - s[j]) + (s[m - 1] - s[j] - k * (m - 1 - j));
      }
    }
    return ret;
  }
};
