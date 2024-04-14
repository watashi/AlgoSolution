class Solution {
public:
  static long long count(vector<pair<long long, int>>& v, long long n) {
    long long ret = 0;
    for (const auto& i : v) {
      ret += n / i.first * i.second;
    }
    return ret;
  }

  static long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  long long findKthSmallest(vector<int>& coins, int k) {
    int n = coins.size();
    vector<pair<long long, int>> v;
    for (int i : coins) {
      auto w = v;
      v.emplace_back(i, 1);
      for (const auto& j : w) {
        v.emplace_back(j.first * i / gcd(j.first, i), -j.second);
      }
    }
    long long lo = 0, hi = *min_element(coins.begin(), coins.end()) * 1LL * k;
    while (lo < hi) {
      auto mi = (lo + hi) / 2;
      if (count(v, mi) < k) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi;
  }
};
