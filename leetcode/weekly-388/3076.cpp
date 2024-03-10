class Solution {
public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    map<string_view, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= arr[i].size(); ++j) {
        for (int k = 0; k < j; ++k) {
          string_view sv(&arr[i][k], j - k);
          auto it = mp.find(sv);
          if (it == mp.end()) {
            mp[sv] = i;
          }
          else if (it->second != i) {
            it->second = -1;
          }
        }
      }
    }
    vector<string> ret(n);
    for (const auto& i : mp) {
      if (i.second != -1) {
        auto& r = ret[i.second];
        if (r.empty() || (r.length() > i.first.length()) || (r.length() == i.first.length() && r > i.first)) {
          r = i.first;
        }
      }
    }
    return ret;
  }
};
