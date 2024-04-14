class Solution {
  struct PrimeTable {
    vector<int> p;

    PrimeTable(int n) {
      init(n);
    }

    void init(int n) {
      p = vector<int>(n, 0);
      iota(p.begin(), p.end(), 0);
      for (int i = 2; i * i < n; ++i) {
        if (p[i] == i) {
          for (int j = i * i; j < n; j += i) {
            if (p[j] == j) {
              p[j] = i;
            }
          }
        }
      }
    }

    bool isPrime(int i) const {
      return i >= 2 && p[i] == i;
    }
  };

public:
  int maximumPrimeDifference(vector<int>& nums) {
    const PrimeTable pt(1000);
    int n = (int)nums.size(), i = 0, j = n - 1;
    while (i <= j && !pt.isPrime(nums[i])) {
      ++i;
    }
    while (i <= j && !pt.isPrime(nums[j])) {
      --j;
    }
    return j - i;
  }
};
