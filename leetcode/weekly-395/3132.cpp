class Solution {
public:
  int minimumAddedInteger(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 2; i >= 0; --i) {
      const int x = b[0] - a[i];
      vector<int> c = b;
      for (int& j : c) {
        j -= x;
      }
      if (set_difference(c.begin(), c.end(), a.begin(), a.end(), c.begin()) == c.begin()) {
        return x;
      }
    }
    return -1;
  }
};
