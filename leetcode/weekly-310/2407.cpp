class Solution {
public:
  int m;
  vector<int> v;

  static int L(int p) {
    return p << 1;
  }

  static int R(int p) {
    return L(p) ^ 1;
  }

  void update(int i, int x) {
    for (int p = m + i; p > 0; p >>= 1) {
      v[p] = max(v[p], x);
    }
  }

  int query(int p, int pl, int pr, int l, int r) {
    if (l == pl && r == pr) {
      return v[p];
    }
    int pm = (pl + pr) / 2;
    if (r <= pm) {
      return query(L(p), pl, pm, l, r);
    }
    else if (pm <= l) {
      return query(R(p), pm, pr, l, r);
    }
    else {
      return max(query(L(p), pl, pm, l, pm), query(R(p), pm, pr, pm, r));
    }
  }

  int lengthOfLIS(vector<int>& nums, int k) {
    m = 1 << 17;
    v = vector<int>(m + m, 0);
    for (int i : nums) {
      int j = max(0, i - k);
      int x = query(1, 0, m, j, i);
      update(i, x + 1);
    }
    return *max_element(v.begin(), v.end());
  }
};
