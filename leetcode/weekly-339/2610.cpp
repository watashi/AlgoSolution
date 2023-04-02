class Solution {
public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int i : nums) {
      ++m[i];
    }
    vector<vector<int>> v;
    while (!m.empty()) {
      v.push_back({});
      auto it = m.begin();
      while (it != m.end()) {
        v.back().push_back(it->first);
        if (--it->second == 0) {
          it = m.erase(it);
        }
        else {
          ++it;
        }
      }
    }
    return v;
  }
};
