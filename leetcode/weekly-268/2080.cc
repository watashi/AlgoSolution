class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        mp.clear();
        for (int i = 0; i < (int)arr.size(); ++i) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto it = mp.find(value);
        if (it == mp.end()) {
            return 0;
        }
        const auto& v = it->second;
        return lower_bound(v.begin(), v.end(), right + 1) - lower_bound(v.begin(), v.end(), left);
    }

    unordered_map<int, vector<int>> mp;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
