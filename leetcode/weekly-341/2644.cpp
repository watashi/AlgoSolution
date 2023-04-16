class Solution {
public:
  int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    pair<int, int> best(-1, -1);
    for (int d : divisors) {
      int c = count_if(nums.begin(), nums.end(), [d](int i) { return i % d == 0;  });
      best = max(best, make_pair(c, -d));
    }
    return -best.second;
  }
};
