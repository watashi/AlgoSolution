struct BIT {
    vector<unordered_map<int, int>> a;

    void init(int n) {
        vector<unordered_map<int, int>>(n + 1).swap(a);
    }

    void add(int i, int v) {
        for (int j = i + 1; j < (int)a.size(); j = (j | (j - 1)) + 1) {
            ++a[j][v];
        }
    }

    // [0, i)
    int count(int i, int k) const {
        int v = 0;
        for (int j = i; j > 0; j = j & (j - 1)) {
            auto it = a[j].find(k);
            if (it != a[j].end()) {
                v += it->second;
            }
        }
        return v;
    }
};

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        bit.init(n);
        for (int i = 0; i < n; ++i) {
            bit.add(i, arr[i]);
        }
    }

    int query(int left, int right, int value) {
        return bit.count(right + 1, value) - bit.count(left, value);
    }

    BIT bit;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
