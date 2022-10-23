class Solution {
public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    vector<pair<long long, long long>> v;
    long long sl = 0, sr = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      v.emplace_back(nums[i], cost[i]);
      sr += cost[i];
    }
    sort(v.begin(), v.end());

    long long sum = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      sum += (v[i].first - v[0].first) * v[i].second;
    }

    long long ret = sum;
    for (int i = 1; i < (int)v.size(); ++i) {
      sl += v[i - 1].second;
      sr -= v[i - 1].second;
      sum += (sl - sr) * (v[i].first - v[i - 1].first);
      ret = min(ret, sum);
    }
    return ret;
  }
};
