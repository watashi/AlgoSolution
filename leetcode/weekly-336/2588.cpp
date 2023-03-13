class Solution {
public:
  long long beautifulSubarrays(vector<int>& nums) {
    int64_t ret = 0;
    unordered_map<int, int> m;
    int k = 0;
    m[0] = 1;
    for (int i : nums) {
      k ^= i;
      ret += m[k]++;
    }
    return ret;
  }
};
