class Solution {
public:
    int nextGreaterElement(int n) {
        char buf[80];
        sprintf(buf, "%d", n);
        string s = buf;
        puts(s.data());
        sort(s.begin(), s.end());
        long long ans = INT_MAX + 1LL;
        do {
            long long tmp = atoll(s.c_str());
            if (tmp > n) {
                ans = min(ans, tmp);
            }
        } while (next_permutation(s.begin(), s.end()));
        return ans <= INT_MAX ? ans : -1;
    }
};
