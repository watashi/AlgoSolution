class Solution {
public:
  vector<int> arrayChange(vector<int>& v, vector<vector<int>>& op) {
    unordered_map<int, int> mp;
    for (int i : v) {
      mp[i] = i;
    }
    for (const auto& i : op) {
      auto x = i[0], y = i[1], z = mp[x];
      mp.erase(x);
      mp[y] = z;
    }
    unordered_map<int, int> rmp;
    for (const auto& i : mp) {
      rmp[i.second] = i.first;
    }
    vector<int> ret = v;
    for (int& i : ret) {
      i = rmp[i];
    }
    return ret;
  }
};

// operations[i][0] will exist in nums when applying the ith operation.
// operations[i][1] will not exist in nums when applying the ith operation.
