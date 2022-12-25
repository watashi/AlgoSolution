class Solution {
public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int ret = n;
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        int d = abs(i - startIndex);
        ret = min({ ret, d, n - d });
      }
    }
    if (ret >= n) {
      ret = -1;
    }
    return ret;
  }
};
