class Solution {
public:
  int mostFrequentEven(vector<int>& nums) {
    map<int, int> m;
    for (int i : nums) {
      if (i % 2 == 0) {
        ++m[i];
      }
    }
    if (m.empty()) {
      return -1;
    }
    else {
      pair<int, int> p{0, 0};
      for (const auto& i : m) {
        if (i.second > p.second) {
          p = i;
        }
      }
      return p.first;
    }
  }
};
