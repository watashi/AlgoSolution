class Solution {
  struct SegTree {
    int m;
    vector<int> x;

    static inline int L(int i) { return i << 1; }
    static inline int R(int i) { return L(i) ^ 1; }

    void init(int n) {
      m = 1;
      while (m < n) {
        m <<= 1;
      }
      x = vector<int>(m + m, 0);
    }

    void set(int i, int v) {
      i += m;
      x[i] = v;
      while (i > 1) {
        i >>= 1;
        x[i] = max(x[L(i)], x[R(i)]);
      }
    }

    int find(int v) {
      int p = 1;
      if (x[p] < v) {
        return -1;
      }
      while (p < m) {
        if (x[L(p)] >= v) {
          p = L(p);
        }
        else {
          p = R(p);
        }
      }
      return p - m;
    }
  };

public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    SegTree st;
    st.init(baskets.size());
    for (int i = 0; i < (int)baskets.size(); ++i) {
      st.set(i, baskets[i]);
    }

    int ret = 0;
    for (int i : fruits) {
      int j = st.find(i);
      if (j < 0) {
        ++ret;
      }
      else {
        st.set(j, 0);
      }
    }
    return ret;
  }
};
