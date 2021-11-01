class Solution {
public:
    string sa, sb;
    vector<vector<unordered_set<int>>> done;
    int depth;

    bool go(int a, int b, int d) {
        /*
        fprintf(stderr, "%*sgo(%d, %d, %d)\n", depth, "", a, b, d);
        ScopeGuard sg(&depth);
        */
        if (done[a][b].count(d) > 0) {
            return false;
        }
        done[a][b].insert(d);
        if (a == sa.size() && b == sb.size()) {
            return d == 0;
        } else if (a == sa.size() || (b != sb.size() && d > 0)) {
            if (!isdigit(sb[b])) {
                return go(a, b + 1, d - 1);
            } else {
LABEL:
                int x = 0;
                do {
                    x *= 10;
                    x += sb[b++] - '0';
                    if (x != 0 && go(a, b, d - x)) {
                        return true;
                    }
                } while (b < (int)sb.size() && isdigit(sb[b]));
                return false;
            }
        } else if (b == sb.size() || (a != sa.size() && d < 0)) {
            if (!isdigit(sa[a])) {
                return go(a + 1, b, d + 1);
            } else {
                int x = 0;
                do {
                    x *= 10;
                    x += sa[a++] - '0';
                    if (x != 0 && go(a, b, d + x)) {
                        return true;
                    }
                } while (a < (int)sa.size() && isdigit(sa[a]));
                return false;
            }
        } else if (a == sa.size() || b == sb.size()) {
            return false;
        } else if (!isdigit(sa[a]) && !isdigit(sb[b])) {
            return sa[a] == sb[b] && go(a + 1, b + 1, d);
        } else if (!isdigit(sa[a])) {
            return go(a + 1, b, d + 1);
        } else if (!isdigit(sb[b])) {
            return go(a, b + 1, d - 1);
        } else {
            goto LABEL;
        }
    }

    bool possiblyEquals(string s1, string s2) {
        depth = 0;
        sa = s1;
        sb = s2;
        done = vector<vector<unordered_set<int>>>(sa.size() + 1, vector<unordered_set<int>>(sb.size() + 1));
        return go(0, 0, 0);
    }
};

