class Solution {
public:
  int maxDistance(int side0, vector<vector<int>>& points, int k) {
    const long long side = side0;
    vector<long long> v;
    for (const auto& i : points) {
      long long x = i[0], y = i[1];
      if (y == 0) {
        v.push_back(x);
      }
      else if (x == side) {
        v.push_back(side + y);
      }
      else if (y == side) {
        v.push_back(side * 3 - x);
      }
      else if (x == 0) {
        v.push_back(side * 4 - y);
      }
    }
    sort(v.begin(), v.end());
    /*
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
    */

    const int n = v.size();
    long long lo = 0, hi = side * 4 + 1;
    while (lo < hi) {
      bool ok = false;
      int mi = (lo + hi) / 2;
      vector<pair<int, long long>> lasts(v.size(), make_pair(-1, 0));
      for (int i = 0; i < n; ++i) {
        if (lasts[i].first != -1) {
          continue;
        }
        int pos = i;
        vector<int> chain;
        chain.push_back(pos);
        while (lasts[pos].first == -1) {
          int next = lower_bound(v.begin() + pos, v.end(), v[pos] + mi) - v.begin();
          if (next == n) {
            lasts[pos] = make_pair(1, v[pos]);
            break;
          }
          pos = next;
          chain.push_back(pos);
        }
        for (int j = (int)chain.size() - 2; j >= 0; --j) {
          int prev = chain[j], next = chain[j + 1];
          lasts[prev] = lasts[next];
          ++lasts[prev].first;
        }
        int steps = lasts[i].first;
        if (lasts[i].second + mi > side * 4 + v[i]) {
          --steps;
        }
        // cout << mi << " " << i << " " << steps << endl;
        if (steps >= k) {
          ok = true;
          break;
        }
      }
      if (ok) {
        lo = mi + 1;
      }
      else {
        hi = mi;
      }
    }
    return hi - 1;
  }
};
