class Solution {
public:
  long long minCost(vector<int>& b1, vector<int>& b2) {
    map<int, int> m, m1;
    for (int i : b1) {
      ++m[i];
      ++m1[i];
    }
    for (int i : b2) {
      ++m[i];
    }
    for (auto& i : m) {
      if (i.second % 2 != 0) {
        return -1;
      }
      i.second /= 2;
    }

    int w2 = m.begin()->first * 2;
    vector<int> v;
    for (const auto& i : m) {
      int x = i.second;
      int y = m1[i.first] - x;
      while (y > 0) {
        v.push_back(i.first);
        --y;
      }
      while (y < 0) {
        v.push_back(i.first);
        ++y;
      }
    }

    int64_t ret = 0;
    v.resize((int)v.size() / 2);
    while (!v.empty() && v.back() > w2) {
      ret += w2;
      v.pop_back();
    }
    return accumulate(v.begin(), v.end(), ret);
  }
};
