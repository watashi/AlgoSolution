class Solution {
public:
  vector<int> resultArray(vector<int>& x) {
    vector<int> a, b;
    reverse(x.begin(), x.end());
    a.push_back(x.back());
    x.pop_back();
    b.push_back(x.back());
    x.pop_back();
    while (!x.empty()) {
      if (a.back() > b.back()) {
        a.push_back(x.back());
      }
      else {
        b.push_back(x.back());
      }
      x.pop_back();
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};
