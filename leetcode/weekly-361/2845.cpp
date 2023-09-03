
class Solution {
public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long ret = 0;
    int s = 0;
    unordered_map<int, int> c;
    ++c[s];
    for (int i : nums) {
      s = (s + (i % modulo == k ? 1 : 0)) % modulo;
      auto it = c.find((s + modulo - k) % modulo);
      ret += it == c.end() ? 0 : it->second;
      ++c[s];
    }
    return ret;
  }
};
