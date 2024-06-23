class Solution {
  template<typename T = int>
  struct BIT {
    vector<T> a;

    void init(int n) {
      vector<T>(n + 1).swap(a);
    }

    void add(int i, T v) {
      for (int j = i + 1; j < (int)a.size(); j = (j | (j - 1)) + 1) {
        a[j] += v;
      }
    }

    // [0, i)
    T sum(int i) const {
      T ret = T();
      for (int j = i; j > 0; j = j & (j - 1)) {
        ret += a[j];
      }
      return ret;
    }

    T get(int i) const {
      return sum(i + 1) - sum(i);
    }

    void set(int i, T v) {
      add(i, v - get(i));
    }
  };

public:
  bool isPeak(const vector<int>& a, int i) {
    return 0 <= i - 1 && i + 1 < (int)a.size() && a[i - 1] < a[i] && a[i] > a[i + 1];
  }

  vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
    auto a = nums;
    const int n = a.size();
    BIT<int> bit;
    bit.init(n);
    for (int i = 0; i < n; ++i) {
      if (isPeak(a, i)) {
        bit.add(i, 1);
      }
    }
    vector<int> ret;
    for (const auto& q : queries) {
      if (q[0] == 1) {
        const int l = q[1] + 1, r = q[2];
        if (l >= r) {
          ret.push_back(0);
        }
        else {
          ret.push_back(bit.sum(r) - bit.sum(l));
        }
      }
      else {
        const int i = q[1], v = q[2];
        for (int j = i - 1; j <= i + 1; ++j) {
          if (isPeak(a, j)) {
            bit.add(j, -1);
          }
        }
        a[i] = v;
        for (int j = i - 1; j <= i + 1; ++j) {
          if (isPeak(a, j)) {
            bit.add(j, 1);
          }
        }
      }
    }
    return ret;
  }
};
