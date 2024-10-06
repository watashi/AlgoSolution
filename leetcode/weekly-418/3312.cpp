class Solution {
public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    constexpr int MAXN = 50005;
    vector<long long> v(MAXN, 0);
    for (int i : nums) {
      for (int j = 1; j * j <= i; ++j) {
        if (i % j == 0) {
          ++v[j];
          int k = i / j;
          if (k != j) {
            ++v[k];
          }
        }
      }
    }
    for (long long& i : v) {
      i = i * (i - 1) / 2;
    }
    for (int i = v.size() - 1; i > 1; --i) {
      if (v[i] == 0) {
        continue;
      }
      // printf("[%d] %lld\n", i, v[i]);
      v[1] -= v[i];
      for (int j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
          v[j] -= v[i];
          int k = i / j;
          if (k != j) {
            v[k] -= v[i];
          }
        }
      }
    }
    partial_sum(v.begin(), v.end(), v.begin());

    vector<int> ret;
    for (auto q : queries) {
      int lo = 0, hi = v.size();
      while (lo < hi) {
        int mi = (lo + hi) / 2;
        // printf("%d %d %d %lld ? %lld\n", lo, hi, mi, v[mi], q);
        if (v[mi] <= q) {
          lo = mi + 1;
        }
        else {
          hi = mi;
        }
      }
      ret.push_back(hi);
    }
    return ret;
  }
};
