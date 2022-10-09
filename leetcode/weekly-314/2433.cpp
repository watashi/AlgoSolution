class Solution {
public:
  vector<int> findArray(vector<int>& pref) {
    vector<int> ret = pref;
    for (int i = (int)ret.size() - 1; i > 0; --i) {
      ret[i] ^= ret[i - 1];
    }
    return ret;
  }
};
