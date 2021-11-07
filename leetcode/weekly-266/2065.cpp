class Solution {
public:
    int n;
    vector<int> used;
    vector<int> v, d;
    vector<vector<pair<int, int>>> e;

    int dfs(int cur, int rem, int tot) {
        if (d[cur] > rem) {
            return 0;
        }
        if (used[cur]++ == 0) {
            tot += v[cur];
        }
        int ret = cur == 0 ? tot : 0;
        for (const auto& i: e[cur]) {
            ret = max(ret, dfs(i.first, rem - i.second, tot));
        }
        --used[cur];
        return ret;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        n = values.size();
        v = values;
        e.clear();
        e.resize(n);
        for (const auto& i: edges) {
            int a = i[0], b = i[1], c = i[2];
            e[a].emplace_back(b, c);
            e[b].emplace_back(a, c);
        }

        priority_queue<pair<int, int>> pq;
        d = vector<int>(n, numeric_limits<int>::max());
        d[0] = 0;
        pq.push(make_pair(0, 0));
        while (!pq.empty()) {
            int s = pq.top().second;
            int ds = -pq.top().first;
            pq.pop();
            if (d[s] != ds) {
                continue;
            }
            for (const auto& i: e[s]) {
                if (d[i.first] > ds + i.second) {
                    d[i.first] = ds + i.second;
                    pq.push(make_pair(-d[i.first], i.first));
                }
            }
        }

        used = vector<int>(n, 0);
        return dfs(0, maxTime, 0);
    }
};
