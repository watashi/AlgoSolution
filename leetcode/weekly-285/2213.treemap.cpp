class Solution {
public:
    map<int, int> mp;
    multiset<int> d;

    void insert(int i, int j) {
        mp[i] = j;
        d.insert(j - i);
    }
    
    void erase(int i, int j) {
        mp.erase(i);
        d.erase(d.find(j - i));
    }
    
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        for (int i = 0; i < (int)s.length(); ) {
            int j = i;
            while (j < (int)s.length() && s[j] == s[i]) {
                ++j;
            }
            insert(i, j);
            i = j;
        }

        vector<int> ret;
        for (int i = 0; i < (int)qc.length(); ++i) {
            int k = qi[i];
            int c = qc[i];
            if (c != s[k]) {
                s[k] = c;
                auto pre = *--mp.upper_bound(k);
                erase(pre.first, pre.second);
                auto cur = make_pair(k, k + 1);
                if (pre.first < k) {
                    insert(pre.first, k);
                } else if (k > 0 && s[k] == s[k - 1]) {
                    auto before = *--mp.upper_bound(k);
                    erase(before.first, before.second);
                    cur.first = before.first;
                }
                if (k + 1 < pre.second) {
                    insert(k + 1, pre.second);
                } else if (k + 1 < (int)s.length() && s[k] == s[k + 1]) {
                    auto after = *mp.find(k + 1);
                    erase(after.first, after.second);
                    cur.second = after.second;
                }
                insert(cur.first, cur.second);
            }
            ret.push_back(*d.rbegin());
        }
        return ret;
    }
};
