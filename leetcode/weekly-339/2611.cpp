class Solution {
public:
  int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int s = 0;
    vector<int> d;
    for (int i = 0; i < n; ++i) {
      s += b[i];
      d.push_back(a[i] - b[i]);
    }
    sort(d.rbegin(), d.rend());
    for (int i = 0; i < k; ++i) {
      s += d[i];
    }
    return s;
  }
};
