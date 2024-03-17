class Solution {
public:
  long long minimumMoves(vector<int>& a, int k, int maxChanges) {
    vector<int> p;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (a[i] != 0) {
        p.push_back(i);
      }
    }
    if (p.size() + maxChanges < k) {
      return -1;
    }
    if (p.empty()) {
      return 2 * k;
    }
    if (k < 2) {
      return 0;
    }

    vector<long long> ps;
    ps.push_back(0);
    for (int x : p) {
      ps.push_back(ps.back() + x);
    }

    long long ret = numeric_limits<long long>::max();
    maxChanges = min(maxChanges, k - 1);
    for (int c = max(0, maxChanges - 2); c <= maxChanges; ++c) {
      const int d = k - c;
      for (int i = 0; i + d <= (int)p.size(); ++i) {
        int mid = i + d / 2, end = i + d;
        long long tmp = 2LL * c;
        tmp += (mid - i) * (long long)p[mid] - (ps[mid] - ps[i]);
        tmp += (ps[end] - ps[mid]) - (end - mid) * (long long)p[mid];
        // cout << c << " " << i << " [" << p[i] << "," << p[end - 1] << "] " << tmp << endl;
        ret = min(ret, tmp);
      }
    }
    return ret;
  }
};
