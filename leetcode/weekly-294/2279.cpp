class Solution {
public:
  int maximumBags(vector<int>& c, vector<int>& r, int ar) {
    vector<int> v;
    for (int i = 0; i < (int)c.size(); ++i) {
      v.push_back(c[i] - r[i]);
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    while (!v.empty() && v.back() <= ar) {
      ar -= v.back();
      v.pop_back();
      ++ans;
    }
    return ans;
  }
};
