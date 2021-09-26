class Solution {
public:
    static constexpr int MAXN = 20;
    static constexpr int INF = 1000 + 1;
    vector<int> dp[MAXN][MAXN];

    const vector<int>& go(int from, int to, const vector<int>& x, const string& op) {
        auto& ret = dp[from][to];
        if (!ret.empty()) {
            return ret;
        }
        if (from == to) {
            ret.emplace_back(x[from]);
            return ret;
        }
        set<int> st;
        for (int i = from; i < to; ++i) {
            const auto& lhs = go(from, i, x, op);
            const auto& rhs = go(i + 1, to, x, op);
            if (op[i] == '+') {
              for (int x: lhs) {
                for (int y: rhs) {
                  int z = min(INF, x + y);
                  st.emplace(z);
                  if (z == INF) {
                    break;
                  }
                }
              }
            } else {
              for (int x: lhs) {
                for (int y: rhs) {
                  int z = min(INF, x * y);
                  st.emplace(z);
                  if (z == INF) {
                    break;
                  }
                }
              }
            }
        }
        ret = vector<int>(st.begin(), st.end());
        return ret;
    }

    int scoreOfStudents(string s, vector<int>& answers) {
        int n = (int)s.size() / 2;
        vector<int> x;
        string op;
        for (int i = 0; i <= n; ++i) {
            x.push_back(s[2 * i] - '0');
        }
        for (int i = 0; i < n; ++i) {
            op.push_back(s[2 * i + 1]);
        }
        int64_t sum = 0, part = x[0];
        for (int i = 0; i < n; ++i) {
            if (op[i] == '+') {
                sum += part;
                part = x[i + 1];
            } else {
                part *= x[i + 1];
            }
        }
        sum += part;

        fill(dp[0], dp[MAXN], vector<int>());
        const auto& st = go(0, (int)op.size(), x, op);
        bitset<INF + 1> bs;
        for (auto i: st) {
          bs[i] = true;
        }
        int ret = 0;
        for (int i: answers) {
            if (i == sum) {
                ret += 5;
            } else if (bs[i]) {
                ret += 2;
            }
        }
        return ret;
    }
};
