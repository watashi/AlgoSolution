class Solution {
  template<typename T>
  struct RMQ {
    int n;
    vector<T> e;
    vector<vector<int> > rmq;

    static const int INT_BIT = sizeof(4) * CHAR_BIT;
    static inline int LG2(int i) { return INT_BIT - 1 - __builtin_clz(i); }
    static inline int BIN(int i) { return 1 << i; }

    int cmp(int l, int r) const {
      return e[l] <= e[r] ? l : r;
    }

    void init(int n, const T e[]) {
      this->n = n;
      vector<T>(e, e + n).swap(this->e);

      int m = 1;
      while (BIN(m) <= n) {
        ++m;
      }
      vector<vector<int> >(m, vector<int>(n)).swap(rmq);

      for (int i = 0; i < n; ++i) {
        rmq[0][i] = i;
      }
      for (int i = 0; BIN(i + 1) <= n; ++i) {
        for (int j = 0; j + BIN(i + 1) <= n; ++j) {
          rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);
        }
      }
    }

    int index(int l, int r) const {
      int b = LG2(r - l);
      return cmp(rmq[b][l], rmq[b][r - (1 << b)]);
    }

    T value(int l, int r) const {
      return e[index(l, r)];
    }
  };

public:
  long long minimumOperations(vector<int>& nums, vector<int>& target) {
    const int N = nums.size();
    vector<int> d;
    for (int i = 0; i < N; ++i) {
      d.push_back(target[i] - nums[i]);
    }

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < N; ) {
      if (d[i] == 0) {
        ++i;
        continue;
      }
      int start = i;
      if (d[i] > 0) {
        while (i < N && d[i] > 0) {
          ++i;
        }
      }
      else {
        while (i < N && d[i] < 0) {
          d[i] = -d[i];
          ++i;
        }
      }
      q.emplace(start, i, 0);
    }
    
    RMQ<int> rmq;
    rmq.init(N, d.data());

    long long ret = 0;
    while (!q.empty()) {
      int start, end, from;
      tie(start, end, from) = q.front();
      q.pop();
      if (start == end) {
        continue;
      }
      int mid = rmq.index(start, end);
      int to = d[mid];
      ret += to - from;
      if (start < mid) {
        q.emplace(start, mid, to);
      }
      if (mid + 1 < end) {
        q.emplace(mid + 1, end, to);
      }
    }
    return ret;
  }
};
