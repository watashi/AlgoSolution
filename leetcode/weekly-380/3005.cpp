class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> m;
    int mf = 0;
    for (int i : nums) {
      mf = max(mf, ++m[i]);
    }
    return mf * count_if(m.begin(), m.end(), [mf](const auto& i) { return i.second == mf; });
  }
};
