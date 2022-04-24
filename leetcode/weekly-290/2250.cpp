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

class Solution {
public:
  vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
    vector<int> ret(points.size());
    vector<pair<pair<int, int>, int>> qs;
    for (int i = 0; i < (int)points.size(); ++i) {
      qs.emplace_back(make_pair(points[i][0], points[i][1]), i);
    }
    sort(qs.rbegin(), qs.rend());
    BIT<int> bit;
    bit.init(200);
    sort(rect.begin(), rect.end());
    for (const auto& q : qs) {
      int x = q.first.first;
      int y = q.first.second;
      while (!rect.empty() && rect.back()[0] >= x) {
        bit.add(rect.back()[1], 1);
        rect.pop_back();
      }
      ret[q.second] = bit.sum(111) - bit.sum(y);
    }
    return ret;
  }
};
