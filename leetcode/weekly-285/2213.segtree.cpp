class Solution {
public:
    vector<pair<int, int>> v;

    int L(int p) {
        return p * 2;
    }

    int R(int p) {
        return L(p) + 1;
    }

    void force(int p, int pl, int pm) {
        int& x = v[p].second;
        if (x != -1) {
            v[L(p)].second = x;
            v[L(p)].first = x - pl;
            v[R(p)].second = x;
            v[R(p)].first = x - pm;
            x = -1;
        }
    }

    void update(int p, int pl, int pr, int l, int r, int x) {
        // printf("update(%d, %d, %d, %d, %d)\n", p, pl, pr, l, r);
        if (pl == l && pr == r) {
            v[p].first = x - pl;
            v[p].second = x;
        }
        else {
            int pm = (pl + pr) / 2;
            force(p, pl, pm);
            if (l < pm) {
                update(L(p), pl, pm, l, min(pm, r), x);
            }
            if (pm < r) {
                update(R(p), pm, pr, max(pm, l), r, x);
            }
            v[p].first = max(v[L(p)].first, v[R(p)].first);
        }
    }

    int query(int p, int pl, int pr, int i) {
        // printf("query(%d, %d, %d)\n", p, pl, pr);
        if (pl == i && pr == i + 1) {
            return v[p].first;
        }
        else {
            int pm = (pl + pr) / 2;
            force(p, pl, pm);
            if (i < pm) {
                return query(L(p), pl, pm, i);
            }
            else {
                return query(R(p), pm, pr, i);
            }
        }
    }

    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = 1;
        while (n < (int)s.size()) {
            n <<= 1;
        }
        v = vector<pair<int, int>>(2 * n, make_pair(0, -1));
        for (int i = 0; i < (int)s.length(); ) {
            int j = i;
            while (j < (int)s.length() && s[j] == s[i]) {
                ++j;
            }
            update(1, 0, n, i, j, j);
            i = j;
        }

        vector<int> ret;
        for (int i = 0; i < (int)qc.length(); ++i) {
            int k = qi[i];
            int c = qc[i];
            if (c != s[k]) {
                int x = k + 1;
                s[k] = c;
                if (x < (int)s.length() && s[k] == s[x]) {
                    x += query(1, 0, n, k + 1);
                }
                update(1, 0, n, k, k + 1, x);
                int lo = 0, hi = k;
                while (lo < hi) {
                    int mi = (lo + hi) / 2;
                    if (mi + query(1, 0, n, mi) >= k) {
                        hi = mi;
                    }
                    else {
                        lo = mi + 1;
                    }
                }
                if (hi < k) {
                    update(1, 0, n, hi, k, s[hi] == s[k] ? x : k);
                }
            }
            ret.push_back(v[1].first);
        }
        return ret;
    }
};
