class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        constexpr int CHARSET = 26;
        unordered_map<int, int> m;
        for (const auto& w : words) {
            int x = 0;
            for (char c : w) {
                x |= 1 << (c - 'a');
            }
            ++m[x];
        }

        vector<int> ans{ 0, 0 };
        while (!m.empty()) {
            queue<int> q;
            auto s = *m.begin();
            m.erase(m.begin());
            q.push(s.first);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int i = 0; i < CHARSET; ++i) {
                    {
                        int y = x ^ (1 << i);
                        auto it = m.find(y);
                        if (it != m.end()) {
                            q.push(it->first);
                            s.second += it->second;
                            m.erase(it);
                        }
                    }
                    if ((x & (1 << i)) != 0) {
                        for (int j = 0; j < CHARSET; ++j) {
                            if ((x & (1 << j)) == 0) {
                                int y = x ^ (1 << i) ^ (1 << j);
                                auto it = m.find(y);
                                if (it != m.end()) {
                                    q.push(it->first);
                                    s.second += it->second;
                                    m.erase(it);
                                }
                            }
                        }
                    }
                }
            }
            ++ans[0];
            ans[1] = max(ans[1], s.second);
        }
        return ans;
    }
};

