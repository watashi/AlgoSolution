class Solution {
public:
  int minimumBoxes(vector<int>& a, vector<int>& c) {
    int s = accumulate(a.begin(), a.end(), 0);
    sort(c.rbegin(), c.rend());
    int ret = 1;
    for (int i : c) {
      s -= i;
      if (s <= 0) {
        return ret;
      }
      ++ret;
    }
    return ret;
  }
};
