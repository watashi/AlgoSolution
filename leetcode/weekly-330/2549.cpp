class Solution {
public:
  int distinctIntegers(int n) {
    set<int> st;
    queue<int> q;
    st.insert(n);
    q.push(n);
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      for (int i = 1; i <= n; ++i) {
        if (s % i == 1 && st.insert(i).second) {
          q.push(i);
        }
      }
    }
    return st.size();
  }
};
