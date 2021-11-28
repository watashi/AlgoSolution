class Solution {
public:
    static void dfs(int v, vector<bool>& mark, const unordered_map<int, vector<int>>& e) {
        auto it = e.find(v);
        if (it != e.end()) {
            for (auto y: it->second) {
                if (!mark[y]) {
                    mark[y] = true;
                    dfs(y, mark, e);
                }
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> mark(n);
        mark[0] = true;
        mark[firstPerson] = true;

        map<int, vector<pair<int, int>>> m;
        for (const auto& i: meetings) {
            m[i[2]].emplace_back(i[0], i[1]);
        }

        for (const auto& i: m) {
            unordered_map<int, vector<int>> e;
            for (const auto& j: i.second) {
                int a = mark[j.first] ? 0 : j.first;
                int b = mark[j.second] ? 0 : j.second;
                if (a != b) {
                    e[a].push_back(b);
                    e[b].push_back(a);
                }
            }
            dfs(0, mark, e);
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
