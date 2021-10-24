class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> degree(n), dist(n);
        vector<vector<int>> e(n);
        for (const auto& i: relations) {
            int s = i[0] - 1, t = i[1] - 1;
            e[s].push_back(t);
            ++degree[t];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            dist[s] += time[s];
            for (int t: e[s]) {
                dist[t] = max(dist[t], dist[s]);
                if (--degree[t] == 0) {
                    q.push(t);
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};
