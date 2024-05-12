class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    vector<int> s = energy;
    const int n = s.size();
    for (int i = n - k - 1; i >= 0; --i) {
      s[i] += s[i + k];
    }
    return *max_element(s.begin(), s.end());
  }
};
