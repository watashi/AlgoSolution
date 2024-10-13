class Solution {
public:
  int findXSum(const int* a, int n, int x) {
    map<int, int> c;
    for (int i = 0; i < n; ++i) {
      ++c[a[i]];
    }
    vector<pair<int, int>> v;
    for (const auto& i : c) {
      v.emplace_back(i.second, i.first);
    }
    sort(v.rbegin(), v.rend());
    if (v.size() >= x) {
      v.resize(x);
    }
    int ret = 0;
    for (const auto& i : v) {
      ret += i.first * i.second;
    }
    return ret;
  }

  vector<int> findXSum(vector<int>& nums, int k, int x) {
    vector<int> ret;
    for (int i = 0; i + k <= (int)nums.size(); ++i) {
      ret.push_back(findXSum(nums.data() + i, k, x));
    }
    return ret;
  }
};
