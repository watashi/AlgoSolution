struct Point {
  long long x, y;
};

Point operator-(const Point& a, const Point& b) {
  return Point{ a.x - b.x, a.y - b.y };
}

long long operator%(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

class Solution {
public:
  int minimumLines(vector<vector<int>>& stockPrices) {
    vector<Point> v;
    sort(stockPrices.begin(), stockPrices.end());
    for (const auto& i : stockPrices) {
      v.push_back({ i[0], i[1] });
    }
    if (v.size() == 1) {
      return 0;
    }
    int ans = 1;
    Point a = v[0];
    Point b = v[1];
    for (int i = 2; i < (int)v.size(); ++i) {
      Point c = v[i];
      if ((c - a) % (b - a) != 0) {
        a = b;
        b = c;
        ++ans;
      }
      else {
        b = c;
      }
    }
    return ans;
  }
};
