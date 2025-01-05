class Solution {
public:
  long long maximumCoins(vector<vector<int>>& coins, int k) {
    map<int, long long> d;
    for (const auto& i : coins) {
      int l = i[0], r = i[1], c = i[2];
      d[l - k] += c;
      d[l] -= c;
      d[r - k + 1] -= c;
      d[r + 1] += c;
    }
    long long ret = 0, x = d.begin()->first - k - 100, dy = 0, y = 0;
    for (const auto& i : d) {
      int dx = i.first - x;
      y += dy * dx;
      ret = max(ret, y);
      dy += i.second;
      x = i.first;
    }
    return ret;
  }
};
