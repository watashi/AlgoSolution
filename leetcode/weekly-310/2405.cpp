class Solution {
public:
  int partitionString(string s) {
    int ret = 1;
    set<char> st;
    for (char c : s) {
      if (st.count(c) > 0) {
        ++ret;
        st.clear();
      }
      st.insert(c);
    }
    return ret;
  }
};
