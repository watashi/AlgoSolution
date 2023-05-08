class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n, 0), suf(n, 0);
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(a[i]);
            pre[i] = st.size();
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            st.insert(a[i]);
            suf[i] = st.size();
        }
        vector<int> ret = pre;
        for (int i = 1; i < n; ++i) {
            ret[i - 1] -= suf[i];
        }
        return ret;
    }
};
