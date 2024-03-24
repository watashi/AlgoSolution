class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    unordered_map<int, long long> mp;
    set<pair<long long, int>> st;
    vector<long long> ret;
    int n = nums.size();
    ret.reserve(n);
    for (int i = 0; i < n; ++i) {
      const int k = nums[i];
      long long& v = mp[k];
      st.erase(make_pair(v, k));
      v += freq[i];
      st.insert(make_pair(v, k));
      ret.push_back(st.rbegin()->first);
    }
    return ret;
  }
};
