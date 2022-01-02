class Solution {
public:

    int maximumInvitations(vector<int>& fav) {
        int n = (int)fav.size();
        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            ++d[fav[i]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        vector<int> c(n, 1);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            c[fav[i]] = max(c[fav[i]], c[i] + 1);
            if (--d[fav[i]] == 0) {
                q.push(fav[i]);
            }
        }

        int ans = 0;
        int pairs = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] != 0) {
                int s = i, t = 0;
                do {
                    d[s] = 0;
                    s = fav[s];
                    ++t;
                } while (s != i);
                ans = max(ans, t);
                if (t == 2) {
                    pairs += c[i] + c[fav[i]];
                }
            }
        }
        return max(ans, pairs);
    }
};
