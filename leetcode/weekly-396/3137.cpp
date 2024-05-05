class Solution {
public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    int n = (int)word.size();
    map<string, int> mp;
    for (int i = 0; i < n; i += k) {
      ++mp[word.substr(i, k)];
    }
    int ret = 0;
    for (const auto& i : mp) {
      ret = max(ret, i.second);
    }
    return n / k - ret;
  }
};
