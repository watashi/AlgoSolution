class Solution {
public:
  static int c2(int n) {
    return n * (n + 1) / 2;
  }

  int numberOfSubstrings(string s) {
    const int n = s.length();
    vector<int> zs;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        zs.push_back(i);
      }
    }

    const int m = zs.size();
    int off = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      // printf("[%d] %d\n", i, off);
      for (int j = 0; off + j <= m; ++j) {
        // [start, end]
        int start = max(i + j + j * j - 1, j == 0 ? i : zs[off + j - 1]);
        int end = off + j < m ? zs[off + j] - 1 : n - 1;
        // printf("%d %d %d\n", j, start, end);
        if (start >= n) {
          break;
        } else if (start <= end) {
          ret += end - start + 1;
        }
      }
      if (off < m && zs[off] == i) {
        ++off;
      }
    }
    return ret;
  }
};

