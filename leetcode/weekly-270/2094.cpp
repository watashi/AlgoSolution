class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> c(10);
        for (int i: digits) {
            ++c[i];
        }
        vector<int> ret;
        for (int i = 1; i < 10; ++i) {
            if (c[i] == 0) {
                continue;
            }
            --c[i];
            for (int j = 0; j < 10; ++j) {
                if (c[j] == 0) {
                    continue;
                }
                --c[j];
                for (int k = 0; k < 10; k += 2) {
                    if (c[k] > 0) {
                        ret.push_back(i * 100 + j * 10 + k);
                    }
                }
                ++c[j];
            }
            ++c[i];
        }
        return ret;
    }
};
