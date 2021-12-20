class Solution {
public:
    static int lis(const vector<int>& v) {
        vector<int> w;
        for (int i: v) {
            auto it = upper_bound(w.begin(), w.end(), i);
            if (it == w.end()) {
                w.push_back(i);
            } else {
                *it = i;
            }
        }
        return (int)w.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int ret = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v;
            for (int j = i; j < (int)arr.size(); j += k) {
                v.push_back(arr[j]);
            }
            ret += (int)v.size() - lis(v);
        }
        return ret;
    }
};
