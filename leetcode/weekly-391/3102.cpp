class Solution {
public:
  int dist(const vector<pair<int, int>>& v, int k) {
    int i = 0, j = (int)v.size() - 1;
    if (v[i].second == k) {
      ++i;
    }
    if (v[j].second == k) {
      --j;
    }
    return v[j].first - v[i].first;
  }

  int minimumDistance(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < n; ++i) {
      int x = points[i][0], y = points[i][1];
      v1.emplace_back(x + y, i);
      v2.emplace_back(x - y, i);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ret = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      ret = min(ret, max(dist(v1, i), dist(v2, i)));
    }
    return ret;
  }
};
