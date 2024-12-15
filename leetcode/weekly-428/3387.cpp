class Solution {
public:
  vector<vector<double>> getBest(const vector<string>& currencies, vector<vector<string>>& pairs, vector<double>& rates) {
    const int n = currencies.size();
    vector<vector<double>> d(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
      d[i][i] = 1;
    }
    for (int i = 0; i < (int)pairs.size(); ++i) {
      int a = lower_bound(currencies.begin(), currencies.end(), pairs[i][0]) - currencies.begin();
      int b = lower_bound(currencies.begin(), currencies.end(), pairs[i][1]) - currencies.begin();
      double c = rates[i];
      d[a][b] = max(d[a][b], c);
      d[b][a] = max(d[b][a], 1 / c);
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
        }
      }
    }
    return d;
  }

  double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
    vector<string> currencies;
    currencies.push_back(initialCurrency);
    for (const auto& p : pairs1) {
      currencies.push_back(p[0]);
      currencies.push_back(p[1]);
    }
    for (const auto& p : pairs2) {
      currencies.push_back(p[0]);
      currencies.push_back(p[1]);
    }
    sort(currencies.begin(), currencies.end());
    currencies.erase(unique(currencies.begin(), currencies.end()), currencies.end());

    auto d1 = getBest(currencies, pairs1, rates1);
    auto d2 = getBest(currencies, pairs2, rates2);
    double ret = 1;
    int init = lower_bound(currencies.begin(), currencies.end(), initialCurrency) - currencies.begin();
    const int n = currencies.size();
    for (int i = 0; i < n; ++i) {
      ret = max(ret, d1[init][i] * d2[i][init]);
    }
    return ret;
  }
};
