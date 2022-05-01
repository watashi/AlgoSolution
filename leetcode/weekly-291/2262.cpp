class Solution {
public:
  long long appealSum(string s) {
    vector<int> last(26, 0);
    int64_t sum = 0;
    int64_t ret = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
      sum -= last[s[i] - 'a'];
      last[s[i] - 'a'] = i + 1;
      sum += last[s[i] - 'a'];
      ret += sum;
    }
    return ret;
  }
};
