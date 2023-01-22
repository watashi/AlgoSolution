class Solution {
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    auto ret = score;
    sort(ret.begin(), ret.end(), [k](const auto& i, const auto& j) { return i[k] > j[k];  });
    return ret;
  }
};
