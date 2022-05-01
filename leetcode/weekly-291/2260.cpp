class Solution {
public:
  int minimumCardPickup(vector<int>& c) {
    int pre = 0;
    int ret = c.size() + 1;
    set<int> st;
    for (int i = 0; i < (int)c.size(); ++i) {
      if (st.count(c[i]) == 0) {
        st.insert(c[i]);
      }
      else {
        while (c[pre] != c[i]) {
          st.erase(c[pre++]);
        }
        ret = min(ret, i + 1 - pre);
        ++pre;
      }
    }
    if (ret > (int)c.size()) {
      ret = -1;
    }
    return ret;
  }
};
