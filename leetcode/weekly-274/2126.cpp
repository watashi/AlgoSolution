class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int64_t m = mass;
        sort(a.begin(), a.end());
        for (int i: a) {
            if (i > m) {
                return false;
            }
            m += i;
        }
        return true;
    }
};
