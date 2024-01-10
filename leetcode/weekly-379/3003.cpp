class Solution {
public:
  static constexpr int CHARSET = 26;

  int maxPartitionsAfterOperations(string s, int k) {
    const int n = (int)s.length();
    if (k == CHARSET) {
      return 1;
    }

    vector<int> post(n + 1, 0);
    vector<vector<pair<int, bitset<CHARSET>>>> next(n + 1);
    next[n] = vector<pair<int, bitset<CHARSET>>>(CHARSET + 1, make_pair(n, 0));
    for (int i = n - 1; i >= 0; --i) {
      next[i] = vector<pair<int, bitset<CHARSET>>>(CHARSET + 1, make_pair(i, 0));
      for (int j = 0; j <= CHARSET; ++j) {
        int x;
        bitset<CHARSET> y;
        tie(x, y) = next[i + 1][j];
        y.set(s[i] - 'a');
        int z = y.count();
        if (x > next[i][z].first) {
          next[i][z] = make_pair(x, y);
        }
      }
      for (int j = 1; j <= CHARSET; ++j) {
        if (next[i][j].first < next[i][j - 1].first) {
          next[i][j] = next[i][j - 1];
        }
      }
      post[i] = post[next[i][k].first] + 1;
    }

    int ret = post[0];
    int pre = 1;
    bitset<CHARSET> bs;
    for (int i = 0; i < n; ++i) {
      if (bs.count() == k) {
        if ((bs | next[i + 1][k].second).count() < CHARSET) {
          // errf("[%d] A %d+%d (%d)\n", i, pre, 1 + post[next[i + 1][k - 1].first], next[i + 1][k - 1].first);
          ret = max(ret, pre + 1 + post[next[i + 1][k - 1].first]);
        }
      }
      else {
        int skip = i + 1;
        for (int j = 0; j <= CHARSET; ++j) {
          if ((bs | next[i + 1][j].second).count() >= k) {
            break;
          }
          skip = max(skip, next[i + 1][j].first);
        }
        // errf("[%d] B %d+%d (%d)\n", i, pre, post[skip], skip);
        ret = max(ret, pre + post[skip]);
      }
      bs.set(s[i] - 'a');
      if (bs.count() > k) {
        bs.reset();
        bs.set(s[i] - 'a');
        ++pre;
      }
    }
    return ret;
  }
};
