class Solution {
public:
  int edgeScore(vector<int>& e) {
    int n = e.size();
    vector<int64_t> s(n, 0);
    for (int i = 0; i < n; ++i) {
      s[e[i]] += i;
    }
    return max_element(s.begin(), s.end()) - s.begin();
  }
};
