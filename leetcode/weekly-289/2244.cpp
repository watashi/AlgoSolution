class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> c;
    for (int i : tasks) {
      ++c[i];
    }
    int ans = 0;
    for (const auto& i : c) {
      if (i.second == 1) {
        return -1;
      }
      ans += (i.second + 2) / 3;
    }
    return ans;
  }
};
