class Solution {
public:
  int minimumAddedCoins(vector<int>& coins, int target) {
    vector<int> v = coins;
    long long sum = 0;
    int ret = 0;
    sort(v.begin(), v.end());
    v.push_back(target + 1);
    for (int i : v) {
      while (sum < target && sum < i - 1) {
        sum += sum + 1;
        ++ret;
      }
      if (sum >= target) {
        break;
      }
      sum += i;
    }
    return ret;
  }
};
