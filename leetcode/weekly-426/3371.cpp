class Solution {
public:
  int getLargestOutlier(vector<int>& nums) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    map<int, int> mp;
    for (int i : nums) {
      ++mp[i];
    }

    vector<int> v;
    for (int i : nums) {
      int t = s - i;
      if (t % 2 == 0) {
        t /= 2;
        auto it = mp.find(t);
        if (it != mp.end() && (t != i || it->second > 1)) {
          v.push_back(i);
        }
      }
    }
    return *max_element(v.begin(), v.end());
  }
};
