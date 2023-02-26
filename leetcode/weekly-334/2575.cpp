class Solution {
public:
  vector<int> divisibilityArray(string word, int m) {
    vector<int> v;
    int64_t r = 0;
    for (char c : word) {
      r = (r * 10 + (c - '0')) % m;
      v.push_back(r == 0 ? 1 : 0);
    }
    return v;
  }
};
