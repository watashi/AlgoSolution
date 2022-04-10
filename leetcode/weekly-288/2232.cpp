class Solution {
public:
    string minimizeResult(string expr) {
        int plus = expr.find('+');
        int end = expr.length();
        pair<int64_t, string> ans(numeric_limits<int64_t>::max(), "");
        for (int i = 0; i < plus; ++i) {
            for (int j = plus + 2; j <= end; ++j) {
                string sa = expr.substr(0, i);
                string sb = expr.substr(i, plus - i);
                string sc = expr.substr(plus + 1, j - plus - 1);
                string sd = expr.substr(j, end - j);
                int64_t a = sa.empty() ? 1 : stoll(sa);
                int64_t b = stoll(sb);
                int64_t c = stoll(sc);
                int64_t d = sd.empty() ? 1 : stoll(sd);
                int64_t tmp = a * d * (b + c);
                ans = min(ans, make_pair(tmp, sa + "(" + sb + "+" + sc + ")" + sd));
                // cout << sa + "(" + sb + "+" + sc + ")" + sd << ": " << tmp << endl;
            }
        }
        return ans.second;
    }
};
