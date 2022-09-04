class Solution {
public:
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> v(26, -1);
    for (int i = 0; i < (int)s.size(); ++i) {
      int c = s[i] - 'a';
      int& x = v[c];
      if (x == -1) {
        x = i;
      }
      else if (i - x != distance[c] + 1) {
        return false;
      }
    }
    return true;
  }
};
