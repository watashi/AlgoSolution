class Solution {
public:
    static void dfs(int v, unordered_map<int, list<int>>& e, list<int>& path, list<int>::iterator pathPos) {
        list<int>& ev = e[v];
        while (!ev.empty()) {
            int w = ev.front();
            ev.pop_front();

            auto pos = path.insert(pathPos, w);
            dfs(w, e, path, pathPos);
            pathPos = pos;
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, list<int>> e;
        unordered_map<int, int> din, dout;
        for (const auto& i: pairs) {
            int a = i[0], b = i[1];
            e[a].push_back(b);
            ++dout[a];
            ++din[b];
        }

        int start = pairs.front()[0];
        for (const auto& i: dout) {
            auto it = din.find(i.first);
            if (it == din.end() || it->second < i.second) {
                start = i.first;
                break;
            }
        }

        list<int> path;
        path.push_back(start);
        dfs(start, e, path, path.end());

        auto cur = path.begin();
        auto pre = cur++;
        vector<vector<int>> ret;
        while (cur != path.end()) {
            ret.push_back(vector<int>{*pre, *cur});
            pre = cur;
            ++cur;
        }

        return ret;
    }
};
