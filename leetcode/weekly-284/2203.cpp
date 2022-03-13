
class Solution {
public:
    static constexpr int64_t INF = 12345678987654321LL;

    static vector<int64_t> solve(int n, const vector < vector<pair<int, int64_t>>>& e, int s) {
        vector<int64_t> mind(n, INF);
        priority_queue<pair<int64_t, int>> pq;
        mind[s] = 0;
        pq.push(make_pair(-mind[s], s));
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            auto s = top.second;
            if (top.first != -mind[s]) {
                continue;
            }
            for (const auto& i : e[s]) {
                if (mind[i.first] > mind[s] + i.second) {
                    mind[i.first] = mind[s] + i.second;
                    pq.push(make_pair(-mind[i.first], i.first));
                }
            }
        }
        return mind;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector < vector<pair<int, int64_t>>> e(n), re(n);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int w = edge[2];
            e[from].emplace_back(to, w);
            re[to].emplace_back(from, w);
        }
        vector<int64_t> s1 = solve(n, e, src1);
        vector<int64_t> s2 = solve(n, e, src2);
        vector<int64_t> d = solve(n, re, dest);
        int64_t ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, s1[i] + s2[i] + d[i]);
        }
        return ans < INF ? ans : -1;
    }
};
