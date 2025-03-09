class Solution {
public:
  vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    const int n = nums1.size();
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; ++i) {
      m[nums1[i]].emplace_back(i, nums2[i]);
    }

    vector<long long> ret(n);
    multiset<long long> st;
    long long tot = 0;
    for (const auto& i : m) {
      for (const auto& j : i.second) {
        ret[j.first] = tot;
      }
      for (const auto& j : i.second) {
        tot += j.second;
        st.insert(j.second);
        if (st.size() > k) {
          tot -= *st.begin();
          st.erase(st.begin());
        }
      }
    }
    return ret;
  }
};
