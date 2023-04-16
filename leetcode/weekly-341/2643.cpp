class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> c;
    for (const auto& i : mat) {
      c.push_back(count(i.begin(), i.end(), 1));
    }
    auto it = max_element(c.begin(), c.end());
    return vector<int>{(int)(it - c.begin()), *it};
  }
};
