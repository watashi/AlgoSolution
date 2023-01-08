class Solution {
public:
  long long maxKelements(vector<int>& nums, int k) {
    long long ret = 0;
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k; ++i) {
      auto x = pq.top();
      pq.pop();
      ret += x;
      pq.push((x + 2) / 3);
    }
    return ret;
  }
};
