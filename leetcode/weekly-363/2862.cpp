class Solution {
  struct PrimeTable {
    vector<int> p;
    vector<int> pl;

    PrimeTable(int n) {
      init(n);
    }

    void init(int n) {
      p = vector<int>(n, 0);
      iota(p.begin(), p.end(), 0);
      for (int i = 2; i * i < n; ++i) {
        if (p[i] == i) {
          pl.push_back(i);
          for (int j = i * i; j < n; j += i) {
            if (p[j] == j) {
              p[j] = i;
            }
          }
        }
      }
    }
  };

public:
  long long maximumSum(vector<int>& nums) {
    const PrimeTable& pt(33000);
    vector<int> pp;
    for (int i : pt.pl) {
      pp.push_back(i * i);
    }
    unordered_map<int, long long> s;
    for (int i = 0; i < (int)nums.size(); ++i) {
      int k = i + 1;
      for (int j : pp) {
        if (j > k) {
          break;
        }
        while (k % j == 0) {
          k /= j;
        }
      }
      s[k] += nums[i];
    }
    long long ret = 0;
    for (const auto& i : s) {
      ret = max(ret, i.second);
    }
    return ret;
  }
};
