class Solution {
public:
  vector<int> numberOfPairs(vector<int>& nums) {
    map<int, int> mp;
    for (int i : nums) {
      ++mp[i];
    }
    vector<int> ret = { 0, 0 };
    for (const auto& i : mp) {
      ret[0] += i.second / 2;
      ret[1] += i.second % 2;
    }
    return ret;
  }
};
