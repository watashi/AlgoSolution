class Solution {
public:
  static inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int minOperations(vector<int>& a) {
    if (find(a.begin(), a.end(), 1) != a.end()) {
      return (int)count_if(a.begin(), a.end(), [](const auto& i) { return i != 1; });
    }

    int n = a.size();
    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
      int g = a[i];
      for (int j = i; j < n; ++j) {
        g = gcd(g, a[j]);
        if (g == 1) {
          ans = min(ans, j - i);
          break;
        }
      }
    }
    if (ans < n) {
      return ans + n - 1;
    }
    else {
      return -1;
    }
  }
};
